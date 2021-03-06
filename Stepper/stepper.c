/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
AUTHOR: CHARLTON FERNANDES

stepper.c

DESCRIPTION: FUNCTIONS DECLARED IN stepper.h DEFINED HERE.
*/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/

#include <avr/io.h>
#include <avr/sfr_defs.h>
#include <stdint.h>

/******************************************************************************************************/

#include "cf.h"
#include "stepper.h"

/******************************************************************************************************/
//FUNCTION DEFINITIONS
/******************************************************************************************************/

#if (USE_stepper_init==YES)
void stepper_init(STEPPER* INPUT_STEPPER_STRUCT)
{
//    uint8_t *address_of_register=0;

    #if(STEPPER_LIBRARY_IN_BYTE_CONTROL_MODE == YES)

    PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_DDR_ALL(INPUT_STEPPER_STRUCT))|=((1<<STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT)));

    if(STEPPER_VALUE_OF_ADDRESS_OF_DDR_ALL(INPUT_STEPPER_STRUCT) == &DDRA)
    {
        STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)=(uint8_t*)&PORTA;
    }
    else if(STEPPER_VALUE_OF_ADDRESS_OF_DDR_ALL(INPUT_STEPPER_STRUCT) == &DDRB)
    {
        STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)=(uint8_t*)&PORTB;
    }
    else if(STEPPER_VALUE_OF_ADDRESS_OF_DDR_ALL(INPUT_STEPPER_STRUCT) == &DDRC)
    {
        STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)=(uint8_t*)&PORTC;
    }
    else if(STEPPER_VALUE_OF_ADDRESS_OF_DDR_ALL(INPUT_STEPPER_STRUCT) == &DDRD)
    {
        STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)=(uint8_t*)&PORTD;
    }

    #elif (STEPPER_LIBRARY_IN_BIT_CONTROL_MODE == YES)

    PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_DDR_A_PLUS(INPUT_STEPPER_STRUCT))|=(1<<STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT));

    if(STEPPER_VALUE_OF_ADDRESS_OF_DDR_A_PLUS(INPUT_STEPPER_STRUCT) == &DDRA)
    {
        STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_PLUS(INPUT_STEPPER_STRUCT)=(uint8_t*)&PORTA;
    }
    else if(STEPPER_VALUE_OF_ADDRESS_OF_DDR_A_PLUS(INPUT_STEPPER_STRUCT) == &DDRB)
    {
        STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_PLUS(INPUT_STEPPER_STRUCT)=(uint8_t*)&PORTB;
    }
    else if(STEPPER_VALUE_OF_ADDRESS_OF_DDR_A_PLUS(INPUT_STEPPER_STRUCT) == &DDRC)
    {
        STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_PLUS(INPUT_STEPPER_STRUCT)=(uint8_t*)&PORTC;
    }
    else if(STEPPER_VALUE_OF_ADDRESS_OF_DDR_A_PLUS(INPUT_STEPPER_STRUCT) == &DDRD)
    {
        STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_PLUS(INPUT_STEPPER_STRUCT)=(uint8_t*)&PORTD;
    }

    PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_DDR_A_MINUS(INPUT_STEPPER_STRUCT))|=(1<<STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT));

    if(STEPPER_VALUE_OF_ADDRESS_OF_DDR_A_MINUS(INPUT_STEPPER_STRUCT) == &DDRA)
    {
        STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_MINUS(INPUT_STEPPER_STRUCT)=(uint8_t*)&PORTA;
    }
    else if(STEPPER_VALUE_OF_ADDRESS_OF_DDR_A_MINUS(INPUT_STEPPER_STRUCT) == &DDRB)
    {
        STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_MINUS(INPUT_STEPPER_STRUCT)=(uint8_t*)&PORTB;
    }
    else if(STEPPER_VALUE_OF_ADDRESS_OF_DDR_A_MINUS(INPUT_STEPPER_STRUCT) == &DDRC)
    {
        STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_MINUS(INPUT_STEPPER_STRUCT)=(uint8_t*)&PORTC;
    }
    else if(STEPPER_VALUE_OF_ADDRESS_OF_DDR_A_MINUS(INPUT_STEPPER_STRUCT) == &DDRD)
    {
        STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_MINUS(INPUT_STEPPER_STRUCT)=(uint8_t*)&PORTD;
    }

    PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_DDR_B_PLUS(INPUT_STEPPER_STRUCT))|=(1<<STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT));

    if(STEPPER_VALUE_OF_ADDRESS_OF_DDR_B_PLUS(INPUT_STEPPER_STRUCT) == &DDRA)
    {
        STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_PLUS(INPUT_STEPPER_STRUCT)=(uint8_t*)&PORTA;
    }
    else if(STEPPER_VALUE_OF_ADDRESS_OF_DDR_B_PLUS(INPUT_STEPPER_STRUCT) == &DDRB)
    {
        STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_PLUS(INPUT_STEPPER_STRUCT)=(uint8_t*)&PORTB;
    }
    else if(STEPPER_VALUE_OF_ADDRESS_OF_DDR_B_PLUS(INPUT_STEPPER_STRUCT) == &DDRC)
    {
        STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_PLUS(INPUT_STEPPER_STRUCT)=(uint8_t*)&PORTC;
    }
    else if(STEPPER_VALUE_OF_ADDRESS_OF_DDR_B_PLUS(INPUT_STEPPER_STRUCT) == &DDRD)
    {
        STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_PLUS(INPUT_STEPPER_STRUCT)=(uint8_t*)&PORTD;
    }

    PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_DDR_B_MINUS(INPUT_STEPPER_STRUCT))|=(1<<STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT));

    if(STEPPER_VALUE_OF_ADDRESS_OF_DDR_B_MINUS(INPUT_STEPPER_STRUCT) == &DDRA)
    {
        STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_MINUS(INPUT_STEPPER_STRUCT)=(uint8_t*)&PORTA;
    }
    else if(STEPPER_VALUE_OF_ADDRESS_OF_DDR_B_MINUS(INPUT_STEPPER_STRUCT) == &DDRB)
    {
        STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_MINUS(INPUT_STEPPER_STRUCT)=(uint8_t*)&PORTB;
    }
    else if(STEPPER_VALUE_OF_ADDRESS_OF_DDR_B_MINUS(INPUT_STEPPER_STRUCT) == &DDRC)
    {
        STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_MINUS(INPUT_STEPPER_STRUCT)=(uint8_t*)&PORTC;
    }
    else if(STEPPER_VALUE_OF_ADDRESS_OF_DDR_B_MINUS(INPUT_STEPPER_STRUCT) == &DDRD)
    {
        STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_MINUS(INPUT_STEPPER_STRUCT)=(uint8_t*)&PORTD;
    }

    #endif

}
#endif

