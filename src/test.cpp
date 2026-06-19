#include <Arduino.h>
#include "catalog.h"
#include "delete.h"

CatalogItem catalog[85];

void setup() {
    Serial.begin(9600);

    // INIT DATA
    InitializeCatalog(catalog, 85);

    // BUAT DATA CONTOH
    UpdateNamaKomponen(&catalog[10], (char*)"TESTDATA");

    Serial.println(F("=== SEBELUM DELETE ==="));

    char nama[9];
    GetNamaKomponen(&catalog[10], nama);

    Serial.print(F("Nama: "));
    Serial.println(nama);

    // TEST DELETE + KONFIRMASI
    DeleteItem(catalog, 85, 10);
}

void loop() {
}