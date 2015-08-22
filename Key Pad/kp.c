/************
check if the pullups of rows affect the system in interrupt mode
************/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
Author: Charlton Fernandes

kp.c

DESCRIPTION: Functions declared in kp.h defined here.
*/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/

#include <avr/io.h>
#include "kp.h"
//#include "cf.h"

#if (KP_INTERRUPT_BASED) //== YES
#include <avr/interrupt.h>
#endif

/******************************************************************************************************/

#if (KP_INTERRUPT_BASED) //== YES

unsigned char  kp_buffer[KP_BUFFER_SIZE],kp_in_p,kp_out_p,kp_buffer_count;

#endif

/******************************************************************************************************/

#if (USE_kp_init) //== YES

void kp_init(void)//Initialising function
{
    #if (KP_OPTIMIZATION) == 1

    #if (KP_INTERRUPT_BASED) //== YES

    {//Initialize column as output and row pins as input
    #if (KP_DDRA_VALUE_FINAL) !=0

    #if (KP_DDRA_VALUE_ROW_FINAL) == 0xFF
    DDRA = 0x00;
    #elif (KP_DDRA_VALUE_COLUMN_FINAL) == 0xFF
    DDRA = 0xFF;
    #elif (KP_DDRA_VALUE_FINAL_BIT_SUM) == 8
    DDRA = KP_DDRA_VALUE_COLUMN_FINAL;
    #else
    DDRA = (DDRA & ~(KP_DDRA_VALUE_ROW_FINAL))|(KP_DDRA_VALUE_COLUMN_FINAL);
    #endif

    #endif

    #if (KP_DDRB_VALUE_FINAL) !=0

    #if (KP_DDRB_VALUE_ROW_FINAL) == 0xFF
    DDRB = 0x00;
    #elif (KP_DDRB_VALUE_COLUMN_FINAL) == 0xFF
    DDRB = 0xFF;
    #elif (KP_DDRB_VALUE_FINAL_BIT_SUM) == 8
    DDRB = KP_DDRB_VALUE_COLUMN_FINAL;
    #else
    DDRB = (DDRB & ~(KP_DDRB_VALUE_ROW_FINAL))|(KP_DDRB_VALUE_COLUMN_FINAL);
    #endif

    #endif

    #if (KP_DDRC_VALUE_FINAL) !=0

    #if (KP_DDRC_VALUE_ROW_FINAL) == 0xFF
    DDRC = 0x00;
    #elif (KP_DDRC_VALUE_COLUMN_FINAL) == 0xFF
    DDRC = 0xFF;
    #elif (KP_DDRC_VALUE_FINAL_BIT_SUM) == 8
    DDRC = KP_DDRC_VALUE_COLUMN_FINAL;
    #else
    DDRC = (DDRC & ~(KP_DDRC_VALUE_ROW_FINAL))|(KP_DDRC_VALUE_COLUMN_FINAL);
    #endif

    #endif

    #if (KP_DDRD_VALUE_FINAL) !=0

    #if (KP_DDRD_VALUE_ROW_FINAL) == 0xFF
    DDRD = 0x00;
    #elif (KP_DDRD_VALUE_COLUMN_FINAL) == 0xFF
    DDRD = 0xFF;
    #elif (KP_DDRD_VALUE_FINAL_BIT_SUM) == 8
    DDRD = KP_DDRD_VALUE_COLUMN_FINAL;
    #else
    DDRD = (DDRD & ~(KP_DDRD_VALUE_ROW_FINAL))|(KP_DDRD_VALUE_COLUMN_FINAL);
    #endif

    #endif
    }

    #else

    {//Initialize column and row pins as input
    #if (KP_DDRA_VALUE_FINAL) !=0

    #if (KP_DDRA_VALUE_FINAL) == 0xFF
    DDRA = 0x00;
    #else
    DDRA &= ~ (KP_DDRA_VALUE_FINAL);
    #endif

    #endif

    #if (KP_DDRB_VALUE_FINAL) !=0

    #if (KP_DDRB_VALUE_FINAL) == 0xFF
    DDRB = 0x00;
    #else
    DDRB &= ~ (KP_DDRB_VALUE_FINAL);
    #endif

    #endif

    #if (KP_DDRC_VALUE_FINAL) !=0

    #if (KP_DDRC_VALUE_FINAL) == 0xFF
    DDRC = 0x00;
    #else
    DDRC &= ~ (KP_DDRC_VALUE_FINAL);
    #endif

    #endif

    #if (KP_DDRD_VALUE_FINAL) !=0

    #if (KP_DDRD_VALUE_FINAL) == 0xFF
    DDRD = 0x00;
    #else
    DDRD &= ~ (KP_DDRD_VALUE_FINAL);
    #endif

    #endif
    }

    #endif

    {//Set column pins as output low/pullup disable and row pins as output high/pullup enable
    #if (KP_DDRA_VALUE_FINAL) !=0

    #if (KP_DDRA_VALUE_ROW_FINAL) == 0xFF
    PORTA = 0xFF;
    #elif (KP_DDRA_VALUE_COLUMN_FINAL) == 0xFF
    PORTA = 0x00;
    #elif (KP_DDRA_VALUE_FINAL_BIT_SUM) == 8
    PORTA = KP_DDRA_VALUE_ROW_FINAL;
    #else
    PORTA = (PORTA & ~(KP_DDRA_VALUE_COLUMN_FINAL))|(KP_DDRA_VALUE_ROW_FINAL);
    #endif

    #endif

    #if (KP_DDRB_VALUE_FINAL) !=0

    #if (KP_DDRB_VALUE_ROW_FINAL) == 0xFF
    PORTB = 0xFF;
    #elif (KP_DDRB_VALUE_COLUMN_FINAL) == 0xFF
    PORTB = 0x00;
    #elif (KP_DDRB_VALUE_FINAL_BIT_SUM) == 8
    PORTB = KP_DDRB_VALUE_ROW_FINAL;
    #else
    PORTB = (PORTB & ~(KP_DDRB_VALUE_COLUMN_FINAL))|(KP_DDRB_VALUE_ROW_FINAL);
    #endif

    #endif

    #if (KP_DDRC_VALUE_FINAL) !=0

    #if (KP_DDRC_VALUE_ROW_FINAL) == 0xFF
    PORTC = 0xFF;
    #elif (KP_DDRC_VALUE_COLUMN_FINAL) == 0xFF
    PORTC = 0x00;
    #elif (KP_DDRC_VALUE_FINAL_BIT_SUM) == 8
    PORTC = KP_DDRC_VALUE_ROW_FINAL;
    #else
    PORTC = (PORTC & ~(KP_DDRC_VALUE_COLUMN_FINAL))|(KP_DDRC_VALUE_ROW_FINAL);
    #endif

    #endif

    #if (KP_DDRD_VALUE_FINAL) !=0

    #if (KP_DDRD_VALUE_ROW_FINAL) == 0xFF
    PORTD = 0xFF;
    #elif (KP_DDRD_VALUE_COLUMN_FINAL) == 0xFF
    PORTD = 0x00;
    #elif (KP_DDRD_VALUE_FINAL_BIT_SUM) == 8
    PORTD = KP_DDRD_VALUE_ROW_FINAL;
    #else
    PORTD = (PORTD & ~(KP_DDRD_VALUE_COLUMN_FINAL))|(KP_DDRD_VALUE_ROW_FINAL);
    #endif

    #endif

    }

    #elif (KP_OPTIMIZATION) == 2

    {//Row Initializations - DDR & PORT
        #if KP_MAX_ROW >= 1
        KP_DDR_ROW_0 &= ~((0x01)<< KP_ROW_0_GPIO_PIN);
        KP_PORT_ROW_0 |= ((0x01)<< KP_ROW_0_GPIO_PIN);
        #endif

        #if KP_MAX_ROW >= 2
        KP_DDR_ROW_1 &= ~((0x01)<< KP_ROW_1_GPIO_PIN);
        KP_PORT_ROW_1 |= ((0x01)<< KP_ROW_1_GPIO_PIN);
        #endif

        #if KP_MAX_ROW >= 3
        KP_DDR_ROW_2 &= ~((0x01)<< KP_ROW_2_GPIO_PIN);
        KP_PORT_ROW_2 |= ((0x01)<< KP_ROW_2_GPIO_PIN);
        #endif

        #if KP_MAX_ROW >= 4
        KP_DDR_ROW_3 &= ~((0x01)<< KP_ROW_3_GPIO_PIN);
        KP_PORT_ROW_3 |= ((0x01)<< KP_ROW_3_GPIO_PIN);
        #endif

        #if KP_MAX_ROW >= 5
        KP_DDR_ROW_4 &= ~((0x01)<< KP_ROW_4_GPIO_PIN);
        KP_PORT_ROW_4 |= ((0x01)<< KP_ROW_4_GPIO_PIN);
        #endif

        #if KP_MAX_ROW >= 6
        KP_DDR_ROW_5 &= ~((0x01)<< KP_ROW_5_GPIO_PIN);
        KP_PORT_ROW_5 |= ((0x01)<< KP_ROW_5_GPIO_PIN);
        #endif

        #if KP_MAX_ROW >= 7
        KP_DDR_ROW_6 &= ~((0x01)<< KP_ROW_6_GPIO_PIN);
        KP_PORT_ROW_6 |= ((0x01)<< KP_ROW_6_GPIO_PIN);
        #endif

        #if KP_MAX_ROW >= 8
        KP_DDR_ROW_7 &= ~((0x01)<< KP_ROW_7_GPIO_PIN);
        KP_PORT_ROW_7 |= ((0x01)<< KP_ROW_7_GPIO_PIN);
        #endif

        #if KP_MAX_ROW >= 9
        KP_DDR_ROW_8 &= ~((0x01)<< KP_ROW_8_GPIO_PIN);
        KP_PORT_ROW_8 |= ((0x01)<< KP_ROW_8_GPIO_PIN);
        #endif

        #if KP_MAX_ROW >= 10
        KP_DDR_ROW_9 &= ~((0x01)<< KP_ROW_9_GPIO_PIN);
        KP_PORT_ROW_9 |= ((0x01)<< KP_ROW_9_GPIO_PIN);
        #endif

        #if KP_MAX_ROW >= 11
        KP_DDR_ROW_10 &= ~((0x01)<< KP_ROW_10_GPIO_PIN);
        KP_PORT_ROW_10 |= ((0x01)<< KP_ROW_10_GPIO_PIN);
        #endif

        #if KP_MAX_ROW >= 12
        KP_DDR_ROW_11 &= ~((0x01)<< KP_ROW_11_GPIO_PIN);
        KP_PORT_ROW_11 |= ((0x01)<< KP_ROW_11_GPIO_PIN);
        #endif

        #if KP_MAX_ROW >= 13
        KP_DDR_ROW_12 &= ~((0x01)<< KP_ROW_12_GPIO_PIN);
        KP_PORT_ROW_12 |= ((0x01)<< KP_ROW_12_GPIO_PIN);
        #endif

        #if KP_MAX_ROW >= 14
        KP_DDR_ROW_13 &= ~((0x01)<< KP_ROW_13_GPIO_PIN);
        KP_PORT_ROW_13 |= ((0x01)<< KP_ROW_13_GPIO_PIN);
        #endif

        #if KP_MAX_ROW >= 15
        KP_DDR_ROW_14 &= ~((0x01)<< KP_ROW_14_GPIO_PIN);
        KP_PORT_ROW_14 |= ((0x01)<< KP_ROW_14_GPIO_PIN);
        #endif

        #if KP_MAX_ROW >= 16
        KP_DDR_ROW_15 &= ~((0x01)<< KP_ROW_15_GPIO_PIN);
        KP_PORT_ROW_15 |= ((0x01)<< KP_ROW_15_GPIO_PIN);
        #endif
    }

    #if (KP_INTERRUPT_BASED) //== YES

    {//Column Initializations - DDR & PORT (output & low)
        #if KP_MAX_COLUMN >= 1
        KP_DDR_COLUMN_0 |= ((0x01)<< KP_COLUMN_0_GPIO_PIN);
        KP_PORT_COLUMN_0 &= ~ ((0x01)<< KP_COLUMN_0_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 2
        KP_DDR_COLUMN_1 |= ((0x01)<< KP_COLUMN_1_GPIO_PIN);
        KP_PORT_COLUMN_1 &= ~ ((0x01)<< KP_COLUMN_1_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 3
        KP_DDR_COLUMN_2 |= ((0x01)<< KP_COLUMN_2_GPIO_PIN);
        KP_PORT_COLUMN_2 &= ~ ((0x01)<< KP_COLUMN_2_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 4
        KP_DDR_COLUMN_3 |= ((0x01)<< KP_COLUMN_3_GPIO_PIN);
        KP_PORT_COLUMN_3 &= ~ ((0x01)<< KP_COLUMN_3_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 5
        KP_DDR_COLUMN_4 |= ((0x01)<< KP_COLUMN_4_GPIO_PIN);
        KP_PORT_COLUMN_4 &= ~ ((0x01)<< KP_COLUMN_4_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 6
        KP_DDR_COLUMN_5 |= ((0x01)<< KP_COLUMN_5_GPIO_PIN);
        KP_PORT_COLUMN_5 &= ~ ((0x01)<< KP_COLUMN_5_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 7
        KP_DDR_COLUMN_6 |= ((0x01)<< KP_COLUMN_6_GPIO_PIN);
        KP_PORT_COLUMN_6 &= ~ ((0x01)<< KP_COLUMN_6_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 8
        KP_DDR_COLUMN_7 |= ((0x01)<< KP_COLUMN_7_GPIO_PIN);
        KP_PORT_COLUMN_7 &= ~ ((0x01)<< KP_COLUMN_7_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 9
        KP_DDR_COLUMN_8 |= ((0x01)<< KP_COLUMN_8_GPIO_PIN);
        KP_PORT_COLUMN_8 &= ~ ((0x01)<< KP_COLUMN_8_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 10
        KP_DDR_COLUMN_9 |= ((0x01)<< KP_COLUMN_9_GPIO_PIN);
        KP_PORT_COLUMN_9 &= ~ ((0x01)<< KP_COLUMN_9_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 11
        KP_DDR_COLUMN_10 |= ((0x01)<< KP_COLUMN_10_GPIO_PIN);
        KP_PORT_COLUMN_10 &= ~ ((0x01)<< KP_COLUMN_10_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 12
        KP_DDR_COLUMN_11 |= ((0x01)<< KP_COLUMN_11_GPIO_PIN);
        KP_PORT_COLUMN_11 &= ~ ((0x01)<< KP_COLUMN_11_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 13
        KP_DDR_COLUMN_12 |= ((0x01)<< KP_COLUMN_12_GPIO_PIN);
        KP_PORT_COLUMN_12 &= ~ ((0x01)<< KP_COLUMN_12_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 14
        KP_DDR_COLUMN_13 |= ((0x01)<< KP_COLUMN_13_GPIO_PIN);
        KP_PORT_COLUMN_13 &= ~ ((0x01)<< KP_COLUMN_13_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 15
        KP_DDR_COLUMN_14 |= ((0x01)<< KP_COLUMN_14_GPIO_PIN);
        KP_PORT_COLUMN_14 &= ~ ((0x01)<< KP_COLUMN_14_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 16
        KP_DDR_COLUMN_15 |= ((0x01)<< KP_COLUMN_15_GPIO_PIN);
        KP_PORT_COLUMN_15 &= ~ ((0x01)<< KP_COLUMN_15_GPIO_PIN);
        #endif
    }

    #else

    {//Column Initializations - DDR & PORT (input & low)
        #if KP_MAX_COLUMN >= 1
        KP_DDR_COLUMN_0 &= ~((0x01)<< KP_COLUMN_0_GPIO_PIN);
        KP_PORT_COLUMN_0 &= ~ ((0x01)<< KP_COLUMN_0_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 2
        KP_DDR_COLUMN_1 &= ~((0x01)<< KP_COLUMN_1_GPIO_PIN);
        KP_PORT_COLUMN_1 &= ~ ((0x01)<< KP_COLUMN_1_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 3
        KP_DDR_COLUMN_2 &= ~((0x01)<< KP_COLUMN_2_GPIO_PIN);
        KP_PORT_COLUMN_2 &= ~ ((0x01)<< KP_COLUMN_2_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 4
        KP_DDR_COLUMN_3 &= ~((0x01)<< KP_COLUMN_3_GPIO_PIN);
        KP_PORT_COLUMN_3 &= ~ ((0x01)<< KP_COLUMN_3_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 5
        KP_DDR_COLUMN_4 &= ~((0x01)<< KP_COLUMN_4_GPIO_PIN);
        KP_PORT_COLUMN_4 &= ~ ((0x01)<< KP_COLUMN_4_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 6
        KP_DDR_COLUMN_5 &= ~((0x01)<< KP_COLUMN_5_GPIO_PIN);
        KP_PORT_COLUMN_5 &= ~ ((0x01)<< KP_COLUMN_5_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 7
        KP_DDR_COLUMN_6 &= ~((0x01)<< KP_COLUMN_6_GPIO_PIN);
        KP_PORT_COLUMN_6 &= ~ ((0x01)<< KP_COLUMN_6_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 8
        KP_DDR_COLUMN_7 &= ~((0x01)<< KP_COLUMN_7_GPIO_PIN);
        KP_PORT_COLUMN_7 &= ~ ((0x01)<< KP_COLUMN_7_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 9
        KP_DDR_COLUMN_8 &= ~((0x01)<< KP_COLUMN_8_GPIO_PIN);
        KP_PORT_COLUMN_8 &= ~ ((0x01)<< KP_COLUMN_8_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 10
        KP_DDR_COLUMN_9 &= ~((0x01)<< KP_COLUMN_9_GPIO_PIN);
        KP_PORT_COLUMN_9 &= ~ ((0x01)<< KP_COLUMN_9_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 11
        KP_DDR_COLUMN_10 &= ~((0x01)<< KP_COLUMN_10_GPIO_PIN);
        KP_PORT_COLUMN_10 &= ~ ((0x01)<< KP_COLUMN_10_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 12
        KP_DDR_COLUMN_11 &= ~((0x01)<< KP_COLUMN_11_GPIO_PIN);
        KP_PORT_COLUMN_11 &= ~ ((0x01)<< KP_COLUMN_11_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 13
        KP_DDR_COLUMN_12 &= ~((0x01)<< KP_COLUMN_12_GPIO_PIN);
        KP_PORT_COLUMN_12 &= ~ ((0x01)<< KP_COLUMN_12_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 14
        KP_DDR_COLUMN_13 &= ~((0x01)<< KP_COLUMN_13_GPIO_PIN);
        KP_PORT_COLUMN_13 &= ~ ((0x01)<< KP_COLUMN_13_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 15
        KP_DDR_COLUMN_14 &= ~((0x01)<< KP_COLUMN_14_GPIO_PIN);
        KP_PORT_COLUMN_14 &= ~ ((0x01)<< KP_COLUMN_14_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 16
        KP_DDR_COLUMN_15 &= ~((0x01)<< KP_COLUMN_15_GPIO_PIN);
        KP_PORT_COLUMN_15 &= ~ ((0x01)<< KP_COLUMN_15_GPIO_PIN);
        #endif
    }

    #endif

    #endif

    #if (KP_INTERRUPT_BASED) //== YES

    kp_in_p=kp_out_p=0;
    kp_buffer_count=0;
    KP_DDR_INTERRUPT &= ~(1<<KP_INTERRUPT_GPIO_PIN);
    KP_PORT_INTERRUPT |= (1<<KP_INTERRUPT_GPIO_PIN);
    KP_ISR_FALLING
    KP_ISR_ENABLE
    sei();

    #endif

}

#endif

/******************************************************************************************************/

#if (KP_INTERRUPT_BASED) //== YES

/******************************************************************************************************/

ISR(KP_ISR_VECTOR)
{
    #if (KP_OPTIMIZATION_FOR_INTERRUPT) == 1

    {//Column DDR Initializations - Set column pins as input
    #if (KP_DDRA_VALUE_COLUMN_FINAL) != 0

    #if (KP_DDRA_VALUE_COLUMN_FINAL) == 0xFF
    DDRA = 0x00;
    #else
    DDRA &= ~ (KP_DDRA_VALUE_COLUMN_FINAL);
    #endif

    #endif

    #if (KP_DDRB_VALUE_COLUMN_FINAL) != 0

    #if (KP_DDRB_VALUE_COLUMN_FINAL) == 0xFF
    DDRB = 0x00;
    #else
    DDRB &= ~ (KP_DDRB_VALUE_COLUMN_FINAL);
    #endif

    #endif

    #if (KP_DDRC_VALUE_COLUMN_FINAL) != 0

    #if (KP_DDRC_VALUE_COLUMN_FINAL) == 0xFF
    DDRC = 0x00;
    #else
    DDRC &= ~ (KP_DDRC_VALUE_COLUMN_FINAL);
    #endif

    #endif

    #if (KP_DDRD_VALUE_COLUMN_FINAL) != 0

    #if (KP_DDRD_VALUE_COLUMN_FINAL) == 0xFF
    DDRD = 0x00;
    #else
    DDRD &= ~ (KP_DDRD_VALUE_COLUMN_FINAL);
    #endif

    #endif

    }

    #elif (KP_OPTIMIZATION_FOR_INTERRUPT) == 2

    {//Column DDR Initializations - Set column pins as input
        #if KP_MAX_COLUMN >= 1
        KP_DDR_COLUMN_0 &= ~ ((0x01)<< KP_COLUMN_0_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 2
        KP_DDR_COLUMN_1 &= ~ ((0x01)<< KP_COLUMN_1_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 3
        KP_DDR_COLUMN_2 &= ~ ((0x01)<< KP_COLUMN_2_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 4
        KP_DDR_COLUMN_3 &= ~ ((0x01)<< KP_COLUMN_3_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 5
        KP_DDR_COLUMN_4 &= ~ ((0x01)<< KP_COLUMN_4_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 6
        KP_DDR_COLUMN_5 &= ~ ((0x01)<< KP_COLUMN_5_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 7
        KP_DDR_COLUMN_6 &= ~ ((0x01)<< KP_COLUMN_6_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 8
        KP_DDR_COLUMN_7 &= ~ ((0x01)<< KP_COLUMN_7_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 9
        KP_DDR_COLUMN_8 &= ~ ((0x01)<< KP_COLUMN_8_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 10
        KP_DDR_COLUMN_9 &= ~ ((0x01)<< KP_COLUMN_9_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 11
        KP_DDR_COLUMN_10 &= ~ ((0x01)<< KP_COLUMN_10_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 12
        KP_DDR_COLUMN_11 &= ~ ((0x01)<< KP_COLUMN_11_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 13
        KP_DDR_COLUMN_12 &= ~ ((0x01)<< KP_COLUMN_12_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 14
        KP_DDR_COLUMN_13 &= ~ ((0x01)<< KP_COLUMN_13_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 15
        KP_DDR_COLUMN_14 &= ~ ((0x01)<< KP_COLUMN_14_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 16
        KP_DDR_COLUMN_15 &= ~ ((0x01)<< KP_COLUMN_15_GPIO_PIN);
        #endif
    }

    #endif

    kp_putdata(kp_read());

    #if (KP_OPTIMIZATION_FOR_INTERRUPT) == 1

    {//Column DDR Initializations - Set column pins as input
    #if (KP_DDRA_VALUE_COLUMN_FINAL) != 0

    #if (KP_DDRA_VALUE_COLUMN_FINAL) == 0xFF
    DDRA = 0xFF;
    #else
    DDRA |=  (KP_DDRA_VALUE_COLUMN_FINAL);
    #endif

    #endif

    #if (KP_DDRB_VALUE_COLUMN_FINAL) != 0

    #if (KP_DDRB_VALUE_COLUMN_FINAL) == 0xFF
    DDRB = 0xFF;
    #else
    DDRB |=  (KP_DDRB_VALUE_COLUMN_FINAL);
    #endif

    #endif

    #if (KP_DDRC_VALUE_COLUMN_FINAL) != 0

    #if (KP_DDRC_VALUE_COLUMN_FINAL) == 0xFF
    DDRC = 0xFF;
    #else
    DDRC |=  (KP_DDRC_VALUE_COLUMN_FINAL);
    #endif

    #endif

    #if (KP_DDRD_VALUE_COLUMN_FINAL) != 0

    #if (KP_DDRD_VALUE_COLUMN_FINAL) == 0xFF
    DDRD = 0xFF;
    #else
    DDRD |=  (KP_DDRD_VALUE_COLUMN_FINAL);
    #endif

    #endif

    }

    #elif (KP_OPTIMIZATION_FOR_INTERRUPT) == 2

    {//Column DDR Initializations - Set column pins as input
        #if KP_MAX_COLUMN >= 1
        KP_DDR_COLUMN_0 |= ((0x01)<< KP_COLUMN_0_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 2
        KP_DDR_COLUMN_1 |= ((0x01)<< KP_COLUMN_1_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 3
        KP_DDR_COLUMN_2 |= ((0x01)<< KP_COLUMN_2_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 4
        KP_DDR_COLUMN_3 |= ((0x01)<< KP_COLUMN_3_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 5
        KP_DDR_COLUMN_4 |= ((0x01)<< KP_COLUMN_4_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 6
        KP_DDR_COLUMN_5 |= ((0x01)<< KP_COLUMN_5_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 7
        KP_DDR_COLUMN_6 |= ((0x01)<< KP_COLUMN_6_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 8
        KP_DDR_COLUMN_7 |= ((0x01)<< KP_COLUMN_7_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 9
        KP_DDR_COLUMN_8 |= ((0x01)<< KP_COLUMN_8_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 10
        KP_DDR_COLUMN_9 |= ((0x01)<< KP_COLUMN_9_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 11
        KP_DDR_COLUMN_10 |= ((0x01)<< KP_COLUMN_10_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 12
        KP_DDR_COLUMN_11 |= ((0x01)<< KP_COLUMN_11_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 13
        KP_DDR_COLUMN_12 |= ((0x01)<< KP_COLUMN_12_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 14
        KP_DDR_COLUMN_13 |= ((0x01)<< KP_COLUMN_13_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 15
        KP_DDR_COLUMN_14 |= ((0x01)<< KP_COLUMN_14_GPIO_PIN);
        #endif

        #if KP_MAX_COLUMN >= 16
        KP_DDR_COLUMN_15 |= ((0x01)<< KP_COLUMN_15_GPIO_PIN);
        #endif
    }

    #endif

}

/******************************************************************************************************/

#if (USE_kp_putdata) //== YES

void kp_putdata(unsigned char value)//Put data in circular queue
{
    if (kp_buffer_count<KP_BUFFER_SIZE)
    {
        kp_buffer[kp_in_p]=value;
        kp_in_p++;
        kp_buffer_count++;

        if (kp_in_p >=KP_BUFFER_SIZE)
        kp_in_p =0;
    }
}

#endif

/******************************************************************************************************/

#if (USE_kp_getdata) //== YES

unsigned char kp_getdata(void)//Get data from circular queue
{
    unsigned char data;

    if(kp_buffer_count == 0)
        return 0xFF; //Default value when no key pressed

    data =kp_buffer[kp_out_p];
    kp_out_p++;

    if (kp_out_p >=KP_BUFFER_SIZE)
        kp_out_p =0;

    kp_buffer_count--;

    return data;
}

#endif

/******************************************************************************************************/

#endif

/******************************************************************************************************/

#if (USE_kp_read) //== YES

uint8_t kp_read(void)//Call this function to read which key is press at that instance
{
    uint8_t row,column;

      for(column=0;column<KP_MAX_COLUMN;column++)
      {
          kp_setpin(column);

         for(row=0;row<KP_MAX_ROW;row++)
         {
            if(!(kp_checkpin(row)))
            {
                kp_resetpin(column);
                return (row*KP_MAX_COLUMN+column);
            }
         }

         kp_resetpin(column);
      }
	  return 0xFF;//Default value when no key pressed

}

#endif

/******************************************************************************************************/

#if (USE_kp_checkpin) //== YES

unsigned char kp_checkpin(unsigned char x)//Checks the status of the row pin
{
	#if KP_MAX_ROW >= 1
	if(x==0)
        return ((KP_PIN_ROW_0)&(1<<(KP_ROW_0_GPIO_PIN)));
	#endif

	#if KP_MAX_ROW >= 2
	if(x==1)
        return ((KP_PIN_ROW_1)&(1<<(KP_ROW_1_GPIO_PIN)));
    #endif

	#if KP_MAX_ROW >= 3
	if(x==2)
        return ((KP_PIN_ROW_2)&(1<<(KP_ROW_2_GPIO_PIN)));
    #endif

	#if KP_MAX_ROW >= 4
	if(x==3)
        return ((KP_PIN_ROW_3)&(1<<(KP_ROW_3_GPIO_PIN)));
    #endif

	#if KP_MAX_ROW >= 5
	if(x==4)
        return ((KP_PIN_ROW_4)&(1<<(KP_ROW_4_GPIO_PIN)));
    #endif

	#if KP_MAX_ROW >= 6
	if(x==5)
        return ((KP_PIN_ROW_5)&(1<<(KP_ROW_5_GPIO_PIN)));
    #endif

	#if KP_MAX_ROW >= 7
	if(x==6)
        return ((KP_PIN_ROW_6)&(1<<(KP_ROW_6_GPIO_PIN)));
    #endif

	#if KP_MAX_ROW >= 8
	if(x==7)
        return ((KP_PIN_ROW_7)&(1<<(KP_ROW_7_GPIO_PIN)));
    #endif

	#if KP_MAX_ROW >= 9
	if(x==8)
        return ((KP_PIN_ROW_8)&(1<<(KP_ROW_8_GPIO_PIN)));
    #endif

	#if KP_MAX_ROW >= 10
	if(x==9)
        return ((KP_PIN_ROW_9)&(1<<(KP_ROW_9_GPIO_PIN)));
    #endif

	#if KP_MAX_ROW >= 11
	if(x==10)
        return ((KP_PIN_ROW_10)&(1<<(KP_ROW_10_GPIO_PIN)));
    #endif

	#if KP_MAX_ROW >= 12
	if(x==11)
        return ((KP_PIN_ROW_11)&(1<<(KP_ROW_11_GPIO_PIN)));
    #endif

	#if KP_MAX_ROW >= 13
	if(x==12)
        return ((KP_PIN_ROW_12)&(1<<(KP_ROW_12_GPIO_PIN)));
    #endif

	#if KP_MAX_ROW >= 14
	if(x==13)
        return ((KP_PIN_ROW_13)&(1<<(KP_ROW_13_GPIO_PIN)));
    #endif

	#if KP_MAX_ROW >= 15
	if(x==14)
        return ((KP_PIN_ROW_14)&(1<<(KP_ROW_14_GPIO_PIN)));
    #endif

	#if KP_MAX_ROW >= 16
	if(x==15)
        return ((KP_PIN_ROW_15)&(1<<(KP_ROW_15_GPIO_PIN)));
    #endif

	return 0;

}

#endif

/******************************************************************************************************/

#if (USE_kp_setpin) //== YES

void kp_setpin(unsigned char x)//set column pin as output low
{
    #if KP_MAX_COLUMN >= 1
	if(x==0)
        KP_DDR_COLUMN_0 |= ((0x01)<< KP_COLUMN_0_GPIO_PIN);
	#endif

	#if KP_MAX_COLUMN >= 2
	if(x==1)
        KP_DDR_COLUMN_1 |= ((0x01)<< KP_COLUMN_1_GPIO_PIN);
    #endif

	#if KP_MAX_COLUMN >= 3
	if(x==2)
        KP_DDR_COLUMN_2 |= ((0x01)<< KP_COLUMN_2_GPIO_PIN);
    #endif

	#if KP_MAX_COLUMN >= 4
	if(x==3)
        KP_DDR_COLUMN_3 |= ((0x01)<< KP_COLUMN_3_GPIO_PIN);
    #endif

	#if KP_MAX_COLUMN >= 5
	if(x==4)
        KP_DDR_COLUMN_4 |= ((0x01)<< KP_COLUMN_4_GPIO_PIN);
    #endif

	#if KP_MAX_COLUMN >= 6
	if(x==5)
        KP_DDR_COLUMN_5 |= ((0x01)<< KP_COLUMN_5_GPIO_PIN);
    #endif

	#if KP_MAX_COLUMN >= 7
	if(x==6)
        KP_DDR_COLUMN_6 |= ((0x01)<< KP_COLUMN_6_GPIO_PIN);
    #endif

	#if KP_MAX_COLUMN >= 8
	if(x==7)
        KP_DDR_COLUMN_7 |= ((0x01)<< KP_COLUMN_7_GPIO_PIN);
    #endif

	#if KP_MAX_COLUMN >= 9
	if(x==8)
        KP_DDR_COLUMN_8 |= ((0x01)<< KP_COLUMN_8_GPIO_PIN);
    #endif

	#if KP_MAX_COLUMN >= 10
	if(x==9)
        KP_DDR_COLUMN_9 |= ((0x01)<< KP_COLUMN_9_GPIO_PIN);
    #endif

	#if KP_MAX_COLUMN >= 11
	if(x==10)
        KP_DDR_COLUMN_10 |= ((0x01)<< KP_COLUMN_10_GPIO_PIN);
    #endif

	#if KP_MAX_COLUMN >= 12
	if(x==11)
        KP_DDR_COLUMN_11 |= ((0x01)<< KP_COLUMN_11_GPIO_PIN);
    #endif

	#if KP_MAX_COLUMN >= 13
	if(x==12)
        KP_DDR_COLUMN_12 |= ((0x01)<< KP_COLUMN_12_GPIO_PIN);
    #endif

	#if KP_MAX_COLUMN >= 14
	if(x==13)
        KP_DDR_COLUMN_13 |= ((0x01)<< KP_COLUMN_13_GPIO_PIN);
    #endif

	#if KP_MAX_COLUMN >= 15
	if(x==14)
        KP_DDR_COLUMN_14 |= ((0x01)<< KP_COLUMN_14_GPIO_PIN);
    #endif

	#if KP_MAX_COLUMN >= 16
	if(x==15)
        KP_DDR_COLUMN_15 |= ((0x01)<< KP_COLUMN_15_GPIO_PIN);
    #endif

}

#endif

/******************************************************************************************************/

#if (USE_kp_resetpin) //== YES

void kp_resetpin(unsigned char x)//reset column pin as input/tri-stated
{
    #if KP_MAX_COLUMN >= 1
	if(x==0)
        KP_DDR_COLUMN_0 &= !((0x01)<< KP_COLUMN_0_GPIO_PIN);
	#endif

	#if KP_MAX_COLUMN >= 2
	if(x==1)
        KP_DDR_COLUMN_1 &= !((0x01)<< KP_COLUMN_1_GPIO_PIN);
    #endif

	#if KP_MAX_COLUMN >= 3
	if(x==2)
        KP_DDR_COLUMN_2 &= !((0x01)<< KP_COLUMN_2_GPIO_PIN);
    #endif

	#if KP_MAX_COLUMN >= 4
	if(x==3)
        KP_DDR_COLUMN_3 &= !((0x01)<< KP_COLUMN_3_GPIO_PIN);
    #endif

	#if KP_MAX_COLUMN >= 5
	if(x==4)
        KP_DDR_COLUMN_4 &= !((0x01)<< KP_COLUMN_4_GPIO_PIN);
    #endif

	#if KP_MAX_COLUMN >= 6
	if(x==5)
        KP_DDR_COLUMN_5 &= !((0x01)<< KP_COLUMN_5_GPIO_PIN);
    #endif

	#if KP_MAX_COLUMN >= 7
	if(x==6)
        KP_DDR_COLUMN_6 &= !((0x01)<< KP_COLUMN_6_GPIO_PIN);
    #endif

	#if KP_MAX_COLUMN >= 8
	if(x==7)
        KP_DDR_COLUMN_7 &= !((0x01)<< KP_COLUMN_7_GPIO_PIN);
    #endif

	#if KP_MAX_COLUMN >= 9
	if(x==8)
        KP_DDR_COLUMN_8 &= !((0x01)<< KP_COLUMN_8_GPIO_PIN);
    #endif

	#if KP_MAX_COLUMN >= 10
	if(x==9)
        KP_DDR_COLUMN_9 &= !((0x01)<< KP_COLUMN_9_GPIO_PIN);
    #endif

	#if KP_MAX_COLUMN >= 11
	if(x==10)
        KP_DDR_COLUMN_10 &= !((0x01)<< KP_COLUMN_10_GPIO_PIN);
    #endif

	#if KP_MAX_COLUMN >= 12
	if(x==11)
        KP_DDR_COLUMN_11 &= !((0x01)<< KP_COLUMN_11_GPIO_PIN);
    #endif

	#if KP_MAX_COLUMN >= 13
	if(x==12)
        KP_DDR_COLUMN_12 &= !((0x01)<< KP_COLUMN_12_GPIO_PIN);
    #endif

	#if KP_MAX_COLUMN >= 14
	if(x==13)
        KP_DDR_COLUMN_13 &= !((0x01)<< KP_COLUMN_13_GPIO_PIN);
    #endif

	#if KP_MAX_COLUMN >= 15
	if(x==14)
        KP_DDR_COLUMN_14 &= !((0x01)<< KP_COLUMN_14_GPIO_PIN);
    #endif

	#if KP_MAX_COLUMN >= 16
	if(x==15)
        KP_DDR_COLUMN_15 &= !((0x01)<< KP_COLUMN_15_GPIO_PIN);
    #endif

}

#endif

/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
