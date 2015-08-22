/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
AUTHOR:CHARLTON FERNANDES

lcd.h

LCD SUPPORTED:JHD 162A

LCD MICRO-CONTROLLER:HITACHI HD44780U

DEFAULT SETTINGS:

DATA MODE:4 BIT
RS----------------PORTB 4
RW----------------GROUND (LCD_DO_NOT_USE_RW) / PORTB 6 (LCD_USE_RW)
E-----------------PORTB 5
D0----------------OPEN
D1----------------OPEN
D2----------------OPEN
D3----------------OPEN
D4----------------PORTB 0
D5----------------PORTB 1
D6----------------PORTB 2
D7----------------PORTB 3
LED CONTROL-------TO RESPECTIVE VOLTAGE (LCD_DO_NOT_CONTROL_LED) /PORTB 7 (LCD_CONTROL_LED)

DATA MODE:8 BIT
RS----------------PORTC 0
RW----------------GROUND (LCD_DO_NOT_USE_RW) / PORTC 2 (LCD_USE_RW)
E-----------------PORTC 1
D0----------------PORTB 0
D1----------------PORTB 1
D2----------------PORTB 2
D3----------------PORTB 3
D4----------------PORTB 4
D5----------------PORTB 5
D6----------------PORTB 6
D7----------------PORTB 7
LED CONTROL-------TO RESPECTIVE VOLTAGE (LCD_DO_NOT_CONTROL_LED) /PORTC 3 (LCD_CONTROL_LED)

DESCRIPTION:
	THIS HEADER FILE HAVE IMPLEMENTATION OF SOME COMMON FUNCTIONS OF THE LCD.
	INCLUDE THIS HEADER FILE IN YOUR C CODE.

	lcd_init(): INITIALIZE THE MODULE.CALL THIS FUNCTION FIRST BEFORE CALLING ANY OTHER FUNCTION.
	lcd_cmd():  THIS FUNCTION IS USED TO GIVE ANY COMMAND INSTRUCTIONS TO THE LCD MODULE.
	lcd_char(): THIS FUNCTION WILL DISPLAY A SINGLE CHARACTER ON THE LCD DISPLAY.
	lcd_string():THIS FUNCTION WILL DISPLAY A STRING.
	lcd_string_p():THIS FUNCTION WILL DISPLAY A STRING DIRECTLY FROM FLASH MEMORY.
	lcd_gotoxy():WILL SET THE CURSOR AT A PARTICULAR POSITION ON OF THE LCD.
	lcd_clear():TO CLEAR THE LCD
	lcd_home():RETURNS THE CURSOR TO INITIAL POSITION I.E. (0,0)
	lcd_delay_ms_custom():DELAY ROUTINE USED TO PRODUCE DELAY IN MILLI-SECOND RANGE.SAME AS _DELAY_MS() FUNCTION IN UTIL/DELAY.H.
	lcd_delay_us_custom():DELAY ROUTINE USED TO PRODUCE DELAY IN NANO-SECOND RANGE.
	lcd_custom():USED TO SET VALUES TO CREATE CUSTOM CHARACTERS.CALL THIS FUNCTION BEFORE USING ANY OF THE CUSTON CHARACTERS.
	lcd_showvalue():THIS FUNCTION WILL DISPLAY THE INTEGER VALUE OF SINGLE CHARACTER ON THE LCD DISPLAY.
    lcd_int():USED TO DISPLAY VALUE OF AN INTEGER.
              THE VALUE OF MACRO LIMIT_INT SPECIFIES NUMBER OF CHARACTERS THE INTEGER WILL OCCUPY ON THE SCREEN(INCLUDES THE SIGN CHARACTER ALSO).
    lcd_float():USED TO DISPLAY VALUE OF A FLOAT.
              THE VALUE OF MACRO LIMIT_INT SPECIFIES NUMBER OF CHARACTERS THE INTEGER PART OF THE FLOAT WILL OCCUPY ON THE LCD DISPLAY(INCLUDES THE SIGN CHARACTER ALSO).
              THE VALUE OF MACRO LIMIT_FLOAT SPECIFIES NUMBER OF CHARACTERS THE DECIMAL PART OF THE FLOAT WILL OCCUPY ON THE LCD DISPLAY(DOES NOT INCLUDE THE DECIMAL DOT '.').

