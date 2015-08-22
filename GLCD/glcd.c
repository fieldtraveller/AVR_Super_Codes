/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
AUTHOR: CHARLTON FERNANDES

glcd.c

FOR MORE INFORMATION CHECK glcd.h
*/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/

#include "glcd.h"

/******************************************************************************************************/
//GLOBAL VARIABLES
/******************************************************************************************************/

unsigned char glcd_global_x,glcd_global_y,glcd_global_page;

/******************************************************************************************************/

#if (USE_glcd_init == YES)
void glcd_init(void)    //INITIALIZISES THE GLCD
{
	glcd_global_x = 0;
	glcd_global_y = 0;
	glcd_global_page = 0;

	#ifdef GLCD_LIBRARY_IN_BYTE_CONTROL_MODE
	{
	    #if (defined(GLCD_CONTROL_LED) && defined(GLCD_USE_RST))
        GLCD_DDR_CONTROL_ALL |= ((1<<GLCD_CONTROL_RS_GPIO_PIN)|(1<<GLCD_CONTROL_RW_GPIO_PIN)|(1<<GLCD_CONTROL_EN_GPIO_PIN)
                                 |(1<<GLCD_CONTROL_CS1_GPIO_PIN)|(1<<GLCD_CONTROL_CS2_GPIO_PIN)
                                 |(1<<GLCD_CONTROL_RST_GPIO_PIN)|(1<<GLCD_CONTROL_LED_GPIO_PIN));
        #elif defined(GLCD_CONTROL_LED)
        GLCD_DDR_CONTROL_ALL |= ((1<<GLCD_CONTROL_RS_GPIO_PIN)|(1<<GLCD_CONTROL_RW_GPIO_PIN)|(1<<GLCD_CONTROL_EN_GPIO_PIN)
                                 |(1<<GLCD_CONTROL_CS1_GPIO_PIN)|(1<<GLCD_CONTROL_CS2_GPIO_PIN)
                                 |(1<<GLCD_CONTROL_LED_GPIO_PIN));
        #elif defined(GLCD_USE_RST)
        GLCD_DDR_CONTROL_ALL |= ((1<<GLCD_CONTROL_RS_GPIO_PIN)|(1<<GLCD_CONTROL_RW_GPIO_PIN)|(1<<GLCD_CONTROL_EN_GPIO_PIN)
                                 |(1<<GLCD_CONTROL_CS1_GPIO_PIN)|(1<<GLCD_CONTROL_CS2_GPIO_PIN)
                                 |(1<<GLCD_CONTROL_LED_GPIO_PIN));
        #else
        GLCD_DDR_CONTROL_ALL |= ((1<<GLCD_CONTROL_RS_GPIO_PIN)|(1<<GLCD_CONTROL_RW_GPIO_PIN)|(1<<GLCD_CONTROL_EN_GPIO_PIN)
                                 |(1<<GLCD_CONTROL_CS1_GPIO_PIN)|(1<<GLCD_CONTROL_CS2_GPIO_PIN));
        #endif
	}
    #else
    {
        #if (defined(GLCD_CONTROL_LED) && defined(GLCD_USE_RST))
        GLCD_DDR_CONTROL_RS  |= (1<<GLCD_CONTROL_RS_GPIO_PIN);
        GLCD_DDR_CONTROL_RS  |= (1<<GLCD_CONTROL_RW_GPIO_PIN);
        GLCD_DDR_CONTROL_EN  |=(1<<GLCD_CONTROL_EN_GPIO_PIN);
        GLCD_DDR_CONTROL_CS1 |=(1<<GLCD_CONTROL_CS1_GPIO_PIN);
        GLCD_DDR_CONTROL_CS2 |=(1<<GLCD_CONTROL_CS2_GPIO_PIN);

        GLCD_DDR_CONTROL_RST |=(1<<GLCD_CONTROL_RST_GPIO_PIN);
        GLCD_DDR_CONTROL_LED |=(1<<GLCD_CONTROL_LED_GPIO_PIN);

        #elif defined(GLCD_CONTROL_LED)
        GLCD_DDR_CONTROL_RS  |= (1<<GLCD_CONTROL_RS_GPIO_PIN);
        GLCD_DDR_CONTROL_RS  |= (1<<GLCD_CONTROL_RW_GPIO_PIN);
        GLCD_DDR_CONTROL_EN  |=(1<<GLCD_CONTROL_EN_GPIO_PIN);
        GLCD_DDR_CONTROL_CS1 |=(1<<GLCD_CONTROL_CS1_GPIO_PIN);
        GLCD_DDR_CONTROL_CS2 |=(1<<GLCD_CONTROL_CS2_GPIO_PIN);

        GLCD_DDR_CONTROL_LED |=(1<<GLCD_CONTROL_LED_GPIO_PIN);

        #elif defined(GLCD_USE_RST)
        GLCD_DDR_CONTROL_RS  |= (1<<GLCD_CONTROL_RS_GPIO_PIN);
        GLCD_DDR_CONTROL_RS  |= (1<<GLCD_CONTROL_RW_GPIO_PIN);
        GLCD_DDR_CONTROL_EN  |=(1<<GLCD_CONTROL_EN_GPIO_PIN);
        GLCD_DDR_CONTROL_CS1 |=(1<<GLCD_CONTROL_CS1_GPIO_PIN);
        GLCD_DDR_CONTROL_CS2 |=(1<<GLCD_CONTROL_CS2_GPIO_PIN);

        GLCD_DDR_CONTROL_RST |=(1<<GLCD_CONTROL_RST_GPIO_PIN);

        #else
        GLCD_DDR_CONTROL_RS  |= (1<<GLCD_CONTROL_RS_GPIO_PIN);
        GLCD_DDR_CONTROL_RS  |= (1<<GLCD_CONTROL_RW_GPIO_PIN);
        GLCD_DDR_CONTROL_EN  |=(1<<GLCD_CONTROL_EN_GPIO_PIN);
        GLCD_DDR_CONTROL_CS1 |=(1<<GLCD_CONTROL_CS1_GPIO_PIN);
        GLCD_DDR_CONTROL_CS2 |=(1<<GLCD_CONTROL_CS2_GPIO_PIN);

        #endif
    }

    #endif

    glcd_cmd(GLCD_TURN_ON_DISPLAY, GLCD_CHIP1_SELECT);  //GLCD POWER ON
	glcd_cmd(GLCD_TURN_ON_DISPLAY, GLCD_CHIP2_SELECT);

	glcd_cmd(GLCD_DISPLAY_START_LINE, GLCD_CHIP1_SELECT);   //START DISPLAYING FROM LINE 0
	glcd_cmd(GLCD_DISPLAY_START_LINE, GLCD_CHIP2_SELECT);
	glcd_clear();
	glcd_gotoxy(0,0);   //START FROM (0,0)
}
#endif

/******************************************************************************************************/

#if (USE_glcd_enable == YES)
void glcd_enable(void)   //ENABLE PULSE
{
	GLCD_PORT_CONTROL_EN |= (0x01 << GLCD_CONTROL_EN_GPIO_PIN);
	GLCD_DELAY_US(1);   //MIN:450ns
	GLCD_PORT_CONTROL_EN &= ~(0x01 << GLCD_CONTROL_EN_GPIO_PIN);
	GLCD_DELAY_US(6);   //ALTERNATIVE TO READING STATUS
}
#endif

/******************************************************************************************************/

