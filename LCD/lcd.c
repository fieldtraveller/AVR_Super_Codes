/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
AUTHOR: CHARLTON FERNANDES

lcd.c

FOR MORE INFORMATION CHECK lcd.h
*/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/

#if ((USE_lcd_string_p == YES) || (USE_lcd_custom == YES))
#include <avr/pgmspace.h>
#endif

#include "lcd.h"

/******************************************************************************************************/
//GLOBAL VARIABLES
/******************************************************************************************************/

#if (USE_lcd_custom) == YES
static const PROGMEM unsigned char custom_char[]=  //DEFINE CUSTOM CHARACTERS
{
    0x00, 0x00, 0x0A, 0x00, 0x11, 0x0E, 0x00, 0x00, //CHARACTER 0
    0x0C, 0x12, 0x04, 0x08, 0x1E, 0x00, 0x00, 0x00, //CHARACTER 1
    0x0A, 0x15, 0x11, 0x0A, 0x04, 0x00, 0x00, 0x00, //CHARACTER 2
    0x03, 0x05, 0x09, 0x0B, 0x0B, 0x18, 0x18, 0x00, //CHARACTER 3
    0x1F, 0x0E, 0x0E, 0x04, 0x04, 0x04, 0x04, 0x04, //CHARACTER 4
    0x01, 0x01, 0x05, 0x05, 0x15, 0x15, 0x15, 0x00, //CHARACTER 5
    0x0E, 0x11, 0x11, 0x1F, 0x1F, 0x1F, 0x1F, 0x00, //CHARACTER 6
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  //CHARACTER 7
};
#endif

/******************************************************************************************************/

#if (USE_lcd_init) == YES
void lcd_init(void)	//INITIATE THE LCD
{
    LCD_DELAY_MS(1);//USED WHEN CAPACITOR REQUIRES CHARGING ON STARTUP

	#ifdef LCD_IN_8_BIT_MODE
	LCD_DDR_DATA_0 |= (1<<LCD_DATA_0_GPIO_PIN); //LOWER DATA NIBBLE
	LCD_DDR_DATA_1 |= (1<<LCD_DATA_1_GPIO_PIN);
	LCD_DDR_DATA_2 |= (1<<LCD_DATA_2_GPIO_PIN);
	LCD_DDR_DATA_3 |= (1<<LCD_DATA_3_GPIO_PIN);
    #endif

    LCD_DDR_DATA_4 |= (1<<LCD_DATA_4_GPIO_PIN); //UPPER DATA NIBBLE
	LCD_DDR_DATA_5 |= (1<<LCD_DATA_5_GPIO_PIN);
	LCD_DDR_DATA_6 |= (1<<LCD_DATA_6_GPIO_PIN);
	LCD_DDR_DATA_7 |= (1<<LCD_DATA_7_GPIO_PIN);

    LCD_DDR_CONTROL_RS |= (1<<LCD_CONTROL_RS_GPIO_PIN); //REGISTER SELECT LINE
    LCD_DDR_CONTROL_E |= (1<<LCD_CONTROL_E_GPIO_PIN);   //ENABLE LINE

    #ifdef LCD_USE_RW
    LCD_DDR_CONTROL_RW |= (1<<LCD_CONTROL_RW_GPIO_PIN); //READ/WRITE SELECT
    #endif

    #ifdef LCD_CONTROL_LED
    LCD_DDR_CONTROL_LED |= (1<<LCD_CONTROL_LED_GPIO_PIN);   //BACKLIT LED ON/OFF LINE
    #endif

	LCD_DELAY_MS(5);//INCREASE IF LCD DOES NOT WORK. ALLOWING TIME FOR CODE TO BE LOADED.

	#ifdef LCD_IN_4_BIT_MODE //ENABLE 4 BIT MODE: INITIALLY 8 BIT MODE: FUNCTION SET
	LCD_PORT_DATA_4 &= ~(1<<LCD_DATA_4_GPIO_PIN);   //0
	LCD_PORT_DATA_5 |= (1<<LCD_DATA_5_GPIO_PIN);    //1
	LCD_PORT_DATA_6 &= ~(1<<LCD_DATA_6_GPIO_PIN);   //0
	LCD_PORT_DATA_7 &= ~(1<<LCD_DATA_7_GPIO_PIN);   //0
	#endif

	#ifdef LCD_USE_RW
    LCD_PORT_CONTROL_RW &= ~(1<<LCD_CONTROL_RW_GPIO_PIN); //WRITE SELECT
    #endif

	lcd_latch();

	lcd_cmd(0x28);		//SET INTERFACE 4 BIT 2 LINE:FUNCTION SET

	lcd_cmd(0x08);		//ENABLE DISPLAY/CURSOR:DISPLAY ON/OFF CONTROL

	lcd_clear();        //CLEAR THE DISPLAY

	lcd_cmd(0x06);		//SET CURSOR MOVE, MOVE CURSOR RIGHT:ENTRY MODE SET

	lcd_cmd(0x0C);		//TURN ON DISPLAY:DISPLAY ON/OFF CONTROL

}
#endif