NOTES:(OPTIONAL)
AFTER LOADING THE CODE ONTO THE MICRO-CONTROLLER, REST THE ENTIRE SYSTEM TO PROPERLY INITIATE THE LCD.

FOLLOWING CODE TO BE USED WITH LCD_CMD()
           INSTRUCTION	                                     HEXADECIMAL
FUNCTION SET (8-BIT INTERFACE, 2 LINES, 5*8 PIXELS)	             38
FUNCTION SET (8-BIT INTERFACE, 1 LINE, 5*8 PIXELS)	             30
FUNCTION SET (4-BIT INTERFACE, 2 LINES, 5*8 PIXELS)	             28
FUNCTION SET (4-BIT INTERFACE, 1 LINE, 5*8 PIXELS) 	             20
SCROLL DISPLAY ONE CHARACTER RIGHT (ALL LINES)	                 1E
SCROLL DISPLAY ONE CHARACTER LEFT (ALL LINES)  	                 18
HOME (MOVE CURSOR TO TOP/LEFT CHARACTER POSITION)  	             02
MOVE CURSOR ONE CHARACTER LEFT 	                                 10
MOVE CURSOR ONE CHARACTER RIGHT 	                             14
TURN ON VISIBLE UNDERLINE CURSOR 	                             0E
TURN ON VISIBLE BLINKING-BLOCK CURSOR 	                         0F
MAKE CURSOR INVISIBLE 	                                         0C
BLANK THE DISPLAY (WITHOUT CLEARING)	                         08
RESTORE THE DISPLAY (WITH CURSOR HIDDEN) 	                     0C
CLEAR SCREEN 	                                                 01
SET CURSOR POSITION (DDRAM ADDRESS) 	                       80+ ADDR
SET POINTER IN CHARACTER-GENERATOR RAM                         40+ ADDR
(CG RAM ADDRESS)

ENTRY MODE SET (HOW DATA WILL BE DISPLAYED ON SCREEN)
1)SHIFT:OFF AND DECREMENT                                        04
2)SHIFT:ON AND DECREMENT                                         05
3)SHIFT:OFF AND INCREMENT (DEFAULT MODE)                         06
4)SHIFT:ON AND INCREMENT                                         07

USING CUSTOM CHARACTERS(CC)
INITIALIZING CC:YOU CAN CREATE 8 CC CORRESPONDING TO THE LCD ADDRESSES(CGRAM) 0X00 TO 0X07.
                SPECIFY THE VALUES OF THE CC IN CUSTOM_CHAR ARRAY IN LCD_CUSTOM FUNCTION.
USING CC:BY CALLING LCD_CHAR() WITH THE ADDRESS OF THE REQUIRED CC AS THE ARGUMENT.
         BY CALLING LCD_STRING() AND USING % SYMBOL FOLLOWED BY THE DECIMAL VALUE OF THE ADDRESS OF CC IN BETWEEN OTHER CHARACTERS IN THE STRING.
         FOR EXAMPLE	TO DISPLAY CC NUMBER 0, YOU	NEED TO WRITE %0

CODES DERIVED FROM THE FOLLOWING(OBTAINED FROM DATA SHEET):

INSTRUCTION     RS  R/(LOW W)   DB7     DB6     DB5     DB4     DB3     DB2     DB1     DB0     DESCRIPTION
CLEAR DISPLAY   0   0           0       0       0       0       0       0       0       1       CLEARS ENTIRE DISPLAY AND SETS DDRAM ADDRESS 0 IN ADDRESS COUNTER.

RETURN HOME     0   0           0       0       0       0       0       0       1       —       SETS DDRAM ADDRESS 0 IN ADDRESS COUNTER. ALSO RETURNS DISPLAY FROM BEING SHIFTED TO ORIGINAL POSITION.
                                                                                                DDRAM CONTENTS REMAIN UNCHANGED.

ENTRY MODE SET  0   0           0       0       0       0       0       1       I/D     S       SETS CURSOR MOVE DIRECTION AND SPECIFIES DISPLAY SHIFT.
                                                                                                THESE OPERATIONS ARE PERFORMED DURING DATA WRITE AND READ.

