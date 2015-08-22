/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
Author: Charlton Fernandes

byte.c

DESCRIPTION: Byte manipulation library source code
*/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/

#include "byte.h"

/******************************************************************************************************/

#if (USE_USE_flip_lr_byte)

unsigned char flip_lr_byte(unsigned char data)  //flip the bits in the byte
{
    unsigned char byte,a=0;

    for(;a<8;a++)
    {
        if(data&(1<<a))
            {
                byte|=(1<<(7-a));
            }
        else
            {
                byte&=~(1<<(7-a));
            }
    }

    return byte;
}

#endif

/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
