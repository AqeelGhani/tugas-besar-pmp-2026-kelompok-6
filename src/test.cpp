#include <Arduino.h>
#include "testHFile.h"
#include <EEPROM.h>
#include "catalog.h"

void setup() {
    Serial.begin(9600);

    CatalogItem catalog[93];
    InitializeCatalog(catalog);

    Serial.print("EEPROM Size: ");
    Serial.println(EEPROM.length());
    Serial.print("Catalog Size : ");
    Serial.println((short)sizeof(catalog));
    Serial.print("Catalog Item Size: ");
    Serial.println((short)sizeof(catalog[0]));

    char nama[9] = "tes3", PIC[5] = "knth", newNama[9], newPIC[5];

    UpdateNamaKomponen(&catalog[0], nama);
    UpdateJumlahStock(&catalog[0], 200);
    UpdateLokasi(&catalog[0], 24);
    UpdateStatus(&catalog[0], 0);
    UpdateKategori(&catalog[0], 9);
    UpdatePIC(&catalog[0], PIC);

    GetNamaKomponen(&catalog[0], newNama);
    GetPIC(&catalog[0], newPIC);

    Serial.print(newNama);
    Serial.print(" ");
    Serial.print(GetJumlahStock(&catalog[0]));
    Serial.print(" ");
    Serial.print(GetLokasi(&catalog[0]));
    Serial.print(" ");
    Serial.print(GetStatus(&catalog[0]));
    Serial.print(" ");
    Serial.print(GetKategori(&catalog[0]));
    Serial.print(" ");
    Serial.println(newPIC);
}

void loop() {
    SayHello();
    delay(1000); 
}