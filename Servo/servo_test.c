#include <avr/io.h>

#define F_CPU 16000000UL
#include <util/delay.h>

#define USE_lcd_hex YES

#include "lcd.c"
#include "servo.h"
#include "servo_1.h"
#include "servo_2.h"
#include "servo_3.h"
#include "servo.c"

#define DELAY 500

int main()
{
	lcd_init();

	servo_init(SERVO_1);
	servo_init(SERVO_2);
	servo_init(SERVO_3);
	servo_timer_init();

	while(1)
    {
		///*
		servo_set_angle(SERVO_1,0);
        _delay_ms(DELAY);

		servo_set_angle(SERVO_1,30);
        _delay_ms(DELAY);

		servo_set_angle(SERVO_1,60);
        _delay_ms(DELAY);

		servo_set_angle(SERVO_1,90);
        _delay_ms(DELAY);

		servo_set_angle(SERVO_1,120);
        _delay_ms(DELAY);

		servo_set_angle(SERVO_1,150);
        _delay_ms(DELAY);

		servo_set_angle(SERVO_1,180);
        _delay_ms(DELAY);

		servo_set_angle(SERVO_1,150);
        _delay_ms(DELAY);

		servo_set_angle(SERVO_1,120);
        _delay_ms(DELAY);

		servo_set_angle(SERVO_1,90);
        _delay_ms(DELAY);

		servo_set_angle(SERVO_1,60);
        _delay_ms(DELAY);

		servo_set_angle(SERVO_1,30);
        _delay_ms(DELAY);

		//*/
    }
}

