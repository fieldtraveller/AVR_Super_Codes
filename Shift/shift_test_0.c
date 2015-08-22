/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
Author: Charlton Fernandes

shift_test_0.c

DESCRIPTION:shift library testing code.
*/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/

#include <avr/io.h>
#include <util/delay.h>

/******************************************************************************************************/

#define SHIFT_1_USE
#define SHIFT_1_LATCH_ENABLE

//#define SHIFT_LATCH_DELAY 100
//#define SHIFT_CLOCK_DELAY 100

/******************************************************************************************************/

#define F_CPU 16000000UL

/******************************************************************************************************/

#include "shift.c"
#include "shift.h"

/******************************************************************************************************/

void main(void)
{
	unsigned char a=0xFF;
	shift_init();


	while(1)
	{

	shift_data_out_byte(a,SHIFT_1);
	shift_latch_data(SHIFT_1);
	a--;
	_delay_ms(100);
	}

}

/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
