/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
AUTHOR:CHARLTON FERNANDES

glcd.h

LCD MODULE SUPPORTED:JHD 12864E

LCD CONTROLLER:SAMSUNG KS0107B

*/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/

#ifndef GLCD_H_
#define GLCD_H_

/******************************************************************************************************/

#include "cf.h"

/******************************************************************************************************/
//OPERATION MODE
/******************************************************************************************************/

#ifndef GLCD_LIBRARY_IN_BIT_CONTROL_MODE
#define GLCD_LIBRARY_IN_BYTE_CONTROL_MODE YES   //IF ALL CONTROL SIGNALS ON SINGLE PORT
#endif

/******************************************************************************************************/
//LCD CONFIGURATIONS
/******************************************************************************************************/

#ifndef GLCD_USE_RST
#define GLCD_DO_NOT_USE_RST YES
#endif

#ifndef GLCD_CONTROL_LED
#define GLCD_DO_NOT_CONTROL_LED YES
#endif

/******************************************************************************************************/
//GPIO PORTS
/******************************************************************************************************/

#ifndef GLCD_DATA_ALL_GPIO_PORT
#define GLCD_DATA_ALL_GPIO_PORT A
#endif

#ifndef GLCD_CONTROL_ALL_GPIO_PORT
#define GLCD_CONTROL_ALL_GPIO_PORT B
#endif

#ifndef GLCD_DATA_ALL_LOWER_NIBBLE_GPIO_PORT
#define GLCD_DATA_ALL_LOWER_NIBBLE_GPIO_PORT GLCD_DATA_ALL_GPIO_PORT
#endif

#ifndef GLCD_DATA_ALL_UPPER_NIBBLE_GPIO_PORT
#define GLCD_DATA_ALL_UPPER_NIBBLE_GPIO_PORT GLCD_DATA_ALL_GPIO_PORT
#endif

/******************************************************************************************************/

#ifndef GLCD_DATA_0_GPIO_PORT
#define GLCD_DATA_0_GPIO_PORT GLCD_DATA_ALL_LOWER_NIBBLE_GPIO_PORT
#endif

#ifndef GLCD_DATA_1_GPIO_PORT
#define GLCD_DATA_1_GPIO_PORT GLCD_DATA_ALL_LOWER_NIBBLE_GPIO_PORT
#endif

#ifndef GLCD_DATA_2_GPIO_PORT
#define GLCD_DATA_2_GPIO_PORT GLCD_DATA_ALL_LOWER_NIBBLE_GPIO_PORT
#endif

#ifndef GLCD_DATA_3_GPIO_PORT
#define GLCD_DATA_3_GPIO_PORT GLCD_DATA_ALL_LOWER_NIBBLE_GPIO_PORT
#endif

#ifndef GLCD_DATA_4_GPIO_PORT
#define GLCD_DATA_4_GPIO_PORT GLCD_DATA_ALL_UPPER_NIBBLE_GPIO_PORT
#endif

#ifndef GLCD_DATA_5_GPIO_PORT
#define GLCD_DATA_5_GPIO_PORT GLCD_DATA_ALL_UPPER_NIBBLE_GPIO_PORT
#endif

#ifndef GLCD_DATA_6_GPIO_PORT
#define GLCD_DATA_6_GPIO_PORT GLCD_DATA_ALL_UPPER_NIBBLE_GPIO_PORT
#endif

#ifndef GLCD_DATA_7_GPIO_PORT
#define GLCD_DATA_7_GPIO_PORT GLCD_DATA_ALL_UPPER_NIBBLE_GPIO_PORT
#endif

#ifndef GLCD_CONTROL_RS_GPIO_PORT
#define GLCD_CONTROL_RS_GPIO_PORT GLCD_CONTROL_ALL_GPIO_PORT
#endif

#ifndef GLCD_CONTROL_RW_GPIO_PORT
#define GLCD_CONTROL_RW_GPIO_PORT GLCD_CONTROL_ALL_GPIO_PORT
#endif

#ifndef GLCD_CONTROL_EN_GPIO_PORT
#define GLCD_CONTROL_EN_GPIO_PORT GLCD_CONTROL_ALL_GPIO_PORT
#endif

