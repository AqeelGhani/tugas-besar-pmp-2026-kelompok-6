#include <Arduino.h>
#include "catalog.h"
#include "eepromControl.h"
#include "constant.h"

CatalogItem catalog[85];

void setup() {
  Serial.begin(9600);
  
  InitializeCatalog(catalog, sizeof(catalog)/sizeof(catalog[0]));

  InitializeEEPROM(catalog, sizeof(catalog)/sizeof(catalog[0]));
}

void loop() {
  // put your main code here, to run repeatedly:
}
