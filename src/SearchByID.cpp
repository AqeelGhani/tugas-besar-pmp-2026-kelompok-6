#include <Arduino.h>
#include <stdio.h>
#include "catalog.h"
#include "SearchByID.h"

// Search By ID function implementation
void SearchByID(CatalogItem catalog[], unsigned short arraySize, unsigned short searchID){
    char buffer[100];

    // Validasi ID yang dicari ada di rentang index array
    if(searchID >= arraySize){
        sprintf(buffer, "ERROR!! ID %d melebihi batas memori.\r\n", searchID);
        Serial.print(buffer);
        return; 
    }   

    // Validasi apakah ID yang dicari kosong
    if (IsSlotEmpty(&catalog[searchID])) {
        sprintf(buffer, "ERROR!! Data dengan ID %d tidak ditemukan.\r\n", searchID);
        Serial.print(buffer);
        return; 
    }

    // variabel text sementara (SRAM)
    char namaKomponen[9];
    char namaPIC[5];

    // ambil nama komponen dan PIC dari fungsi basic low-level
    GetNamaKomponen(&catalog[searchID], namaKomponen);
    GetPIC(&catalog[searchID], namaPIC);

    unsigned short kategori = GetKategori(&catalog[searchID]);
    unsigned short lokasi = GetLokasi(&catalog[searchID]);
    unsigned short statusTersedia = GetStatusTersedia(&catalog[searchID]);
    unsigned short statusDipinjam = GetStatusDipinjam(&catalog[searchID]); // Data ini sudah ada
    unsigned short statusRusak = GetStatusRusak(&catalog[searchID]);       // Data ini sudah ada
    unsigned short totalStok = GetJumlahStock(&catalog[searchID]);

    // Interface Output
    Serial.println(F("\n ================ DETAIL BARANG ================ "));
    
    sprintf(buffer, "ID Barang : %d\r\nNama      : %s\r\nKategori  : %d\r\nLokasi    : %d\r\nPIC       : %s\r\n", 
            searchID, namaKomponen, kategori, lokasi, namaPIC);
    Serial.print(buffer);
    
    Serial.println(F("--- STATUS STOCK ---"));
    
    sprintf(buffer, "Tersedia  : %d unit\r\nDipinjam  : %d unit\r\n", 
            statusTersedia, statusDipinjam);
    Serial.print(buffer);

    sprintf(buffer, "Rusak     : %d unit\r\nTotal Stok: %d unit\r\n================================================\r\n", 
            statusRusak, totalStok);
    Serial.print(buffer);

}