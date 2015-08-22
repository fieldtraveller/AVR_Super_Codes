/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
AUTHOR: CHARLTON FERNANDES

stepper.h

DESCRIPTION: TO BE USED TO INTERFACE 2 PHASE, 4 WIRE(EXCLUDING COMMON LINES) BIPOLAR/UNIPOLAR STEPPER MOTOR.
*/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/

#ifndef STEPPER_H_
#define STEPPER_H_

/******************************************************************************************************/

#include <avr/io.h>
#include <stdint.h>

/******************************************************************************************************/

#include "cf.h"

/******************************************************************************************************/
//BIT CONTROL MODE(CONTROLS GIVEN INDIVIDUALLY ON EACH LINE)
//BYTE CONTROL MODE(ALL CONTROL SIGNALS ON SINGLE PORT AND CONTROLS GIVEN IN ONE SHOT)
/******************************************************************************************************/

#if ((!defined(STEPPER_LIBRARY_IN_BIT_CONTROL_MODE))&&(!defined(STEPPER_LIBRARY_IN_BYTE_CONTROL_MODE)))

#define STEPPER_LIBRARY_IN_BIT_CONTROL_MODE  NO
#define STEPPER_LIBRARY_IN_BYTE_CONTROL_MODE YES    //IF ALL CONTROL SIGNALS ON SINGLE PORT

#elif ((defined(STEPPER_LIBRARY_IN_BIT_CONTROL_MODE))&&(defined(STEPPER_LIBRARY_IN_BYTE_CONTROL_MODE)))

#error "DEFINE EITHER STEPPER_LIBRARY_IN_BIT_CONTROL_MODE OR STEPPER_LIBRARY_IN_BIT_CONTROL_MODE"

#elif (defined(STEPPER_LIBRARY_IN_BIT_CONTROL_MODE))

#if (STEPPER_LIBRARY_IN_BIT_CONTROL_MODE==YES)
#define STEPPER_LIBRARY_IN_BYTE_CONTROL_MODE NO
#elif (STEPPER_LIBRARY_IN_BIT_CONTROL_MODE==NO)
#define STEPPER_LIBRARY_IN_BYTE_CONTROL_MODE YES
#else
#undef STEPPER_LIBRARY_IN_BIT_CONTROL_MODE
#define STEPPER_LIBRARY_IN_BIT_CONTROL_MODE  NO
#define STEPPER_LIBRARY_IN_BYTE_CONTROL_MODE YES
#endif

#elif (defined(STEPPER_LIBRARY_IN_BYTE_CONTROL_MODE))

#if (STEPPER_LIBRARY_IN_BYTE_CONTROL_MODE==YES)
#define STEPPER_LIBRARY_IN_BIT_CONTROL_MODE NO
#elif (STEPPER_LIBRARY_IN_BYTE_CONTROL_MODE==NO)
#define STEPPER_LIBRARY_IN_BIT_CONTROL_MODE YES
#else
#undef STEPPER_LIBRARY_IN_BYTE_CONTROL_MODE
#define STEPPER_LIBRARY_IN_BIT_CONTROL_MODE  NO
#define STEPPER_LIBRARY_IN_BYTE_CONTROL_MODE YES
#endif

#endif

/******************************************************************************************************/
//STEPPER STRUCT ACCESS MACROS
/******************************************************************************************************/

#if(STEPPER_LIBRARY_IN_BYTE_CONTROL_MODE == YES)

#define STEPPER_VALUE_OF_ADDRESS_OF_DDR_ALL(STEPPER_STRUCT) (STEPPER_STRUCT->STEPPER_ADDRESS_OF_IOR_ALL)
#define STEPPER_VALUE_OF_ADDRESS_OF_PORT_ALL(STEPPER_STRUCT) (STEPPER_STRUCT->STEPPER_ADDRESS_OF_IOR_ALL)

#elif(STEPPER_LIBRARY_IN_BIT_CONTROL_MODE == YES)

