/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
Author: Charlton Fernandes

shift.c

DESCRIPTION: Functions declared in shift.h defined here.
*/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/

#if !defined(F_CPU)
#define F_CPU 16000000UL
#endif

/******************************************************************************************************/

#include "shift.h"

/******************************************************************************************************/

#if (((SHIFT_CLOCK_DELAY)!=0)||((SHIFT_LATCH_DELAY)!=0))
#include <util/delay.h>
#endif

/******************************************************************************************************/

#if (USE_shift_init)

void shift_init(void)//Used to initiate the shift module
{
    #if ((SHIFT_OPTIMIZATION_TYPE)==(SHIFT_OPTIMIZATION_TYPE_1))

    #if((SHIFT_DDRA_VALUE_HIGH_LOW_BIT_SUM)!=0)

    #if (SHIFT_DDRA_VALUE_LOW) == 0xFF
    DDRA = 0x00;
    #elif (SHIFT_DDRA_VALUE_HIGH) == 0xFF
    DDRA = 0xFF;
    #elif (KP_DDRA_VALUE_FINAL_BIT_SUM) == 8
    DDRA = SHIFT_DDRA_VALUE_HIGH;
    #else
    DDRA = (DDRA & ~(SHIFT_DDRA_VALUE_LOW))|(SHIFT_DDRA_VALUE_HIGH);
    #endif

    #endif

    #if((SHIFT_DDRB_VALUE_HIGH_LOW_BIT_SUM)!=0)

    #if (SHIFT_DDRB_VALUE_LOW) == 0xFF
    DDRB = 0x00;
    #elif (SHIFT_DDRB_VALUE_HIGH) == 0xFF
    DDRB = 0xFF;
    #elif (KP_DDRB_VALUE_FINAL_BIT_SUM) == 8
    DDRB = SHIFT_DDRB_VALUE_HIGH;
    #else
    DDRB = (DDRB & ~(SHIFT_DDRB_VALUE_LOW))|(SHIFT_DDRB_VALUE_HIGH);
    #endif

    #endif

    #if((SHIFT_DDRC_VALUE_HIGH_LOW_BIT_SUM)!=0)

    #if (SHIFT_DDRC_VALUE_LOW) == 0xFF
    DDRC = 0x00;
    #elif (SHIFT_DDRC_VALUE_HIGH) == 0xFF
    DDRC = 0xFF;
    #elif (KP_DDRC_VALUE_FINAL_BIT_SUM) == 8
    DDRC = SHIFT_DDRC_VALUE_HIGH;
    #else
    DDRC = (DDRC & ~(SHIFT_DDRC_VALUE_LOW))|(SHIFT_DDRC_VALUE_HIGH);
    #endif

    #endif

    #if((SHIFT_DDRD_VALUE_HIGH_LOW_BIT_SUM)!=0)

    #if (SHIFT_DDRD_VALUE_LOW) == 0xFF
    DDRD = 0x00;
    #elif (SHIFT_DDRD_VALUE_HIGH) == 0xFF
    DDRD = 0xFF;
    #elif (KP_DDRD_VALUE_FINAL_BIT_SUM) == 8
    DDRD = SHIFT_DDRD_VALUE_HIGH;
    #else
    DDRD = (DDRD & ~(SHIFT_DDRD_VALUE_LOW))|(SHIFT_DDRD_VALUE_HIGH);
    #endif

    #endif

    #if((SHIFT_DDRA_VALUE_PIN_PULL_UP_BIT_SUM)!=0)

    #if (SHIFT_DDRA_VALUE_PIN_PULL_UP_BIT_SUM) == 8
    PORTA = 0xFF;
    #else
    PORTA = (DDRA |(SHIFT_DDRA_VALUE_PIN_PULL_UP));
    #endif

    #endif

    #if((SHIFT_DDRB_VALUE_PIN_PULL_UP_BIT_SUM)!=0)

    #if (SHIFT_DDRB_VALUE_PIN_PULL_UP_BIT_SUM) == 8
    PORTB = 0xFF;
    #else
    PORTB = (DDRB |(SHIFT_DDRB_VALUE_PIN_PULL_UP));
    #endif

    #endif

    #if((SHIFT_DDRC_VALUE_PIN_PULL_UP_BIT_SUM)!=0)

    #if (SHIFT_DDRC_VALUE_PIN_PULL_UP_BIT_SUM) == 8
    PORTC = 0xFF;
    #else
    PORTC = (DDRC |(SHIFT_DDRC_VALUE_PIN_PULL_UP));
    #endif

    #endif

    #if((SHIFT_DDRD_VALUE_PIN_PULL_UP_BIT_SUM)!=0)

    #if (SHIFT_DDRD_VALUE_PIN_PULL_UP_BIT_SUM) == 8
    PORTD = 0xFF;
    #else
    PORTD = (DDRD |(SHIFT_DDRD_VALUE_PIN_PULL_UP));
    #endif

    #endif

    #elif ((SHIFT_OPTIMIZATION_TYPE)==(SHIFT_OPTIMIZATION_TYPE_2))
    #if (SHIFT_1_USE)
    {
    SHIFT_DDR_1_CLOCK|=(1<<(SHIFT_1_CLOCK_GPIO_PIN));

    #if (SHIFT_1_USE_AS_OUTPUT)
    SHIFT_DDR_1_DATA |=(1<<(SHIFT_1_DATA_GPIO_PIN));
    #else
    {
    SHIFT_DDR_1_DATA &=~(1<<(SHIFT_1_DATA_GPIO_PIN));

    #if (SHIFT_1_DATA_PIN_PULL_UP_ENABLE)
    SHIFT_PORT_1_DATA |=(1<<(SHIFT_1_DATA_GPIO_PIN));
    #endif
    }
    #endif

    #if (SHIFT_1_LATCH_ENABLE)
    SHIFT_DDR_1_LATCH|=(1<<(SHIFT_1_LATCH_GPIO_PIN));
    #endif
    }
    #endif

    #if (SHIFT_2_USE)
    {
    SHIFT_DDR_2_CLOCK|=(1<<(SHIFT_2_CLOCK_GPIO_PIN));

    #if (SHIFT_2_USE_AS_OUTPUT)
    SHIFT_DDR_2_DATA |=(1<<(SHIFT_2_DATA_GPIO_PIN));
    #else
    {
    SHIFT_DDR_2_DATA &=~(1<<(SHIFT_2_DATA_GPIO_PIN));

    #if (SHIFT_2_DATA_PIN_PULL_UP_ENABLE)
    SHIFT_PORT_2_DATA |=(1<<(SHIFT_2_DATA_GPIO_PIN));
    #endif
    }
    #endif

    #if (SHIFT_2_LATCH_ENABLE)
    SHIFT_DDR_2_LATCH|=(1<<(SHIFT_2_LATCH_GPIO_PIN));
    #endif
    }
    #endif

    #if (SHIFT_3_USE)
    {
    SHIFT_DDR_3_CLOCK|=(1<<(SHIFT_3_CLOCK_GPIO_PIN));

    #if (SHIFT_3_USE_AS_OUTPUT)
    SHIFT_DDR_3_DATA |=(1<<(SHIFT_3_DATA_GPIO_PIN));
    #else
    {
    SHIFT_DDR_3_DATA &=~(1<<(SHIFT_3_DATA_GPIO_PIN));

    #if (SHIFT_3_DATA_PIN_PULL_UP_ENABLE)
    SHIFT_PORT_3_DATA |=(1<<(SHIFT_3_DATA_GPIO_PIN));
    #endif
    }
    #endif

    #if (SHIFT_3_LATCH_ENABLE)
    SHIFT_DDR_3_LATCH|=(1<<(SHIFT_3_LATCH_GPIO_PIN));
    #endif
    }
    #endif

    #if (SHIFT_4_USE)
    {
    SHIFT_DDR_4_CLOCK|=(1<<(SHIFT_4_CLOCK_GPIO_PIN));

    #if (SHIFT_4_USE_AS_OUTPUT)
    SHIFT_DDR_4_DATA |=(1<<(SHIFT_4_DATA_GPIO_PIN));
    #else
    {
    SHIFT_DDR_4_DATA &=~(1<<(SHIFT_4_DATA_GPIO_PIN));

    #if (SHIFT_4_DATA_PIN_PULL_UP_ENABLE)
    SHIFT_PORT_4_DATA |=(1<<(SHIFT_4_DATA_GPIO_PIN));
    #endif
    }
    #endif

    #if (SHIFT_4_LATCH_ENABLE)
    SHIFT_DDR_4_LATCH|=(1<<(SHIFT_4_LATCH_GPIO_PIN));
    #endif
    }
    #endif

    #endif

}

