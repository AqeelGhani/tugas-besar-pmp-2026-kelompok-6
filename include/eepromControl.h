#ifndef EEPROMCONTROL_H
#define EEPROMCONTROL_H

#include <EEPROM.h>
#include <string.h>
#include "constant.h"
#include "catalog.h"

void ReadEEPROM(CatalogItem catalog[], unsigned short arraySize);

void SaveEEPROM(CatalogItem catalog[], unsigned short arraySize);

#endif