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

#include "shift.h"

/******************************************************************************************************/
//Module Discription
/******************************************************************************************************/

{
/******************************************************************************************************/
//Module 1
/******************************************************************************************************/

#if (SHIFT_1_USE)//Shift module 1
{
/******************************************************************************************************/

#if (SHIFT_1_LATCH_DELAY)||(SHIFT_1_CLOCK_DELAY)
#include <util/delay.h>
#endif

/******************************************************************************************************/

#if (USE_shift_1_init)//Used to initiate the shift module

void shift_1_init(void)
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

/******************************************************************************************************/

#if (USE_shift_1_latch_data)//Used to latch data in the shift module

void shift_1_latch_data(void)
{
    SHIFT_PORT_1_LATCH|=(1<<(SHIFT_1_LATCH_GPIO_PIN));//Rising Edge

    #if (SHIFT_1_LATCH_DELAY)
    _delay_ms(SHIFT_1_LATCH_DELAY);
    #endif

    SHIFT_PORT_1_LATCH&=~(1<<(SHIFT_1_LATCH_GPIO_PIN));//Falling Edge
}

#endif

/******************************************************************************************************/

#if (USE_shift_1_clock)//Provides clock for the shift module (shift register clock)

void shift_1_clock(void)
{
    SHIFT_PORT_1_CLOCK|=(1<<(SHIFT_1_CLOCK_GPIO_PIN));//Rising Edge

    #if (SHIFT_1_CLOCK_DELAY)
    _delay_ms(SHIFT_1_CLOCK_DELAY);
    #endif

    SHIFT_PORT_1_CLOCK&=~(1<<(SHIFT_1_CLOCK_GPIO_PIN));//Falling Edge
}

#endif

/******************************************************************************************************/

#if (USE_shift_1_data_out_bit)//Shift module output bit stream function

void shift_1_data_out_bit(unsigned char data)
{
    if(data)
    {
        SHIFT_PORT_1_DATA |=(1<<(SHIFT_1_DATA_GPIO_PIN));
    }
    else
    {
        SHIFT_PORT_1_DATA &=~(1<<(SHIFT_1_DATA_GPIO_PIN));
    }
}

#endif

/******************************************************************************************************/

#if (USE_shift_1_data_out_byte)//Used to send a byte serially

void shift_1_data_out_byte(unsigned char data)
{
    unsigned char a=0;

    for(;a<8;a++)
    {
        #if (SHIFT_1_DATA_IN_MSB_TO_LSB_ORDER)
        shift_1_data_out_bit(0x80&(data<<a));
        #else
        shift_1_data_out_bit(0x01&(data>>a));
        #endif

        shift_1_clock();
    }
}

#endif

/******************************************************************************************************/

#if (USE_shift_1_data_in_bit)

unsigned char shift_1_data_in_bit(void)//Shift module input bit stream function
{
    if(SHIFT_PIN_1_DATA & (1<<(SHIFT_1_DATA_GPIO_PIN)))
    return 1;
    else
    return 0;
}

#endif

/******************************************************************************************************/

#if (USE_shift_1_data_in_byte)//Used to read a byte from bit stream

unsigned char shift_1_data_in_byte(void)
{
    unsigned char a=0,data;

    for(;a<8;a++)
    {
        #if (SHIFT_1_DATA_IN_MSB_TO_LSB_ORDER)
        data|=((unsigned char)shift_1_data_in_bit()<<a);
        #else
        data|=((unsigned char)shift_1_data_in_bit()>>a);
        #endif

        shift_1_clock();
    }

    return data;
}

#endif

/******************************************************************************************************/
}
#endif

/******************************************************************************************************/
//Module 2
/******************************************************************************************************/

#if (SHIFT_2_USE)//Shift module 2
{
/******************************************************************************************************/

#if (SHIFT_2_LATCH_DELAY)||(SHIFT_2_CLOCK_DELAY)
#include <util/delay.h>
#endif

/******************************************************************************************************/

#if (USE_shift_2_init)//Used to initiate the shift module

void shift_2_init(void)
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

/******************************************************************************************************/

#if (USE_shift_2_latch_data)//Used to latch data in the shift module

void shift_2_latch_data(void)
{
    SHIFT_PORT_2_LATCH|=(1<<(SHIFT_2_LATCH_GPIO_PIN));//Rising Edge

    #if (SHIFT_2_LATCH_DELAY)
    _delay_ms(SHIFT_2_LATCH_DELAY);
    #endif

    SHIFT_PORT_2_LATCH&=~(1<<(SHIFT_2_LATCH_GPIO_PIN));//Falling Edge
}

#endif

/******************************************************************************************************/

#if (USE_shift_2_clock)//Provides clock for the shift module (shift register clock)

void shift_2_clock(void)
{
    SHIFT_PORT_2_CLOCK|=(1<<(SHIFT_2_CLOCK_GPIO_PIN));//Rising Edge

    #if (SHIFT_2_CLOCK_DELAY)
    _delay_ms(SHIFT_2_CLOCK_DELAY);
    #endif

    SHIFT_PORT_2_CLOCK&=~(1<<(SHIFT_2_CLOCK_GPIO_PIN));//Falling Edge
}

#endif

/******************************************************************************************************/

#if (USE_shift_2_data_out_bit)//Shift module output bit stream function

void shift_2_data_out_bit(unsigned char data)
{
    if(data)
    {
        SHIFT_PORT_2_DATA |=(1<<(SHIFT_2_DATA_GPIO_PIN));
    }
    else
    {
        SHIFT_PORT_2_DATA &=~(1<<(SHIFT_2_DATA_GPIO_PIN));
    }
}

#endif

/******************************************************************************************************/

#if (USE_shift_2_data_out_byte)//Used to send a byte serially

void shift_2_data_out_byte(unsigned char data)
{
    unsigned char a=0;

    for(;a<8;a++)
    {
        #if (SHIFT_2_DATA_IN_MSB_TO_LSB_ORDER)
        shift_2_data_out_bit(0x80&(data<<a));
        #else
        shift_2_data_out_bit(0x01&(data>>a));
        #endif

        shift_2_clock();
    }
}

#endif

/******************************************************************************************************/

#if (USE_shift_2_data_in_bit)

unsigned char shift_2_data_in_bit(void)//Shift module input bit stream function
{
    if(SHIFT_PIN_2_DATA & (1<<(SHIFT_2_DATA_GPIO_PIN)))
    return 1;
    else
    return 0;
}

#endif

/******************************************************************************************************/

#if (USE_shift_2_data_in_byte)//Used to read a byte from bit stream

unsigned char shift_2_data_in_byte(void)
{
    unsigned char a=0,data;

    for(;a<8;a++)
    {
        #if (SHIFT_2_DATA_IN_MSB_TO_LSB_ORDER)
        data|=((unsigned char)shift_2_data_in_bit()<<a);
        #else
        data|=((unsigned char)shift_2_data_in_bit()>>a);
        #endif

        shift_2_clock();
    }

    return data;
}

#endif

/******************************************************************************************************/
}
#endif

/******************************************************************************************************/
//Module 3
/******************************************************************************************************/

#if (SHIFT_3_USE)//Shift module 3
{
/******************************************************************************************************/

#if (SHIFT_3_LATCH_DELAY)||(SHIFT_3_CLOCK_DELAY)
#include <util/delay.h>
#endif

/******************************************************************************************************/

#if (USE_shift_3_init)//Used to initiate the shift module

void shift_3_init(void)
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

/******************************************************************************************************/

#if (USE_shift_3_latch_data)//Used to latch data in the shift module

void shift_3_latch_data(void)
{
    SHIFT_PORT_3_LATCH|=(1<<(SHIFT_3_LATCH_GPIO_PIN));//Rising Edge

    #if (SHIFT_3_LATCH_DELAY)
    _delay_ms(SHIFT_3_LATCH_DELAY);
    #endif

    SHIFT_PORT_3_LATCH&=~(1<<(SHIFT_3_LATCH_GPIO_PIN));//Falling Edge
}

#endif

/******************************************************************************************************/

#if (USE_shift_3_clock)//Provides clock for the shift module (shift register clock)

void shift_3_clock(void)
{
    SHIFT_PORT_3_CLOCK|=(1<<(SHIFT_3_CLOCK_GPIO_PIN));//Rising Edge

    #if (SHIFT_3_CLOCK_DELAY)
    _delay_ms(SHIFT_3_CLOCK_DELAY);
    #endif

    SHIFT_PORT_3_CLOCK&=~(1<<(SHIFT_3_CLOCK_GPIO_PIN));//Falling Edge
}

#endif

/******************************************************************************************************/

#if (USE_shift_3_data_out_bit)//Shift module output bit stream function

void shift_3_data_out_bit(unsigned char data)
{
    if(data)
    {
        SHIFT_PORT_3_DATA |=(1<<(SHIFT_3_DATA_GPIO_PIN));
    }
    else
    {
        SHIFT_PORT_3_DATA &=~(1<<(SHIFT_3_DATA_GPIO_PIN));
    }
}

#endif

/******************************************************************************************************/

#if (USE_shift_3_data_out_byte)//Used to send a byte serially

void shift_3_data_out_byte(unsigned char data)
{
    unsigned char a=0;

    for(;a<8;a++)
    {
        #if (SHIFT_3_DATA_IN_MSB_TO_LSB_ORDER)
        shift_3_data_out_bit(0x80&(data<<a));
        #else
        shift_3_data_out_bit(0x01&(data>>a));
        #endif

        shift_3_clock();
    }
}

#endif

/******************************************************************************************************/

#if (USE_shift_3_data_in_bit)

unsigned char shift_3_data_in_bit(void)//Shift module input bit stream function
{
    if(SHIFT_PIN_3_DATA & (1<<(SHIFT_3_DATA_GPIO_PIN)))
    return 1;
    else
    return 0;
}

#endif

/******************************************************************************************************/

#if (USE_shift_3_data_in_byte)//Used to read a byte from bit stream

unsigned char shift_3_data_in_byte(void)
{
    unsigned char a=0,data;

    for(;a<8;a++)
    {
        #if (SHIFT_3_DATA_IN_MSB_TO_LSB_ORDER)
        data|=((unsigned char)shift_3_data_in_bit()<<a);
        #else
        data|=((unsigned char)shift_3_data_in_bit()>>a);
        #endif

        shift_3_clock();
    }

    return data;
}

#endif

/******************************************************************************************************/
}
#endif

/******************************************************************************************************/
//Module 4
/******************************************************************************************************/

#if (SHIFT_4_USE)//Shift module 4
{
/******************************************************************************************************/

#if (SHIFT_4_LATCH_DELAY)||(SHIFT_4_CLOCK_DELAY)
#include <util/delay.h>
#endif

/******************************************************************************************************/

#if (USE_shift_4_init)//Used to initiate the shift module

void shift_4_init(void)
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

/******************************************************************************************************/

#if (USE_shift_4_latch_data)//Used to latch data in the shift module

void shift_4_latch_data(void)
{
    SHIFT_PORT_4_LATCH|=(1<<(SHIFT_4_LATCH_GPIO_PIN));//Rising Edge

    #if (SHIFT_4_LATCH_DELAY)
    _delay_ms(SHIFT_4_LATCH_DELAY);
    #endif

    SHIFT_PORT_4_LATCH&=~(1<<(SHIFT_4_LATCH_GPIO_PIN));//Falling Edge
}

#endif

/******************************************************************************************************/

#if (USE_shift_4_clock)//Provides clock for the shift module (shift register clock)

void shift_4_clock(void)
{
    SHIFT_PORT_4_CLOCK|=(1<<(SHIFT_4_CLOCK_GPIO_PIN));//Rising Edge

    #if (SHIFT_4_CLOCK_DELAY)
    _delay_ms(SHIFT_4_CLOCK_DELAY);
    #endif

    SHIFT_PORT_4_CLOCK&=~(1<<(SHIFT_4_CLOCK_GPIO_PIN));//Falling Edge
}

#endif

/******************************************************************************************************/

#if (USE_shift_4_data_out_bit)//Shift module output bit stream function

void shift_4_data_out_bit(unsigned char data)
{
    if(data)
    {
        SHIFT_PORT_4_DATA |=(1<<(SHIFT_4_DATA_GPIO_PIN));
    }
    else
    {
        SHIFT_PORT_4_DATA &=~(1<<(SHIFT_4_DATA_GPIO_PIN));
    }
}

#endif

/******************************************************************************************************/

#if (USE_shift_4_data_out_byte)//Used to send a byte serially

void shift_4_data_out_byte(unsigned char data)
{
    unsigned char a=0;

    for(;a<8;a++)
    {
        #if (SHIFT_4_DATA_IN_MSB_TO_LSB_ORDER)
        shift_4_data_out_bit(0x80&(data<<a));
        #else
        shift_4_data_out_bit(0x01&(data>>a));
        #endif

        shift_4_clock();
    }
}

#endif

/******************************************************************************************************/

#if (USE_shift_4_data_in_bit)

unsigned char shift_4_data_in_bit(void)//Shift module input bit stream function
{
    if(SHIFT_PIN_4_DATA & (1<<(SHIFT_4_DATA_GPIO_PIN)))
    return 1;
    else
    return 0;
}

#endif

/******************************************************************************************************/

#if (USE_shift_4_data_in_byte)//Used to read a byte from bit stream

unsigned char shift_4_data_in_byte(void)
{
    unsigned char a=0,data;

    for(;a<8;a++)
    {
        #if (SHIFT_4_DATA_IN_MSB_TO_LSB_ORDER)
        data|=((unsigned char)shift_4_data_in_bit()<<a);
        #else
        data|=((unsigned char)shift_4_data_in_bit()>>a);
        #endif

        shift_4_clock();
    }

    return data;
}

#endif

/******************************************************************************************************/
}
#endif

/******************************************************************************************************/
}

/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
