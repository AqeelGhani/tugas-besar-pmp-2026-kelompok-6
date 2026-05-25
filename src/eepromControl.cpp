#include "eepromControl.h"

void FormatEEPROM(){
    EEPROM.update(0, EEPROM_KEY);
    for (unsigned short i = 1; i<EEPROM.length(); ++i){
        EEPROM.update(i, 0);
    }
}

void InitializeEEPROM(CatalogItem catalog[93]){
    if (EEPROM.read(0) != EEPROM_KEY){
        FormatEEPROM();
    } else{
        for (unsigned short i = 0; i<93; ++i){
            EEPROM.get((i*11)+1, catalog[i]);
        }
    }
}

void SaveEEPROM(CatalogItem catalog[93]){
    EEPROM.update(0, EEPROM_KEY);
    for (unsigned short i = 0; i<93; ++i){
        EEPROM.put((i*11)+1, catalog[i]);
    }
}