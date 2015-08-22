/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
AUTHOR: CHARLTON FERNANDES

astable.h

DEFAULT SETTINGS:
ASTABLE_TIMER_OUTPUT_FREQUENCY=38
ASTABLE_TIMER_POSITIVE_DUTY_CYCLE=50
ASTABLE_TIMER_NEGATIVE_DUTY_CYCLE=50
ASTABLE_TIMER_SELECT=0
ASTABLE_TIMER_CONFIG_PRESCALER=8

DESCRIPTION:
THIS HEADER FILE HAVE IMPLEMENTATION OF ASTABLE MULTIVIBRATOR USING TIMERS IN CTC MODE.

astable_init():INITIALIZE THE TIMER TO OPERATE AS ASTABLE MULTIVIBRATOR.

*/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/

#include "cf.h"

/******************************************************************************************************/

#ifndef ASTABLE_H_
#define ASTABLE_H_ 1

/******************************************************************************************************/

#if !defined(ASTABLE_TIMER_OUTPUT_FREQUENCY)
#define ASTABLE_TIMER_OUTPUT_FREQUENCY 38 //in KHz
#endif

/******************************************************************************************************/

#if !defined(ASTABLE_TIMER_POSITIVE_DUTY_CYCLE)
#define ASTABLE_TIMER_POSITIVE_DUTY_CYCLE 50
#endif

/******************************************************************************************************/

#if !defined(ASTABLE_TIMER_NEGATIVE_DUTY_CYCLE)
#define ASTABLE_TIMER_NEGATIVE_DUTY_CYCLE (100-ASTABLE_TIMER_POSITIVE_DUTY_CYCLE)
#endif

/******************************************************************************************************/

#if ((ASTABLE_TIMER_POSITIVE_DUTY_CYCLE + ASTABLE_TIMER_NEGATIVE_DUTY_CYCLE)!=100)
#error "Sum of Positive and Negative Duty cycles should be 100"
#endif

/******************************************************************************************************/

#if !defined(ASTABLE_TIMER_CONFIG_PRESCALER)
#define ASTABLE_TIMER_CONFIG_PRESCALER 8    //(F_CPU/8)
#endif

/******************************************************************************************************/

#if !defined(ASTABLE_TIMER_SELECT)
#define ASTABLE_TIMER_SELECT TIMER_0
#endif

/******************************************************************************************************/

#if !defined(ASTABLE_TIMER_OUTPUT_COMPARE_VALUE_FOR_POSITIVE_PERIOD)
#define ASTABLE_TIMER_OUTPUT_COMPARE_VALUE_FOR_POSITIVE_PERIOD (unsigned char)(((F_CPU/(1000*ASTABLE_TIMER_CONFIG_PRESCALER))*(((float)ASTABLE_TIMER_POSITIVE_DUTY_CYCLE/(float)100)/(float)(ASTABLE_TIMER_OUTPUT_FREQUENCY)))-0.5)
#endif

/******************************************************************************************************/

#if !defined(ASTABLE_TIMER_OUTPUT_COMPARE_VALUE_FOR_NEGATIVE_PERIOD)
#define ASTABLE_TIMER_OUTPUT_COMPARE_VALUE_FOR_NEGATIVE_PERIOD (unsigned char)(((F_CPU/(1000*ASTABLE_TIMER_CONFIG_PRESCALER))*(((float)ASTABLE_TIMER_NEGATIVE_DUTY_CYCLE/(float)100)/(float)(ASTABLE_TIMER_OUTPUT_FREQUENCY)))-0.5)
#endif

/******************************************************************************************************/
/******************************************************************************************************/

#if (ASTABLE_TIMER_SELECT == TIMER_0)

#if !defined(ASTABLE_TIMER_CONFIG_REGISTER)
#define ASTABLE_TIMER_CONFIG_REGISTER TCCR0
#endif

/******************************************************************************************************/

#if !defined(ASTABLE_TIMER_CONFIG_CTC_BIT)
#define ASTABLE_TIMER_CONFIG_CTC_BIT WGM01
#endif

/******************************************************************************************************/

#if (ASTABLE_TIMER_CONFIG_PRESCALER == 1)

#if !defined(ASTABLE_TIMER_CONFIG_PRESCALER_MASK)
#define ASTABLE_TIMER_CONFIG_PRESCALER_MASK (1<<CS00)
#endif

