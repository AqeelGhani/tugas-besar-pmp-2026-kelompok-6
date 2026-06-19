#include <Arduino.h>
#include <stdio.h>
#include "catalog.h"
#include "serialUI.h"
#include "addData.h"
#include "delete.h"
#include "Ringkasan.h"
#include "SearchByID.h"
#include "showAllItem.h"
#include "updateStatus.h"
#include "updateStock.h"
#include "eepromControl.h"

// Fungsi untuk mencetak teks menu agar rapi
void CetakTampilanMenu() {
    Serial.println(F("\n=================================================="));
    Serial.println(F("      SISTEM INVENTARIS LAB EMBEDDED SYSTEMS      "));
    Serial.println(F("=================================================="));
    Serial.println(F("1. Tambah Data Barang      "));
    Serial.println(F("2. Hapus Data Barang       "));
    Serial.println(F("3. Cari Data Berdasarkan ID"));
    Serial.println(F("4. Perbarui Stok Barang    "));
    Serial.println(F("5. Perbarui Status         "));
    Serial.println(F("6. Tampilkan semua item    "));
    Serial.println(F("7. Ringkasan Inventaris    "));
    Serial.println(F("8. Save to EEPROM          "));
    Serial.println(F("=================================================="));
    Serial.print(F("Masukkan pilihan Anda (1-7): "));
}

// ===============================================================================================


// Fungsi pembaca input angka dari Serial Monitor (untuk menghindari error '\n' atau enter)
unsigned short BacaInputAngka() {
    while (Serial.available() == 0) {
        // Tunggu sampai user mengetik
    }
    return Serial.parseInt(); // Langsung mengambil angka dari input
}

// ===============================================================================================
 

// Fungsi utama sistem
void JalankanSistem(CatalogItem catalog[], unsigned short arraySize) {
    CetakTampilanMenu();

    // Tunggu input pilihan menu dari pengguna
    while (Serial.available() == 0) {
        // Menunggu input
    }

    // Ambil karakter pertama yang diketik
    char pilihanMenu = Serial.read();

    // Bersihkan sisa karakter enter (\n atau \r) di buffer Serial
    while(Serial.available() > 0) {
        Serial.read();
    }

    Serial.println(pilihanMenu); // Tampilkan angka yang dipilih ke layar

    // ===============================================================================================

    // Switch case untuk semua menu
    switch (pilihanMenu) {
        case '1':
            Serial.println(F("\n[Menjalankan Menu 1: Tambah Data...]"));
            AddData(catalog, arraySize);
            break;

        case '2':
            Serial.println(F("\n[Menjalankan Menu 2: Hapus Data...]"));
            Serial.print(F("\nMasukkan ID Barang yang ingin dihapus: "));
            unsigned short idHapus = BacaInputAngka();
            Serial.println(idHapus);
            DeleteItem(catalog, arraySize, idHapus);
            break;

        case '3': {
            Serial.println(F("\n[Menjalankan Menu 3: Cari ID...]"));
            Serial.print(F("\nMasukkan ID Barang yang dicari: "));
            unsigned short idCari = BacaInputAngka();
            Serial.println(idCari);
            SearchByID(catalog, arraySize, idCari);
            break;
        }
        case '4':
            Serial.println(F("\n[Menjalankan Menu 4: Perbarui Stok...]"));
            Serial.print(F("\nMasukkan ID Barang yang ingin diupdate: "));
            unsigned short idUpdateStock = BacaInputAngka();
            Serial.println(idUpdateStock);
            UpdateStock(catalog, arraySize, idUpdateStock);
            break;

        case '5':
            Serial.println(F("\n[Menjalankan Menu 5: Perbarui Status...]"));
            Serial.print(F("\nMasukkan ID Barang yang ingin diupdate: "));
            unsigned short idUpdateStatus = BacaInputAngka();
            Serial.println(idUpdateStatus);
            UpdateStatus(catalog, arraySize, idUpdateStatus);
            break;

        case '6':
            Serial.println(F("\n[Menjalankan Menu 6: Menampilkan semua barang...]"));
            ShowAllItems(catalog, arraySize);
            break;

        case '7':
            Serial.println(F("\n[Menjalankan Menu 7: Menampilkan ringkasan inventory...]"));
            showRingkasan(catalog, arraySize);
            break;

        case '8':
            Serial.println(F("\n[Saving...]"));
            SaveEEPROM(catalog, arraySize);
            break;

        default:
            Serial.println(F("\n[ERROR] Pilihan tidak valid! Masukkan angka 1 hingga 7."));
            break;
    }
    
    // delay agar tampilan menu tidak menumpuk cepat
    delay(1000); 
}