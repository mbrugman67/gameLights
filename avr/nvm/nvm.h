/***************************************************
 * file: nvm.h
 ***************************************************
 * handle non-vol memory.  Parameters, settings, 
 * and such will be stored in EEPROM
 **************************************************/
#ifndef NVM_H_
#define NVM_H_

#include <stdint.h>

#define EEPROM_SIGNATURE    0xCAFE
#define MODE_WINKY          0
#define MODE_RAINBOW        1
#define MODE_FADE           2
#define MODE_END_OF_MODES   3

#define MODE_CAB_OFF        0
#define MODE_CAB_RED        1
#define MODE_CAB_YEL        2
#define MODE_CAB_GRN        3
#define MODE_CAB_CYN        4
#define MODE_CAB_BLU        5
#define MODE_CAB_MAG        6
#define MODE_CAB_RBW        7
#define MODE_CAB_END        8

class nvm
{
public:
    nvm() {}
    ~nvm() {}
    
    void saveNVM();
    bool loadNVM();
    void setDefaults();

    uint16_t getSignature()         { return (data.signature); }
    uint16_t getNVMVersion()        { return (data.version); }
    uint16_t getBootCount()         { return (data.bootCount); }
    uint16_t getMarqueeMode()       { return (data.mode); }
    uint16_t getCabMode()           { return (data.cabMode); }

    void setMarqueeMode(uint16_t m) { data.mode = m; }
    void setCabMode(uint16_t m)     { data.cabMode = m; } 


private:
    struct nvm_store_t
    {
        uint16_t    signature;
        uint16_t    version;
        uint16_t    bootCount;
        uint16_t    mode;
        uint16_t    cabMode;
    };

    nvm_store_t data;
};

#endif // NVM_H_