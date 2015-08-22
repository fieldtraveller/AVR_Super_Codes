/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
Author: Charlton Fernandes

adc.c

DESCRIPTION:
*/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/

#include <avr/interrupt.h>
#include <avr/io.h>

/******************************************************************************************************/

#if !defined(F_CPU)
#define F_CPU 16000000UL
#endif

/******************************************************************************************************/

#include "adc.h"

/******************************************************************************************************/

//volatile unsigned char channel_count=0;

/******************************************************************************************************/
/*
ISR(ADC_vect)
{
}
*/
void adc_init(void)
{
      ADCSRA=0x87;
      ADMUX|=0x60; //0x60;
}

void adc_interrupt_start(unsigned char channel)
{
    ADMUX=(ADMUX&(~0x1F))|channel;
    ADCSRA|=0x08;
    sei();
    ADCSRA|=0X40;
}

unsigned char adc_read(unsigned char channel)
{
    ADMUX=(ADMUX&(~0x1F))|channel;
    ADCSRA|=0x40;

    while((ADCSRA&0x40)==0x40);

	return ADCH;
}


/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
