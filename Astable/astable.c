/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
AUTHOR: CHARLTON FERNANDES

astable.c

FOR MORE INFORMATION CHECK astable.h
*/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/

#include <avr/interrupt.h>

/******************************************************************************************************/

#include "astable.h"

/******************************************************************************************************/
//GLOBAL VARIABLES
/******************************************************************************************************/

volatile unsigned char astable_timer_next_edge;

/******************************************************************************************************/
//ISR DEFINITIONS
/******************************************************************************************************/

#if (USE_astable_init == YES)
ISR(ASTABLE_TIMER_INTERRUPT_VECTOR)
{
    if(astable_timer_next_edge==ASTABLE_TIMER_LOW_GOING_EDGE)
    {
        astable_timer_next_edge=ASTABLE_TIMER_HIGH_GOING_EDGE;
        ASTABLE_TIMER_OUTPUT_COMPARE_REGISTER = ASTABLE_TIMER_OUTPUT_COMPARE_VALUE_FOR_NEGATIVE_PERIOD;

        ASTABLE_TIMER_ISR_BODY_ON_HIGH_GOING_EDGE;
    }
    else
    {
        astable_timer_next_edge=ASTABLE_TIMER_LOW_GOING_EDGE;
        ASTABLE_TIMER_OUTPUT_COMPARE_REGISTER = ASTABLE_TIMER_OUTPUT_COMPARE_VALUE_FOR_POSITIVE_PERIOD;

        ASTABLE_TIMER_ISR_BODY_ON_LOW_GOING_EDGE;
    }

    ASTABLE_TIMER_ISR_BODY;
}
#endif

/******************************************************************************************************/
//FUNCTION DEFINITIONS
/******************************************************************************************************/

#if (USE_astable_init == YES)
void astable_init(void)
{
//    ASTABLE_TIMER_CONFIG_REGISTER|=((1<<ASTABLE_TIMER_CONFIG_CTC_BIT)|(ASTABLE_TIMER_CONFIG_PRESCALER_MASK));
//    ASTABLE_TIMER_COUNT_REGISTER=0;
//    ASTABLE_TIMER_ON();
    ASTABLE_TIMER_OUTPUT_COMPARE_REGISTER = ASTABLE_TIMER_OUTPUT_COMPARE_VALUE_FOR_POSITIVE_PERIOD;
    astable_timer_next_edge=ASTABLE_TIMER_LOW_GOING_EDGE;
    cli();
    ASTABLE_TIMER_INTERRUPT_MASK_REGISTER |= ASTABLE_TIMER_INTERRUPT_MASK;
    sei();
}
#endif

/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/

