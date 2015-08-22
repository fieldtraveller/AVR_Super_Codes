/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
Author: Charlton Fernandes

shift.c

DESCRIPTION:Functions declared in shift.h defined here.
*/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/

#if !defined(F_CPU)
#define F_CPU 16000000UL
#endif

/******************************************************************************************************/

#include <avr/pgmspace.h>

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

}

#endif

/******************************************************************************************************/

#if (USE_shift_clock)

void shift_clock(unsigned char * SFR)//Provides clock for the shift module (shift register clock)
{
    _SFR_IO8(pgm_read_byte(SFR+2))|=(1<<(pgm_read_byte(SFR+3)));//Rising Edge

    #if ((SHIFT_CLOCK_DELAY)!=0)
    _delay_ms(SHIFT_CLOCK_DELAY);
    #endif

    _SFR_IO8(pgm_read_byte(SFR+2))&=~(1<<(pgm_read_byte(SFR+3)));//Falling Edge
}

#endif

/******************************************************************************************************/

#if (USE_shift_latch_data)

void shift_latch_data(unsigned char * SFR)//Used to latch data in the shift module
{
    _SFR_IO8(pgm_read_byte(SFR+4))|=(1<<(pgm_read_byte(SFR+5)));//Rising Edge

    #if ((SHIFT_LATCH_DELAY)!=0)
    _delay_ms(SHIFT_LATCH_DELAY);
    #endif

    _SFR_IO8(pgm_read_byte(SFR+4))&=~(1<<(pgm_read_byte(SFR+5)));//Falling Edge
}

#endif

/******************************************************************************************************/

#if (USE_shift_data_out_bit)

void shift_data_out_bit(unsigned char data,unsigned char * SFR)//Shift module output bit stream function
{
    if(data)
    {
        _SFR_IO8(pgm_read_byte(SFR)) |=(1<<(pgm_read_byte(SFR+1)));
    }
    else
    {
        _SFR_IO8(pgm_read_byte(SFR)) &=~(1<<(pgm_read_byte(SFR+1)));
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
        shift_data_out_bit(0x01&(data>>a),SFR);//LSB TO MSB
        shift_clock(SFR);
    }
}

#endif

/******************************************************************************************************/

#if (USE_shift_data_in_bit)

unsigned char shift_data_in_bit(unsigned char * SFR)//Shift module input bit stream function
{
    if(_SFR_IO8(pgm_read_byte(SFR)) & (1<<(pgm_read_byte(SFR+1))))
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
