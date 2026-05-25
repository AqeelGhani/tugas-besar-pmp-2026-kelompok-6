#include <Arduino.h>
#include "testHFile.h"
#include <EEPROM.h>
#include "catalog.h"
#include "eepromControl.h"

CatalogItem catalog[85];

void setup() {
    Serial.begin(9600);

    InitializeCatalog(catalog, sizeof(catalog)/sizeof(catalog[0]));

    InitializeEEPROM(catalog, sizeof(catalog)/sizeof(catalog[0]));

    Serial.print("EEPROM Size: ");
    Serial.println(EEPROM.length());
    Serial.print("Catalog Size : ");
    Serial.println((short)sizeof(catalog));
    Serial.print("Catalog Item Size: ");
    Serial.println((short)sizeof(catalog[0]));
    
    char newNama[9], newPIC[5];
    
    GetNamaKomponen(&catalog[84], newNama);
    GetPIC(&catalog[84], newPIC);

    Serial.print(newNama);
    Serial.print(" ");
    Serial.print(GetJumlahStock(&catalog[84]));
    Serial.print(" ");
    Serial.print(GetLokasi(&catalog[84]));
    Serial.print(" ");
    Serial.print(GetStatusTersedia(&catalog[84]));
    Serial.print(" ");
    Serial.print(GetStatusDipinjam(&catalog[84]));
    Serial.print(" ");
    Serial.print(GetStatusRusak(&catalog[84]));
    Serial.print(" ");
    Serial.print(GetKategori(&catalog[84]));
    Serial.print(" ");
    Serial.println(newPIC);
}

void loop() {
    SayHello();
    char nama[9] = "tes3", PIC[5] = "knth";
    
    UpdateNamaKomponen(&catalog[84], nama);
    UpdateLokasi(&catalog[84], 24);
    UpdateStatusTersedia(&catalog[84], 3);
    UpdateStatusDipinjam(&catalog[84], 45);
    UpdateStatusRusak(&catalog[84], 56);
    UpdateKategori(&catalog[84], 9);
    UpdatePIC(&catalog[84], PIC);
    
    SaveEEPROM(catalog, sizeof(catalog)/sizeof(catalog[0]));
    delay(1000);
}