#if (USE_glcd_cmd ==YES)
void glcd_cmd(unsigned char command, unsigned char chip_select) //SEND COMMANDS/INSTRUCTIONS
{
	if(chip_select == GLCD_CHIP1_SELECT)
	{
	    #ifdef GLCD_LIBRARY_IN_BYTE_CONTROL_MODE
		{
		    GLCD_PORT_CONTROL_ALL = (GLCD_PORT_CONTROL_ALL | (0x01 << GLCD_CONTROL_CS1_GPIO_PIN)) & ~((0x01 << GLCD_CONTROL_CS2_GPIO_PIN)|(0x01 << GLCD_CONTROL_RS_GPIO_PIN)|(0x01 << GLCD_CONTROL_RW_GPIO_PIN));
   		}
		#else
		{
		    GLCD_PORT_CONTROL_CS2 &= ~(0x01 << GLCD_CONTROL_CS2_GPIO_PIN);
            GLCD_PORT_CONTROL_CS1 |=  (0x01 << GLCD_CONTROL_CS1_GPIO_PIN);
            GLCD_PORT_CONTROL_RS &= ~(0x01 << GLCD_CONTROL_RS_GPIO_PIN);   //RS = 0
            GLCD_PORT_CONTROL_RW &= ~(0x01 << GLCD_CONTROL_RW_GPIO_PIN);	//RW = 0
		}
		#endif
	}
	else if(chip_select == GLCD_CHIP2_SELECT)
	{
	    #ifdef GLCD_LIBRARY_IN_BYTE_CONTROL_MODE
		{
		    GLCD_PORT_CONTROL_ALL = (GLCD_PORT_CONTROL_ALL | (0x01 << GLCD_CONTROL_CS2_GPIO_PIN)) & ~((0x01 << GLCD_CONTROL_CS1_GPIO_PIN)|(0x01 << GLCD_CONTROL_RS_GPIO_PIN)|(0x01 << GLCD_CONTROL_RW_GPIO_PIN));
		}
		#else
        {
            GLCD_PORT_CONTROL_CS1 &= ~(0x01 << GLCD_CONTROL_CS1_GPIO_PIN);
            GLCD_PORT_CONTROL_CS2 |=  (0x01 << GLCD_CONTROL_CS2_GPIO_PIN);
            GLCD_PORT_CONTROL_RS  &= ~(0x01 << GLCD_CONTROL_RS_GPIO_PIN);   //RS = 0
            GLCD_PORT_CONTROL_RW  &= ~(0x01 << GLCD_CONTROL_RW_GPIO_PIN);   //RW = 0
        }
		#endif
    }

    /*
    #ifdef GLCD_LIBRARY_IN_BYTE_CONTROL_MODE
    {
        GLCD_PORT_CONTROL_ALL &= ~((0x01 << GLCD_CONTROL_RS_GPIO_PIN)|(0x01 << GLCD_CONTROL_RW_GPIO_PIN));
    }
    #else
    {
        GLCD_PORT_CONTROL_RS &= ~(0x01 << GLCD_CONTROL_RS_GPIO_PIN);   //RS = 0
        GLCD_PORT_CONTROL_RW &= ~(0x01 << GLCD_CONTROL_RW_GPIO_PIN);	//RW = 0
    }
    */

	//CONFIGURE DATA PORT AS OUTPUT PORT
	#ifdef GLCD_LIBRARY_IN_BYTE_CONTROL_MODE
	{
	    GLCD_DDR_DATA_ALL = 0xFF;
	}
    #else
    {
        GLCD_DDR_DATA_0 |= (1<<GLCD_DATA_0_GPIO_PIN);
        GLCD_DDR_DATA_1 |= (1<<GLCD_DATA_1_GPIO_PIN);
        GLCD_DDR_DATA_2 |= (1<<GLCD_DATA_2_GPIO_PIN);
        GLCD_DDR_DATA_3 |= (1<<GLCD_DATA_3_GPIO_PIN);
        GLCD_DDR_DATA_4 |= (1<<GLCD_DATA_4_GPIO_PIN);
        GLCD_DDR_DATA_5 |= (1<<GLCD_DATA_5_GPIO_PIN);
        GLCD_DDR_DATA_6 |= (1<<GLCD_DATA_6_GPIO_PIN);
        GLCD_DDR_DATA_7 |= (1<<GLCD_DATA_7_GPIO_PIN);
    }

    #endif

    //GLCD_DDR_DATA_ALL = 0xFF;

    #ifdef GLCD_LIBRARY_IN_BYTE_CONTROL_MODE
	{
	    GLCD_PORT_DATA_ALL = command;
	}
    #else
    {
        if(command & (1<<0))
            GLCD_PORT_DATA_0 |= (1<<GLCD_DATA_0_GPIO_PIN);
        else
            GLCD_PORT_DATA_0 &= ~(1<<GLCD_DATA_0_GPIO_PIN);

        if(command & (1<<1))
            GLCD_PORT_DATA_1 |= (1<<GLCD_DATA_1_GPIO_PIN);
        else
            GLCD_PORT_DATA_1 &= ~(1<<GLCD_DATA_1_GPIO_PIN);

        if(command & (1<<2))
            GLCD_PORT_DATA_2 |= (1<<GLCD_DATA_2_GPIO_PIN);
        else
            GLCD_PORT_DATA_2 &= ~(1<<GLCD_DATA_2_GPIO_PIN);

        if(command & (1<<3))
            GLCD_PORT_DATA_3 |= (1<<GLCD_DATA_3_GPIO_PIN);
        else
            GLCD_PORT_DATA_3 &= ~(1<<GLCD_DATA_3_GPIO_PIN);

        if(command & (1<<4))
            GLCD_PORT_DATA_4 |= (1<<GLCD_DATA_4_GPIO_PIN);
        else
            GLCD_PORT_DATA_4 &= ~(1<<GLCD_DATA_4_GPIO_PIN);

        if(command & (1<<5))
            GLCD_PORT_DATA_5 |= (1<<GLCD_DATA_5_GPIO_PIN);
        else
            GLCD_PORT_DATA_5 &= ~(1<<GLCD_DATA_5_GPIO_PIN);

        if(command & (1<<6))
            GLCD_PORT_DATA_6 |= (1<<GLCD_DATA_6_GPIO_PIN);
        else
            GLCD_PORT_DATA_6 &= ~(1<<GLCD_DATA_6_GPIO_PIN);

        if(command & (1<<7))
            GLCD_PORT_DATA_7 |= (1<<GLCD_DATA_7_GPIO_PIN);
        else
            GLCD_PORT_DATA_7 &= ~(1<<GLCD_DATA_7_GPIO_PIN);

    }
	#endif

    //GLCD_PORT_DATA_ALL = command;

	glcd_enable();
}
#endif

/******************************************************************************************************/

#if (USE_glcd_gotoxy == YES)
void glcd_gotoxy(unsigned char x, unsigned char y)  //GO TO SPECIFIC POINT ON THE SCREEN
{
	unsigned char chip_select = GLCD_CHIP1_SELECT;
    //MAX POSITION (127,63), IF VALUES EXCEEDS THEN ROLL BACK
	if(x > 127)
	{
		x = 0;
    }

	if(y > 63)
	{
		y = 0;
	}

	glcd_global_x = x;
	glcd_global_y = y;
	glcd_global_page = y/8;

	if(x >= 64) //SELECT CHIP 2
	{
	    x = x-64;
		chip_select = GLCD_CHIP2_SELECT;
	}

	glcd_cmd((GLCD_SET_X_ADDRESS_ON_MODULE | x), chip_select);

	glcd_cmd((GLCD_SET_Y_ADDRESS_ON_MODULE | glcd_global_page), GLCD_CHIP1_SELECT);
	glcd_cmd((GLCD_SET_Y_ADDRESS_ON_MODULE | glcd_global_page), GLCD_CHIP2_SELECT);
}
#endif

/******************************************************************************************************/

