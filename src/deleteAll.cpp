#include <Arduino.h>
#include "catalog.h"
#include "eepromControl.h"
#include "deleteAll.h"

void deleteAll(CatalogItem catalog[], unsigned short arraySize) {
    Serial.println(F("\n!!! PERINGATAN BAHAYA !!!"));
    Serial.println(F("Anda akan menghapus SELURUH data inventaris dari memori."));
    Serial.println(F("Apakah Anda yakin ingin melanjutkan? (Y/N): "));

    // Tunggu input konfirmasi pertama
    while (!Serial.available()) {}
    char confirmDelete = Serial.read();

    while (Serial.available() > 0) Serial.read();

    // Jika input bukan Y atau y, batalkan
    if (confirmDelete != 'Y' && confirmDelete != 'y') {
        Serial.println(F("\nOperasi Hapus Semua DIBATALKAN."));
        return;
    }

    InitializeCatalog(catalog, arraySize);
    Serial.println(F("\nSUCCESS: Seluruh data di memori sementara (SRAM) telah dikosongkan!"));

    // Prompt untuk Save ke EEPROM
    Serial.println(F("\nApakah Anda ingin menyimpan reset kosong secara PERMANEN ke EEPROM? (Y/N): "));
    
    // Tunggu input konfirmasi kedua
    while (!Serial.available()) {}
    char confirmSave = Serial.read();

    // Bersihkan sisa karakter di buffer
    while (Serial.available() > 0) Serial.read();

    // Jika pengguna setuju menyimpan ke EEPROM
    if (confirmSave == 'Y' || confirmSave == 'y') {
        Serial.println(F("\n[Saving to EEPROM...]"));
        SaveEEPROM(catalog, arraySize);
        Serial.println(F("SUCCESS: Data EEPROM telah di-reset! Sistem kembali seperti baru."));
    } else {
        Serial.println(F("\nPenyimpanan EEPROM dibatalkan."));
        Serial.println(F("(Catatan: Data lama akan kembali muncul jika Arduino di-restart)."));
    }
}