#define STEPPER_VALUE_OF_ADDRESS_OF_DDR_A_PLUS(STEPPER_STRUCT) (STEPPER_STRUCT->STEPPER_ADDRESS_OF_IOR_A_PLUS)
#define STEPPER_VALUE_OF_ADDRESS_OF_DDR_A_MINUS(STEPPER_STRUCT) (STEPPER_STRUCT->STEPPER_ADDRESS_OF_IOR_A_MINUS)
#define STEPPER_VALUE_OF_ADDRESS_OF_DDR_B_PLUS(STEPPER_STRUCT) (STEPPER_STRUCT->STEPPER_ADDRESS_OF_IOR_B_PLUS)
#define STEPPER_VALUE_OF_ADDRESS_OF_DDR_B_MINUS(STEPPER_STRUCT) (STEPPER_STRUCT->STEPPER_ADDRESS_OF_IOR_B_MINUS)

#define STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_PLUS(STEPPER_STRUCT) (STEPPER_STRUCT->STEPPER_ADDRESS_OF_IOR_A_PLUS)
#define STEPPER_VALUE_OF_ADDRESS_OF_PORT_A_MINUS(STEPPER_STRUCT) (STEPPER_STRUCT->STEPPER_ADDRESS_OF_IOR_A_MINUS)
#define STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_PLUS(STEPPER_STRUCT) (STEPPER_STRUCT->STEPPER_ADDRESS_OF_IOR_B_PLUS)
#define STEPPER_VALUE_OF_ADDRESS_OF_PORT_B_MINUS(STEPPER_STRUCT) (STEPPER_STRUCT->STEPPER_ADDRESS_OF_IOR_B_MINUS)

#endif

#define STEPPER_VALUE_OF_A_PLUS_GPIO_PIN(STEPPER_STRUCT) (STEPPER_STRUCT->STEPPER_A_PLUS_GPIO_PIN)
#define STEPPER_VALUE_OF_A_MINUS_GPIO_PIN(STEPPER_STRUCT) (STEPPER_STRUCT->STEPPER_A_MINUS_GPIO_PIN)
#define STEPPER_VALUE_OF_B_PLUS_GPIO_PIN(STEPPER_STRUCT) (STEPPER_STRUCT->STEPPER_B_PLUS_GPIO_PIN)
#define STEPPER_VALUE_OF_B_MINUS_GPIO_PIN(STEPPER_STRUCT) (STEPPER_STRUCT->STEPPER_B_MINUS_GPIO_PIN)

#define STEPPER_VALUE_OF_FLAG(STEPPER_STRUCT) (STEPPER_STRUCT->STEPPER_FLAG)
#define STEPPER_VALUE_OF_NEXT_STEP(STEPPER_STRUCT) (STEPPER_VALUE_OF_FLAG(STEPPER_STRUCT) & ~(1<<7))

/******************************************************************************************************/
//UNIPOLAR OR BIPOLAR SELECTION
/******************************************************************************************************/

#if ((!defined(STEPPER_MIX_TYPES))&&(!defined(STEPPER_UNIPOLAR_TYPE))&&(!defined(STEPPER_BIPOLAR_TYPE)))

#define STEPPER_UNIPOLAR_TYPE NO
#define STEPPER_BIPOLAR_TYPE YES

#elif (defined(STEPPER_MIX_TYPES))

#if (STEPPER_MIX_TYPES == YES)
#define STEPPER_UNIPOLAR_TYPE YES
#define STEPPER_BIPOLAR_TYPE YES
#elif (STEPPER_MIX_TYPES == NO)
#define STEPPER_UNIPOLAR_TYPE NO
#define STEPPER_BIPOLAR_TYPE YES
#else
#undef STEPPER_MIX_TYPES
#define STEPPER_MIX_TYPES NO
#define STEPPER_UNIPOLAR_TYPE NO
#define STEPPER_BIPOLAR_TYPE YES
#endif

#elif ((defined(STEPPER_UNIPOLAR_TYPE))&&(!defined(STEPPER_BIPOLAR_TYPE)))

#if (STEPPER_UNIPOLAR_TYPE==YES)
#define STEPPER_BIPOLAR_TYPE NO
#elif (STEPPER_UNIPOLAR_TYPE==NO)
#define STEPPER_BIPOLAR_TYPE YES
#else
#undef STEPPER_UNIPOLAR_TYPE
#define STEPPER_UNIPOLAR_TYPE NO
#define STEPPER_BIPOLAR_TYPE YES
#endif

