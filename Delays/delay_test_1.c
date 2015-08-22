#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define F_CPU 16000000UL

#define USE_lcd_int YES
#define USE_lcd_hex YES

#include "lcd.c"
#include "delays.c"

void main()
{
	unsigned int x=1;

	lcd_init();
	TCNT1=0;

	TCCR1B=0x01;
	delay_ms(x);
	//_delay_ms(1);
	TCCR1B=0x00;

	lcd_int(TCNT1);

	lcd_char(' ');
	lcd_hex(TCNT1H);
	lcd_hex(TCNT1L);

	lcd_char(' ');
	lcd_int(DELAY_FUDGE_FACTOR_MS);

	lcd_gotoxy(1,0);
	lcd_int(x);

	while(1)
	{
	}

}