#if (USE_glcd_read_byte == YES)
unsigned char glcd_read_byte(void)  //READ CONTENTS OF DISPLAY RAM
{
	unsigned char data=0x00;

    //DISABLE PULL-UP RESISTORS
    #ifdef GLCD_LIBRARY_IN_BYTE_CONTROL_MODE
	{
	    GLCD_PORT_DATA_ALL = 0x00;
	}
    #else
    {
        GLCD_PORT_DATA_0 &= ~(1<<GLCD_DATA_0_GPIO_PIN);
        GLCD_PORT_DATA_1 &= ~(1<<GLCD_DATA_1_GPIO_PIN);
        GLCD_PORT_DATA_2 &= ~(1<<GLCD_DATA_2_GPIO_PIN);
        GLCD_PORT_DATA_3 &= ~(1<<GLCD_DATA_3_GPIO_PIN);
        GLCD_PORT_DATA_4 &= ~(1<<GLCD_DATA_4_GPIO_PIN);
        GLCD_PORT_DATA_5 &= ~(1<<GLCD_DATA_5_GPIO_PIN);
        GLCD_PORT_DATA_6 &= ~(1<<GLCD_DATA_6_GPIO_PIN);
        GLCD_PORT_DATA_7 &= ~(1<<GLCD_DATA_7_GPIO_PIN);
    }
	#endif

    //GLCD_PORT_DATA_ALL = 0x00;

	#ifdef GLCD_LIBRARY_IN_BYTE_CONTROL_MODE
	{
	    GLCD_DDR_DATA_ALL = 0x00;
	}
    #else
    {
        GLCD_DDR_DATA_0 &= ~(1<<GLCD_DATA_0_GPIO_PIN);
        GLCD_DDR_DATA_1 &= ~(1<<GLCD_DATA_1_GPIO_PIN);
        GLCD_DDR_DATA_2 &= ~(1<<GLCD_DATA_2_GPIO_PIN);
        GLCD_DDR_DATA_3 &= ~(1<<GLCD_DATA_3_GPIO_PIN);
        GLCD_DDR_DATA_4 &= ~(1<<GLCD_DATA_4_GPIO_PIN);
        GLCD_DDR_DATA_5 &= ~(1<<GLCD_DATA_5_GPIO_PIN);
        GLCD_DDR_DATA_6 &= ~(1<<GLCD_DATA_6_GPIO_PIN);
        GLCD_DDR_DATA_7 &= ~(1<<GLCD_DATA_7_GPIO_PIN);
    }
	#endif

	//GLCD_DDR_DATA_ALL = 0x00;

	if(glcd_global_x < 64)
	{
	    #ifdef GLCD_LIBRARY_IN_BYTE_CONTROL_MODE
		{
		    GLCD_PORT_CONTROL_ALL = (GLCD_PORT_CONTROL_ALL | ((0x01 << GLCD_CONTROL_CS1_GPIO_PIN)|(0x01 << GLCD_CONTROL_RS_GPIO_PIN)|(0x01 << GLCD_CONTROL_RW_GPIO_PIN)|(0x01 << GLCD_CONTROL_EN_GPIO_PIN)))
                                    & ~((0x01 << GLCD_CONTROL_CS2_GPIO_PIN));
   		}
		#else
		{
		    GLCD_PORT_CONTROL_CS2 &= ~(0x01 << GLCD_CONTROL_CS2_GPIO_PIN);
            GLCD_PORT_CONTROL_CS1 |=  (0x01 << GLCD_CONTROL_CS1_GPIO_PIN);
            GLCD_PORT_CONTROL_RS  |=  (0x01 << GLCD_CONTROL_RS_GPIO_PIN);   //RS = 1
            GLCD_PORT_CONTROL_RW  |=  (0x01 << GLCD_CONTROL_RW_GPIO_PIN);	//RW = 1
            GLCD_PORT_CONTROL_EN  |=  (0x01 << GLCD_CONTROL_EN_GPIO_PIN);	//EN HIGH
		}
		#endif
	}
	else if(glcd_global_x >= 64)
	{
	    #ifdef GLCD_LIBRARY_IN_BYTE_CONTROL_MODE
		{
		    GLCD_PORT_CONTROL_ALL = (GLCD_PORT_CONTROL_ALL | ((0x01 << GLCD_CONTROL_CS2_GPIO_PIN)|(0x01 << GLCD_CONTROL_RS_GPIO_PIN)|(0x01 << GLCD_CONTROL_RW_GPIO_PIN)|(0x01 << GLCD_CONTROL_EN_GPIO_PIN)))
                                    & ~((0x01 << GLCD_CONTROL_CS1_GPIO_PIN));
		}
		#else
        {
            GLCD_PORT_CONTROL_CS1 &= ~(0x01 << GLCD_CONTROL_CS1_GPIO_PIN);
            GLCD_PORT_CONTROL_CS2 |=  (0x01 << GLCD_CONTROL_CS2_GPIO_PIN);
            GLCD_PORT_CONTROL_RS  |=  (0x01 << GLCD_CONTROL_RS_GPIO_PIN);   //RS = 1
            GLCD_PORT_CONTROL_RW  |=  (0x01 << GLCD_CONTROL_RW_GPIO_PIN);   //RW = 1
            GLCD_PORT_CONTROL_EN  |=  (0x01 << GLCD_CONTROL_EN_GPIO_PIN);	//EN HIGH
        }
		#endif
    }

	GLCD_DELAY_US(1);   //MIN:450ns

    //READ DATA
    #ifdef GLCD_LIBRARY_IN_BYTE_CONTROL_MODE
	{
	    data = GLCD_PIN_DATA_ALL;
	}
    #else
    {
        data |= (GLCD_PIN_DATA_0 & (1<<GLCD_DATA_0_GPIO_PIN));
        data |= (GLCD_PIN_DATA_0 & (1<<GLCD_DATA_1_GPIO_PIN));
        data |= (GLCD_PIN_DATA_0 & (1<<GLCD_DATA_2_GPIO_PIN));
        data |= (GLCD_PIN_DATA_0 & (1<<GLCD_DATA_3_GPIO_PIN));
        data |= (GLCD_PIN_DATA_0 & (1<<GLCD_DATA_4_GPIO_PIN));
        data |= (GLCD_PIN_DATA_0 & (1<<GLCD_DATA_5_GPIO_PIN));
        data |= (GLCD_PIN_DATA_0 & (1<<GLCD_DATA_6_GPIO_PIN));
        data |= (GLCD_PIN_DATA_0 & (1<<GLCD_DATA_7_GPIO_PIN));
    }
	#endif

	//data = GLCD_PIN_DATA_ALL;   //READ DATA

	GLCD_PORT_CONTROL_EN &= ~(0x01 << GLCD_CONTROL_EN_GPIO_PIN);   //EN LOW
	GLCD_DELAY_US(6);   //ALTERNATIVE TO READING STATUS

	glcd_gotoxy(glcd_global_x, glcd_global_y);  //DO THIS OR SYSTEM FAILS BECAUSE DISPLAY POINTER(WITHIN CHIP) AUTO INCREMENTS ON READ

	return data;
}
#endif

/******************************************************************************************************/

#if (USE_glcd_getc == YES)
unsigned char glcd_getc(void)    //READ CYCLE
{
	glcd_read_byte();
	return glcd_read_byte();
}
#endif

/******************************************************************************************************/