DISPLAY ON/OFF  0   0           0       0       0       0       1       D       C       B       SETS ENTIRE DISPLAY (D) ON/OFF,
CONTROL                                                                                         CURSOR ON/OFF (C), AND BLINKING OF CURSOR POSITION CHARACTER (B).

CURSOR OR       0   0           0       0       0       1       S/C     R/L     —       —       MOVES CURSOR AND SHIFTS DISPLAY WITHOUT CHANGING DDRAM CONTENTS.
DISPLAY
SHIFT

FUNCTION SET    0   0           0       0       1       DL      N       F       —       —       SETS INTERFACE DATA LENGTH(DL), NUMBER OF DISPLAY LINES(N),
                                                                                                AND CHARACTER FONT (F).

SET CGRAM       0   0           0       1       ACG     ACG     ACG     ACG     ACG     ACG     SETS CGRAM ADDRESS.
ADDRESS                                                                                         CGRAM DATA IS SENT AND RECEIVED AFTER THIS SETTING.


SET DDRAM       0   0           1       ADD     ADD     ADD     ADD     ADD     ADD     ADD     SETS DDRAM ADDRESS.
ADDRESS                                                                                         DDRAM DATA IS SENT AND RECEIVED AFTER THIS SETTING.


READ BUSY       0   1           BF      AC      AC      AC      AC      AC      AC      AC      READS BUSY FLAG (BF)INDICATING INTERNAL OPERATION IS BEING PERFORMED AND READS ADDRESS COUNTER CONTENTS.
FLAG &
ADDRESS

WRITE DATA      1   0           WRITE DATA                                                      WRITES DATA INTO DDRAM OR CGRAM.
TO CG OR
DDRAM

READ DATA       1   1           READ DATA                                                       READS DATA FROM DDRAM OR CGRAM.
FROM CG OR
DDRAM

I/D = 1: INCREMENT
I/D = 0: DECREMENT

S   = 1: ACCOMPANIES DISPLAY SHIFT

S/C = 1: DISPLAY SHIFT
S/C = 0: CURSOR MOVE

R/L = 1: SHIFT TO THE RIGHT
R/L = 0: SHIFT TO THE LEFT

DL  = 1: 8 BITS
DL  = 0: 4 BITS

N   = 1: 2 LINES
N   = 0: 1 LINE
F   = 1: 5*10 DOTS
F   = 0: 5*8 DOTS

BF  = 1: INTERNALLY OPERATING
BF  = 0: INSTRUCTIONS ACCEPTABLE

DDRAM: DISPLAY DATA RAM
CGRAM: CHARACTER GENERATOR RAM
ACG: CGRAM ADDRESS
ADD: DDRAM ADDRESS (CORRESPONDS TO CURSOR ADDRESS)
AC: ADDRESS COUNTER USED FOR BOTH DD AND CGRAM ADDRESSES

NOTE:
— INDICATES NO EFFECT.

AFTER EXECUTION OF THE CGRAM/DDRAM DATA WRITE OR READ INSTRUCTION, THE RAM ADDRESS COUNTER
IS INCREMENTED OR DECREMENTED BY 1. THE RAM ADDRESS COUNTER IS UPDATED AFTER THE BUSY FLAG
TURNS OFF.

*/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/

#ifndef LCD_H_
#define LCD_H_

/******************************************************************************************************/

#include "cf.h"

/******************************************************************************************************/

//#if !defined(F_CPU)
//#define F_CPU 16000000UL
//#endif

/******************************************************************************************************/
//LCD CONFIGURATIONS
/******************************************************************************************************/

#ifndef LCD_IN_8_BIT_MODE
#define LCD_IN_4_BIT_MODE
#endif

#ifndef LCD_USE_RW
#define LCD_DO_NOT_USE_RW
#endif

#ifndef LCD_CONTROL_LED
#define LCD_DO_NOT_CONTROL_LED
#endif

#ifndef INT_LIMIT   //SET NUMBER OF CHARACTERS TO DISPLAY BEFORE DECIMAL POINT
#define INT_LIMIT 5
#endif

#ifndef FLOAT_LIMIT //SET NUMBER OF CHARACTERS TO DISPLAY AFTER DECIMAL POINT
#define FLOAT_LIMIT 3
#endif

