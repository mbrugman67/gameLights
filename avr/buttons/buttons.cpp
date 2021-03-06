/***************************************************
 * file: buttons.cpp
 ***************************************************
 * handle hardware buttons.  Buttons may be in 
 * one of 3 possible states:
 *  BUTTON_OFF - button is release
 *  BUTTON_DOWN - button has been pressed
 *  BUTTON_HELD - button has been held down
 * 
 * There are two buttons:
 *  Marquee
 *  Cabinet
 * 
 * This class handles those things, plus debounce 
 * for the "down" state
 **************************************************/
#include <stdlib.h>
#include <string.h>

#include "../project.h"

#ifdef DEBUG
#include <stdio.h>
#include <avr/pgmspace.h>
#endif

/************************************************
 * fnXXXXBtn()
 ************************************************
 * Generic static functions for the button action 
 ***********************************************/ 
static inline bool fnMarqueeBtn()
{
    if (MARQUEE_BUTTON())      return (false);
    else                    return (true);
}

static inline bool fnCabBtn()
{
    if (CABINET_BUTTON())      return (false);
    else                    return (true);
}


// debounce and "HOLD" time in milliseconds, converted
// to task update intervals
#define DEBOUNCE_TIME   20 / (TASK_INTERVAL)
#define HOLD_TIME       500 / (TASK_INTERVAL)

/************************************************
 * getInstance()
 ************************************************
 * return an pointer to the single instance
 * of this class.  If it hasn't been instantiated
 * yet, do it now.  
 ***********************************************/ 
buttons::buttons()
{
    // button function pointers into the button structure
    btns[MARQUEE].btnFnc    = fnMarqueeBtn;
    btns[CABINET].btnFnc    = fnCabBtn;

    strncpy(btns[MARQUEE].name, "Marquee", 8);
    strncpy(btns[CABINET].name, "Cabinet", 8);
}

/************************************************
 * update()
 ************************************************
 * handle the I/O for all 4 buttons.  This needs
 * to happen exactly once per task interval  
 ***********************************************/ 
void buttons::update()
{
#ifdef DEBUG
    static button_t last[BUTTON_COUNT];
    for (size_t ii = 0; ii < BUTTON_COUNT; ++ii)
    {
        if (last[ii].state != btns[ii].state)
        {
            printf_P(PSTR("%s button from %s to %s\n"),
                btns[ii].name,
                this->buttonStateToText(last[ii].state),
                this->buttonStateToText(btns[ii].state));
        }
        last[ii].state = btns[ii].state;
    }   
#endif

    for (size_t ii = 0; ii < BUTTON_COUNT; ++ii)
    {
        ++btns[ii].time;
        btns[ii].oneShot = false;
        
        if (!btns[ii].btnFnc())
        {
            btns[ii].time = 0;
            btns[ii].oneShotLatch = false;
            btns[ii].state = BUTTON_OFF;
        } 
        else if (btns[ii].time > HOLD_TIME)
        {
            // set the on time to be held time
            // plus one.  The problem would be
            // if held for a long time, the integer
            // will rollover and we'll get an 
            // unwanted "up" and "down" event
            btns[ii].time = HOLD_TIME + 1;
            btns[ii].state = BUTTON_HELD;
        }
        else if (btns[ii].time > DEBOUNCE_TIME)
        {
            btns[ii].state = BUTTON_DOWN;

            if (!btns[ii].oneShotLatch)
            {
                btns[ii].oneShotLatch = true;
                btns[ii].oneShot = true;
            }
        }
    }
}
