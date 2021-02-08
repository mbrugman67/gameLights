#ifndef STRING_H_
#define STRING_H_

#include <stdint.h>

#include "../project.h"
#include "../sys/ws2812/WS2812.h"
#include "../sys/ws2812/cRGB.h"
#include "../sys/ioDefinitions.h"

class LEDString
{
public:
    LEDString();
    ~LEDString() {}

    void nextMarqueeMode(void);
    void nextCabMode(bool justSet = false);
    void update();

    uint16_t getMarqueeMode()   { return (mode); }
    uint16_t getCabinetMode()   { return (cabMode); }
    
private:
    WS2812 leds;
    cRGB pixel;
    cRGB pixelCabFade;

    uint16_t mode;
    uint16_t cabMode;

    bool draw;

    void winky(void);
    void rainbow(bool start = false);
    void fade(bool first = false);
    void cabFade(bool first = false);
};

#endif // STRING_H_