/******************************************************************************************************/
//GPIO PORT NAME
/******************************************************************************************************/

#ifndef LCD_ALL_GPIO_PORT
#define LCD_ALL_GPIO_PORT B
#endif

#ifndef LCD_DATA_ALL_GPIO_PORT
#define LCD_DATA_ALL_GPIO_PORT LCD_ALL_GPIO_PORT
#endif

#ifndef LCD_DATA_ALL_UPPER_NIBBLE_GPIO_PORT
#define LCD_DATA_ALL_UPPER_NIBBLE_GPIO_PORT LCD_DATA_ALL_GPIO_PORT
#endif

#ifndef LCD_DATA_ALL_LOWER_NIBBLE_GPIO_PORT
#define LCD_DATA_ALL_LOWER_NIBBLE_GPIO_PORT LCD_DATA_ALL_GPIO_PORT
#endif

#ifndef LCD_CONTROL_ALL_GPIO_PORT
#ifdef LCD_IN_8_BIT_MODE
#define LCD_CONTROL_ALL_GPIO_PORT C
#else
#define LCD_CONTROL_ALL_GPIO_PORT LCD_ALL_GPIO_PORT
#endif
#endif

#ifndef LCD_DATA_0_GPIO_PORT
#define LCD_DATA_0_GPIO_PORT LCD_DATA_ALL_LOWER_NIBBLE_GPIO_PORT
#endif

#ifndef LCD_DATA_1_GPIO_PORT
#define LCD_DATA_1_GPIO_PORT LCD_DATA_ALL_LOWER_NIBBLE_GPIO_PORT
#endif

#ifndef LCD_DATA_2_GPIO_PORT
#define LCD_DATA_2_GPIO_PORT LCD_DATA_ALL_LOWER_NIBBLE_GPIO_PORT
#endif

#ifndef LCD_DATA_3_GPIO_PORT
#define LCD_DATA_3_GPIO_PORT LCD_DATA_ALL_LOWER_NIBBLE_GPIO_PORT
#endif

#ifndef LCD_DATA_4_GPIO_PORT
#define LCD_DATA_4_GPIO_PORT LCD_DATA_ALL_UPPER_NIBBLE_GPIO_PORT
#endif

#ifndef LCD_DATA_5_GPIO_PORT
#define LCD_DATA_5_GPIO_PORT LCD_DATA_ALL_UPPER_NIBBLE_GPIO_PORT
#endif

#ifndef LCD_DATA_6_GPIO_PORT
#define LCD_DATA_6_GPIO_PORT LCD_DATA_ALL_UPPER_NIBBLE_GPIO_PORT
#endif

#ifndef LCD_DATA_7_GPIO_PORT
#define LCD_DATA_7_GPIO_PORT LCD_DATA_ALL_UPPER_NIBBLE_GPIO_PORT
#endif

#ifndef LCD_CONTROL_RS_GPIO_PORT
#define LCD_CONTROL_RS_GPIO_PORT LCD_CONTROL_ALL_GPIO_PORT
#endif

#ifndef LCD_CONTROL_RW_GPIO_PORT
#define LCD_CONTROL_RW_GPIO_PORT LCD_CONTROL_ALL_GPIO_PORT
#endif

#ifndef LCD_CONTROL_E_GPIO_PORT
#define LCD_CONTROL_E_GPIO_PORT LCD_CONTROL_ALL_GPIO_PORT
#endif

#ifndef LCD_CONTROL_LED_GPIO_PORT
#define LCD_CONTROL_LED_GPIO_PORT LCD_CONTROL_ALL_GPIO_PORT
#endif

/******************************************************************************************************/
//GPIO PIN NUMBERS
/******************************************************************************************************/

#ifndef LCD_DATA_0_GPIO_PIN
#ifdef LCD_IN_8_BIT_MODE
#define LCD_DATA_0_GPIO_PIN 0
#endif
#endif

#ifndef LCD_DATA_1_GPIO_PIN
#ifdef LCD_IN_8_BIT_MODE
#define LCD_DATA_1_GPIO_PIN 1
#endif
#endif

#ifndef LCD_DATA_2_GPIO_PIN
#ifdef LCD_IN_8_BIT_MODE
#define LCD_DATA_2_GPIO_PIN 2
#endif
#endif