/******************************************************************************************************/

#if (USE_lcd_latch) == YES
void lcd_latch(void)   //DATA LATCHS ON RISING EDGE.
{
    LCD_PORT_CONTROL_E |= (1<<LCD_CONTROL_E_GPIO_PIN);
    LCD_DELAY_US(100);  //increase to 200 if lcd does not work.
    LCD_PORT_CONTROL_E &= ~(1<<LCD_CONTROL_E_GPIO_PIN);
    LCD_DELAY_US(100);
}
#endif

/******************************************************************************************************/

#if (USE_lcd_cmd) == YES
void lcd_cmd(unsigned char cmd)  //LCD COMMAND PROMPT
{
    unsigned char cmd_temp=cmd;
	LCD_PORT_CONTROL_RS &= ~(1<<LCD_CONTROL_RS_GPIO_PIN);   //REGISTER SELECT LINE LOW
	cmd_temp>>=4;

	#ifdef LCD_USE_RW
    LCD_PORT_CONTROL_RW &= ~(1<<LCD_CONTROL_RW_GPIO_PIN); //WRITE SELECT
    #endif

	#ifdef LCD_IN_4_BIT_MODE
	if(cmd_temp&(1<<0))
        LCD_PORT_DATA_4 |= (1<<LCD_DATA_4_GPIO_PIN);
	else
        LCD_PORT_DATA_4 &= ~(1<<LCD_DATA_4_GPIO_PIN);

    if(cmd_temp&(1<<1))
        LCD_PORT_DATA_5 |= (1<<LCD_DATA_5_GPIO_PIN);
	else
        LCD_PORT_DATA_5 &= ~(1<<LCD_DATA_5_GPIO_PIN);

    if(cmd_temp&(1<<2))
        LCD_PORT_DATA_6 |= (1<<LCD_DATA_6_GPIO_PIN);
	else
        LCD_PORT_DATA_6 &= ~(1<<LCD_DATA_6_GPIO_PIN);

    if(cmd_temp&(1<<3))
        LCD_PORT_DATA_7 |= (1<<LCD_DATA_7_GPIO_PIN);
	else
        LCD_PORT_DATA_7 &= ~(1<<LCD_DATA_7_GPIO_PIN);

    lcd_latch();

    if(cmd&(1<<0))
        LCD_PORT_DATA_4 |= (1<<LCD_DATA_4_GPIO_PIN);
	else
        LCD_PORT_DATA_4 &= ~(1<<LCD_DATA_4_GPIO_PIN);

    if(cmd&(1<<1))
        LCD_PORT_DATA_5 |= (1<<LCD_DATA_5_GPIO_PIN);
	else
        LCD_PORT_DATA_5 &= ~(1<<LCD_DATA_5_GPIO_PIN);

    if(cmd&(1<<2))
        LCD_PORT_DATA_6 |= (1<<LCD_DATA_6_GPIO_PIN);
	else
        LCD_PORT_DATA_6 &= ~(1<<LCD_DATA_6_GPIO_PIN);

    if(cmd&(1<<3))
        LCD_PORT_DATA_7 |= (1<<LCD_DATA_7_GPIO_PIN);
	else
        LCD_PORT_DATA_7 &= ~(1<<LCD_DATA_7_GPIO_PIN);

	#else

	if(cmd&(1<<0))
        LCD_PORT_DATA_0 |= (1<<LCD_DATA_0_GPIO_PIN);
	else
        LCD_PORT_DATA_0 &= ~(1<<LCD_DATA_0_GPIO_PIN);

    if(cmd&(1<<1))
        LCD_PORT_DATA_1 |= (1<<LCD_DATA_1_GPIO_PIN);
	else
        LCD_PORT_DATA_1 &= ~(1<<LCD_DATA_1_GPIO_PIN);

    if(cmd&(1<<2))
        LCD_PORT_DATA_2 |= (1<<LCD_DATA_2_GPIO_PIN);
	else
        LCD_PORT_DATA_2 &= ~(1<<LCD_DATA_2_GPIO_PIN);

    if(cmd&(1<<3))
        LCD_PORT_DATA_3 |= (1<<LCD_DATA_3_GPIO_PIN);
	else
        LCD_PORT_DATA_3 &= ~(1<<LCD_DATA_3_GPIO_PIN);

    if(cmd&(1<<4))
        LCD_PORT_DATA_4 |= (1<<LCD_DATA_4_GPIO_PIN);
	else
        LCD_PORT_DATA_4 &= ~(1<<LCD_DATA_4_GPIO_PIN);

    if(cmd&(1<<5))
        LCD_PORT_DATA_5 |= (1<<LCD_DATA_5_GPIO_PIN);
	else
        LCD_PORT_DATA_5 &= ~(1<<LCD_DATA_5_GPIO_PIN);

    if(cmd&(1<<6))
        LCD_PORT_DATA_6 |= (1<<LCD_DATA_6_GPIO_PIN);
	else
        LCD_PORT_DATA_6 &= ~(1<<LCD_DATA_6_GPIO_PIN);

    if(cmd&(1<<7))
        LCD_PORT_DATA_7 |= (1<<LCD_DATA_7_GPIO_PIN);
	else
        LCD_PORT_DATA_7 &= ~(1<<LCD_DATA_7_GPIO_PIN);

	#endif

	lcd_latch();
}
#endif