#if (USE_glcd_write_byte == YES)
void glcd_write_byte(unsigned char data) //WRITE 8BIT DATA TO DISPLAY RAM
{
	unsigned char output_data, y_offset, command_port_config=0x00;

	if(glcd_global_x < 64)
	{
	    #ifdef GLCD_LIBRARY_IN_BYTE_CONTROL_MODE
		{
		    GLCD_PORT_CONTROL_ALL = (GLCD_PORT_CONTROL_ALL | ((0x01 << GLCD_CONTROL_CS1_GPIO_PIN)|(0x01 << GLCD_CONTROL_RS_GPIO_PIN)))
                                    & ~((0x01 << GLCD_CONTROL_CS2_GPIO_PIN)|(0x01 << GLCD_CONTROL_RW_GPIO_PIN));
   		}
		#else
		{
		    GLCD_PORT_CONTROL_CS2 &= ~(0x01 << GLCD_CONTROL_CS2_GPIO_PIN);
            GLCD_PORT_CONTROL_CS1 |=  (0x01 << GLCD_CONTROL_CS1_GPIO_PIN);
            GLCD_PORT_CONTROL_RS |=  (0x01 << GLCD_CONTROL_RS_GPIO_PIN);    //RS = 1
            GLCD_PORT_CONTROL_RW &= ~(0x01 << GLCD_CONTROL_RW_GPIO_PIN);	//RW = 0
        }
		#endif
	}
	else if(glcd_global_x >= 64)
	{
	    #ifdef GLCD_LIBRARY_IN_BYTE_CONTROL_MODE
		{
		    GLCD_PORT_CONTROL_ALL = (GLCD_PORT_CONTROL_ALL | ((0x01 << GLCD_CONTROL_CS2_GPIO_PIN)|(0x01 << GLCD_CONTROL_RS_GPIO_PIN)))
                                    & ~((0x01 << GLCD_CONTROL_CS1_GPIO_PIN)|(0x01 << GLCD_CONTROL_RW_GPIO_PIN));
		}
		#else
        {
            GLCD_PORT_CONTROL_CS1 &= ~(0x01 << GLCD_CONTROL_CS1_GPIO_PIN);
            GLCD_PORT_CONTROL_CS2 |=  (0x01 << GLCD_CONTROL_CS2_GPIO_PIN);
            GLCD_PORT_CONTROL_RS |=  (0x01 << GLCD_CONTROL_RS_GPIO_PIN);    //RS = 1
            GLCD_PORT_CONTROL_RW &= ~(0x01 << GLCD_CONTROL_RW_GPIO_PIN);	//RW = 0
        }
		#endif
    }

	//CONFIGURE DATA PORT AS OUTPUT PORT
	#ifdef GLCD_LIBRARY_IN_BYTE_CONTROL_MODE
	{
	    GLCD_DDR_DATA_ALL = 0xFF;
	}
    #else
    {
        GLCD_DDR_DATA_0 |= (1<<GLCD_DATA_0_GPIO_PIN);
        GLCD_DDR_DATA_1 |= (1<<GLCD_DATA_1_GPIO_PIN);
        GLCD_DDR_DATA_2 |= (1<<GLCD_DATA_2_GPIO_PIN);
        GLCD_DDR_DATA_3 |= (1<<GLCD_DATA_3_GPIO_PIN);
        GLCD_DDR_DATA_4 |= (1<<GLCD_DATA_4_GPIO_PIN);
        GLCD_DDR_DATA_5 |= (1<<GLCD_DATA_5_GPIO_PIN);
        GLCD_DDR_DATA_6 |= (1<<GLCD_DATA_6_GPIO_PIN);
        GLCD_DDR_DATA_7 |= (1<<GLCD_DATA_7_GPIO_PIN);
    }
	#endif

    //GLCD_DDR_DATA_ALL = 0xFF;

    y_offset = glcd_global_y%8;

	if(y_offset != 0)
	{
		//PART OF FIRST PAGE
		#ifdef GLCD_LIBRARY_IN_BYTE_CONTROL_MODE
        {
            command_port_config = GLCD_PORT_CONTROL_ALL;
        }
        #else
        {
            #if (defined(GLCD_CONTROL_LED) && defined(GLCD_USE_RST))

            if(GLCD_PORT_CONTROL_RS & (1<<GLCD_CONTROL_RS_GPIO_PIN))
                command_port_config |= (1<<0);
            /*else
                command_port_config &= ~(1<<0);
            */

            if(GLCD_PORT_CONTROL_RW & (1<<GLCD_CONTROL_RW_GPIO_PIN))
                command_port_config |= (1<<1);
            /*else
                command_port_config &= ~(1<<1);
            */

            if(GLCD_PORT_CONTROL_EN & (1<<GLCD_CONTROL_EN_GPIO_PIN))
                command_port_config |= (1<<2);
            /*else
                command_port_config &= ~(1<<2);
            */

            if(GLCD_PORT_CONTROL_CS1 & (1<<GLCD_CONTROL_CS1_GPIO_PIN))
                command_port_config |= (1<<3);
            /*else
                command_port_config &= ~(1<<3);
            */

            if(GLCD_PORT_CONTROL_CS2 & (1<<GLCD_CONTROL_CS2_GPIO_PIN))
                command_port_config |= (1<<4);
            /*else
                command_port_config &= ~(1<<4);
            */

            if(GLCD_PORT_CONTROL_LED & (1<<GLCD_CONTROL_LED_GPIO_PIN))
                command_port_config |= (1<<5);
            /*else
                command_port_config &= ~(1<<5);
            */

            if(GLCD_PORT_CONTROL_LED & (1<<GLCD_CONTROL_LED_GPIO_PIN))
                command_port_config |= (1<<6);
            /*else
                command_port_config &= ~(1<<6);
            */

            //DOES NOT WORK
            /*
            command_port_config |= ((GLCD_PORT_CONTROL_RS &(1<<GLCD_CONTROL_RS_GPIO_PIN))!= 0:(1<<0)?(0x00));
            command_port_config |= ((GLCD_PORT_CONTROL_RW &(1<<GLCD_CONTROL_RW_GPIO_PIN))!= 0:(1<<1)?(0x00));
            command_port_config |= ((GLCD_PORT_CONTROL_EN &(1<<GLCD_CONTROL_EN_GPIO_PIN))!= 0:(1<<2)?(0x00));
            command_port_config |= ((GLCD_PORT_CONTROL_CS1 &(1<<GLCD_CONTROL_CS1_GPIO_PIN))!= 0:(1<<3)?(0x00));
            command_port_config |= ((GLCD_PORT_CONTROL_CS2 &(1<<GLCD_CONTROL_CS2_GPIO_PIN))!= 0:(1<<4)?(0x00));

            command_port_config |= ((GLCD_PORT_CONTROL_RST &(1<<GLCD_CONTROL_RST_GPIO_PIN))!= 0:(1<<5)?(0x00));
            command_port_config |= ((GLCD_PORT_CONTROL_LED &(1<<GLCD_CONTROL_LED_GPIO_PIN))!= 0:(1<<6)?(0x00));
            */


            #elif defined(GLCD_CONTROL_LED)

            if(GLCD_PORT_CONTROL_RS & (1<<GLCD_CONTROL_RS_GPIO_PIN))
                command_port_config |= (1<<0);
            /*else
                command_port_config &= ~(1<<0);
            */

            if(GLCD_PORT_CONTROL_RW & (1<<GLCD_CONTROL_RW_GPIO_PIN))
                command_port_config |= (1<<1);
            /*else
                command_port_config &= ~(1<<1);
            */

            if(GLCD_PORT_CONTROL_EN & (1<<GLCD_CONTROL_EN_GPIO_PIN))
                command_port_config |= (1<<2);
            /*else
                command_port_config &= ~(1<<2);
            */

            if(GLCD_PORT_CONTROL_CS1 & (1<<GLCD_CONTROL_CS1_GPIO_PIN))
                command_port_config |= (1<<3);
            /*else
                command_port_config &= ~(1<<3);
            */

            if(GLCD_PORT_CONTROL_CS2 & (1<<GLCD_CONTROL_CS2_GPIO_PIN))
                command_port_config |= (1<<4);
            /*else
                command_port_config &= ~(1<<4);
            */

            if(GLCD_PORT_CONTROL_LED & (1<<GLCD_CONTROL_LED_GPIO_PIN))
                command_port_config |= (1<<6);
            /*else
                command_port_config &= ~(1<<6);
            */

            //DOES NOT WORK
            /*
            command_port_config |= ((GLCD_PORT_CONTROL_RS &(1<<GLCD_CONTROL_RS_GPIO_PIN))!= 0:(1<<0)?(0x00));
            command_port_config |= ((GLCD_PORT_CONTROL_RW &(1<<GLCD_CONTROL_RW_GPIO_PIN))!= 0:(1<<1)?(0x00));
            command_port_config |= ((GLCD_PORT_CONTROL_EN &(1<<GLCD_CONTROL_EN_GPIO_PIN))!= 0:(1<<2)?(0x00));
            command_port_config |= ((GLCD_PORT_CONTROL_CS1 &(1<<GLCD_CONTROL_CS1_GPIO_PIN))!= 0:(1<<3)?(0x00));
            command_port_config |= ((GLCD_PORT_CONTROL_CS2 &(1<<GLCD_CONTROL_CS2_GPIO_PIN))!= 0:(1<<4)?(0x00));

            command_port_config |= ((GLCD_PORT_CONTROL_LED &(1<<GLCD_CONTROL_LED_GPIO_PIN))!= 0:(1<<6)?(0x00));
            */

            #elif defined(GLCD_USE_RST)

            if(GLCD_PORT_CONTROL_RS & (1<<GLCD_CONTROL_RS_GPIO_PIN))
                command_port_config |= (1<<0);
            /*else
                command_port_config &= ~(1<<0);
            */

            if(GLCD_PORT_CONTROL_RW & (1<<GLCD_CONTROL_RW_GPIO_PIN))
                command_port_config |= (1<<1);
            /*else
                command_port_config &= ~(1<<1);
            */

            if(GLCD_PORT_CONTROL_EN & (1<<GLCD_CONTROL_EN_GPIO_PIN))
                command_port_config |= (1<<2);
            /*else
                command_port_config &= ~(1<<2);
            */

            if(GLCD_PORT_CONTROL_CS1 & (1<<GLCD_CONTROL_CS1_GPIO_PIN))
                command_port_config |= (1<<3);
            /*else
                command_port_config &= ~(1<<3);
            */

            if(GLCD_PORT_CONTROL_CS2 & (1<<GLCD_CONTROL_CS2_GPIO_PIN))
                command_port_config |= (1<<4);
            /*else
                command_port_config &= ~(1<<4);
            */

            if(GLCD_PORT_CONTROL_RST & (1<<GLCD_CONTROL_RST_GPIO_PIN))
                command_port_config |= (1<<5);
            /*else
                command_port_config &= ~(1<<5);
            */

            //DOES NOT WORK
            /*
            command_port_config |= ((GLCD_PORT_CONTROL_RS &(1<<GLCD_CONTROL_RS_GPIO_PIN))!= 0:(1<<0)?(0x00));
            command_port_config |= ((GLCD_PORT_CONTROL_RW &(1<<GLCD_CONTROL_RW_GPIO_PIN))!= 0:(1<<1)?(0x00));
            command_port_config |= ((GLCD_PORT_CONTROL_EN &(1<<GLCD_CONTROL_EN_GPIO_PIN))!= 0:(1<<2)?(0x00));
            command_port_config |= ((GLCD_PORT_CONTROL_CS1 &(1<<GLCD_CONTROL_CS1_GPIO_PIN))!= 0:(1<<3)?(0x00));
            command_port_config |= ((GLCD_PORT_CONTROL_CS2 &(1<<GLCD_CONTROL_CS2_GPIO_PIN))!= 0:(1<<4)?(0x00));

            command_port_config |= ((GLCD_PORT_CONTROL_RST &(1<<GLCD_CONTROL_RST_GPIO_PIN))!= 0:(1<<5)?(0x00));
            */
            #else

            if(GLCD_PORT_CONTROL_RS & (1<<GLCD_CONTROL_RS_GPIO_PIN))
                command_port_config |= (1<<0);
            /*else
                command_port_config &= ~(1<<0);
            */

            if(GLCD_PORT_CONTROL_RW & (1<<GLCD_CONTROL_RW_GPIO_PIN))
                command_port_config |= (1<<1);
            /*else
                command_port_config &= ~(1<<1);
            */

            if(GLCD_PORT_CONTROL_EN & (1<<GLCD_CONTROL_EN_GPIO_PIN))
                command_port_config |= (1<<2);
            /*else
                command_port_config &= ~(1<<2);
            */

            if(GLCD_PORT_CONTROL_CS1 & (1<<GLCD_CONTROL_CS1_GPIO_PIN))
                command_port_config |= (1<<3);
            /*else
                command_port_config &= ~(1<<3);
            */

            if(GLCD_PORT_CONTROL_CS2 & (1<<GLCD_CONTROL_CS2_GPIO_PIN))
                command_port_config |= (1<<4);
            /*else
                command_port_config &= ~(1<<4);
            */

            //DOES NOT WORK
            /*
            command_port_config |= ((GLCD_PORT_CONTROL_RW & (1<<GLCD_CONTROL_RW_GPIO_PIN))!= 0:(1<<1)?(0x00));
            command_port_config |= ((GLCD_PORT_CONTROL_EN & (1<<GLCD_CONTROL_EN_GPIO_PIN))!= 0:(1<<2)?(0x00));
            command_port_config |= ((GLCD_PORT_CONTROL_CS1 &(1<<GLCD_CONTROL_CS1_GPIO_PIN))!= 0:(1<<3)?(0x00));
            command_port_config |= ((GLCD_PORT_CONTROL_CS2 &(1<<GLCD_CONTROL_CS2_GPIO_PIN))!= 0:(1<<4)?(0x00));
            */

            #endif
        }

        #endif

        //command_port_config = GLCD_PORT_CONTROL_ALL;
        output_data = glcd_getc();

        #ifdef GLCD_LIBRARY_IN_BYTE_CONTROL_MODE
        {
              GLCD_PORT_CONTROL_ALL = command_port_config;
        }
        #else
        {
            #if (defined(GLCD_CONTROL_LED) && defined(GLCD_USE_RST))
            if(command_port_config &(1<<0))
                GLCD_PORT_CONTROL_RS  |= (1<<GLCD_CONTROL_RS_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_RS  &= ~(1<<GLCD_CONTROL_RS_GPIO_PIN);

            if(command_port_config &(1<<1))
                GLCD_PORT_CONTROL_RW  |= (1<<GLCD_CONTROL_RW_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_RW  &= ~(1<<GLCD_CONTROL_RW_GPIO_PIN);

            if(command_port_config &(1<<2))
                GLCD_PORT_CONTROL_EN  |= (1<<GLCD_CONTROL_EN_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_EN  &= ~(1<<GLCD_CONTROL_EN_GPIO_PIN);

            if(command_port_config &(1<<3))
                GLCD_PORT_CONTROL_CS1  |= (1<<GLCD_CONTROL_CS1_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_CS1  &= ~(1<<GLCD_CONTROL_CS1_GPIO_PIN);

            if(command_port_config &(1<<4))
                GLCD_PORT_CONTROL_CS2  |= (1<<GLCD_CONTROL_CS2_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_CS2  &= ~(1<<GLCD_CONTROL_CS2_GPIO_PIN);

            if(command_port_config &(1<<5))
                GLCD_PORT_CONTROL_RST  |= (1<<GLCD_CONTROL_RST_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_RST  &= ~(1<<GLCD_CONTROL_RST_GPIO_PIN);

            if(command_port_config &(1<<7))
                GLCD_PORT_CONTROL_LED  |= (1<<GLCD_CONTROL_LED_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_LED  &= ~(1<<GLCD_CONTROL_LED_GPIO_PIN);


            #elif defined(GLCD_CONTROL_LED)
            if(command_port_config &(1<<0))
                GLCD_PORT_CONTROL_RS  |= (1<<GLCD_CONTROL_RS_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_RS  &= ~(1<<GLCD_CONTROL_RS_GPIO_PIN);

            if(command_port_config &(1<<1))
                GLCD_PORT_CONTROL_RW  |= (1<<GLCD_CONTROL_RW_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_RW  &= ~(1<<GLCD_CONTROL_RW_GPIO_PIN);

            if(command_port_config &(1<<2))
                GLCD_PORT_CONTROL_EN  |= (1<<GLCD_CONTROL_EN_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_EN  &= ~(1<<GLCD_CONTROL_EN_GPIO_PIN);

            if(command_port_config &(1<<3))
                GLCD_PORT_CONTROL_CS1  |= (1<<GLCD_CONTROL_CS1_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_CS1  &= ~(1<<GLCD_CONTROL_CS1_GPIO_PIN);

            if(command_port_config &(1<<4))
                GLCD_PORT_CONTROL_CS2  |= (1<<GLCD_CONTROL_CS2_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_CS2  &= ~(1<<GLCD_CONTROL_CS2_GPIO_PIN);

            if(command_port_config &(1<<7))
                GLCD_PORT_CONTROL_LED  |= (1<<GLCD_CONTROL_LED_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_LED  &= ~(1<<GLCD_CONTROL_LED_GPIO_PIN);

            #elif defined(GLCD_USE_RST)

            if(command_port_config &(1<<0))
                GLCD_PORT_CONTROL_RS  |= (1<<GLCD_CONTROL_RS_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_RS  &= ~(1<<GLCD_CONTROL_RS_GPIO_PIN);

            if(command_port_config &(1<<1))
                GLCD_PORT_CONTROL_RW  |= (1<<GLCD_CONTROL_RW_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_RW  &= ~(1<<GLCD_CONTROL_RW_GPIO_PIN);

            if(command_port_config &(1<<2))
                GLCD_PORT_CONTROL_EN  |= (1<<GLCD_CONTROL_EN_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_EN  &= ~(1<<GLCD_CONTROL_EN_GPIO_PIN);

            if(command_port_config &(1<<3))
                GLCD_PORT_CONTROL_CS1  |= (1<<GLCD_CONTROL_CS1_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_CS1  &= ~(1<<GLCD_CONTROL_CS1_GPIO_PIN);

            if(command_port_config &(1<<4))
                GLCD_PORT_CONTROL_CS2  |= (1<<GLCD_CONTROL_CS2_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_CS2  &= ~(1<<GLCD_CONTROL_CS2_GPIO_PIN);

            if(command_port_config &(1<<5))
                GLCD_PORT_CONTROL_RST  |= (1<<GLCD_CONTROL_RST_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_RST  &= ~(1<<GLCD_CONTROL_RST_GPIO_PIN);


            #else

            if(command_port_config &(1<<0))
                GLCD_PORT_CONTROL_RS  |= (1<<GLCD_CONTROL_RS_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_RS  &= ~(1<<GLCD_CONTROL_RS_GPIO_PIN);

            if(command_port_config &(1<<1))
                GLCD_PORT_CONTROL_RW  |= (1<<GLCD_CONTROL_RW_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_RW  &= ~(1<<GLCD_CONTROL_RW_GPIO_PIN);

            if(command_port_config &(1<<2))
                GLCD_PORT_CONTROL_EN  |= (1<<GLCD_CONTROL_EN_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_EN  &= ~(1<<GLCD_CONTROL_EN_GPIO_PIN);

            if(command_port_config &(1<<3))
                GLCD_PORT_CONTROL_CS1  |= (1<<GLCD_CONTROL_CS1_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_CS1  &= ~(1<<GLCD_CONTROL_CS1_GPIO_PIN);

            if(command_port_config &(1<<4))
                GLCD_PORT_CONTROL_CS2  |= (1<<GLCD_CONTROL_CS2_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_CS2  &= ~(1<<GLCD_CONTROL_CS2_GPIO_PIN);

            #endif
        }

        #endif

		//GLCD_PORT_CONTROL_ALL = command_port_config;

		//CONFIGURE DATA PORT AS OUTPUT PORT
        #ifdef GLCD_LIBRARY_IN_BYTE_CONTROL_MODE
        {
            GLCD_DDR_DATA_ALL = 0xFF;
        }
        #else
        {
            GLCD_DDR_DATA_0 |= (1<<GLCD_DATA_0_GPIO_PIN);
            GLCD_DDR_DATA_1 |= (1<<GLCD_DATA_1_GPIO_PIN);
            GLCD_DDR_DATA_2 |= (1<<GLCD_DATA_2_GPIO_PIN);
            GLCD_DDR_DATA_3 |= (1<<GLCD_DATA_3_GPIO_PIN);
            GLCD_DDR_DATA_4 |= (1<<GLCD_DATA_4_GPIO_PIN);
            GLCD_DDR_DATA_5 |= (1<<GLCD_DATA_5_GPIO_PIN);
            GLCD_DDR_DATA_6 |= (1<<GLCD_DATA_6_GPIO_PIN);
            GLCD_DDR_DATA_7 |= (1<<GLCD_DATA_7_GPIO_PIN);
        }
		#endif

        //GLCD_DDR_DATA_ALL = 0xFF;

        output_data |= (data << y_offset);

        #ifdef GLCD_LIBRARY_IN_BYTE_CONTROL_MODE
        {
            GLCD_PORT_DATA_ALL = output_data;
        }
        #else
        {
            if(output_data & (1<<0))
                GLCD_PORT_DATA_0 |= (1<<GLCD_DATA_0_GPIO_PIN);
            else
                GLCD_PORT_DATA_0 &= ~(1<<GLCD_DATA_0_GPIO_PIN);

            if(output_data & (1<<1))
                GLCD_PORT_DATA_1 |= (1<<GLCD_DATA_1_GPIO_PIN);
            else
                GLCD_PORT_DATA_1 &= ~(1<<GLCD_DATA_1_GPIO_PIN);

            if(output_data & (1<<2))
                GLCD_PORT_DATA_2 |= (1<<GLCD_DATA_2_GPIO_PIN);
            else
                GLCD_PORT_DATA_2 &= ~(1<<GLCD_DATA_2_GPIO_PIN);

            if(output_data & (1<<3))
                GLCD_PORT_DATA_3 |= (1<<GLCD_DATA_3_GPIO_PIN);
            else
                GLCD_PORT_DATA_3 &= ~(1<<GLCD_DATA_3_GPIO_PIN);

            if(output_data & (1<<4))
                GLCD_PORT_DATA_4 |= (1<<GLCD_DATA_4_GPIO_PIN);
            else
                GLCD_PORT_DATA_4 &= ~(1<<GLCD_DATA_4_GPIO_PIN);

            if(output_data & (1<<5))
                GLCD_PORT_DATA_5 |= (1<<GLCD_DATA_5_GPIO_PIN);
            else
                GLCD_PORT_DATA_5 &= ~(1<<GLCD_DATA_5_GPIO_PIN);

            if(output_data & (1<<6))
                GLCD_PORT_DATA_6 |= (1<<GLCD_DATA_6_GPIO_PIN);
            else
                GLCD_PORT_DATA_6 &= ~(1<<GLCD_DATA_6_GPIO_PIN);

            if(output_data & (1<<7))
                GLCD_PORT_DATA_7 |= (1<<GLCD_DATA_7_GPIO_PIN);
            else
                GLCD_PORT_DATA_7 &= ~(1<<GLCD_DATA_7_GPIO_PIN);

        }
		#endif

		//GLCD_PORT_DATA_ALL = output_data;

		glcd_enable();

		//PART OF SECOND PAGE
		glcd_gotoxy(glcd_global_x, glcd_global_y+8);

		output_data = glcd_getc();

        #ifdef GLCD_LIBRARY_IN_BYTE_CONTROL_MODE
        {
            GLCD_PORT_CONTROL_ALL = command_port_config;
        }
        #else
        {
            #if (defined(GLCD_CONTROL_LED) && defined(GLCD_USE_RST))
            if(command_port_config &(1<<0))
                GLCD_PORT_CONTROL_RS  |= (1<<GLCD_CONTROL_RS_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_RS  &= ~(1<<GLCD_CONTROL_RS_GPIO_PIN);

            if(command_port_config &(1<<1))
                GLCD_PORT_CONTROL_RW  |= (1<<GLCD_CONTROL_RW_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_RW  &= ~(1<<GLCD_CONTROL_RW_GPIO_PIN);

            if(command_port_config &(1<<2))
                GLCD_PORT_CONTROL_EN  |= (1<<GLCD_CONTROL_EN_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_EN  &= ~(1<<GLCD_CONTROL_EN_GPIO_PIN);

            if(command_port_config &(1<<3))
                GLCD_PORT_CONTROL_CS1  |= (1<<GLCD_CONTROL_CS1_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_CS1  &= ~(1<<GLCD_CONTROL_CS1_GPIO_PIN);

            if(command_port_config &(1<<4))
                GLCD_PORT_CONTROL_CS2  |= (1<<GLCD_CONTROL_CS2_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_CS2  &= ~(1<<GLCD_CONTROL_CS2_GPIO_PIN);

            if(command_port_config &(1<<5))
                GLCD_PORT_CONTROL_RST  |= (1<<GLCD_CONTROL_RST_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_RST  &= ~(1<<GLCD_CONTROL_RST_GPIO_PIN);

            if(command_port_config &(1<<7))
                GLCD_PORT_CONTROL_LED  |= (1<<GLCD_CONTROL_LED_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_LED  &= ~(1<<GLCD_CONTROL_LED_GPIO_PIN);


            #elif defined(GLCD_CONTROL_LED)
            if(command_port_config &(1<<0))
                GLCD_PORT_CONTROL_RS  |= (1<<GLCD_CONTROL_RS_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_RS  &= ~(1<<GLCD_CONTROL_RS_GPIO_PIN);

            if(command_port_config &(1<<1))
                GLCD_PORT_CONTROL_RW  |= (1<<GLCD_CONTROL_RW_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_RW  &= ~(1<<GLCD_CONTROL_RW_GPIO_PIN);

            if(command_port_config &(1<<2))
                GLCD_PORT_CONTROL_EN  |= (1<<GLCD_CONTROL_EN_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_EN  &= ~(1<<GLCD_CONTROL_EN_GPIO_PIN);

            if(command_port_config &(1<<3))
                GLCD_PORT_CONTROL_CS1  |= (1<<GLCD_CONTROL_CS1_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_CS1  &= ~(1<<GLCD_CONTROL_CS1_GPIO_PIN);

            if(command_port_config &(1<<4))
                GLCD_PORT_CONTROL_CS2  |= (1<<GLCD_CONTROL_CS2_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_CS2  &= ~(1<<GLCD_CONTROL_CS2_GPIO_PIN);

            if(command_port_config &(1<<7))
                GLCD_PORT_CONTROL_LED  |= (1<<GLCD_CONTROL_LED_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_LED  &= ~(1<<GLCD_CONTROL_LED_GPIO_PIN);

            #elif defined(GLCD_USE_RST)

            if(command_port_config &(1<<0))
                GLCD_PORT_CONTROL_RS  |= (1<<GLCD_CONTROL_RS_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_RS  &= ~(1<<GLCD_CONTROL_RS_GPIO_PIN);

            if(command_port_config &(1<<1))
                GLCD_PORT_CONTROL_RW  |= (1<<GLCD_CONTROL_RW_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_RW  &= ~(1<<GLCD_CONTROL_RW_GPIO_PIN);

            if(command_port_config &(1<<2))
                GLCD_PORT_CONTROL_EN  |= (1<<GLCD_CONTROL_EN_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_EN  &= ~(1<<GLCD_CONTROL_EN_GPIO_PIN);

            if(command_port_config &(1<<3))
                GLCD_PORT_CONTROL_CS1  |= (1<<GLCD_CONTROL_CS1_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_CS1  &= ~(1<<GLCD_CONTROL_CS1_GPIO_PIN);

            if(command_port_config &(1<<4))
                GLCD_PORT_CONTROL_CS2  |= (1<<GLCD_CONTROL_CS2_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_CS2  &= ~(1<<GLCD_CONTROL_CS2_GPIO_PIN);

            if(command_port_config &(1<<5))
                GLCD_PORT_CONTROL_RST  |= (1<<GLCD_CONTROL_RST_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_RST  &= ~(1<<GLCD_CONTROL_RST_GPIO_PIN);


            #else

            if(command_port_config &(1<<0))
                GLCD_PORT_CONTROL_RS  |= (1<<GLCD_CONTROL_RS_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_RS  &= ~(1<<GLCD_CONTROL_RS_GPIO_PIN);

            if(command_port_config &(1<<1))
                GLCD_PORT_CONTROL_RW  |= (1<<GLCD_CONTROL_RW_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_RW  &= ~(1<<GLCD_CONTROL_RW_GPIO_PIN);

            if(command_port_config &(1<<2))
                GLCD_PORT_CONTROL_EN  |= (1<<GLCD_CONTROL_EN_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_EN  &= ~(1<<GLCD_CONTROL_EN_GPIO_PIN);

            if(command_port_config &(1<<3))
                GLCD_PORT_CONTROL_CS1  |= (1<<GLCD_CONTROL_CS1_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_CS1  &= ~(1<<GLCD_CONTROL_CS1_GPIO_PIN);

            if(command_port_config &(1<<4))
                GLCD_PORT_CONTROL_CS2  |= (1<<GLCD_CONTROL_CS2_GPIO_PIN);
            else
                GLCD_PORT_CONTROL_CS2  &= ~(1<<GLCD_CONTROL_CS2_GPIO_PIN);

            #endif
        }

        #endif

		//GLCD_PORT_CONTROL_ALL = command_port_config;

		//CONFIGURE DATA PORT AS OUTPUT PORT
        #ifdef GLCD_LIBRARY_IN_BYTE_CONTROL_MODE
        {
            GLCD_DDR_DATA_ALL = 0xFF;
        }
        #else
        {
            GLCD_DDR_DATA_0 |= (1<<GLCD_DATA_0_GPIO_PIN);
            GLCD_DDR_DATA_1 |= (1<<GLCD_DATA_1_GPIO_PIN);
            GLCD_DDR_DATA_2 |= (1<<GLCD_DATA_2_GPIO_PIN);
            GLCD_DDR_DATA_3 |= (1<<GLCD_DATA_3_GPIO_PIN);
            GLCD_DDR_DATA_4 |= (1<<GLCD_DATA_4_GPIO_PIN);
            GLCD_DDR_DATA_5 |= (1<<GLCD_DATA_5_GPIO_PIN);
            GLCD_DDR_DATA_6 |= (1<<GLCD_DATA_6_GPIO_PIN);
            GLCD_DDR_DATA_7 |= (1<<GLCD_DATA_7_GPIO_PIN);
        }
		#endif

        //GLCD_DDR_DATA_ALL = 0xFF;

		output_data |= data >> (8-y_offset);

		#ifdef GLCD_LIBRARY_IN_BYTE_CONTROL_MODE
        {
            GLCD_PORT_DATA_ALL = output_data;
        }
        #else
        {
            if(output_data & (1<<0))
                GLCD_PORT_DATA_0 |= (1<<GLCD_DATA_0_GPIO_PIN);
            else
                GLCD_PORT_DATA_0 &= ~(1<<GLCD_DATA_0_GPIO_PIN);

            if(output_data & (1<<1))
                GLCD_PORT_DATA_1 |= (1<<GLCD_DATA_1_GPIO_PIN);
            else
                GLCD_PORT_DATA_1 &= ~(1<<GLCD_DATA_1_GPIO_PIN);

            if(output_data & (1<<2))
                GLCD_PORT_DATA_2 |= (1<<GLCD_DATA_2_GPIO_PIN);
            else
                GLCD_PORT_DATA_2 &= ~(1<<GLCD_DATA_2_GPIO_PIN);

            if(output_data & (1<<3))
                GLCD_PORT_DATA_3 |= (1<<GLCD_DATA_3_GPIO_PIN);
            else
                GLCD_PORT_DATA_3 &= ~(1<<GLCD_DATA_3_GPIO_PIN);

            if(output_data & (1<<4))
                GLCD_PORT_DATA_4 |= (1<<GLCD_DATA_4_GPIO_PIN);
            else
                GLCD_PORT_DATA_4 &= ~(1<<GLCD_DATA_4_GPIO_PIN);

            if(output_data & (1<<5))
                GLCD_PORT_DATA_5 |= (1<<GLCD_DATA_5_GPIO_PIN);
            else
                GLCD_PORT_DATA_5 &= ~(1<<GLCD_DATA_5_GPIO_PIN);

            if(output_data & (1<<6))
                GLCD_PORT_DATA_6 |= (1<<GLCD_DATA_6_GPIO_PIN);
            else
                GLCD_PORT_DATA_6 &= ~(1<<GLCD_DATA_6_GPIO_PIN);

            if(output_data & (1<<7))
                GLCD_PORT_DATA_7 |= (1<<GLCD_DATA_7_GPIO_PIN);
            else
                GLCD_PORT_DATA_7 &= ~(1<<GLCD_DATA_7_GPIO_PIN);

        }
		#endif

        //GLCD_PORT_DATA_ALL = output_data;

		glcd_enable();

		glcd_gotoxy(glcd_global_x+1, glcd_global_y-8);
	}
	else
	{
	    #ifdef GLCD_LIBRARY_IN_BYTE_CONTROL_MODE
        {
            GLCD_PORT_DATA_ALL = data;
        }
        #else
        {
            if(data & (1<<0))
                GLCD_PORT_DATA_0 |= (1<<GLCD_DATA_0_GPIO_PIN);
            else
                GLCD_PORT_DATA_0 &= ~(1<<GLCD_DATA_0_GPIO_PIN);

            if(data & (1<<1))
                GLCD_PORT_DATA_1 |= (1<<GLCD_DATA_1_GPIO_PIN);
            else
                GLCD_PORT_DATA_1 &= ~(1<<GLCD_DATA_1_GPIO_PIN);

            if(data & (1<<2))
                GLCD_PORT_DATA_2 |= (1<<GLCD_DATA_2_GPIO_PIN);
            else
                GLCD_PORT_DATA_2 &= ~(1<<GLCD_DATA_2_GPIO_PIN);

            if(data & (1<<3))
                GLCD_PORT_DATA_3 |= (1<<GLCD_DATA_3_GPIO_PIN);
            else
                GLCD_PORT_DATA_3 &= ~(1<<GLCD_DATA_3_GPIO_PIN);

            if(data & (1<<4))
                GLCD_PORT_DATA_4 |= (1<<GLCD_DATA_4_GPIO_PIN);
            else
                GLCD_PORT_DATA_4 &= ~(1<<GLCD_DATA_4_GPIO_PIN);

            if(data & (1<<5))
                GLCD_PORT_DATA_5 |= (1<<GLCD_DATA_5_GPIO_PIN);
            else
                GLCD_PORT_DATA_5 &= ~(1<<GLCD_DATA_5_GPIO_PIN);

            if(data & (1<<6))
                GLCD_PORT_DATA_6 |= (1<<GLCD_DATA_6_GPIO_PIN);
            else
                GLCD_PORT_DATA_6 &= ~(1<<GLCD_DATA_6_GPIO_PIN);

            if(data & (1<<7))
                GLCD_PORT_DATA_7 |= (1<<GLCD_DATA_7_GPIO_PIN);
            else
                GLCD_PORT_DATA_7 &= ~(1<<GLCD_DATA_7_GPIO_PIN);

        }

		#endif

		//GLCD_PORT_DATA_ALL = data;
		glcd_enable();
		glcd_global_x++;

		if(glcd_global_x > 127)
        {
            glcd_global_x = 0;
        }
	}

}
#endif

/******************************************************************************************************/

#if (USE_glcd_write_byte_ms == YES)
void glcd_write_byte_ms(unsigned char data, unsigned char data_cmd, unsigned char chip_select)
{
    if(chip_select == GLCD_CHIP1_SELECT)
	{
	    #ifdef GLCD_LIBRARY_IN_BYTE_CONTROL_MODE
		{
		    GLCD_PORT_CONTROL_ALL = (GLCD_PORT_CONTROL_ALL | (0x01 << GLCD_CONTROL_CS1_GPIO_PIN)) & ~((0x01 << GLCD_CONTROL_CS2_GPIO_PIN)|(0x01 << GLCD_CONTROL_RW_GPIO_PIN));
   		}
		#else
		{
		    GLCD_PORT_CONTROL_CS2 &= ~(0x01 << GLCD_CONTROL_CS2_GPIO_PIN);
            GLCD_PORT_CONTROL_CS1 |=  (0x01 << GLCD_CONTROL_CS1_GPIO_PIN);
            GLCD_PORT_CONTROL_RW &= ~(0x01 << GLCD_CONTROL_RW_GPIO_PIN);	//RW = 0
		}
		#endif
	}
	else if(chip_select == GLCD_CHIP2_SELECT)
	{
	    #ifdef GLCD_LIBRARY_IN_BYTE_CONTROL_MODE
		{
		    GLCD_PORT_CONTROL_ALL = (GLCD_PORT_CONTROL_ALL | (0x01 << GLCD_CONTROL_CS2_GPIO_PIN)) & ~((0x01 << GLCD_CONTROL_CS1_GPIO_PIN)|(0x01 << GLCD_CONTROL_RW_GPIO_PIN));
		}
		#else
        {
            GLCD_PORT_CONTROL_CS1 &= ~(0x01 << GLCD_CONTROL_CS1_GPIO_PIN);
            GLCD_PORT_CONTROL_CS2 |=  (0x01 << GLCD_CONTROL_CS2_GPIO_PIN);
            GLCD_PORT_CONTROL_RW  &= ~(0x01 << GLCD_CONTROL_RW_GPIO_PIN);   //RW = 0
        }
		#endif
    }

    //CONFIGURE DATA PORT AS OUTPUT PORT
	#ifdef GLCD_LIBRARY_IN_BYTE_CONTROL_MODE
	{
	    GLCD_DDR_DATA_ALL = 0xFF;
	}
    #else
    {
        GLCD_DDR_DATA_0 |= (1<<GLCD_DATA_0_GPIO_PIN);
        GLCD_DDR_DATA_1 |= (1<<GLCD_DATA_1_GPIO_PIN);
        GLCD_DDR_DATA_2 |= (1<<GLCD_DATA_2_GPIO_PIN);
        GLCD_DDR_DATA_3 |= (1<<GLCD_DATA_3_GPIO_PIN);
        GLCD_DDR_DATA_4 |= (1<<GLCD_DATA_4_GPIO_PIN);
        GLCD_DDR_DATA_5 |= (1<<GLCD_DATA_5_GPIO_PIN);
        GLCD_DDR_DATA_6 |= (1<<GLCD_DATA_6_GPIO_PIN);
        GLCD_DDR_DATA_7 |= (1<<GLCD_DATA_7_GPIO_PIN);
    }
    #endif

    //GLCD_DDR_DATA_ALL = 0xFF;

	if(data_cmd == GLCD_INSTRUCTION)
	{
		GLCD_PORT_CONTROL_RS &= ~(0x01 << GLCD_CONTROL_RS_GPIO_PIN);    // GLCD_CONTROL_RS_GPIO_PIN = 0

		#ifdef GLCD_LIBRARY_IN_BYTE_CONTROL_MODE
        {
            GLCD_PORT_DATA_ALL = data;
        }
        #else
        {
            if(data & (1<<0))
                GLCD_PORT_DATA_0 |= (1<<GLCD_DATA_0_GPIO_PIN);
            else
                GLCD_PORT_DATA_0 &= ~(1<<GLCD_DATA_0_GPIO_PIN);

            if(data & (1<<1))
                GLCD_PORT_DATA_1 |= (1<<GLCD_DATA_1_GPIO_PIN);
            else
                GLCD_PORT_DATA_1 &= ~(1<<GLCD_DATA_1_GPIO_PIN);

            if(data & (1<<2))
                GLCD_PORT_DATA_2 |= (1<<GLCD_DATA_2_GPIO_PIN);
            else
                GLCD_PORT_DATA_2 &= ~(1<<GLCD_DATA_2_GPIO_PIN);

            if(data & (1<<3))
                GLCD_PORT_DATA_3 |= (1<<GLCD_DATA_3_GPIO_PIN);
            else
                GLCD_PORT_DATA_3 &= ~(1<<GLCD_DATA_3_GPIO_PIN);

            if(data & (1<<4))
                GLCD_PORT_DATA_4 |= (1<<GLCD_DATA_4_GPIO_PIN);
            else
                GLCD_PORT_DATA_4 &= ~(1<<GLCD_DATA_4_GPIO_PIN);

            if(data & (1<<5))
                GLCD_PORT_DATA_5 |= (1<<GLCD_DATA_5_GPIO_PIN);
            else
                GLCD_PORT_DATA_5 &= ~(1<<GLCD_DATA_5_GPIO_PIN);

            if(data & (1<<6))
                GLCD_PORT_DATA_6 |= (1<<GLCD_DATA_6_GPIO_PIN);
            else
                GLCD_PORT_DATA_6 &= ~(1<<GLCD_DATA_6_GPIO_PIN);

            if(data & (1<<7))
                GLCD_PORT_DATA_7 |= (1<<GLCD_DATA_7_GPIO_PIN);
            else
                GLCD_PORT_DATA_7 &= ~(1<<GLCD_DATA_7_GPIO_PIN);

        }
        #endif

        //GLCD_PORT_DATA_ALL = data;

	}
	else if(data_cmd == GLCD_DATA)
	{
		GLCD_PORT_CONTROL_ALL |=  (0x01 << GLCD_CONTROL_RS_GPIO_PIN);   // GLCD_CONTROL_RS_GPIO_PIN = 1

		#ifdef GLCD_LIBRARY_IN_BYTE_CONTROL_MODE
        {
            GLCD_PORT_DATA_ALL = data;
        }
        #else
        {
            if(data & (1<<0))
                GLCD_PORT_DATA_0 |= (1<<GLCD_DATA_0_GPIO_PIN);
            else
                GLCD_PORT_DATA_0 &= ~(1<<GLCD_DATA_0_GPIO_PIN);

            if(data & (1<<1))
                GLCD_PORT_DATA_1 |= (1<<GLCD_DATA_1_GPIO_PIN);
            else
                GLCD_PORT_DATA_1 &= ~(1<<GLCD_DATA_1_GPIO_PIN);

            if(data & (1<<2))
                GLCD_PORT_DATA_2 |= (1<<GLCD_DATA_2_GPIO_PIN);
            else
                GLCD_PORT_DATA_2 &= ~(1<<GLCD_DATA_2_GPIO_PIN);

            if(data & (1<<3))
                GLCD_PORT_DATA_3 |= (1<<GLCD_DATA_3_GPIO_PIN);
            else
                GLCD_PORT_DATA_3 &= ~(1<<GLCD_DATA_3_GPIO_PIN);

            if(data & (1<<4))
                GLCD_PORT_DATA_4 |= (1<<GLCD_DATA_4_GPIO_PIN);
            else
                GLCD_PORT_DATA_4 &= ~(1<<GLCD_DATA_4_GPIO_PIN);

            if(data & (1<<5))
                GLCD_PORT_DATA_5 |= (1<<GLCD_DATA_5_GPIO_PIN);
            else
                GLCD_PORT_DATA_5 &= ~(1<<GLCD_DATA_5_GPIO_PIN);

            if(data & (1<<6))
                GLCD_PORT_DATA_6 |= (1<<GLCD_DATA_6_GPIO_PIN);
            else
                GLCD_PORT_DATA_6 &= ~(1<<GLCD_DATA_6_GPIO_PIN);

            if(data & (1<<7))
                GLCD_PORT_DATA_7 |= (1<<GLCD_DATA_7_GPIO_PIN);
            else
                GLCD_PORT_DATA_7 &= ~(1<<GLCD_DATA_7_GPIO_PIN);

        }
        #endif

        //GLCD_PORT_DATA_ALL = data;
	}

	glcd_enable();

}
#endif

/******************************************************************************************************/

#if (USE_glcd_clear == YES)
void glcd_clear(void)   //CLEAR THE SCREEN
{
  unsigned char x, y;

  for(y = 0; y < 64; y=y+8)
  {
	for(x = 0; x < 128; x++)
	{
		glcd_gotoxy(x,y);
		glcd_write_byte(0);
    }
  }
}
#endif

/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