#ifndef GLCD_CONTROL_CS1_GPIO_PORT
#define GLCD_CONTROL_CS1_GPIO_PORT GLCD_CONTROL_ALL_GPIO_PORT
#endif

#ifndef GLCD_CONTROL_CS2_GPIO_PORT
#define GLCD_CONTROL_CS2_GPIO_PORT GLCD_CONTROL_ALL_GPIO_PORT
#endif

#ifndef GLCD_CONTROL_RST_GPIO_PORT
#define GLCD_CONTROL_RST_GPIO_PORT GLCD_CONTROL_ALL_GPIO_PORT
#endif

#ifndef GLCD_CONTROL_LED_GPIO_PORT
#define GLCD_CONTROL_LED_GPIO_PORT GLCD_CONTROL_ALL_GPIO_PORT
#endif

/******************************************************************************************************/
//GPIO PIN NUMBERS
/******************************************************************************************************/

#ifndef GLCD_DATA_0_GPIO_PIN
#define GLCD_DATA_0_GPIO_PIN 0
#endif

#ifndef GLCD_DATA_1_GPIO_PIN
#define GLCD_DATA_1_GPIO_PIN 1
#endif

#ifndef GLCD_DATA_2_GPIO_PIN
#define GLCD_DATA_2_GPIO_PIN 2
#endif

#ifndef GLCD_DATA_3_GPIO_PIN
#define GLCD_DATA_3_GPIO_PIN 3
#endif

#ifndef GLCD_DATA_4_GPIO_PIN
#define GLCD_DATA_4_GPIO_PIN 4
#endif

#ifndef GLCD_DATA_5_GPIO_PIN
#define GLCD_DATA_5_GPIO_PIN 5
#endif

#ifndef GLCD_DATA_6_6GPIO_PIN
#define GLCD_DATA_6_GPIO_PIN 6
#endif

#ifndef GLCD_DATA_7_GPIO_PIN
#define GLCD_DATA_7_GPIO_PIN 7
#endif

#ifndef GLCD_CONTROL_RS_GPIO_PIN
#define GLCD_CONTROL_RS_GPIO_PIN 0
#endif

#ifndef GLCD_CONTROL_RW_GPIO_PIN
#define GLCD_CONTROL_RW_GPIO_PIN 1
#endif

#ifndef GLCD_CONTROL_EN_GPIO_PIN
#define GLCD_CONTROL_EN_GPIO_PIN 2
#endif

#ifndef GLCD_CONTROL_CS1_GPIO_PIN
#define GLCD_CONTROL_CS1_GPIO_PIN 3
#endif

#ifndef GLCD_CONTROL_CS2_GPIO_PIN
#define GLCD_CONTROL_CS2_GPIO_PIN 4
#endif

#ifndef GLCD_CONTROL_RST_GPIO_PIN
#define GLCD_CONTROL_RST_GPIO_PIN 5
#endif

#ifndef GLCD_CONTROL_LED_GPIO_PIN
#define GLCD_CONTROL_LED_GPIO_PIN 6
#endif

/******************************************************************************************************/
//DDR DEFINITIONS
/******************************************************************************************************/

#ifndef GLCD_DDR_DATA_ALL
#define GLCD_DDR_DATA_ALL DDR(GLCD_DATA_ALL_GPIO_PORT)
#endif

#ifndef GLCD_DDR_CONTROL_ALL
#define GLCD_DDR_CONTROL_ALL DDR(GLCD_CONTROL_ALL_GPIO_PORT)
#endif

/******************************************************************************************************/

#ifndef GLCD_DDR_DATA_0
#define GLCD_DDR_DATA_0 DDR(GLCD_DATA_0_GPIO_PORT)
#endif

#ifndef GLCD_DDR_DATA_1
#define GLCD_DDR_DATA_1 DDR(GLCD_DATA_1_GPIO_PORT)
#endif

#ifndef GLCD_DDR_DATA_2
#define GLCD_DDR_DATA_2 DDR(GLCD_DATA_2_GPIO_PORT)
#endif

#ifndef GLCD_DDR_DATA_3
#define GLCD_DDR_DATA_3 DDR(GLCD_DATA_3_GPIO_PORT)
#endif