#elif (ASTABLE_TIMER_CONFIG_PRESCALER == 8)

#if !defined(ASTABLE_TIMER_CONFIG_PRESCALER_MASK)
#define ASTABLE_TIMER_CONFIG_PRESCALER_MASK (1<<CS01)
#endif

#elif (ASTABLE_TIMER_CONFIG_PRESCALER == 32)

#error "Not Compatible with the selected timer"

#elif (ASTABLE_TIMER_CONFIG_PRESCALER == 64)

#if !defined(ASTABLE_TIMER_CONFIG_PRESCALER_MASK)
#define ASTABLE_TIMER_CONFIG_PRESCALER_MASK ((1<<CS00)|(1<<CS01))
#endif

#elif (ASTABLE_TIMER_CONFIG_PRESCALER == 128)

#error "Not Compatible with the selected timer"

#elif (ASTABLE_TIMER_CONFIG_PRESCALER == 256)

#if !defined(ASTABLE_TIMER_CONFIG_PRESCALER_MASK)
#define ASTABLE_TIMER_CONFIG_PRESCALER_MASK (1<<CS02)
#endif

#elif (ASTABLE_TIMER_CONFIG_PRESCALER == 1024)

#if !defined(ASTABLE_TIMER_CONFIG_PRESCALER_MASK)
#define ASTABLE_TIMER_CONFIG_PRESCALER_MASK ((1<<CS00)|(1<<CS02))
#endif

#else

#error "Invalid Prescaler."

#endif

/******************************************************************************************************/

#if !defined(ASTABLE_TIMER_INTERRUPT_MASK_REGISTER)
#define ASTABLE_TIMER_INTERRUPT_MASK_REGISTER TIMSK
#endif

/******************************************************************************************************/

#if !defined(ASTABLE_TIMER_INTERRUPT_MASK)
#define ASTABLE_TIMER_INTERRUPT_MASK (1<<OCIE0)
#endif

/******************************************************************************************************/

#if !defined(ASTABLE_TIMER_INTERRUPT_VECTOR)
#define ASTABLE_TIMER_INTERRUPT_VECTOR TIMER0_COMP_vect
#endif

/******************************************************************************************************/

#if !defined(ASTABLE_TIMER_OUTPUT_COMPARE_REGISTER)
#define ASTABLE_TIMER_OUTPUT_COMPARE_REGISTER OCR0
#endif

/******************************************************************************************************/

#if !defined(ASTABLE_TIMER_COUNT_REGISTER)
#define ASTABLE_TIMER_COUNT_REGISTER TCNT0
#endif

/******************************************************************************************************/
/******************************************************************************************************/

#elif (ASTABLE_TIMER_SELECT==TIMER_1)

#if !defined(ASTABLE_TIMER_CONFIG_REGISTER)
#define ASTABLE_TIMER_CONFIG_REGISTER TCCR1B
#endif

/******************************************************************************************************/

#if !defined(ASTABLE_TIMER_CONFIG_CTC_BIT)
#define ASTABLE_TIMER_CONFIG_CTC_BIT WGM12
#endif

/******************************************************************************************************/

#if (ASTABLE_TIMER_CONFIG_PRESCALER == 1)

#if !defined(ASTABLE_TIMER_CONFIG_PRESCALER_MASK)
#define ASTABLE_TIMER_CONFIG_PRESCALER_MASK (1<<CS10)
#endif

#elif (ASTABLE_TIMER_CONFIG_PRESCALER == 8)

#if !defined(ASTABLE_TIMER_CONFIG_PRESCALER_MASK)
#define ASTABLE_TIMER_CONFIG_PRESCALER_MASK (1<<CS11)
#endif

#elif (ASTABLE_TIMER_CONFIG_PRESCALER == 32)

#error "Not Compatible with the selected timer"

#elif (ASTABLE_TIMER_CONFIG_PRESCALER == 64)

#if !defined(ASTABLE_TIMER_CONFIG_PRESCALER_MASK)
#define ASTABLE_TIMER_CONFIG_PRESCALER_MASK ((1<<CS10)|(1<<CS11))
#endif

#elif (ASTABLE_TIMER_CONFIG_PRESCALER == 128)

#error "Not Compatible with the selected timer"

