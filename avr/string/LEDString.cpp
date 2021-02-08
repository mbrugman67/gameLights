#include <stdlib.h>
#include <string.h>

#include <avr/io.h>

#include "../project.h"

#ifdef DEBUG
#include <stdio.h>
#include <avr/pgmspace.h>
#endif

#define RAINBOW_LENGTH      7
const uint8_t rnbw[RAINBOW_LENGTH][3] = {{255, 0, 0}, {255, 80, 0}, {255, 255, 0},
                                        {0, 255, 0}, {0, 80, 255}, {0, 0, 255},
                                        {80, 0, 255}};

LEDString::LEDString() : leds()
{
    leds.setOutput(&PORTD, &DDRD, PIND4);

    mode = settings.getMarqueeMode();
    if (mode >= MODE_END_OF_MODES)
    {
        mode = MODE_WINKY;
    }

    cabMode = settings.getCabMode();
    if (cabMode >= MODE_CAB_END)
    {
        cabMode = MODE_CAB_OFF;
    }
    this->nextCabMode(true);
}

void LEDString::nextCabMode(bool justSet)
{
    pixel.r = 0; 
    pixel.g = 0;
    pixel.b = 0;

    if (!justSet)
    {
        ++cabMode;
        cabMode %= MODE_CAB_END;
    }

    switch (cabMode)
    {
        default:
        case MODE_CAB_OFF:
        {
            //
        }  break;
        case MODE_CAB_RED:
        {
            pixel.r = 255;
        }  break;
        case MODE_CAB_YEL:
        {
            pixel.r = 255;
            pixel.g = 255;
        }  break;
        case MODE_CAB_GRN:
        {
            pixel.g = 255;
        }  break;
        case MODE_CAB_CYN:
        {
            pixel.g = 255;
            pixel.b = 255;
        }  break;
        case MODE_CAB_BLU:
        {
            pixel.b = 255;
        }  break;
        case MODE_CAB_MAG:
        {
            pixel.b = 255;
            pixel.r = 255;
        }  break;
        case MODE_CAB_RBW:
        {
            this->cabFade(true);
        }
    }

    if (cabMode != MODE_CAB_RBW)
    {
        for (uint16_t ii = MARQUEE_LENGTH; ii < STRING_LENGTH; ++ii)
        {
            leds.set_crgb_at(ii, pixel);
        }
    }

    draw = true;
}

void LEDString::nextMarqueeMode(void)
{
    ++mode;
    mode %= MODE_END_OF_MODES;

    if (mode == MODE_FADE)
    {
        this->fade(true);
    }
    else if (mode == MODE_RAINBOW)
    {
        this->rainbow(true);
    }

#ifdef DEBUG
    printf_P(PSTR("Marquee mode to %d\n"), mode);
#endif
}

void LEDString::cabFade(bool first)
{
    static uint8_t cstate = 0;

    if (first)
    {
        cstate = 0;
    }

    switch (cstate)
    {
        default:
        case 0:
        {
            pixelCabFade.r = 255;
            pixelCabFade.g = 255;
            pixelCabFade.b = 0;
            cstate = 1;
        }  // intentional fall through

        case 1:
        {
            --pixelCabFade.r;
            ++pixelCabFade.g;

            if (!pixelCabFade.r)
            {
                pixelCabFade.g = 255;
                cstate = 2;
            }
        }  break;

        case 2:
        {
            --pixelCabFade.g;
            ++pixelCabFade.b;

            if (!pixelCabFade.g)
            {
                pixelCabFade.b = 255;
                cstate = 3;
            }
        }  break;

        case 3:
        {
            --pixelCabFade.b;
            ++pixelCabFade.r;

            if (!pixelCabFade.b)
            {
                cstate = 0;
            }
        }  break;
    }

    for (uint16_t ii = MARQUEE_LENGTH; ii < STRING_LENGTH; ++ii)
    {
        leds.set_crgb_at(ii, pixelCabFade);
    }

    draw = true;
}

void LEDString::fade(bool first)
{
    static uint8_t state = 0;

    if (first)
    {
        state = 0;
    }

    switch (state)
    {
        default:
        case 0:
        {
            pixel.r = 255;
            pixel.g = 0;
            pixel.b = 0;
            state = 1;
        }  // intentional fall through

        case 1:
        {
            --pixel.r;
            ++pixel.g;

            if (!pixel.r)
            {
                pixel.g = 255;
                state = 2;
            }
        }  break;

        case 2:
        {
            --pixel.g;
            ++pixel.b;

            if (!pixel.g)
            {
                pixel.b = 255;
                state = 3;
            }
        }  break;

        case 3:
        {
            --pixel.b;
            ++pixel.r;

            if (!pixel.b)
            {
                state = 0;
            }
        }  break;
    }

    for (uint16_t ii = 0; ii < MARQUEE_LENGTH; ++ii)
    {
        leds.set_crgb_at(ii, pixel);
    }

    draw = true;
}

void LEDString::rainbow(bool start)
{
    static uint16_t begin = 0;
    static uint16_t step = 0;

    if (start)
    {
        begin = 0;
        step = 0;
    }

    uint16_t offset = begin;

    if (!(step % 8))
    {
        for (uint16_t ii = 0; ii < MARQUEE_LENGTH; ++ii)
        {
            pixel.r = rnbw[offset][0];
            pixel.g = rnbw[offset][1];
            pixel.b = rnbw[offset][2];

            leds.set_crgb_at(ii, pixel);

            ++offset;
            offset %= RAINBOW_LENGTH;
        }

        ++begin;
        begin %= MARQUEE_LENGTH;

        draw = true;
    }
    ++step;
}

void LEDString::winky()
{
    static uint16_t step = 0;

    if (!(step % 4))
    {
        for (uint16_t ii = 0; ii < MARQUEE_LENGTH; ++ii)
        {
            pixel.r = uint8_t(rand() & 0xff);
            pixel.g = uint8_t(rand() & 0xff);
            pixel.b = uint8_t(rand() & 0xff);

            leds.set_crgb_at(ii, pixel);
        }
        draw = true;
    }
    ++step;
}

void LEDString::update()
{
    if (cabMode == MODE_CAB_RBW)
    {
        this->cabFade(false);
    }

    switch (mode)
    {
        default:
        case MODE_WINKY:
        {
            this->winky();
        }  break;

        case MODE_RAINBOW:
        {
            this->rainbow();
        }  break;

        case MODE_FADE:
        {
            this->fade();
        }  break;
    }

    if (draw)
    {
        leds.sync();
        draw = false;
    }
}