#ifndef LCD_DATA_3_GPIO_PIN
#ifdef LCD_IN_8_BIT_MODE
#define LCD_DATA_3_GPIO_PIN 3
#endif
#endif

#ifndef LCD_DATA_4_GPIO_PIN
#ifdef LCD_IN_8_BIT_MODE
#define LCD_DATA_4_GPIO_PIN 4
#else
#define LCD_DATA_4_GPIO_PIN 0
#endif
#endif

#ifndef LCD_DATA_5_GPIO_PIN
#ifdef LCD_IN_8_BIT_MODE
#define LCD_DATA_5_GPIO_PIN 5
#else
#define LCD_DATA_5_GPIO_PIN 1
#endif
#endif

#ifndef LCD_DATA_6_GPIO_PIN
#ifdef LCD_IN_8_BIT_MODE
#define LCD_DATA_6_GPIO_PIN 6
#else
#define LCD_DATA_6_GPIO_PIN 2
#endif
#endif

#ifndef LCD_DATA_7_GPIO_PIN
#ifdef LCD_IN_8_BIT_MODE
#define LCD_DATA_7_GPIO_PIN 7
#else
#define LCD_DATA_7_GPIO_PIN 3
#endif
#endif

#ifndef LCD_CONTROL_RS_GPIO_PIN
#ifdef LCD_IN_8_BIT_MODE
#define LCD_CONTROL_RS_GPIO_PIN 0
#else
#define LCD_CONTROL_RS_GPIO_PIN 4
#endif
#endif

#ifdef LCD_USE_RW
#ifndef LCD_CONTROL_RW_GPIO_PIN
#ifdef LCD_IN_8_BIT_MODE
#define LCD_CONTROL_RW_GPIO_PIN 2
#else
#define LCD_CONTROL_RW_GPIO_PIN 6
#endif
#endif
#endif

#ifndef LCD_CONTROL_E_GPIO_PIN
#ifdef LCD_IN_8_BIT_MODE
#define LCD_CONTROL_E_GPIO_PIN 1
#else
#define LCD_CONTROL_E_GPIO_PIN 5
#endif
#endif

#ifdef LCD_CONTROL_LED
#ifndef LCD_CONTROL_LED_GPIO_PIN
#ifdef LCD_IN_8_BIT_MODE
#define LCD_CONTROL_LED_GPIO_PIN 3
#else
#define LCD_CONTROL_LED_GPIO_PIN 7
#endif
#endif
#endif

/******************************************************************************************************/
//DDR DEFINITIONS
/******************************************************************************************************/

#ifndef LCD_DDR_DATA_0
#define LCD_DDR_DATA_0 DDR(LCD_DATA_0_GPIO_PORT)
#endif

#ifndef LCD_DDR_DATA_1
#define LCD_DDR_DATA_1 DDR(LCD_DATA_1_GPIO_PORT)
#endif

#ifndef LCD_DDR_DATA_2
#define LCD_DDR_DATA_2 DDR(LCD_DATA_2_GPIO_PORT)
#endif

#ifndef LCD_DDR_DATA_3
#define LCD_DDR_DATA_3 DDR(LCD_DATA_3_GPIO_PORT)
#endif

#ifndef LCD_DDR_DATA_4
#define LCD_DDR_DATA_4 DDR(LCD_DATA_4_GPIO_PORT)
#endif

#ifndef LCD_DDR_DATA_5
#define LCD_DDR_DATA_5 DDR(LCD_DATA_5_GPIO_PORT)
#endif

#ifndef LCD_DDR_DATA_6
#define LCD_DDR_DATA_6 DDR(LCD_DATA_6_GPIO_PORT)
#endif

#ifndef LCD_DDR_DATA_7
#define LCD_DDR_DATA_7 DDR(LCD_DATA_7_GPIO_PORT)
#endif

#ifndef LCD_DDR_CONTROL_RS
#define LCD_DDR_CONTROL_RS DDR(LCD_CONTROL_RS_GPIO_PORT)
#endif

#ifndef LCD_DDR_CONTROL_RW
#define LCD_DDR_CONTROL_RW DDR(LCD_CONTROL_RW_GPIO_PORT)
#endif