#elif (ASTABLE_TIMER_CONFIG_PRESCALER == 256)

#if !defined(ASTABLE_TIMER_CONFIG_PRESCALER_MASK)
#define ASTABLE_TIMER_CONFIG_PRESCALER_MASK (1<<CS12)
#endif

#elif (ASTABLE_TIMER_CONFIG_PRESCALER == 1024)

#if !defined(ASTABLE_TIMER_CONFIG_PRESCALER_MASK)
#define ASTABLE_TIMER_CONFIG_PRESCALER_MASK ((1<<CS10)|(1<<CS12))
#endif

#else

#error "Invalid Prescaler."

#endif

/******************************************************************************************************/

#if !defined(ASTABLE_TIMER_CHANNEL)
#define ASTABLE_TIMER_CHANNEL TIMER_1A
#endif

/******************************************************************************************************/

#if !defined(ASTABLE_TIMER_INTERRUPT_MASK_REGISTER)
#define ASTABLE_TIMER_INTERRUPT_MASK_REGISTER TIMSK
#endif

/******************************************************************************************************/

#if (ASTABLE_TIMER_CHANNEL==TIMER_1A)

#if !defined(ASTABLE_TIMER_INTERRUPT_MASK)
#define ASTABLE_TIMER_INTERRUPT_MASK (1<<OCIE1A)
#endif

#if !defined(ASTABLE_TIMER_INTERRUPT_VECTOR)
#define ASTABLE_TIMER_INTERRUPT_VECTOR TIMER1_COMPA_vect
#endif

#if !defined(ASTABLE_TIMER_OUTPUT_COMPARE_REGISTER)
#define ASTABLE_TIMER_OUTPUT_COMPARE_REGISTER OCR1A
#endif

#elif (ASTABLE_TIMER_CHANNEL==TIMER_1B)

#if !defined(ASTABLE_TIMER_INTERRUPT_MASK)
#define ASTABLE_TIMER_INTERRUPT_MASK (1<<OCIE1B)
#endif

#if !defined(ASTABLE_TIMER_INTERRUPT_VECTOR)
#define ASTABLE_TIMER_INTERRUPT_VECTOR TIMER1_COMPB_vect
#endif

#if !defined(ASTABLE_TIMER_OUTPUT_COMPARE_REGISTER)
#define ASTABLE_TIMER_OUTPUT_COMPARE_REGISTER OCR1B
#endif

#endif

/******************************************************************************************************/

#if !defined(ASTABLE_TIMER_COUNT_REGISTER)
#define ASTABLE_TIMER_COUNT_REGISTER TCNT1
#endif

/******************************************************************************************************/
/******************************************************************************************************/

#elif (ASTABLE_TIMER_SELECT==TIMER_2)

#if !defined(ASTABLE_TIMER_CONFIG_REGISTER)
#define ASTABLE_TIMER_CONFIG_REGISTER TCCR2
#endif

/******************************************************************************************************/

#if !defined(ASTABLE_TIMER_CONFIG_CTC_BIT)
#define ASTABLE_TIMER_CONFIG_CTC_BIT WGM21
#endif

/******************************************************************************************************/

#if (ASTABLE_TIMER_CONFIG_PRESCALER == 1)

#if !defined(ASTABLE_TIMER_CONFIG_PRESCALER_MASK)
#define ASTABLE_TIMER_CONFIG_PRESCALER_MASK (1<<CS20)
#endif

#elif (ASTABLE_TIMER_CONFIG_PRESCALER == 8)

#if !defined(ASTABLE_TIMER_CONFIG_PRESCALER_MASK)
#define ASTABLE_TIMER_CONFIG_PRESCALER_MASK (1<<CS21)
#endif

#elif (ASTABLE_TIMER_CONFIG_PRESCALER == 32)

#if !defined(ASTABLE_TIMER_CONFIG_PRESCALER_MASK)
#define ASTABLE_TIMER_CONFIG_PRESCALER_MASK ((1<<CS20)|(1<<CS21))
#endif

#elif (ASTABLE_TIMER_CONFIG_PRESCALER == 64)

#if !defined(ASTABLE_TIMER_CONFIG_PRESCALER_MASK)
#define ASTABLE_TIMER_CONFIG_PRESCALER_MASK (1<<CS22)
#endif

