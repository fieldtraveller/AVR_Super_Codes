/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
/*
AUTHOR:CHARLTON FERNANDES

delays.h

DESCRIPTION: PROVIDES TIME DELAY IN SPECIFIED MICRO-SECONDS AND MILLI-SECONDS.
             ACCURACY VERY POOR FOR MICRO-SECOND DELAY

*/
/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/

#ifndef DELAYS_H_
#define DELAYS_H_ 1

/******************************************************************************************************/

#ifndef DELAY_FUDGE_FACTOR_MS
#define DELAY_FUDGE_FACTOR_MS 1996
#endif

#ifndef DELAY_FUDGE_FACTOR_US
#define DELAY_FUDGE_FACTOR_US 2
#endif

/******************************************************************************************************/
//FUNCTION PROTOTYPES
/******************************************************************************************************/

static inline void delay_ms(unsigned int) __attribute__((always_inline));
static inline void delay_us(unsigned int) __attribute__((always_inline));

/******************************************************************************************************/

#endif

/******************************************************************************************************/
/*ALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEXALEX*/
/******************************************************************************************************/
