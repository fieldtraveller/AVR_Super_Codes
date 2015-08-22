/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
AUTHOR:CHARLTON FERNANDES

delays.c

DESCRIPTION:FOR MORE INFO CHECK delays.h

*/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/

#include "delays.h"

/******************************************************************************************************/

void delay_ms(unsigned int time_ms) //PROVIDES DELAY IN APPROXIMATELY SPECIFIED MILLI-SECONDS   ACCURACY ~1-5%
{
	unsigned int x;

	while(time_ms--)
	{
		x=DELAY_FUDGE_FACTOR_MS;

		while(x--)
		{
			asm("NOP");
		}
	}

}

/******************************************************************************************************/

void delay_us(unsigned int time_us) //PROVIDES DELAY IN APPROXIMATELY SPECIFIED MICRO-SECONDS   ACCURACY ~25-50%
{
	unsigned int x;

	while(time_us--)
	{
		x=DELAY_FUDGE_FACTOR_US;

		while(x--)
		{
			asm("NOP");
		}
	}

}

/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