#ifndef LCD_DDR_CONTROL_E
#define LCD_DDR_CONTROL_E DDR(LCD_CONTROL_E_GPIO_PORT)
#endif

#ifndef LCD_DDR_CONTROL_LED
#define LCD_DDR_CONTROL_LED DDR(LCD_CONTROL_LED_GPIO_PORT)
#endif

/******************************************************************************************************/
//PIN DEFINITIONS
/******************************************************************************************************/

#ifndef LCD_PIN_DATA_0
#define LCD_PIN_DATA_0 PIN(LCD_DATA_0_GPIO_PORT)
#endif

#ifndef LCD_PIN_DATA_1
#define LCD_PIN_DATA_1 PIN(LCD_DATA_1_GPIO_PORT)
#endif

#ifndef LCD_PIN_DATA_2
#define LCD_PIN_DATA_2 PIN(LCD_DATA_2_GPIO_PORT)
#endif

#ifndef LCD_PIN_DATA_3
#define LCD_PIN_DATA_3 PIN(LCD_DATA_3_GPIO_PORT)
#endif

#ifndef LCD_PIN_DATA_4
#define LCD_PIN_DATA_4 PIN(LCD_DATA_4_GPIO_PORT)
#endif

#ifndef LCD_PIN_DATA_5
#define LCD_PIN_DATA_5 PIN(LCD_DATA_5_GPIO_PORT)
#endif

#ifndef LCD_PIN_DATA_6
#define LCD_PIN_DATA_6 PIN(LCD_DATA_6_GPIO_PORT)
#endif

#ifndef LCD_PIN_DATA_7
#define LCD_PIN_DATA_7 PIN(LCD_DATA_7_GPIO_PORT)
#endif

#ifndef LCD_PIN_CONTROL_RS
#define LCD_PIN_CONTROL_RS PIN(LCD_CONTROL_RS_GPIO_PORT)
#endif

#ifndef LCD_PIN_CONTROL_RW
#define LCD_PIN_CONTROL_RW PIN(LCD_CONTROL_RW_GPIO_PORT)
#endif

#ifndef LCD_PIN_CONTROL_E
#define LCD_PIN_CONTROL_E PIN(LCD_CONTROL_E_GPIO_PORT)
#endif

#ifndef LCD_PIN_CONTROL_LED
#define LCD_PIN_CONTROL_LED PIN(LCD_CONTROL_LED_GPIO_PORT)
#endif

/******************************************************************************************************/
//PORT DEFINITAIONS
/******************************************************************************************************/

#ifndef LCD_PORT_DATA_0
#define LCD_PORT_DATA_0 PORT(LCD_DATA_0_GPIO_PORT)
#endif

#ifndef LCD_PORT_DATA_1
#define LCD_PORT_DATA_1 PORT(LCD_DATA_1_GPIO_PORT)
#endif

#ifndef LCD_PORT_DATA_2
#define LCD_PORT_DATA_2 PORT(LCD_DATA_2_GPIO_PORT)
#endif

#ifndef LCD_PORT_DATA_3
#define LCD_PORT_DATA_3 PORT(LCD_DATA_3_GPIO_PORT)
#endif

#ifndef LCD_PORT_DATA_4
#define LCD_PORT_DATA_4 PORT(LCD_DATA_4_GPIO_PORT)
#endif

#ifndef LCD_PORT_DATA_5
#define LCD_PORT_DATA_5 PORT(LCD_DATA_5_GPIO_PORT)
#endif

#ifndef LCD_PORT_DATA_6
#define LCD_PORT_DATA_6 PORT(LCD_DATA_6_GPIO_PORT)
#endif

#ifndef LCD_PORT_DATA_7
#define LCD_PORT_DATA_7 PORT(LCD_DATA_7_GPIO_PORT)
#endif

#ifndef LCD_PORT_CONTROL_RS
#define LCD_PORT_CONTROL_RS PORT(LCD_CONTROL_RS_GPIO_PORT)
#endif

#ifndef LCD_PORT_CONTROL_RW
#define LCD_PORT_CONTROL_RW PORT(LCD_CONTROL_RW_GPIO_PORT)
#endif

#ifndef LCD_PORT_CONTROL_E
#define LCD_PORT_CONTROL_E PORT(LCD_CONTROL_E_GPIO_PORT)
#endif