/******************************************************************************************************/

#if (USE_stepper_step==YES)
void stepper_step(STEPPER* INPUT_STEPPER_STRUCT)
{
    #if (STEPPER_BIPOLAR_TYPE == YES)
    if(!(STEPPER_VALUE_OF_FLAG(INPUT_STEPPER_STRUCT) & (1<<7)))
    {
        switch(STEPPER_VALUE_OF_NEXT_STEP(INPUT_STEPPER_STRUCT))
        {
            case 0:
                #if(STEPPER_LIBRARY_IN_BYTE_CONTROL_MODE == YES)
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)) = (PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)) & ~((1<<STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT))))|((1<<STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT)));
				#elif(STEPPER_LIBRARY_IN_BIT_CONTROL_MODE == YES)
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_PLUS(INPUT_STEPPER_STRUCT)) &= ~(1<<STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_MINUS(INPUT_STEPPER_STRUCT)) |= (1<<STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_PLUS(INPUT_STEPPER_STRUCT)) |= (1<<STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_MINUS(INPUT_STEPPER_STRUCT)) |= (1<<STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                #endif
                break;

            case 1:
                #if(STEPPER_LIBRARY_IN_BYTE_CONTROL_MODE == YES)
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)) = (PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)) & ~((1<<STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT))))|((1<<STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT)));
                #elif(STEPPER_LIBRARY_IN_BIT_CONTROL_MODE == YES)
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_PLUS(INPUT_STEPPER_STRUCT)) &= ~(1<<STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_MINUS(INPUT_STEPPER_STRUCT)) |= (1<<STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_PLUS(INPUT_STEPPER_STRUCT)) &= ~(1<<STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_MINUS(INPUT_STEPPER_STRUCT)) |= (1<<STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                #endif
                break;

            case 2:
                #if(STEPPER_LIBRARY_IN_BYTE_CONTROL_MODE == YES)
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)) = (PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)) & ~((1<<STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT))))|((1<<STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT)));
                #elif(STEPPER_LIBRARY_IN_BIT_CONTROL_MODE == YES)
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_PLUS(INPUT_STEPPER_STRUCT)) |= (1<<STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_MINUS(INPUT_STEPPER_STRUCT)) |= (1<<STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_PLUS(INPUT_STEPPER_STRUCT)) &= ~(1<<STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_MINUS(INPUT_STEPPER_STRUCT)) |= (1<<STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                #endif
                break;

            case 3:
                #if(STEPPER_LIBRARY_IN_BYTE_CONTROL_MODE == YES)
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)) = (PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)) & ~((1<<STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT))))|((1<<STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT)));
                #elif(STEPPER_LIBRARY_IN_BIT_CONTROL_MODE == YES)
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_PLUS(INPUT_STEPPER_STRUCT)) |= (1<<STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_MINUS(INPUT_STEPPER_STRUCT)) &= ~(1<<STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_PLUS(INPUT_STEPPER_STRUCT)) &= ~(1<<STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_MINUS(INPUT_STEPPER_STRUCT)) |= (1<<STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                #endif
                break;

            case 4:
                #if(STEPPER_LIBRARY_IN_BYTE_CONTROL_MODE == YES)
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)) = (PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)) & ~((1<<STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT))))|((1<<STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT)));
                #elif(STEPPER_LIBRARY_IN_BIT_CONTROL_MODE == YES)
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_PLUS(INPUT_STEPPER_STRUCT)) |= (1<<STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_MINUS(INPUT_STEPPER_STRUCT)) &= ~(1<<STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_PLUS(INPUT_STEPPER_STRUCT)) |= (1<<STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_MINUS(INPUT_STEPPER_STRUCT)) |= (1<<STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                #endif
                break;

            case 5:
                #if(STEPPER_LIBRARY_IN_BYTE_CONTROL_MODE == YES)
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)) = (PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)) & ~((1<<STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT))))|((1<<STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT)));
                #elif(STEPPER_LIBRARY_IN_BIT_CONTROL_MODE == YES)
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_PLUS(INPUT_STEPPER_STRUCT)) |= (1<<STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_MINUS(INPUT_STEPPER_STRUCT)) &= ~(1<<STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_PLUS(INPUT_STEPPER_STRUCT)) |= (1<<STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_MINUS(INPUT_STEPPER_STRUCT)) &= ~(1<<STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                #endif
                break;

            case 6:
                #if(STEPPER_LIBRARY_IN_BYTE_CONTROL_MODE == YES)
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)) = (PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)) & ~((1<<STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT))))|((1<<STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT)));
                #elif(STEPPER_LIBRARY_IN_BIT_CONTROL_MODE == YES)
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_PLUS(INPUT_STEPPER_STRUCT)) |= (1<<STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_MINUS(INPUT_STEPPER_STRUCT)) |= (1<<STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_PLUS(INPUT_STEPPER_STRUCT)) |= (1<<STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_MINUS(INPUT_STEPPER_STRUCT)) &= ~(1<<STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                #endif
                break;

            case 7:
                #if(STEPPER_LIBRARY_IN_BYTE_CONTROL_MODE == YES)
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)) = (PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)) & ~((1<<STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT))))|((1<<STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT)));
                #elif(STEPPER_LIBRARY_IN_BIT_CONTROL_MODE == YES)
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_PLUS(INPUT_STEPPER_STRUCT)) &= ~(1<<STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_MINUS(INPUT_STEPPER_STRUCT)) |= (1<<STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_PLUS(INPUT_STEPPER_STRUCT)) |= (1<<STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_MINUS(INPUT_STEPPER_STRUCT)) &= ~(1<<STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                #endif
                break;
        }
    }
    #endif

    #if (STEPPER_UNIPOLAR_TYPE == YES)
    if(STEPPER_VALUE_OF_FLAG(INPUT_STEPPER_STRUCT) & (1<<7))
    {
        switch(STEPPER_VALUE_OF_NEXT_STEP(INPUT_STEPPER_STRUCT))
        {
            case 0:
                #if(STEPPER_LIBRARY_IN_BYTE_CONTROL_MODE == YES)
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)) = (PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)) & ~((1<<STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT))))|((1<<STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT)));
                #elif(STEPPER_LIBRARY_IN_BIT_CONTROL_MODE == YES)
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_PLUS(INPUT_STEPPER_STRUCT)) |= (1<<STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_MINUS(INPUT_STEPPER_STRUCT)) &= ~(1<<STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_PLUS(INPUT_STEPPER_STRUCT)) &= ~(1<<STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_MINUS(INPUT_STEPPER_STRUCT)) &= ~(1<<STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                #endif
                break;

            case 1:
                #if(STEPPER_LIBRARY_IN_BYTE_CONTROL_MODE == YES)
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)) = (PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)) & ~((1<<STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT))))|((1<<STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT)));
                #elif(STEPPER_LIBRARY_IN_BIT_CONTROL_MODE == YES)
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_PLUS(INPUT_STEPPER_STRUCT)) |= (1<<STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_MINUS(INPUT_STEPPER_STRUCT)) &= ~(1<<STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_PLUS(INPUT_STEPPER_STRUCT)) |= (1<<STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_MINUS(INPUT_STEPPER_STRUCT)) &= ~(1<<STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                #endif
                break;

            case 2:
                #if(STEPPER_LIBRARY_IN_BYTE_CONTROL_MODE == YES)
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)) = (PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)) & ~((1<<STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT))))|((1<<STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT)));
                #elif(STEPPER_LIBRARY_IN_BIT_CONTROL_MODE == YES)
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_PLUS(INPUT_STEPPER_STRUCT)) &= ~(1<<STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_MINUS(INPUT_STEPPER_STRUCT)) &= ~(1<<STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_PLUS(INPUT_STEPPER_STRUCT)) |= (1<<STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_MINUS(INPUT_STEPPER_STRUCT)) &= ~(1<<STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                #endif
                break;

            case 3:
                #if(STEPPER_LIBRARY_IN_BYTE_CONTROL_MODE == YES)
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)) = (PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)) & ~((1<<STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT))))|((1<<STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT)));
                #elif(STEPPER_LIBRARY_IN_BIT_CONTROL_MODE == YES)
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_PLUS(INPUT_STEPPER_STRUCT)) &= ~(1<<STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_MINUS(INPUT_STEPPER_STRUCT)) |= (1<<STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_PLUS(INPUT_STEPPER_STRUCT)) |= (1<<STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_MINUS(INPUT_STEPPER_STRUCT)) &= ~(1<<STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                #endif
                break;

            case 4:
                #if(STEPPER_LIBRARY_IN_BYTE_CONTROL_MODE == YES)
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)) = (PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)) & ~((1<<STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT))))|((1<<STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT)));
                #elif(STEPPER_LIBRARY_IN_BIT_CONTROL_MODE == YES)
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_PLUS(INPUT_STEPPER_STRUCT)) &= ~(1<<STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_MINUS(INPUT_STEPPER_STRUCT)) |= (1<<STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_PLUS(INPUT_STEPPER_STRUCT)) &= ~(1<<STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_MINUS(INPUT_STEPPER_STRUCT)) &= ~(1<<STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                #endif
                break;

            case 5:
                #if(STEPPER_LIBRARY_IN_BYTE_CONTROL_MODE == YES)
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)) = (PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)) & ~((1<<STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT))))|((1<<STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT)));
                #elif(STEPPER_LIBRARY_IN_BIT_CONTROL_MODE == YES)
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_PLUS(INPUT_STEPPER_STRUCT)) &= ~(1<<STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_MINUS(INPUT_STEPPER_STRUCT)) |= (1<<STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_PLUS(INPUT_STEPPER_STRUCT)) &= ~(1<<STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_MINUS(INPUT_STEPPER_STRUCT)) |= (1<<STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                #endif
                break;

            case 6:
                #if(STEPPER_LIBRARY_IN_BYTE_CONTROL_MODE == YES)
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)) = (PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)) & ~((1<<STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT))))|((1<<STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT)));
                #elif(STEPPER_LIBRARY_IN_BIT_CONTROL_MODE == YES)
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_PLUS(INPUT_STEPPER_STRUCT)) &= ~(1<<STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_MINUS(INPUT_STEPPER_STRUCT)) &= ~(1<<STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_PLUS(INPUT_STEPPER_STRUCT)) &= ~(1<<STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_MINUS(INPUT_STEPPER_STRUCT)) |= (1<<STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                #endif
                break;

            case 7:
                #if(STEPPER_LIBRARY_IN_BYTE_CONTROL_MODE == YES)
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)) = (PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(INPUT_STEPPER_STRUCT)) & ~((1<<STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT))))|((1<<STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT))|(1<<STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT)));
                #elif(STEPPER_LIBRARY_IN_BIT_CONTROL_MODE == YES)
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_PLUS(INPUT_STEPPER_STRUCT)) |= (1<<STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_MINUS(INPUT_STEPPER_STRUCT)) &= ~(1<<STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_PLUS(INPUT_STEPPER_STRUCT)) &= ~(1<<STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                PHYSICAL_REGISTER_ACCESS_8_BIT(STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_MINUS(INPUT_STEPPER_STRUCT)) |= (1<<STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(INPUT_STEPPER_STRUCT));
                #endif
                break;
        }
    }
    #endif
}
#endif

