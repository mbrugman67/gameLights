#ifndef _PROJECT_H_INCLUDED
#define _PROJECT_H_INCLUDED

/*******************************************
* Project globals
*******************************************/
#include <stdint.h>

#include "./nvm/nvm.h"
#include "./string/LEDString.h"
#include "./buttons/buttons.h"

extern nvm settings;

/*********************************************
* Number of LEDS in the metronome string
**********************************************/
#define STRING_LENGTH   211
#define MARQUEE_LENGTH  168

/*********************************************
* Number of tasks, and by definition, interval
* in MS between task iterations
**********************************************/
#define TASK_INTERVAL   4

#define true    1
#define false   0

#ifndef BIT
#define BIT(x) (1u << x)
#endif

#ifndef SETBIT
#define	SETBIT(a, b)	(a |= BIT(b))
#endif

#ifndef GETBIT
#define	GETBIT(a, b)	(a & BIT(b))
#endif

#ifndef CLRBIT
#define CLRBIT(a, b)	(a &= ~BIT(b))
#endif

uint32_t getTickCount();

#endif // _PROJECT_H_INCLUDED
