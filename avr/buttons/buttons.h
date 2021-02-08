/***************************************************
 * file: buttons.h
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
#ifndef BUTTONS_H_
#define BUTTONS_H_

#include <stdint.h>
#include "../sys/ioDefinitions.h"

#define BUTTON_OFF      (uint8_t)0x00   // Up, or unpressed
#define BUTTON_DOWN     (uint8_t)0x01   // pressed, but not yet held
#define BUTTON_HELD     (uint8_t)0x02   // pressed and held
class buttons
{
public:
    buttons();
    ~buttons() {}

    // this method must be called exactly once per task time
    void update();

    // two buttons
    bool isMarqueePressed()      { return (isButtonOn(btns[MARQUEE].state)); }
    bool isMarqueeHeld()         { return (isButtonHeld(btns[MARQUEE].state)); }
    bool MarqueeOneShot()        { return (btns[MARQUEE].oneShot); }

    bool isCabPressed()          { return (isButtonOn(btns[CABINET].state)); }
    bool isCabHeld()             { return (isButtonHeld(btns[CABINET].state)); }
    bool cabOneShot()            { return (btns[CABINET].oneShot); }

private:
    enum BUTTONS 
    {
        MARQUEE,
        CABINET,
        BUTTON_COUNT
    };

    // Handy struct to hold everything for 
    // all four buttons
    struct button_t
    {
        uint8_t     state : 2;
        uint8_t     oneShot : 1;
        uint8_t     oneShotLatch : 1;
        uint8_t     padding : 4;
        uint8_t     time;
        char        name[8];
        bool        (*btnFnc)(void);
    };

    button_t btns[BUTTON_COUNT];

    inline void setButton(uint8_t btn, uint8_t state)
    {
        btn = state;
    }

    inline bool isButtonOff(uint8_t btn)
    {
        return (btn == BUTTON_OFF);
    }

    inline bool isButtonOn(uint8_t btn)
    {
        return (btn == BUTTON_DOWN);
    }

    inline bool isButtonHeld(uint8_t btn)
    {
        return (btn == BUTTON_HELD);
    }

#ifdef DEBUG
    inline const char* buttonStateToText(uint8_t s)
    {
        switch (s)
        {
            case BUTTON_OFF:     return ("up");     break;
            case BUTTON_DOWN:   return ("down");    break;
            case BUTTON_HELD:   return ("held");    break;
        }
        return ("");
    }
#endif
};

#endif // BUTTONS_H_