/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
Author: Charlton Fernandes

kb.c

DESCRIPTION: Functions declared in kb.h defined here.
*/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/

#include <avr/interrupt.h>
#include <avr/pgmspace.h>

#include <util/parity.h>

/******************************************************************************************************/

#if !defined(F_CPU)
#define F_CPU 16000000UL
#endif

/******************************************************************************************************/

#include "kb.h"
#include "kb_c_code.h"

#include "lcd.h"

//#include "cf.h"

#if (USE_kb_cmd)
#include <util/delay.h>
#endif

#if (KB_USE_WDT)
#include <avr/wdt.h>
#endif

/******************************************************************************************************/

volatile unsigned char kb_buffer[KB_BUFFER_SIZE];
volatile unsigned char kb_in_p,kb_out_p,kb_buffer_count,kb_bit_count,kb_flags_RX,kb_temp_data;

#if (USE_kb_cmd)
volatile unsigned char kb_flags_TX;
#endif

/******************************************************************************************************/

#if (USE_kb_init) //== YES

void kb_init(void)//Initialisation function
{
    #if (KB_USE_WDT)
    wdt_disable();
    #endif

    kb_flags_RX=(KB_BAT_CHECK_FLAG);
    kb_in_p=kb_out_p=0;
    kb_buffer_count=0;
    kb_bit_count=11;

    KB_DDR_CLOCK&=~(1<<KB_CLOCK_GPIO_PIN);
    KB_DDR_DATA&=~(1<<KB_DATA_GPIO_PIN);

    KB_PORT_CLOCK|=(1<<KB_CLOCK_GPIO_PIN);//Activate Pull-Up Resistors
    KB_PORT_DATA|=(1<<KB_DATA_GPIO_PIN);

    KB_ISR_FALLING;
    KB_ISR_ENABLE;
    sei();
}

#endif

/******************************************************************************************************/

ISR(KB_ISR_VECTOR)//Appropriate ISR
{
    if((kb_flags_TX&KB_MODE_FLAG)==(KB_RX_MODE_FLAG))
    {
        if((kb_flags_RX&KB_EDGE_FLAG)==(KB_FALL_FLAG))
        {
            if((kb_bit_count<11)&&(kb_bit_count>2))
            {
                kb_temp_data=(kb_temp_data>>1);
                if ( (KB_PIN_DATA) & (KB_DATA_MASK) )
                    kb_temp_data |= 0x80;
            }

            (kb_flags_RX) |= (KB_RISE_FLAG);
            KB_ISR_RISING;
        }
        else
        {

	    (kb_flags_RX) &= ~(KB_RISE_FLAG);
		KB_ISR_FALLING;

		if(--kb_bit_count==0)
		{
		    if(!((kb_flags_RX)&(KB_BAT_CHECK_FLAG)))
            {
              // lcd_hex((unsigned char)kb_temp_data);
               kb_decode();
            }
            else
            {
                (kb_flags_RX)&=~(KB_BAT_CHECK_FLAG);
            }

		    kb_bit_count = 11;
		}
	}
    }
    else
    {
        #if (USE_kb_cmd)
        /*
        if(kb_bit_count==0)
        {
            KB_PORT_DATA &=~(1<<KB_DATA_GPIO_PIN);
        }
        */

        if((kb_bit_count>0)&&(kb_bit_count<9))
        {
            if(kb_temp_data&(1<<(kb_bit_count-1)))
                KB_PORT_DATA |=(1<<KB_DATA_GPIO_PIN);
            else
                KB_PORT_DATA &=~(1<<KB_DATA_GPIO_PIN);
        }
        else if (kb_bit_count==9)
        {
            if(kb_flags_TX&KB_PARITY_FLAG)
                KB_PORT_DATA |=(1<<KB_DATA_GPIO_PIN);
            else
                KB_PORT_DATA &=~(1<<KB_DATA_GPIO_PIN);
        }
        else if(kb_bit_count==10)
        {
            KB_PORT_DATA |=(1<<KB_DATA_GPIO_PIN);
            KB_DDR_DATA &=~(1<<KB_DATA_GPIO_PIN);
        }
        else if (kb_bit_count==11)
        {
            //KB_PORT_DATA |=(1<<KB_DATA_GPIO_PIN);
            /*if(((KB_PIN_DATA)&(1<<KB_DATA_GPIO_PIN))==0)
                (kb_flags_TX)|=(KB_ACKNOWLEDGEMENT_BIT_FLAG);
            */
            (kb_flags_TX) &= ~(KB_MODE_FLAG);
            kb_bit_count = 10;
            (kb_flags_RX) &= ~(KB_RISE_FLAG);

            #if (KB_ACKNOWLEDGEMENT_BYTE_IS_SENT)//== YES
            (kb_flags_RX)|=(KB_ACKNOWLEDGEMENT_BYTE_CHECK_FLAG); //Used to Ignore Acknowledgement byte(0xFA)
            #endif
        }

        kb_bit_count++;

        #endif

    }
}

/******************************************************************************************************/

#if (USE_kb_cmd) //==YES

void kb_cmd(unsigned char data)//Command Function - Used to send commands to keyboard.
{
    while((kb_flags_TX&KB_MODE_FLAG)==KB_TX_MODE_FLAG);//Wait till previous transfer is complete

    cli();
    kb_bit_count=0;
    kb_temp_data=data;
    kb_flags_TX |= (KB_MODE_FLAG);
    KB_ISR_FALLING;

    KB_DDR_CLOCK |=(1<<KB_CLOCK_GPIO_PIN);
    KB_PORT_CLOCK &=~(1<<KB_CLOCK_GPIO_PIN);
    _delay_ms(100);

    sei();

    KB_DDR_DATA |=(1<<KB_DATA_GPIO_PIN);
    KB_PORT_DATA &=~(1<<KB_DATA_GPIO_PIN);

    KB_DDR_CLOCK &=~(1<<KB_CLOCK_GPIO_PIN);
    KB_PORT_CLOCK|=(1<<KB_CLOCK_GPIO_PIN);

    if(parity_even_bit(data))
        (kb_flags_TX) &= ~(KB_PARITY_FLAG);
    else
        (kb_flags_TX) |= (KB_PARITY_FLAG);
}

