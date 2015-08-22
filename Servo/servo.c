/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
AUTHOR: CHARLTON FERNANDES

servo.c

DESCRIPTION:
*/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/

#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/sfr_defs.h>
#include <stdint.h>

/******************************************************************************************************/

#if !defined(F_CPU)
#define F_CPU 16000000UL
#endif

/******************************************************************************************************/

#include <util/atomic.h>

/******************************************************************************************************/

#include "cf.h"
#include "servo.h"
#include "servo_timer.h"

/******************************************************************************************************/
//FUNCTION AND ISR DEFINITIONS
/******************************************************************************************************/

#if ((defined(SERVO_USE_TIMER_0))&&(SERVO_USE_TIMER_0 == YES))
ISR (TIMER0_COMP_vect)
{
    servo_timer_interrupt_handler((uint8_t*)&OCR0,(uint8_t*)&servo_timer_0_ticks,(SERVO**)servo_timer_0_channels,(uint8_t*)&servo_timer_0_status);
}
#endif

/******************************************************************************************************/

#if ((defined(SERVO_USE_TIMER_1))&&(SERVO_USE_TIMER_1 == YES))
ISR (TIMER1_COMPA_vect)
{
    servo_timer_interrupt_handler((uint8_t*)&OCR1AL,(uint8_t*)&servo_timer_1_ticks,(SERVO**)servo_timer_1_channels,(uint8_t*)&servo_timer_1_status);
}
#endif

/******************************************************************************************************/

#if ((defined(SERVO_USE_TIMER_2))&&(SERVO_USE_TIMER_2 == YES))
ISR (TIMER2_COMP_vect)
{
    servo_timer_interrupt_handler((uint8_t*)&OCR2,(uint8_t*)&servo_timer_2_ticks,(SERVO**)servo_timer_2_channels,(uint8_t*)&servo_timer_2_status);
}
#endif

/******************************************************************************************************/

#if (USE_servo_init == YES)
void servo_init(SERVO* INPUT_SERVO_STRUCT)
{
    PHYSICAL_REGISTER_ACCESS_8_BIT(SERVO_VALUE_OF_ADDRESS_OF_DDR_DATA(INPUT_SERVO_STRUCT))|=(1<<SERVO_VALUE_OF_DATA_GPIO_PIN(INPUT_SERVO_STRUCT));

    if(SERVO_VALUE_OF_ADDRESS_OF_DDR_DATA(INPUT_SERVO_STRUCT) == &DDRA)
    {
        SERVO_VALUE_OF_ADDRESS_OF_PORT_DATA(INPUT_SERVO_STRUCT)=(uint8_t*)&PORTA;
    }
    else if(SERVO_VALUE_OF_ADDRESS_OF_DDR_DATA(INPUT_SERVO_STRUCT) == &DDRB)
    {
        SERVO_VALUE_OF_ADDRESS_OF_PORT_DATA(INPUT_SERVO_STRUCT)=(uint8_t*)&PORTB;
    }
    else if(SERVO_VALUE_OF_ADDRESS_OF_DDR_DATA(INPUT_SERVO_STRUCT) == &DDRC)
    {
        SERVO_VALUE_OF_ADDRESS_OF_PORT_DATA(INPUT_SERVO_STRUCT)=(uint8_t*)&PORTC;
    }
    else if(SERVO_VALUE_OF_ADDRESS_OF_DDR_DATA(INPUT_SERVO_STRUCT) == &DDRD)
    {
        SERVO_VALUE_OF_ADDRESS_OF_PORT_DATA(INPUT_SERVO_STRUCT)=(uint8_t*)&PORTD;
    }
    /*
    if(SERVO_VALUE_OF_CHANNEL(INPUT_SERVO_STRUCT)== 0)
    {
        PHYSICAL_REGISTER_ACCESS_8_BIT(SERVO_VALUE_OF_ADDRESS_OF_PORT_DATA(INPUT_SERVO_STRUCT))|=(1<<SERVO_VALUE_OF_DATA_GPIO_PIN(INPUT_SERVO_STRUCT));
    }
    */
    switch(SERVO_VALUE_OF_TIMER(INPUT_SERVO_STRUCT))
    {
        #if ((defined(SERVO_USE_TIMER_0))&&(SERVO_USE_TIMER_0 == YES))
    case SERVO_TIMER_0:
        servo_timer_0_channels[SERVO_VALUE_OF_CHANNEL(INPUT_SERVO_STRUCT)]=INPUT_SERVO_STRUCT;
        break;
        #endif

        #if ((defined(SERVO_USE_TIMER_1))&&(SERVO_USE_TIMER_1 == YES))
    case SERVO_TIMER_1:
        servo_timer_1_channels[SERVO_VALUE_OF_CHANNEL(INPUT_SERVO_STRUCT)]=INPUT_SERVO_STRUCT;
        break;
        #endif

        #if ((defined(SERVO_USE_TIMER_2))&&(SERVO_USE_TIMER_2 == YES))
    case SERVO_TIMER_2:
        servo_timer_2_channels[SERVO_VALUE_OF_CHANNEL(INPUT_SERVO_STRUCT)]=INPUT_SERVO_STRUCT;
        break;
        #endif
    }
}
#endif

/******************************************************************************************************/

