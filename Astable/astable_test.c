#include <avr/io.h>

#define F_CPU 16000000UL
#include <util/delay.h>

#include "cf.h"

#define USE_lcd_hex YES
#include "lcd.h"
#include "lcd.c"

#define ASTABLE_TIMER_ISR_BODY PORTA^=0xFF;
#define ASTABLE_TIMER_SELECT 1
#define ASTABLE_TIMER_POSITIVE_DUTY_CYCLE 50

#include "astable.h"
#include "astable.c"

void main(void)
{
    DDRA=0xFF;
    DDRD=0x00;

	lcd_init();

	lcd_char('A');
	_delay_ms(1000);

	astable_init();
	ASTABLE_TIMER_ON();

	lcd_char('B');
	_delay_ms(1000);

    while(1)
	{
		if((PIND & 0x01) == 0x01)
		{
			lcd_home();
			lcd_char('1');
			//ASTABLE_TIMER_ON();
		}
		else
		{
			lcd_home();
			lcd_char('0');
			//ASTABLE_TIMER_OFF();
		}

        _delay_ms(100);

	}
}