/******************************************************************************************************/

#if (USE_lcd_clear) == YES
void lcd_clear() //CLEARS TEXT ON LCD DISPLAY
{
     lcd_cmd(0x01);
     LCD_DELAY_MS(2);   //IF NOT USED LEADS TO CORRUPTION OF LCD MODULE RAM.
}
#endif

/******************************************************************************************************/

#if (USE_lcd_home) == YES
void lcd_home() //GOES TO (0,0) CURSOR POSITION
{
    lcd_cmd(0x02);
    LCD_DELAY_MS(2);    //IF NOT USED LEADS TO CORRUPTION OF LCD MODULE RAM.
}
#endif

/******************************************************************************************************/

#if (USE_lcd_char) == YES
void lcd_char(unsigned char single_char) // DISPLAY SINGLE CHARACTER
{
    unsigned char temp_single_char=single_char;
	temp_single_char>>=4;
	LCD_PORT_CONTROL_RS |= (1<<LCD_CONTROL_RS_GPIO_PIN);    //REGISTER SELECT LINE HIGH

	#ifdef LCD_USE_RW
    LCD_PORT_CONTROL_RW &= ~(1<<LCD_CONTROL_RW_GPIO_PIN); //WRITE SELECT
    #endif

	#ifdef LCD_IN_4_BIT_MODE
	if(temp_single_char&(1<<0))
        LCD_PORT_DATA_4 |= (1<<LCD_DATA_4_GPIO_PIN);
	else
        LCD_PORT_DATA_4 &= ~(1<<LCD_DATA_4_GPIO_PIN);

    if(temp_single_char&(1<<1))
        LCD_PORT_DATA_5 |= (1<<LCD_DATA_5_GPIO_PIN);
	else
        LCD_PORT_DATA_5 &= ~(1<<LCD_DATA_5_GPIO_PIN);

    if(temp_single_char&(1<<2))
        LCD_PORT_DATA_6 |= (1<<LCD_DATA_6_GPIO_PIN);
	else
        LCD_PORT_DATA_6 &= ~(1<<LCD_DATA_6_GPIO_PIN);

    if(temp_single_char&(1<<3))
        LCD_PORT_DATA_7 |= (1<<LCD_DATA_7_GPIO_PIN);
	else
        LCD_PORT_DATA_7 &= ~(1<<LCD_DATA_7_GPIO_PIN);

    lcd_latch();

    if(single_char&(1<<0))
        LCD_PORT_DATA_4 |= (1<<LCD_DATA_4_GPIO_PIN);
	else
        LCD_PORT_DATA_4 &= ~(1<<LCD_DATA_4_GPIO_PIN);

    if(single_char&(1<<1))
        LCD_PORT_DATA_5 |= (1<<LCD_DATA_5_GPIO_PIN);
	else
        LCD_PORT_DATA_5 &= ~(1<<LCD_DATA_5_GPIO_PIN);

    if(single_char&(1<<2))
        LCD_PORT_DATA_6 |= (1<<LCD_DATA_6_GPIO_PIN);
	else
        LCD_PORT_DATA_6 &= ~(1<<LCD_DATA_6_GPIO_PIN);

    if(single_char&(1<<3))
        LCD_PORT_DATA_7 |= (1<<LCD_DATA_7_GPIO_PIN);
	else
        LCD_PORT_DATA_7 &= ~(1<<LCD_DATA_7_GPIO_PIN);

	#else

	if(single_char&(1<<0))
        LCD_PORT_DATA_0 |= (1<<LCD_DATA_0_GPIO_PIN);
	else
        LCD_PORT_DATA_0 &= ~(1<<LCD_DATA_0_GPIO_PIN);

    if(single_char&(1<<1))
        LCD_PORT_DATA_1 |= (1<<LCD_DATA_1_GPIO_PIN);
	else
        LCD_PORT_DATA_1 &= ~(1<<LCD_DATA_1_GPIO_PIN);

    if(single_char&(1<<2))
        LCD_PORT_DATA_2 |= (1<<LCD_DATA_2_GPIO_PIN);
	else
        LCD_PORT_DATA_2 &= ~(1<<LCD_DATA_2_GPIO_PIN);

    if(single_char&(1<<3))
        LCD_PORT_DATA_3 |= (1<<LCD_DATA_3_GPIO_PIN);
	else
        LCD_PORT_DATA_3 &= ~(1<<LCD_DATA_3_GPIO_PIN);

    if(single_char&(1<<4))
        LCD_PORT_DATA_4 |= (1<<LCD_DATA_4_GPIO_PIN);
	else
        LCD_PORT_DATA_4 &= ~(1<<LCD_DATA_4_GPIO_PIN);

    if(single_char&(1<<5))
        LCD_PORT_DATA_5 |= (1<<LCD_DATA_5_GPIO_PIN);
	else
        LCD_PORT_DATA_5 &= ~(1<<LCD_DATA_5_GPIO_PIN);

    if(single_char&(1<<6))
        LCD_PORT_DATA_6 |= (1<<LCD_DATA_6_GPIO_PIN);
	else
        LCD_PORT_DATA_6 &= ~(1<<LCD_DATA_6_GPIO_PIN);

    if(single_char&(1<<7))
        LCD_PORT_DATA_7 |= (1<<LCD_DATA_7_GPIO_PIN);
	else
        LCD_PORT_DATA_7 &= ~(1<<LCD_DATA_7_GPIO_PIN);

	#endif

	lcd_latch();
}
#endif