#endif

/******************************************************************************************************/

#if (USE_kb_decode) //== YES

void kb_decode(void)//Decoding function
{
    if(!(kb_flags_RX&KB_BREAK_CODE_FLAG))
    {
        switch(kb_temp_data)
        {
        case 0xF0:
            (kb_flags_RX)|=(KB_BREAK_CODE_FLAG);
            break;

        case 0x12:
        case 0x59:
            (kb_flags_RX)|=(KB_SHIFT_FLAG);
            break;

        case 0x58:
            (kb_flags_RX)|=(KB_CAPS_LOCK_FLAG);
            break;

        case 0x14:
            if((kb_flags_TX)&(KB_PREVIOUS_FLAG_WAS_EXTENDED))
            {
                 (kb_flags_RX)&=~(KB_EXTENDED_FLAG);
                 (kb_flags_TX)&=~(KB_PREVIOUS_FLAG_WAS_EXTENDED);
                 (kb_flags_TX)|=(KB_LEFT_CONTROL);
            }
            else
                (kb_flags_TX)&=~(KB_LEFT_CONTROL);

            (kb_flags_RX)|=(KB_CTRL_FLAG);
            break;

        case 0x11:
            if((kb_flags_TX)&(KB_PREVIOUS_FLAG_WAS_EXTENDED))
            {
                 (kb_flags_RX)&=~(KB_EXTENDED_FLAG);
                 (kb_flags_TX)&=~(KB_PREVIOUS_FLAG_WAS_EXTENDED);
                 (kb_flags_TX)|=(KB_LEFT_ALTERNATE);
            }
            else
                (kb_flags_TX)&=~(KB_LEFT_ALTERNATE);

            (kb_flags_RX)|=(KB_ALT_FLAG);
            break;

        case 0xE0:
            if(!((kb_flags_RX)&(KB_EXTENDED_FLAG)))
                {
                    (kb_flags_RX)|=(KB_EXTENDED_FLAG);
                    (kb_flags_TX)|=(KB_PREVIOUS_FLAG_WAS_EXTENDED);

                }
            break;

        default:
            (kb_flags_TX)&=~(KB_PREVIOUS_FLAG_WAS_EXTENDED);
            kb_scan2ascii();
            break;
        }
    }
    else
    {
        (kb_flags_RX)&=~(KB_BREAK_CODE_FLAG);
        (kb_flags_RX)&=~(KB_EXTENDED_FLAG);

        switch(kb_temp_data)
        {
        case 0x12:
        case 0x59:
            (kb_flags_RX)&=~(KB_SHIFT_FLAG);
            break;

        case 0x58:
            (kb_flags_RX)&=~(KB_CAPS_LOCK_FLAG);
            break;

        case 0x14:
            (kb_flags_RX)&=~(KB_CTRL_FLAG);
            break;

        case 0x11:
            (kb_flags_RX)&=~(KB_ALT_FLAG);
            break;

        default:
            return;

    }
    }
}

#endif

/******************************************************************************************************/

#if (USE_kb_scan2ascii) //== YES

void kb_scan2ascii(void)//Translating Function
{
    unsigned char a,data;

            if((kb_flags_RX)&(KB_EXTENDED_FLAG))
                a=87;
            else
                a=0;

        #if (KB_USE_WDT)
        wdt_enable(7);
        #endif

        for(;kb_temp_data!=(pgm_read_byte(&kb_LUT[a][0]));a++);

        #if (KB_USE_WDT)
        wdt_disable();
        #endif

        switch((kb_flags_RX)&(0x0F))
        {
        case KB_SHIFT_FLAG:
        case KB_CAPS_LOCK_FLAG:
            data=pgm_read_byte(&kb_LUT[a][2]);
            break;

        #if (KB_USE_CONTROL_COMBINATIONS)

        case KB_CTRL_FLAG:
            data=pgm_read_byte(&kb_LUT[a][3]);
            break;

        #endif

        #if (KB_USE_ALTERNATE_COMBINATIONS)

        case KB_ALT_FLAG:
            data=pgm_read_byte(&kb_LUT[a][KB_ALTERNATE_OFFSET]);
            break;

        #endif

        default:
            data=pgm_read_byte(&kb_LUT[a][1]);
            break;
        }

    kb_putdata(data);

}

#endif

/******************************************************************************************************/

#if (USE_kb_putdata) //== YES

void kb_putdata(unsigned char value)//Put data in circular queue
{
    if (kb_buffer_count<KB_BUFFER_SIZE)
    {
        kb_buffer[kb_in_p]=value;
        kb_in_p++;
        kb_buffer_count++;

        if (kb_in_p >=KB_BUFFER_SIZE)
        kb_in_p =0;
    }
}

#endif

/******************************************************************************************************/

#if (USE_kb_getdata) //== YES

unsigned char kb_getdata(void)//Get data from circular queue
{
    unsigned char data;

    while(kb_buffer_count == 0);

    data =kb_buffer[kb_out_p];
    kb_out_p++;

    if (kb_out_p >=KB_BUFFER_SIZE)
        kb_out_p =0;

    kb_buffer_count--;

    return data;
}

#endif

/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
