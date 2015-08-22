#include <avr/io.h>

#define F_CPU 16000000UL
#include <util/delay.h>

#define USE_stepper_next_half_step_ccw YES

#include "lcd.c"
#include "stepper.h"
#include "stepper_1.h"
#include "stepper.c"

#define DELAY 1000

int main()
{
	lcd_init();
	stepper_init(STEPPER_1);

	while(1)
    {
		///*
		lcd_home();
		lcd_showvalue(VALUE_OF_STEPPER_NEXT_STEP(STEPPER_1));

        //stepper_next_full_step_low_torque_cw(STEPPER_1);
		stepper_next_half_step_ccw(STEPPER_1);
        _delay_ms(DELAY);
		//*/
    }
}

