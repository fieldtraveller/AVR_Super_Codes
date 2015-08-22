#include <avr/io.h>
#include <avr/interrupt.h>

#define F_CPU 16000000UL
#include <util/delay.h>

#define USE_lcd_hex YES

#include "lcd.h"
#include "lcd.c"

#define DELAY 1000

/*
1 tick = 1/(16000000/256) = 0.000016
*/
volatile unsigned int servo_ticks[8]={155,155,155,155,155,155,155,155},servo_pp_count,servo_count;

ISR (TIMER0_COMP_vect)
{
	if(servo_pp_count==0)
	{
	    if(servo_ticks[servo_count]== 155)
        {
            servo_count++;

            if(servo_count == 8)
            {
                 servo_count=0;
            }

            OCR0=servo_ticks[servo_count];

            if(servo_ticks[servo_count]!= 155)
            {
                switch(servo_count)
                {
                case 0:
                    PORTA ^= ((1<<0));
                    break;

                case 1:
                    PORTA ^= ((1<<1));
                    break;

                case 2:
                    PORTA ^= ((1<<2));
                    break;

                case 3:
                    PORTA ^= ((1<<3));
                    break;

                case 4:
                    PORTA ^= ((1<<4));
                    break;

                case 5:
                    PORTA ^= ((1<<5));
                    break;

                case 6:
                    PORTA ^= ((1<<6));
                    break;

                case 7:
                    PORTA ^= ((1<<7));
                    break;
                }
            }
        }
        else
        {
            OCR0=155-servo_ticks[servo_count];
            servo_pp_count++;

            switch(servo_count)
            {
            case 0:
                PORTA ^= ((1<<0));
                break;

            case 1:
                PORTA ^= ((1<<1));
                break;

            case 2:
                PORTA ^= ((1<<2));
                break;

            case 3:
                PORTA ^= ((1<<3));
                break;

            case 4:
                PORTA ^= ((1<<4));
                break;

            case 5:
                PORTA ^= ((1<<5));
                break;

            case 6:
                PORTA ^= ((1<<6));
                break;

            case 7:
                PORTA ^= ((1<<7));
                break;
            }
        }

	}
	else
    {
        servo_count++;

        if(servo_count == 8)
        {
            servo_count=0;
        }

        OCR0=servo_ticks[servo_count];

        servo_pp_count=0;

        if(servo_ticks[servo_count]!= 155)
        {
            switch(servo_count)
            {
            case 0:
                PORTA ^= ((1<<0));
                break;

            case 1:
                PORTA ^= ((1<<1));
                break;

            case 2:
                PORTA ^= ((1<<2));
                break;

            case 3:
                PORTA ^= ((1<<3));
                break;

            case 4:
                PORTA ^= ((1<<4));
                break;

            case 5:
                PORTA ^= ((1<<5));
                break;

            case 6:
                PORTA ^= ((1<<6));
                break;

            case 7:
                PORTA ^= ((1<<7));
                break;
            }
        }
    }
}

ISR (TIMER0_OVF_vect)
{
    lcd_char('F');
    TIMSK &= ~((1<<1)|(1<<0));
}

int main()
{
	lcd_init();

	DDRA=0xFF;
	DDRD=0xFF;

	PORTA ^= ((1<<0));

	servo_pp_count=0;
	servo_count=0;

    TCCR0|=((1<<3)|(1<<2));
    TCNT0=0x00;

    OCR0=servo_ticks[servo_count];
    TIMSK|=((1<<1)|(1<<0));

	lcd_hex(TCCR0);
	lcd_char(' ');
	lcd_hex(OCR0);
	lcd_char(' ');


	sei();


	while(1)
    {
	
       servo_ticks[0]=30;	//around 0
       servo_ticks[1]=30;
       servo_ticks[2]=30;
       _delay_ms(DELAY);

       servo_ticks[0]=72;	//around 90
       servo_ticks[1]=72;
       servo_ticks[2]=72;
       _delay_ms(DELAY);

       servo_ticks[0]=108;
       servo_ticks[1]=108;
       servo_ticks[2]=108;
       _delay_ms(DELAY);

       servo_ticks[0]=124;	//around 180
       servo_ticks[1]=124;
       servo_ticks[2]=124;
       _delay_ms(DELAY);
	   //*/

	}
}