#elif ((!defined(STEPPER_UNIPOLAR_TYPE))&&(defined(STEPPER_BIPOLAR_TYPE)))

#if (STEPPER_BIIPOLAR_TYPE==YES)
#define STEPPER_UNPOLAR_TYPE NO
#elif (STEPPER_BIIPOLAR_TYPE==NO)
#define STEPPER_UNPOLAR_TYPE YES
#else
#undef STEPPER_BIIPOLAR_TYPE
#define STEPPER_UNIPOLAR_TYPE NO
#define STEPPER_BIPOLAR_TYPE YES
#endif

#elif ((defined(STEPPER_UNIPOLAR_TYPE))&&(defined(STEPPER_BIPOLAR_TYPE)))
#define STEPPER_MIX_TYPES YES
#endif

/******************************************************************************************************/
//USER DEFINED DATA TYPES
/******************************************************************************************************/

struct STEPPER_STRUCT
{
    #if (STEPPER_LIBRARY_IN_BYTE_CONTROL_MODE == YES)

    uint8_t* STEPPER_ADDRESS_OF_IOR_ALL;

    #elif (STEPPER_LIBRARY_IN_BIT_CONTROL_MODE == YES)

    uint8_t* STEPPER_ADDRESS_OF_IOR_A_PLUS;
    uint8_t* STEPPER_ADDRESS_OF_IOR_A_MINUS;
    uint8_t* STEPPER_ADDRESS_OF_IOR_B_PLUS;
    uint8_t* STEPPER_ADDRESS_OF_IOR_B_MINUS;

    #endif

    uint8_t STEPPER_A_PLUS_GPIO_PIN;
    uint8_t STEPPER_A_MINUS_GPIO_PIN;
    uint8_t STEPPER_B_PLUS_GPIO_PIN;
    uint8_t STEPPER_B_MINUS_GPIO_PIN;

    uint8_t STEPPER_FLAG;
};

/******************************************************************************************************/

#define STEPPER struct STEPPER_STRUCT

/******************************************************************************************************/
//USE MACROS
/******************************************************************************************************/

#ifndef USE_stepper_init
#define USE_stepper_init YES
#endif

#ifndef USE_stepper_step
#define USE_stepper_step YES
#endif

#ifndef USE_stepper_next_full_step_high_torque_cw
#define USE_stepper_next_full_step_high_torque_cw YES
#endif

#ifndef USE_stepper_next_full_step_low_torque_cw
#define USE_stepper_next_full_step_low_torque_cw NO
#endif

#ifndef USE_stepper_next_half_step_cw
#define USE_stepper_next_half_step_cw NO
#endif

#ifndef USE_stepper_next_full_step_high_torque_ccw
#define USE_stepper_next_full_step_high_torque_ccw NO
#endif

#ifndef USE_stepper_next_full_step_low_torque_ccw
#define USE_stepper_next_full_step_low_torque_ccw NO
#endif

#ifndef USE_stepper_next_half_step_ccw
#define USE_stepper_next_half_step_ccw NO
#endif

/******************************************************************************************************/
//FUNCTION PROTOTYPE
/******************************************************************************************************/

#if (USE_stepper_init==YES)
void stepper_init(STEPPER*);
#endif

#if (USE_stepper_step==YES)
void stepper_step(STEPPER*);
#endif

#if (USE_stepper_next_full_step_high_torque_cw==YES)
void stepper_next_full_step_high_torque_cw(STEPPER*);
#endif

#if (USE_stepper_next_full_step_low_torque_cw==YES)
void stepper_next_full_step_low_torque_cw(STEPPER*);
#endif

#if (USE_stepper_next_half_step_cw==YES)
void stepper_next_half_step_cw(STEPPER*);
#endif

#if (USE_stepper_next_full_step_high_torque_ccw==YES)
void stepper_next_full_step_high_torque_ccw(STEPPER*);
#endif

#if (USE_stepper_next_full_step_low_torque_ccw==YES)
void stepper_next_full_step_low_torque_ccw(STEPPER*);
#endif

#if (USE_stepper_next_half_step_ccw==YES)
void stepper_next_half_step_ccw(STEPPER*);
#endif

/******************************************************************************************************/

#endif

/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
