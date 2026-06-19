#include <Arduino.h>
#include <stdio.h>
#include "catalog.h"
#include "Ringkasan.h"

void showRingkasan(CatalogItem catalog[], unsigned short arraySize) {
    // Variabel untuk total akhir
    unsigned short totalSlotTerpakai = 0;
    unsigned short totalBarangTersedia = 0;
    unsigned short totalBarangDipinjam = 0;
    unsigned short totalBarangRusak = 0;

    // Looping untuk membaca dan menjumlahkan seluruh data di array
    for (unsigned short i = 0; i < arraySize; i++) {
        // Hanya hitung jika slot tidak kosong
        if (!IsSlotEmpty(&catalog[i])) {
            totalSlotTerpakai++; // Tambah 1 slot identified untuk ID tidak kosong
            
            // Tambah jumlah stok dari masing-masing status
            totalBarangTersedia += GetStatusTersedia(&catalog[i]);
            totalBarangDipinjam += GetStatusDipinjam(&catalog[i]);
            totalBarangRusak += GetStatusRusak(&catalog[i]);
        }
    }

    // Hitung sisa memori dan total barang
    unsigned short sisaSlot = arraySize - totalSlotTerpakai;
    unsigned short grandTotal = totalBarangTersedia + totalBarangDipinjam + totalBarangRusak;

    // Output dengan Buffer SRAM kecil (~50 byte)
    char buffer[50];

    Serial.println(F("\n=================================================="));
    Serial.println(F("                  RINGKASAN INVENTARIS                "));
    Serial.println(F("=================================================="));

    // STATUS MEMORI (EEPROM)
    Serial.println(F("     -----  STATUS KAPASITAS DATABASE   -----  "));
    sprintf(buffer, "- Slot Terpakai   : %d / %d\n", totalSlotTerpakai, arraySize);
    Serial.print(buffer);
    
    sprintf(buffer, "- Slot Tersisa    : %d\n", sisaSlot);
    Serial.print(buffer);

    // Notify capacity memori hampir abis
    if (sisaSlot <= 5) {
        Serial.println(F("  *** PERINGATAN: KAPASITAS MEMORI HAMPIR HABIS! ***"));
    }
    Serial.println(F("=================================================="));

    // STATUS BARANG
    Serial.println(F("       ------ STATUS KONDISI BARANG LAB ------   "));
    
    sprintf(buffer, "- Siap Digunakan  : %d unit\n", totalBarangTersedia);
    Serial.print(buffer);
    
    sprintf(buffer, "- Sedang Dipinjam : %d unit\n", totalBarangDipinjam);
    Serial.print(buffer);
    
    sprintf(buffer, "- Kondisi Rusak   : %d unit\n", totalBarangRusak);
    Serial.print(buffer);
    
    Serial.println(F("--------------------------------------------------"));
    sprintf(buffer, "GRAND TOTAL : %d unit\n", grandTotal);
    Serial.print(buffer);
    Serial.println(F("==================================================\n"));
}