/******************************************************************************************************/

#if (USE_stepper_next_full_step_high_torque_cw==YES)
void stepper_next_full_step_high_torque_cw(STEPPER* INPUT_STEPPER_STRUCT)
{
    stepper_step(INPUT_STEPPER_STRUCT);
    STEPPER_VALUE_OF_FLAG(INPUT_STEPPER_STRUCT) += 2;

    if(STEPPER_VALUE_OF_NEXT_STEP(INPUT_STEPPER_STRUCT) == 8)
        STEPPER_VALUE_OF_FLAG(INPUT_STEPPER_STRUCT) &= (1<<7);
}
#endif

/******************************************************************************************************/

#if (USE_stepper_next_full_step_low_torque_cw==YES)
void stepper_next_full_step_low_torque_cw(STEPPER* INPUT_STEPPER_STRUCT)
{
    if(STEPPER_VALUE_OF_NEXT_STEP(INPUT_STEPPER_STRUCT) == 0)
    {
        STEPPER_VALUE_OF_FLAG(INPUT_STEPPER_STRUCT) = (STEPPER_VALUE_OF_FLAG(INPUT_STEPPER_STRUCT) & (1<<7))|(1<<0);
        //stepper_step(INPUT_STEPPER_STRUCT);
        //delay
    }

    stepper_step(INPUT_STEPPER_STRUCT);
    STEPPER_VALUE_OF_FLAG(INPUT_STEPPER_STRUCT) += 2;

    if(STEPPER_VALUE_OF_NEXT_STEP(INPUT_STEPPER_STRUCT) == 9)
        STEPPER_VALUE_OF_FLAG(INPUT_STEPPER_STRUCT) = (STEPPER_VALUE_OF_FLAG(INPUT_STEPPER_STRUCT) & (1<<7))|(1<<0);
}
#endif