#ifndef GLCD_DDR_DATA_4
#define GLCD_DDR_DATA_4 DDR(GLCD_DATA_4_GPIO_PORT)
#endif

#ifndef GLCD_DDR_DATA_5
#define GLCD_DDR_DATA_5 DDR(GLCD_DATA_5_GPIO_PORT)
#endif

#ifndef GLCD_DDR_DATA_6
#define GLCD_DDR_DATA_6 DDR(GLCD_DATA_6_GPIO_PORT)
#endif

#ifndef GLCD_DDR_DATA_7
#define GLCD_DDR_DATA_7 DDR(GLCD_DATA_7_GPIO_PORT)
#endif

#ifndef GLCD_DDR_CONTROL_RS
#define GLCD_DDR_CONTROL_RS DDR(GLCD_CONTROL_RS_GPIO_PORT)
#endif

#ifndef GLCD_DDR_CONTROL_RW
#define GLCD_DDR_CONTROL_RW DDR(GLCD_CONTROL_RW_GPIO_PORT)
#endif

#ifndef GLCD_DDR_CONTROL_EN
#define GLCD_DDR_CONTROL_EN DDR(GLCD_CONTROL_EN_GPIO_PORT)
#endif

#ifndef GLCD_DDR_CONTROL_CS1
#define GLCD_DDR_CONTROL_CS1 DDR(GLCD_CONTROL_CS1_GPIO_PORT)
#endif

#ifndef GLCD_DDR_CONTROL_CS2
#define GLCD_DDR_CONTROL_CS2 DDR(GLCD_CONTROL_CS2_GPIO_PORT)
#endif

#ifndef GLCD_DDR_CONTROL_RST
#define GLCD_DDR_CONTROL_RST DDR(GLCD_CONTROL_RST_GPIO_PORT)
#endif

#ifndef GLCD_DDR_CONTROL_LED
#define GLCD_DDR_CONTROL_LED DDR(GLCD_CONTROL_LED_GPIO_PORT)
#endif

/******************************************************************************************************/
//PIN DEFINITAIONS
/******************************************************************************************************/

#ifndef GLCD_PIN_DATA_ALL
#define GLCD_PIN_DATA_ALL PIN(GLCD_DATA_ALL_GPIO_PORT)
#endif

/*
#ifndef GLCD_PIN_CONTROL_ALL
#define GLCD_PIN_CONTROL_ALL PIN(GLCD_CONTROL_ALL_GPIO_PORT)
#endif
*/

/******************************************************************************************************/

#ifndef GLCD_PIN_DATA_0
#define GLCD_PIN_DATA_0 PIN(GLCD_DATA_0_GPIO_PORT)
#endif

#ifndef GLCD_PIN_DATA_1
#define GLCD_PIN_DATA_1 PIN(GLCD_DATA_1_GPIO_PORT)
#endif

#ifndef GLCD_PIN_DATA_2
#define GLCD_PIN_DATA_2 PIN(GLCD_DATA_2_GPIO_PORT)
#endif

#ifndef GLCD_PIN_DATA_3
#define GLCD_PIN_DATA_3 PIN(GLCD_DATA_3_GPIO_PORT)
#endif

#ifndef GLCD_PIN_DATA_4
#define GLCD_PIN_DATA_4 PIN(GLCD_DATA_4_GPIO_PORT)
#endif

#ifndef GLCD_PIN_DATA_5
#define GLCD_PIN_DATA_5 PIN(GLCD_DATA_5_GPIO_PORT)
#endif

#ifndef GLCD_PIN_DATA_6
#define GLCD_PIN_DATA_6 PIN(GLCD_DATA_6_GPIO_PORT)
#endif

#ifndef GLCD_PIN_DATA_7
#define GLCD_PIN_DATA_7 PIN(GLCD_DATA_7_GPIO_PORT)
#endif