#ifndef LCD_PORT_CONTROL_LED
#define LCD_PORT_CONTROL_LED PORT(LCD_CONTROL_LED_GPIO_PORT)
#endif

/******************************************************************************************************/
//CUSTOM DELAY ROUTINES
/******************************************************************************************************/

#ifndef _UTIL_DELAY_H_
#define LCD_DELAY_MS(x) lcd_delay_ms_custom(x)
#define LCD_DELAY_US(x) lcd_delay_us_custom(x)
#else
#define LCD_DELAY_MS(x) _delay_ms(x)
#define LCD_DELAY_US(x) _delay_us(x)
#endif

/******************************************************************************************************/
//USE MACROS
/******************************************************************************************************/

#ifndef USE_lcd_init
#define USE_lcd_init YES
#endif

#ifndef USE_lcd_cmd
#define USE_lcd_cmd YES
#endif


#ifndef USE_lcd_clear
#define USE_lcd_clear YES
#endif

#ifndef USE_lcd_home
#define USE_lcd_home YES
#endif

#ifndef USE_lcd_latch
#define USE_lcd_latch YES
#endif

#ifndef USE_lcd_char
#define USE_lcd_char YES
#endif

#ifndef USE_lcd_string
#define USE_lcd_string YES
#endif

#ifndef USE_lcd_string_p
#define USE_lcd_string_p NO
#endif

#ifndef USE_lcd_gotoxy
#define USE_lcd_gotoxy YES
#endif

#ifndef USE_lcd_delay_ms_custom
#define USE_lcd_delay_ms_custom YES
#endif

#ifndef USE_lcd_delay_us_custom
#define USE_lcd_delay_us_custom YES
#endif

#ifndef USE_lcd_custom
#define USE_lcd_custom NO
#endif

#ifndef USE_lcd_showvalue
#define USE_lcd_showvalue YES
#endif

#ifndef USE_lcd_hex
#define USE_lcd_hex NO
#endif

#ifndef USE_lcd_int
#define USE_lcd_int NO
#endif

#ifndef USE_lcd_float
#define USE_lcd_float NO
#endif

#ifndef USE_lcd_led_on
#define USE_lcd_led_on NO
#endif

#ifndef USE_lcd_led_off
#define USE_lcd_led_off NO
#endif

/******************************************************************************************************/
//FUNCTION PROTOTYPES
/******************************************************************************************************/

#if (USE_lcd_init) == YES
void lcd_init(void);
#endif

#if (USE_lcd_cmd) == YES
void lcd_cmd(unsigned char );
#endif

#if (USE_lcd_clear) == YES
void lcd_clear(void);
#endif

#if (USE_lcd_home) == YES
void lcd_home(void);
#endif

#if (USE_lcd_latch) == YES
void lcd_latch(void);
#endif

#if (USE_lcd_char) == YES
void lcd_char(unsigned char );
#endif

#if (USE_lcd_string) == YES
void lcd_string(unsigned char* );
#endif

#if (USE_lcd_string_p) == YES
void lcd_string_p(const unsigned char *);
#endif

#if (USE_lcd_gotoxy) == YES
void lcd_gotoxy(unsigned char ,unsigned char );
#endif

#ifndef _UTIL_DELAY_H_

#if (USE_lcd_delay_ms_custom) == YES
void lcd_delay_ms_custom(unsigned int );
#endif

#if (USE_lcd_delay_us_custom) == YES
void lcd_delay_us_custom(unsigned char);
#endif

#endif

#if (USE_lcd_custom) == YES
void lcd_custom(void);
#endif

#if (USE_lcd_showvalue) == YES
void lcd_showvalue(unsigned char );
#endif

#if (USE_lcd_hex) == YES
void lcd_hex(unsigned char );
#endif

#if (USE_lcd_int) == YES
void lcd_int(int);
#endif

#if (USE_lcd_float) == YES
void lcd_float(float);
#endif

#ifdef LCD_CONTROL_LED

#if (Use_lcd_led_on) == YES
void lcd_led_on(void);
#endif

#if (Use_lcd_led_off) == YES
void lcd_led_off(void);
#endif

#endif

/******************************************************************************************************/

#endif

/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
