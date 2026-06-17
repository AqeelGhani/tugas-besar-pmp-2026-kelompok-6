#include "addData.h"

void AddData(CatalogItem catalog[], unsigned short arraySize) {
    unsigned short emptyCount = GetEmptySlotCount(catalog, arraySize);
    
    if (emptyCount == 0) {
        Serial.println("ERROR: Kapasitas memori penuh! Tidak bisa menambah data.");
        return;
    } else if (emptyCount <= 5) {
        Serial.print("WARNING: Kapasitas memori hampir habis. Sisa slot: ");
        Serial.println(emptyCount);
    }

    Serial.println("\n=== TAMBAH DATA INVENTARIS ===");
    Serial.println("Masukkan ID Barang (0 - 84):");
    while(!Serial.available()){}
    unsigned short id = Serial.parseInt();
    
    while(Serial.available()) Serial.read();

    if (id >= arraySize) {
        Serial.println("ERROR: ID di luar rentang array!");
        return;
    }

    if (!IsSlotEmpty(&catalog[id])) {
        Serial.println("ERROR: ID Duplikat! ID tersebut sudah terpakai.");
        return;
    }

    char nama[9];
    char pic[5];
    unsigned short lokasi, tersedia, dipinjam, rusak, kategori;

    Serial.println("Masukkan Nama Komponen (Maks 8 huruf):");
    while(!Serial.available()){}
    Serial.readBytesUntil('\n', nama, 8);
    nama[8] = '\0'; 

    Serial.println("Masukkan Kategori (0-15):");
    while(!Serial.available()){}
    kategori = Serial.parseInt();

    Serial.println("Masukkan Lokasi (0-63):");
    while(!Serial.available()){}
    lokasi = Serial.parseInt();

    Serial.println("Masukkan Jumlah Stok Tersedia:");
    while(!Serial.available()){}
    tersedia = Serial.parseInt();

    Serial.println("Masukkan Jumlah Stok Dipinjam:");
    while(!Serial.available()){}
    dipinjam = Serial.parseInt();

    Serial.println("Masukkan Jumlah Stok Rusak:");
    while(!Serial.available()){}
    rusak = Serial.parseInt();

    Serial.println("Masukkan Nama PIC (Maks 4 huruf):");
    while(!Serial.available()){}
    Serial.readBytesUntil('\n', pic, 4);
    pic[4] = '\0';

    UpdateNamaKomponen(&catalog[id], nama);
    UpdateKategori(&catalog[id], kategori);
    UpdateLokasi(&catalog[id], lokasi);
    UpdateStatusTersedia(&catalog[id], tersedia);
    UpdateStatusDipinjam(&catalog[id], dipinjam);
    UpdateStatusRusak(&catalog[id], rusak);
    UpdatePIC(&catalog[id], pic);

    Serial.println("\nSUCCESS: Data barang berhasil ditambahkan!");
}