/*
#ifndef GLCD_PIN_CONTROL_RS
#define GLCD_PIN_CONTROL_RS PIN(GLCD_CONTROL_RS_GPIO_PORT)
#endif

#ifndef GLCD_PIN_CONTROL_RW
#define GLCD_PIN_CONTROL_RW PIN(GLCD_CONTROL_RW_GPIO_PORT)
#endif

#ifndef GLCD_PIN_CONTROL_EN
#define GLCD_PIN_CONTROL_EN PIN(GLCD_CONTROL_EN_GPIO_PORT)
#endif

#ifndef GLCD_PIN_CONTROL_CS1
#define GLCD_PIN_CONTROL_CS1 PIN(GLCD_CONTROL_CS1_GPIO_PORT)
#endif

#ifndef GLCD_PIN_CONTROL_CS2
#define GLCD_PIN_CONTROL_CS2 PIN(GLCD_CONTROL_CS2_GPIO_PORT)
#endif

#ifndef GLCD_PIN_CONTROL_RST
#define GLCD_PIN_CONTROL_RST PIN(GLCD_CONTROL_RST_GPIO_PORT)
#endif

#ifndef GLCD_PIN_CONTROL_LED
#define GLCD_PIN_CONTROL_LED PIN(GLCD_CONTROL_LED_GPIO_PORT)
#endif
*/

/******************************************************************************************************/
//PORT DEFINITAIONS
/******************************************************************************************************/

#ifndef GLCD_PORT_DATA_ALL
#define GLCD_PORT_DATA_ALL PORT(GLCD_DATA_ALL_GPIO_PORT)
#endif

#ifndef GLCD_PORT_CONTROL_ALL
#define GLCD_PORT_CONTROL_ALL PORT(GLCD_CONTROL_ALL_GPIO_PORT)
#endif

/******************************************************************************************************/

#ifndef GLCD_PORT_DATA_0
#define GLCD_PORT_DATA_0 PORT(GLCD_DATA_0_GPIO_PORT)
#endif

#ifndef GLCD_PORT_DATA_1
#define GLCD_PORT_DATA_1 PORT(GLCD_DATA_1_GPIO_PORT)
#endif

#ifndef GLCD_PORT_DATA_2
#define GLCD_PORT_DATA_2 PORT(GLCD_DATA_2_GPIO_PORT)
#endif

#ifndef GLCD_PORT_DATA_3
#define GLCD_PORT_DATA_3 PORT(GLCD_DATA_3_GPIO_PORT)
#endif

#ifndef GLCD_PORT_DATA_4
#define GLCD_PORT_DATA_4 PORT(GLCD_DATA_4_GPIO_PORT)
#endif

#ifndef GLCD_PORT_DATA_5
#define GLCD_PORT_DATA_5 PORT(GLCD_DATA_5_GPIO_PORT)
#endif

#ifndef GLCD_PORT_DATA_6
#define GLCD_PORT_DATA_6 PORT(GLCD_DATA_6_GPIO_PORT)
#endif

#ifndef GLCD_PORT_DATA_7
#define GLCD_PORT_DATA_7 PORT(GLCD_DATA_7_GPIO_PORT)
#endif

#ifndef GLCD_PORT_CONTROL_RS
#define GLCD_PORT_CONTROL_RS PORT(GLCD_CONTROL_RS_GPIO_PORT)
#endif

#ifndef GLCD_PORT_CONTROL_RW
#define GLCD_PORT_CONTROL_RW PORT(GLCD_CONTROL_RW_GPIO_PORT)
#endif

#ifndef GLCD_PORT_CONTROL_EN
#define GLCD_PORT_CONTROL_EN PORT(GLCD_CONTROL_EN_GPIO_PORT)
#endif

#ifndef GLCD_PORT_CONTROL_CS1
#define GLCD_PORT_CONTROL_CS1 PORT(GLCD_CONTROL_CS1_GPIO_PORT)
#endif

#ifndef GLCD_PORT_CONTROL_CS2
#define GLCD_PORT_CONTROL_CS2 PORT(GLCD_CONTROL_CS2_GPIO_PORT)
#endif

#ifndef GLCD_PORT_CONTROL_RST
#define GLCD_PORT_CONTROL_RST PORT(GLCD_CONTROL_RST_GPIO_PORT)
#endif

#ifndef GLCD_PORT_CONTROL_LED
#define GLCD_PORT_CONTROL_LED PORT(GLCD_CONTROL_LED_GPIO_PORT)
#endif

/******************************************************************************************************/
//CHIP SELECTS
/******************************************************************************************************/

#define GLCD_CHIP1_SELECT   0x00
#define GLCD_CHIP2_SELECT	0x01

