#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define F_CPU 16000000UL

#define USE_lcd_int YES
#define USE_lcd_hex YES

#include "lcd.c"
#include "delays.c"
#include "uart.c"

void main()
{
	unsigned int x=1;

	lcd_init();
	uart_init(207);	//4800

	while(x!=0)
    {
        lcd_clear();

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

        uart_write_char(TCNT1H);
        uart_write_char(TCNT1L);

        TCNT1=0;
        TCCR1B=0x01;
        _delay_ms(1);
        TCCR1B=0x00;

        lcd_gotoxy(1,0);
        lcd_int(TCNT1);
        lcd_char(' ');
        lcd_hex(TCNT1H);
        lcd_hex(TCNT1L);
        lcd_char(' ');
        lcd_int(x);

        uart_write_char(TCNT1H);
        uart_write_char(TCNT1L);

        x++;
    }

    lcd_clear();
    lcd_string("Done");

	while(1)
	{
	}

}

