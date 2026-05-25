#include "eepromControl.h"

void FormatEEPROM(){
    EEPROM.put(0, EEPROM_KEY);
    for (unsigned short i = 4; i<EEPROM.length(); ++i){
        EEPROM.update(i, 0);
    }
}

void InitializeEEPROM(CatalogItem catalog[], unsigned short arraySize){
    uint8_t initialKeyEEPROM[4];
    EEPROM.get(0, initialKeyEEPROM);
    if (memcmp(initialKeyEEPROM, EEPROM_KEY, 4) == 0){
        for (unsigned short i = 0; i<arraySize; ++i){
            EEPROM.get((i*12)+4, catalog[i]);
        }
    } else{
        FormatEEPROM();
    }
}

void SaveEEPROM(CatalogItem catalog[], unsigned short arraySize){
    EEPROM.put(0, EEPROM_KEY);
    for (unsigned short i = 0; i<arraySize; ++i){
        EEPROM.put((i*12)+4, catalog[i]);
    }
}