/******************************************************************************************************/

#if (USE_lcd_string) == YES
void lcd_string(unsigned char *str) //DISPLAY STRINGS
{
    unsigned char temp;

		while(*str!='\0')	//TILL NULL CHARACTER IS ENCOUNTERED
		{
		    if(*str=='%')
		    {
		        str++;
		        temp=*str-'0';

		        if(temp>=0 && temp<=7)
		        {
		            lcd_char(temp);
		        }
		        else
		        {
                    lcd_char('%');
                    lcd_char(*str);
		        }
		    }
		    else
			{
			    lcd_char(*str);
			}
			str++;
		}
}
#endif

/******************************************************************************************************/

#if (USE_lcd_string_p) == YES
void lcd_string_p(const unsigned char *str) //DISPLAY STRINGS DIRECTLY FROM FLASH MEMORY
{
		while(pgm_read_byte(str)!='\0') //TILL NULL CHARACTER IS ENCOUNTERED
		{
            lcd_char(pgm_read_byte(str));
			str++;
		}
}
#endif

/******************************************************************************************************/

#if (USE_lcd_showvalue) == YES
void lcd_showvalue(unsigned char num)	//PRINTS THE DECIMAL 3 DIGIT VALUE OF NUM
{
	unsigned char H=0,T=0,O=0;
	H=num/100;
	/*
	T=(num - (H*100))/10;
    O=(num - (H*100) - (T*10));
    */

    O=num - (H*100);
    T=(O)/10;
    O=(O - (T*10));

	lcd_char(H+48);
	lcd_char(T+48);
	lcd_char(O+48);
}
#endif

