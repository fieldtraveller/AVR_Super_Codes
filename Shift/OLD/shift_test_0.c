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

/******************************************************************************************************/

#define SHIFT_1_USE
#define SHIFT_1_LATCH_ENABLE

//#define SHIFT_1_LATCH_DELAY 100
//#define SHIFT_1_CLOCK_DELAY 100



/******************************************************************************************************/

#define F_CPU 16000000UL

/******************************************************************************************************/

#include "shift.c"
#include "shift.h"

/******************************************************************************************************/

void main(void)
{
	unsigned char a=255;
	shift_1_init();

	
	while(1)
	{
			shift_1_data_out_byte(a);
			shift_1_latch_data();
			a--;
			_delay_ms(100);
	}
	
}

/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
