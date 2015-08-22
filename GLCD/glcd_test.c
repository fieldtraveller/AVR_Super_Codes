#include <avr/io.h>
#include <util/delay.h>

//#define GLCD_CONTROL_CS2_GPIO_PIN 5
//#define GLCD_LIBRARY_IN_BIT_CONTROL_MODE

#include "glcd.c"

//#define USE_lcd_hex YES
//#include "lcd.c"

int main(void) 
{
	glcd_init();
	
	unsigned char data=0X00;
	
	glcd_gotoxy(127,0);
	
	//glcd_putc(255);
	//glcd_putc(255);
	
	while(data<128)
	{
		glcd_putc(data);
		data = data+1;
		
	}
	
	while(1);
}
