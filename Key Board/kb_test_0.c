/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
Author: Charlton Fernandes

kb_test_0.c

DESCRIPTION:kb library testing code.
*/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/

#include <avr/io.h>

/******************************************************************************************************/

//#define KB_DATA_GPIO_PORT A
//#define KB_CLOCK_GPIO_PORT B
//#define KB_DATA_GPIO_PIN 0
//#define KB_CLOCK_GPIO_PIN 3

/******************************************************************************************************/

#define F_CPU 16000000UL

/******************************************************************************************************/

#include "kb.c"
#include "kb.h"

#include "lcd.h"

/******************************************************************************************************/

void main(void)
{
	lcd_init();

    kb_init();

	while(1)
	{
	lcd_char(kb_getdata());
	}

}

/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