/******************************************************************************************************/

#if (USE_lcd_hex) == YES
void lcd_hex(unsigned char num) //DISPLAY 8 BIT NUMBERS IN HEX
{
    unsigned char a;
    a=num & 0xF0;
    a=a>>4;

    if(a>=0x0A)
        lcd_char(a+55);
    else
        lcd_char(a+48);

    a=num & 0x0F;

    if(a>=0x0A)
        lcd_char(a+55);
    else
        lcd_char(a+48);
}
#endif

/******************************************************************************************************/

#if (USE_lcd_gotoxy) == YES
void lcd_gotoxy(unsigned char row,unsigned char column) //MOVE CURSOR TO THE SPECIFIED POSITION
{
   if(row==0)
    {
	 lcd_cmd(0x80+column);
	}
   else if(row==1)
	{
	 lcd_cmd(0xC0+column);
	}
}
#endif

/******************************************************************************************************/

#ifndef _UTIL_DELAY_H_

#if (USE_lcd_delay_ms_custom) == YES
void lcd_delay_ms_custom(unsigned int time_ms) //MILLI-SECOND DELAY
{
    int i;
    while (time_ms-- > 0)
	{
		for (i= 0; i < 3276; ++i)
			asm("nop");
	}
}
#endif

/******************************************************************************************************/
unsigned char j,k;

#if (USE_lcd_delay_us_custom) == YES
void lcd_delay_us_custom(unsigned char time) //MICRO-SECOND DELAY
{
    for(j=0;j<time;j++)
	{
	    k=11;
	    while(k--);
		//for(k=0;k<11;k++)
		//{};
	}
}
#endif

#endif

/******************************************************************************************************/

#if (USE_lcd_custom) == YES
void lcd_custom() //CREATE CUSTOM CHARACTERS
{
    unsigned char a;

    lcd_cmd(0x40);
	for(a=0;a<64;a++)
	{
	    lcd_char(pgm_read_byte(&custom_char[a]));
	}
    lcd_clear();
}
#endif

/******************************************************************************************************/

#if (USE_lcd_int) == YES
void lcd_int(int temp_int) //DISPLAY INTEGER NUMBERS
 {
     unsigned char s[INT_LIMIT],i;
     unsigned char sign=0;

     for(i=0;i<INT_LIMIT;i++)
     s[i]=32; //ASCII value of space

     i=INT_LIMIT;

     if (temp_int < 0)
       {
          temp_int = -temp_int;
          sign='-';
       }

     do
     {
         s[--i] = temp_int % 10 + '0';
     } while ((temp_int /= 10) > 0);

     if (sign=='-')
         s[--i] = '-';

    for(i=0;i<INT_LIMIT;i++)
    {
        if(s[i]!=32)
        lcd_char(s[i]);
    }
 }
#endif

/******************************************************************************************************/

#if (USE_lcd_float) == YES
void lcd_float(float temp_float) //DISPLAY FLOATING POINT NUMBERS
 {
     int temp_int;
     unsigned char temp;

     temp_int=(int) temp_float;
     lcd_int(temp_int);

     lcd_char('.');

      for(temp=FLOAT_LIMIT;temp!=0;temp--)
      {
          temp_float=temp_float*10;
          temp_int=temp_int*10;
      }

     temp_int=(int)temp_float-temp_int;

      if(temp_int <0)
     {
         temp_int = -temp_int;
     }

     lcd_int(temp_int);
 }
#endif

/******************************************************************************************************/

#ifdef LCD_CONTROL_LED

#if (USE_lcd_led_on) == YES
void lcd_led_on(void)//BACKLIT LED ON
{
    LCD_PORT_CONTROL_LED |= (1<<LCD_CONTROL_LED_GPIO_PIN);
}
#endif

/******************************************************************************************************/

#if (USE_lcd_led_off) == YES
void lcd_led_off(void)//BACKLIT LED OFF
{
    LCD_PORT_CONTROL_LED &= ~(1<<LCD_CONTROL_LED_GPIO_PIN);
}
#endif

#endif

/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