#elif (ASTABLE_TIMER_CONFIG_PRESCALER == 128)

#if !defined(ASTABLE_TIMER_CONFIG_PRESCALER_MASK)
#define ASTABLE_TIMER_CONFIG_PRESCALER_MASK ((1<<CS20)|(1<<CS22))
#endif

#elif (ASTABLE_TIMER_CONFIG_PRESCALER == 256)

#if !defined(ASTABLE_TIMER_CONFIG_PRESCALER_MASK)
#define ASTABLE_TIMER_CONFIG_PRESCALER_MASK ((1<<CS21)|(1<<CS22))
#endif

#elif (ASTABLE_TIMER_CONFIG_PRESCALER == 1024)

#if !defined(ASTABLE_TIMER_CONFIG_PRESCALER_MASK)
#define ASTABLE_TIMER_CONFIG_PRESCALER_MASK ((1<<CS20)|(1<<CS21)|(1<<CS22))
#endif

#else

#error "Invalid Prescaler."

#endif

/******************************************************************************************************/

#if !defined(ASTABLE_TIMER_INTERRUPT_MASK_REGISTER)
#define ASTABLE_TIMER_INTERRUPT_MASK_REGISTER TIMSK
#endif

/******************************************************************************************************/

#if !defined(ASTABLE_TIMER_INTERRUPT_MASK)
#define ASTABLE_TIMER_INTERRUPT_MASK (1<<OCIE2)
#endif

/******************************************************************************************************/

#if !defined(ASTABLE_TIMER_INTERRUPT_VECTOR)
#define ASTABLE_TIMER_INTERRUPT_VECTOR TIMER2_COMP_vect
#endif

/******************************************************************************************************/

#if !defined(ASTABLE_TIMER_OUTPUT_COMPARE_REGISTER)
#define ASTABLE_TIMER_OUTPUT_COMPARE_REGISTER OCR2
#endif

/******************************************************************************************************/

#if !defined(ASTABLE_TIMER_COUNT_REGISTER)
#define ASTABLE_TIMER_COUNT_REGISTER TCNT2
#endif

#endif

/******************************************************************************************************/
/******************************************************************************************************/
//MISC MACROS
/******************************************************************************************************/

#if !defined(ASTABLE_TIMER_LOW_GOING_EDGE)
#define ASTABLE_TIMER_LOW_GOING_EDGE 0
#endif

/******************************************************************************************************/

#if !defined(ASTABLE_TIMER_HIGH_GOING_EDGE)
#define ASTABLE_TIMER_HIGH_GOING_EDGE 1
#endif

/******************************************************************************************************/

#define ASTABLE_TIMER_ON() ASTABLE_TIMER_CONFIG_REGISTER|=((1<<ASTABLE_TIMER_CONFIG_CTC_BIT)|(ASTABLE_TIMER_CONFIG_PRESCALER_MASK));\
                           ASTABLE_TIMER_COUNT_REGISTER=0;

/******************************************************************************************************/

#define ASTABLE_TIMER_OFF() ASTABLE_TIMER_CONFIG_REGISTER &=~((1<<ASTABLE_TIMER_CONFIG_CTC_BIT)|(ASTABLE_TIMER_CONFIG_PRESCALER_MASK));

/******************************************************************************************************/
//ISR BODY
/******************************************************************************************************/

#if !defined(ASTABLE_TIMER_ISR_BODY)
#define ASTABLE_TIMER_ISR_BODY
#endif

#if !defined(ASTABLE_TIMER_ISR_BODY_ON_HIGH_GOING_EDGE)
#define ASTABLE_TIMER_ISR_BODY_ON_HIGH_GOING_EDGE
#endif

#if !defined(ASTABLE_TIMER_ISR_BODY_ON_LOW_GOING_EDGE)
#define ASTABLE_TIMER_ISR_BODY_ON_LOW_GOING_EDGE
#endif

/******************************************************************************************************/
//USE MACROS
/******************************************************************************************************/

#if !defined(USE_astable_init)
#define USE_astable_init YES
#endif

/******************************************************************************************************/
//FUNCTION PROTOTYPES
/******************************************************************************************************/

#if (USE_astable_init == YES)
void astable_init(void);
#endif

/******************************************************************************************************/

#endif // ASTABLE_H_

/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
