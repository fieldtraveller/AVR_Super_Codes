/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
Author: Charlton Fernandes

kp_test_0.c

DESCRIPTION:kp library test code.
*/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/

#include <avr/io.h>

/******************************************************************************************************/

//#define KP_COLUMN_3_GPIO_PIN 0
//#define KP_COLUMN_3_GPIO_PORT A

/******************************************************************************************************/

#define F_CPU 16000000UL

/******************************************************************************************************/

#include "kp.c"
#include "kp.h"

#include "lcd.h"

/******************************************************************************************************/

void main(void)
{
	unsigned char data,p_data=255;
	lcd_init();
	kp_init();

    while(1)
    {
        data=kp_read();

        if(p_data!=data)
        {
			if(data!=255)
            lcd_showvalue(data);

            p_data=data;
        }

    }

}

/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
