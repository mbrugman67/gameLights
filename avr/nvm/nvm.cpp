/***************************************************
 * file: nvm.cpp
 ***************************************************
 * handle non-vol memory.  Parameters, settings, 
 * and such will be stored in EEPROM
 **************************************************/

#include "nvm.h"
#include "../project.h"

#include <stdlib.h>

#ifdef DEBUG
#include <stdio.h>
#include <avr/pgmspace.h>
#endif

#include <avr/eeprom.h>

void nvm::setDefaults()
{
    data.signature = EEPROM_SIGNATURE;
    data.bootCount = 0;
    data.mode = MODE_WINKY;
}

void nvm::saveNVM()
{
    eeprom_update_block((void*)&data, (void*)0x100, sizeof(data));
}

bool nvm::loadNVM()
{
    bool retVal = true;

    eeprom_read_block((void*)&data, (void*)0x100, sizeof(data));

    if (data.signature != EEPROM_SIGNATURE)
    {
#ifdef DEBUG
        printf_P(PSTR("Invalid EEPROM signature! 0x%04x\n"),
            data.signature);
#endif

        this->setDefaults();
        retVal = false;
    }

#ifdef DEBUG
    printf_P(PSTR("loadNVM: sig %d, ver %d, bcnt %d, mmode %d, cmode %d\n"),
        data.signature, data.version, data.bootCount, data.mode, data.cabMode);
#endif

    ++data.bootCount;
    this->saveNVM();

    return (retVal);
}
