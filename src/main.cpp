#include <Arduino.h>
#include "catalog.h"
#include "eepromControl.h"
#include "constant.h"
#include "serialUI.h"

CatalogItem catalog[MAX_ITEMS];

void setup() {
  Serial.begin(9600);
  Serial.println("Start");
  
  InitializeCatalog(catalog, MAX_ITEMS);

  ReadEEPROM(catalog, MAX_ITEMS);
}

void loop() {
  // put your main code here, to run repeatedly:
  runSystem(catalog, MAX_ITEMS);
}
