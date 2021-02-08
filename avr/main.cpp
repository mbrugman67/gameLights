/*
 */
#include <stdio.h>
#include <string.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include <avr/pgmspace.h>

#include "project.h"
#include "sys/hardware.h"
#include "sys/serialPrintf.h"

#include "nvm/nvm.h"
#include "string/LEDString.h"

static volatile uint8_t isrMilliseconds = 0;
static volatile uint8_t isrLastMilleseconds = 0;
static uint32_t milliseconds = 0;

nvm settings;

uint32_t getTickCount()
{
    return (milliseconds);
}

int main(void)
{
    buttons btns;
    uint8_t taskNum = 0;

#ifdef DEBUG
    cfgSerial(S_BAUD_115200, S_FORMAT_8N1);

    // set stdin and stdout to go through the serial port
    FILE uart_str; 
    uart_str.put = USART0SendByte;
    uart_str.get = USART0ReceiveByte;
    uart_str.flags = _FDEV_SETUP_RW;
    stdout = stdin = &uart_str;
#endif

    // init hardware
    setupIO();
    setupTimer2();

    settings.loadNVM();

    LEDString ledstring;

    setupWatchdog();
    sei();

#ifdef DEBUG
    printf_P(PSTR("Starting gameLight main loop, boot count %u\r\n"),
        settings.getBootCount());
#endif

    uint16_t blinkyTimer = 0;

    while (true)
    {
        switch (taskNum)
        {
            case 0:
            {
                ++blinkyTimer;
                if (blinkyTimer < (667 / TASK_INTERVAL))
                {
                    LED_L_SET(true);
                }
                else if (blinkyTimer < (1000 / TASK_INTERVAL))
                {
                    LED_L_SET(false);
                }
                else
                {
                    blinkyTimer = 0;
                }

            }  break;

            case 1:
            {
                btns.update();

                if (btns.MarqueeOneShot())
                {
                    ledstring.nextMarqueeMode();

                    settings.setMarqueeMode(ledstring.getMarqueeMode());
                    settings.saveNVM();
                }

                if (btns.cabOneShot())
                {
                    ledstring.nextCabMode();

                    settings.setCabMode(ledstring.getCabinetMode());
                    settings.saveNVM();
                }
            }  break;
            
            case 2:
            {
                PIN_AD0_TGL();
                ledstring.update();
            }  break;
            
            case 3:
            {
                //

            }  break;
        }

        ++taskNum;
        taskNum %= TASK_INTERVAL;

        // do busy stuff in the dead time between the end of one
        // task and the start of the next
        while (isrMilliseconds == isrLastMilleseconds)
        {
            // busy
        }

        // global millisecond counter
        uint8_t incr = isrMilliseconds - isrLastMilleseconds;
        isrLastMilleseconds = isrMilliseconds;
        milliseconds += (uint32_t)(incr) & 0xff;
        
        wdt_reset();
    }

    return 0;
}

/*****************************************************
* System tick ISR.  Once each millisecond
*****************************************************/
ISR(TIMER2_COMPA_vect, ISR_BLOCK)
{
    ++isrMilliseconds;
    PIN_IO2_TGL();
}
