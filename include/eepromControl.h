#ifndef EEPROMCONTROL_H
#define EEPROMCONTROL_H

#include <EEPROM.h>
#include "constant.h"
#include "catalog.h"

void FormatEEPROM();

void InitializeEEPROM(CatalogItem catalog[93]);

void SaveEEPROM(CatalogItem catalog[93]);

#endif