#if (USE_servo_set_angle == YES)
void servo_set_angle(SERVO* INPUT_SERVO_STRUCT,float value)
{
    if(value>180)
        return;

    value=value*0.52+27.5;

    switch(SERVO_VALUE_OF_TIMER(INPUT_SERVO_STRUCT))
    {
        #if ((defined(SERVO_USE_TIMER_0))&&(SERVO_USE_TIMER_0 == YES))
    case SERVO_TIMER_0:
            servo_timer_0_ticks[SERVO_VALUE_OF_CHANNEL(INPUT_SERVO_STRUCT)]=(uint8_t)value;
            break;
        #endif

        #if ((defined(SERVO_USE_TIMER_1))&&(SERVO_USE_TIMER_1 == YES))
    case SERVO_TIMER_1:
            servo_timer_1_ticks[SERVO_VALUE_OF_CHANNEL(INPUT_SERVO_STRUCT)]=(uint8_t)value;
            break;
        #endif

        #if ((defined(SERVO_USE_TIMER_2))&&(SERVO_USE_TIMER_2 == YES))
    case SERVO_TIMER_2:
            servo_timer_2_ticks[SERVO_VALUE_OF_CHANNEL(INPUT_SERVO_STRUCT)]=(uint8_t)value;
            break;
        #endif
    }
}
#endif

/******************************************************************************************************/

#if (USE_servo_timer_init == YES)
void servo_timer_init()
{
    #if ((defined(SERVO_USE_TIMER_0))&&(SERVO_USE_TIMER_0 == YES))
    TCNT0=0x00;
    TIMSK|=((1<<OCIE0));
    OCR0=servo_timer_0_ticks[0];
    TCCR0|=((1<<WGM01)|(1<<CS02));
    #endif

    #if ((defined(SERVO_USE_TIMER_1))&&(SERVO_USE_TIMER_1 == YES))
    TCNT1H=0x00;
    TCNT1L=0x00;
    TIMSK|=((1<<OCIE1A));
    OCR1AH=0x00;
    OCR1AL=servo_timer_1_ticks[0];
    TCCR1B|=((1<<WGM12)|(1<<CS12));
    #endif

    #if ((defined(SERVO_USE_TIMER_2))&&(SERVO_USE_TIMER_2 == YES))
    TCNT2=0x00;
    TIMSK|=((1<<OCIE2));
    OCR2=servo_timer_2_ticks[0];
    TCCR2|=((1<<WGM21)|(1<<CS22)|(1<<CS21));
    #endif

    sei();
}
#endif

/******************************************************************************************************/

#if (USE_servo_timer_interrupt_handler == YES)
void servo_timer_interrupt_handler(uint8_t* address_of_compare_output_register,uint8_t* servo_timer_ticks,SERVO** servo_timer_channels,uint8_t* servo_timer_status)
{
    SERVO *temp1;

    if(SERVO_TIMER_CHANNEL_PULSE_POSITION(*servo_timer_status) == 0x00)
    {
        if(servo_timer_ticks[SERVO_TIMER_CHANNEL_COUNT(*servo_timer_status)] == 155)
        {
            *servo_timer_status=*servo_timer_status+1;

            if(SERVO_TIMER_CHANNEL_COUNT(*servo_timer_status) >= 8)
            {
                 *servo_timer_status &=~(0x0F);
            }

            PHYSICAL_REGISTER_ACCESS_8_BIT(address_of_compare_output_register)=servo_timer_ticks[SERVO_TIMER_CHANNEL_COUNT(*servo_timer_status)];

            if(servo_timer_ticks[SERVO_TIMER_CHANNEL_COUNT(*servo_timer_status)]!= 155)
            {
                temp1=servo_timer_channels[SERVO_TIMER_CHANNEL_COUNT(*servo_timer_status)];
                PHYSICAL_REGISTER_ACCESS_8_BIT(temp1->SERVO_ADDRESS_OF_IOR_DATA)|=(1<<SERVO_VALUE_OF_DATA_GPIO_PIN(temp1));
            }
        }
        else
        {
            PHYSICAL_REGISTER_ACCESS_8_BIT(address_of_compare_output_register)=155-servo_timer_ticks[SERVO_TIMER_CHANNEL_COUNT(*servo_timer_status)];
            *servo_timer_status|=(1<<7);

			temp1=servo_timer_channels[SERVO_TIMER_CHANNEL_COUNT(*servo_timer_status)];
            PHYSICAL_REGISTER_ACCESS_8_BIT(temp1->SERVO_ADDRESS_OF_IOR_DATA)&=~(1<<SERVO_VALUE_OF_DATA_GPIO_PIN(temp1));
        }
    }
    else
    {
        *servo_timer_status=*servo_timer_status+1;

        if(SERVO_TIMER_CHANNEL_COUNT(*servo_timer_status) >= 8)
        {
            *servo_timer_status &=~(0x0F);
        }

        PHYSICAL_REGISTER_ACCESS_8_BIT(address_of_compare_output_register)=servo_timer_ticks[SERVO_TIMER_CHANNEL_COUNT(*servo_timer_status)];
        *servo_timer_status&=~(1<<7);

        if(servo_timer_ticks[SERVO_TIMER_CHANNEL_COUNT(*servo_timer_status)]!= 155)
        {
            temp1=servo_timer_channels[SERVO_TIMER_CHANNEL_COUNT(*servo_timer_status)];
            PHYSICAL_REGISTER_ACCESS_8_BIT(temp1->SERVO_ADDRESS_OF_IOR_DATA)|=(1<<SERVO_VALUE_OF_DATA_GPIO_PIN(temp1));
        }
    }
}
#endif

/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
