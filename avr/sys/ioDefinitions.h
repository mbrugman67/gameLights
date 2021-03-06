/***************************************************
 * file: ioDefinitions.h
 ***************************************************
 * Friendly names for the I/O points.  For each 
 * point there are macros for
 * ON() - set to on state
 * OFF() - set to off state
 * TGL() - toggle output state
 * SET(x) - set to on/off as commanded
 * GET() - get the input state
 * 
 * The first set of macros use the name of the 
 * I/O point as stenciled on the board.
 * 
 * If they are used in the project, there are
 * macros that have a functional name below
 **************************************************/
#ifndef IO_DEF_H_
#define IO_DEF_H_

#include <avr/io.h>
#include "../project.h"

// pins AD0 to AD5 are on port C
#define PIN_AD0_ON()        (SETBIT(PORTC, PORTC0))
#define PIN_AD0_OFF()       (CLRBIT(PORTC, PORTC0))
#define PIN_AD0_TGL()       (SETBIT(PINC, PORTC0))
#define PIN_AD0_SET(x)      if(x){SETBIT(PORTC, PORTC0);} else {CLRBIT(PORTC, PORTC0);}
#define PIN_AD0_GET()       (GETBIT(PINC, PORTC0))

#define PIN_AD1_ON()        (SETBIT(PORTC, PORTC1))
#define PIN_AD1_OFF()       (CLRBIT(PORTC, PORTC1))
#define PIN_AD1_TGL()       (SETBIT(PINC, PORTC1))
#define PIN_AD1_SET(x)      if(x){SETBIT(PORTC, PORTC1);} else {CLRBIT(PORTC, PORTC1);}
#define PIN_AD1_GET()       (GETBIT(PINC, PORTC1))

#define PIN_AD2_ON()        (SETBIT(PORTC, PORTC2))
#define PIN_AD2_OFF()       (CLRBIT(PORTC, PORTC2))
#define PIN_AD2_TGL()       (SETBIT(PINC, PORTC2))
#define PIN_AD2_SET(x)      if(x){SETBIT(PORTC, PORTC2);} else {CLRBIT(PORTC, PORTC2);}
#define PIN_AD2_GET()       (GETBIT(PINC, PORTC2))

#define PIN_AD3_ON()        (SETBIT(PORTC, PORTC3))
#define PIN_AD3_OFF()       (CLRBIT(PORTC, PORTC3))
#define PIN_AD3_TGL()       (SETBIT(PINC, PORTC3))
#define PIN_AD3_SET(x)      if(x){SETBIT(PORTC, PORTC3);} else {CLRBIT(PORTC, PORTC3);}
#define PIN_AD3_GET()       (GETBIT(PINC, PORTC3))

#define PIN_AD4_ON()        (SETBIT(PORTC, PORTC4))
#define PIN_AD4_OFF()       (CLRBIT(PORTC, PORTC4))
#define PIN_AD4_TGL()       (SETBIT(PINC, PORTC4))
#define PIN_AD4_SET(x)      if(x){SETBIT(PORTC, PORTC4);} else {CLRBIT(PORTC, PORTC4);}
#define PIN_AD4_GET()       (GETBIT(PINC, PORTC4))

#define PIN_AD5_ON()        (SETBIT(PORTC, PORTC5))
#define PIN_AD5_OFF()       (CLRBIT(PORTC, PORTC5))
#define PIN_AD5_TGL()       (SETBIT(PINC, PORTC5))
#define PIN_AD5_SET(x)      if(x){SETBIT(PORTC, PORTC5);} else {CLRBIT(PORTC, PORTC5);}
#define PIN_AD5_GET()       (GETBIT(PINC, PORTC5))

// Pins 0 to 7 are port D
/* DO NOT USE pins 0 and 1 - Serial port to USB
#define PIN_IO0_ON()        (SETBIT(PORTD, PORTD0))
#define PIN_IO0_OFF()       (CLRBIT(PORTD, PORTD0))
#define PIN_IO0_TGL()       (SETBIT(PIND, PORTD0))
#define PIN_IO0_SET(x)      if(x){SETBIT(PORTD, PORTD0);} else {CLRBIT(PORTD, PORTD0);}
#define PIN_IO0_GET()       (GETBIT(PORTD, PORTD0))

#define PIN_IO1_ON()        (SETBIT(PORTD, PORTD1))
#define PIN_IO1_OFF()       (CLRBIT(PORTD, PORTD1))
#define PIN_IO1_TGL()       (SETBIT(PIND, PORTD1))
#define PIN_IO1_SET(x)      if(x){SETBIT(PORTD, PORTD1);} else {CLRBIT(PORTD, PORTD1);}
#define PIN_IO1_GET()       (GETBIT(PORTD, PORTD1))
*/

#define PIN_IO2_ON()        (SETBIT(PORTD, PORTD2))
#define PIN_IO2_OFF()       (CLRBIT(PORTD, PORTD2))
#define PIN_IO2_TGL()       (SETBIT(PIND, PORTD2))
#define PIN_IO2_SET(x)      if(x){SETBIT(PORTD, PORTD2);} else {CLRBIT(PORTD, PORTD2);}
#define PIN_IO2_GET()       (GETBIT(PIND, PORTD2))

#define PIN_IO3_ON()        (SETBIT(PORTD, PORTD3))
#define PIN_IO3_OFF()       (CLRBIT(PORTD, PORTD3))
#define PIN_IO3_TGL()       (SETBIT(PIND, PORTD3))
#define PIN_IO3_SET(x)      if(x){SETBIT(PORTD, PORTD3);} else {CLRBIT(PORTD, PORTD3);}
#define PIN_IO3_GET()       (GETBIT(PIND, PORTD3))