#endif

/******************************************************************************************************/

#if (USE_shift_clock)

void shift_clock(unsigned char * SFR)//Provides clock for the shift module (shift register clock)
{
    _SFR_IO8(*(SFR+2))|=(1<<(*(SFR+3)));//Rising Edge

    #if ((SHIFT_CLOCK_DELAY)!=0)
    _delay_ms(SHIFT_CLOCK_DELAY);
    #endif

    _SFR_IO8(*(SFR+2))&=~(1<<(*(SFR+3)));//Falling Edge
}

#endif

/******************************************************************************************************/

#if (USE_shift_latch_data)

void shift_latch_data(unsigned char * SFR)//Used to latch data in the shift module
{
    _SFR_IO8(*(SFR+4))|=(1<<(*(SFR+5)));//Rising Edge

    #if ((SHIFT_LATCH_DELAY)!=0)
    _delay_ms(SHIFT_LATCH_DELAY);
    #endif

    _SFR_IO8(*(SFR+4))&=~(1<<(*(SFR+5)));//Falling Edge
}

#endif

/******************************************************************************************************/

#if (USE_shift_data_out_bit)

void shift_data_out_bit(unsigned char data,unsigned char * SFR)//Shift module output bit stream function
{
    if(data)
    {
        _SFR_IO8(*(SFR)) |=(1<<(*(SFR+1)));
    }
    else
    {
        _SFR_IO8(*(SFR)) &=~(1<<(*(SFR+1)));
    }
}

#endif

/******************************************************************************************************/

#if (USE_shift_data_out_byte)

void shift_data_out_byte(unsigned char data,unsigned char * SFR)//Used to send a byte serially
{
    unsigned char a=0;

    for(;a<8;a++)
    {
        shift_data_out_bit(0x01&(data>>a),SFR);

        shift_clock(SFR);
    }
}

#endif

/******************************************************************************************************/

#if (USE_shift_data_in_bit)

unsigned char shift_data_in_bit(unsigned char * SFR)//Shift module input bit stream function
{
    if(_SFR_IO8(*(SFR)) & (1<<(*(SFR+1))))
    return 1;
    else
    return 0;
}

#endif

/******************************************************************************************************/

#if (USE_shift_data_in_byte)

unsigned char shift_data_in_byte(unsigned char * SFR)//Used to read a byte from bit stream
{
    unsigned char a=0,data=0;

    for(;a<8;a++)
    {
        data|=((unsigned char)shift_data_in_bit(SFR)<<a);
        shift_clock(SFR);
    }

    return data;
}

#endif

/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