/******************************************************************************************************/

#if (USE_stepper_next_half_step_cw==YES)
void stepper_next_half_step_cw(STEPPER* INPUT_STEPPER_STRUCT)
{
    stepper_step(INPUT_STEPPER_STRUCT);
    STEPPER_VALUE_OF_FLAG(INPUT_STEPPER_STRUCT) += 1;

    if(STEPPER_VALUE_OF_NEXT_STEP(INPUT_STEPPER_STRUCT) == 8)
        STEPPER_VALUE_OF_FLAG(INPUT_STEPPER_STRUCT) = (STEPPER_VALUE_OF_FLAG(INPUT_STEPPER_STRUCT) & (1<<7));
}
#endif

/******************************************************************************************************/

#if (USE_stepper_next_full_step_high_torque_ccw==YES)
void stepper_next_full_step_high_torque_ccw(STEPPER* INPUT_STEPPER_STRUCT)
{
    stepper_step(INPUT_STEPPER_STRUCT);
    STEPPER_VALUE_OF_FLAG(INPUT_STEPPER_STRUCT) -= 2;

    if(STEPPER_VALUE_OF_FLAG(INPUT_STEPPER_STRUCT) == 0xFE)
    {
        STEPPER_VALUE_OF_FLAG(INPUT_STEPPER_STRUCT) = ((1<<2)|(1<<1));
    }
    else if(STEPPER_VALUE_OF_FLAG(INPUT_STEPPER_STRUCT) == 0x7E)
    {
        STEPPER_VALUE_OF_FLAG(INPUT_STEPPER_STRUCT) = ((1<<7)|(1<<2)|(1<<1));
    }
}
#endif

