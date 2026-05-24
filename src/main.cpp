#include <Arduino.h>
#include "catalog.h"

void setup() {
  Serial.begin(9600);
  
  CatalogItem catalog[93];
  InitializeCatalog(catalog);
}

void loop() {
  // put your main code here, to run repeatedly:
}