#define PIN_IO4_ON()        (SETBIT(PORTD, PORTD4))
#define PIN_IO4_OFF()       (CLRBIT(PORTD, PORTD4))
#define PIN_IO4_TGL()       (SETBIT(PIND, PORTD4))
#define PIN_IO4_SET(x)      if(x){SETBIT(,PORTD PORTD4);} else {CLRBIT(PORTD, PORTD4);}
#define PIN_IO4_GET()       (GETBIT(PIND, PORTD4))

#define PIN_IO5_ON()        (SETBIT(PORTD, PORTD5))
#define PIN_IO5_OFF()       (CLRBIT(PORTD, PORTD5))
#define PIN_IO5_TGL()       (SETBIT(PIND, PORTD5))
#define PIN_IO5_SET(x)      if(x){SETBIT(PORTD, PORTD5);} else {CLRBIT(PORTD, PORTD5);}
#define PIN_IO5_GET()       (GETBIT(PIND, PORTD5))

#define PIN_IO6_ON()        (SETBIT(PORTD, PORTD6))
#define PIN_IO6_OFF()       (CLRBIT(PORTD, PORTD6))
#define PIN_IO6_TGL()       (SETBIT(PIND, PORTD6))
#define PIN_IO6_SET(x)      if(x){SETBIT(PORTD, PORTD6);} else {CLRBIT(PORTD, PORTD6);}
#define PIN_IO6_GET()       (GETBIT(PIND, PORTD6))

#define PIN_IO7_ON()        (SETBIT(PORTD, PORTD7))
#define PIN_IO7_OFF()       (CLRBIT(PORTD, PORTD7))
#define PIN_IO7_TGL()       (SETBIT(PIND, PORTD7))
#define PIN_IO7_SET(x)      if(x){SETBIT(PORTD, PORTD7);} else {CLRBIT(PORTD, PORTD7);}
#define PIN_IO7_GET()       (GETBIT(PIND, PORTD7))

// pins 8 to 13 are port D
#define PIN_IO8_ON()        (SETBIT(PORTB, PORTB0))
#define PIN_IO8_OFF()       (CLRBIT(PORTB, PORTB0))
#define PIN_IO8_TGL()       (SETBIT(PINB, PORTB0))
#define PIN_IO8_SET(x)      if(x){SETBIT(PORTB, PORTB0);} else {CLRBIT(PORTB, PORTB0);}
#define PIN_IO8_GET()       (GETBIT(PINB, PORTB0))

#define PIN_IO9_ON()        (SETBIT(PORTB, PORTB1))
#define PIN_IO9_OFF()       (CLRBIT(PORTB, PORTB1))
#define PIN_IO9_TGL()       (SETBIT(PINB, PORTB1))
#define PIN_IO9_SET(x)      if(x){SETBIT(PORTB, PORTB1);} else {CLRBIT(PORTB, PORTB1);}
#define PIN_IO9_GET()       (GETBIT(PINB, PORTB1))

#define PIN_IO10_ON()        (SETBIT(PORTB, PORTB2))
#define PIN_IO10_OFF()       (CLRBIT(PORTB, PORTB2))
#define PIN_IO10_TGL()       (SETBIT(PINB, PORTB2))
#define PIN_IO10_SET(x)      if(x){SETBIT(PORTB, PORTB2);} else {CLRBIT(PORTB, PORTB2);}
#define PIN_IO10_GET()       (GETBIT(PINB, PORTB2))

#define PIN_IO11_ON()        (SETBIT(PORTB, PORTB3))
#define PIN_IO11_OFF()       (CLRBIT(PORTB, PORTB3))
#define PIN_IO11_TGL()       (SETBIT(PINB, PORTB3))
#define PIN_IO11_SET(x)      if(x){SETBIT(PORTB, PORTB3);} else {CLRBIT(PORTB, PORTB3);}
#define PIN_IO11_GET()       (GETBIT(PINB, PORTB3))

#define PIN_IO12_ON()        (SETBIT(PORTB, PORTB4))
#define PIN_IO12_OFF()       (CLRBIT(PORTB, PORTB4))
#define PIN_IO12_TGL()       (SETBIT(PINB, PORTB4))
#define PIN_IO12_SET(x)      if(x){SETBIT(PORTB, PORTB4);} else {CLRBIT(PORTB, PORTB4);}
#define PIN_IO12_GET()       (GETBIT(PINB, PORTB4))

#define PIN_IO13_ON()        (SETBIT(PORTB, PORTB5))
#define PIN_IO13_OFF()       (CLRBIT(PORTB, PORTB5))
#define PIN_IO13_TGL()       (SETBIT(PINB, PORTB5))
#define PIN_IO13_SET(x)      if(x){SETBIT(PORTB, PORTB5);} else {CLRBIT(PORTB, PORTB5);}
#define PIN_IO13_GET()       (GETBIT(PINB, PORTB5))

/************************************************
 * Application-specific I/O macros
 ***********************************************/
// The "L" LED on the board
#define LED_L_ON()          PIN_IO13_ON()
#define LED_L_OFF()         PIN_IO13_OFF()
#define LED_L_TGL()         PIN_IO13_TGL()
#define LED_L_SET(x)        PIN_IO13_SET(x)
#define LED_L_GET()         PIN_IO13_GET()   

// buttons
#define MARQUEE_BUTTON()     PIN_IO8_GET()
#define CABINET_BUTTON()     PIN_IO9_GET()

#endif //IO_DEF_H_