/******************************************************************************************************/
//MISC MACROS
/******************************************************************************************************/

#define GLCD_DATA 1
#define GLCD_INSTRUCTION 0
#define GLCD_INS GLCD_INSTRUCTION

/******************************************************************************************************/
//INSTRUCTION SET
/******************************************************************************************************/

#define GLCD_TURN_ON_DISPLAY	0x3F
#define GLCD_TURN_OFF_DISPLAY	0x3E
#define GLCD_SET_ADDRESS		0x40
#define GLCD_SET_PAGE			0xB8
#define GLCD_DISPLAY_START_LINE	0xC0

#define GLCD_SET_X_ADDRESS_ON_CHIP	GLCD_SET_PAGE
#define GLCD_SET_Y_ADDRESS_ON_CHIP	GLCD_SET_ADDRESS
#define GLCD_SET_Z_ADDRESS_ON_CHIP 	GLCD_DISPLAY_START_LINE

#define GLCD_SET_X_ADDRESS_ON_MODULE    GLCD_SET_ADDRESS
#define GLCD_SET_Y_ADDRESS_ON_MODULE	GLCD_SET_PAGE
#define GLCD_SET_Z_ADDRESS_ON_MODULE 	GLCD_DISPLAY_START_LINE

/******************************************************************************************************/
//CUSTOM DELAY ROUTINES
/******************************************************************************************************/

#ifndef _UTIL_DELAY_H_
#define GLCD_DELAY_MS(x) glcd_delay_ms_custom(x)
#define GLCD_DELAY_US(x) glcd_delay_us_custom(x)
#else
#define GLCD_DELAY_MS(x) _delay_ms(x)
#define GLCD_DELAY_US(x) _delay_us(x)
#endif

#ifndef _UTIL_DELAY_H_

#ifndef glcd_delay_ms_custom(x)
#error glcd_delay_ms_custom(x) not defined
#define glcd_delay_ms_custom(x)
#endif

#ifndef glcd_delay_us_custom(x)
#error glcd_delay_ms_custom(x) not defined
#define glcd_delay_us_custom(x)
#endif

#endif

/******************************************************************************************************/
//USE MACROS
/******************************************************************************************************/

#ifndef USE_glcd_init
#define USE_glcd_init YES
#endif

#ifndef USE_glcd_enable
#define USE_glcd_enable YES
#endif

#ifndef USE_glcd_cmd
#define USE_glcd_cmd YES
#endif

#ifndef USE_glcd_gotoxy
#define USE_glcd_gotoxy YES
#endif

#ifndef USE_glcd_read_byte
#define USE_glcd_read_byte YES
#endif

#ifndef USE_glcd_getc
#define USE_glcd_getc YES
#endif

#ifndef USE_glcd_write_byte
#define USE_glcd_write_byte YES
#endif

#ifndef USE_glcd_write_byte_ms
#define USE_glcd_write_byte_ms NO
#endif

#ifndef USE_glcd_clear
#define USE_glcd_clear YES
#endif

/******************************************************************************************************/
//FUNCTION PROTOTYPES
/******************************************************************************************************/

#if (USE_glcd_init ==YES)
void glcd_init(void);
#endif

#if (USE_glcd_enable==YES)
static inline void glcd_enable(void);
#endif

#if (USE_glcd_cmd==YES)
void glcd_cmd(unsigned char, unsigned char);
#endif

#if (USE_glcd_gotoxy==YES)
void glcd_gotoxy(unsigned char, unsigned char);
#endif

#if (USE_glcd_read_byte==YES)
unsigned char glcd_read_byte(void);
#endif

#if (USE_glcd_getc==YES)
static inline unsigned char glcd_getc(void);
#endif

#if (USE_glcd_write_byte==YES)
void glcd_write_byte(unsigned char);
#endif

#if (USE_glcd_write_byte_ms == YES)
void glcd_write_byte_ms(unsigned char, unsigned char, unsigned char);
#endif

#if (USE_glcd_clear==YES)
void glcd_clear(void);
#endif

/******************************************************************************************************/
//SIMPLIFIED FUNCTION NAMES
/******************************************************************************************************/

#define glcd_putc(x) glcd_write_byte(x)

/******************************************************************************************************/

#endif

/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