/******************************************************************************************************/

#if (USE_stepper_next_full_step_low_torque_ccw==YES)
void stepper_next_full_step_low_torque_ccw(STEPPER* INPUT_STEPPER_STRUCT)
{
    if(STEPPER_VALUE_OF_NEXT_STEP(INPUT_STEPPER_STRUCT) == 0)
    {
        STEPPER_VALUE_OF_FLAG(INPUT_STEPPER_STRUCT) = (STEPPER_VALUE_OF_FLAG(INPUT_STEPPER_STRUCT) & ((1<<2)|(1<<1)|(1<<0)));
        //stepper_step(INPUT_STEPPER_STRUCT);
        //delay
    }

    stepper_step(INPUT_STEPPER_STRUCT);
    STEPPER_VALUE_OF_FLAG(INPUT_STEPPER_STRUCT) -= 2;

    if(STEPPER_VALUE_OF_FLAG(INPUT_STEPPER_STRUCT) == 0xFF)
    {
        STEPPER_VALUE_OF_FLAG(INPUT_STEPPER_STRUCT) = ((1<<2)|(1<<1)|(1<<0));
    }
    else if(STEPPER_VALUE_OF_FLAG(INPUT_STEPPER_STRUCT) == 0x7F)
    {
        STEPPER_VALUE_OF_FLAG(INPUT_STEPPER_STRUCT) = ((1<<7)|(1<<2)|(1<<1)|(1<<0));
    }
}
#endif

/******************************************************************************************************/

#if (USE_stepper_next_half_step_ccw==YES)
void stepper_next_half_step_ccw(STEPPER* INPUT_STEPPER_STRUCT)
{
    stepper_step(INPUT_STEPPER_STRUCT);
    STEPPER_VALUE_OF_FLAG(INPUT_STEPPER_STRUCT) -=1;

    if(STEPPER_VALUE_OF_FLAG(INPUT_STEPPER_STRUCT) == 0xFF)
    {
        STEPPER_VALUE_OF_FLAG(INPUT_STEPPER_STRUCT) = ((1<<2)|(1<<1)|(1<<0));
    }
    else if(STEPPER_VALUE_OF_FLAG(INPUT_STEPPER_STRUCT) == 0x7F) //unipolar
    {
        STEPPER_VALUE_OF_FLAG(INPUT_STEPPER_STRUCT) = ((1<<7)|(1<<2)|(1<<1)|(1<<0));
    }
}
#endif

/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
