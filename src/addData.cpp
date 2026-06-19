#include "addData.h"

void AddData(CatalogItem catalog[], unsigned short arraySize) {
    unsigned short emptyCount = GetEmptySlotCount(catalog, arraySize);
    
    if (emptyCount == 0) {
        Serial.println(F("ERROR: Kapasitas memori penuh! Tidak bisa menambah data."));
        return;
    } else if (emptyCount <= 5) {
        Serial.print(F("WARNING: Kapasitas memori hampir habis. Sisa slot: "));
        Serial.println(emptyCount);
    }

    Serial.println(F("\n=== TAMBAH DATA INVENTARIS ==="));
    Serial.println(F("Masukkan ID Barang (0 - 84):"));
    while(!Serial.available()){}
    unsigned short id = Serial.parseInt();
    Serial.print(F(">> ")); Serial.println(id); // Menampilkan inputan ID
    
    while(Serial.available()) Serial.read();

    if (id >= arraySize) {
        Serial.println(F("ERROR: ID di luar rentang array!"));
        return;
    }

    if (!IsSlotEmpty(&catalog[id])) {
        Serial.println(F("ERROR: ID Duplikat! ID tersebut sudah terpakai."));
        return;
    }

    char nama[9];
    char pic[5];
    unsigned short lokasi, tersedia, dipinjam, rusak, kategori;

    Serial.println(F("\nMasukkan Nama Komponen (Maks 8 huruf):"));
    while(!Serial.available()){}
    Serial.readBytesUntil('\n', nama, 8);
    nama[8] = '\0'; 
    Serial.print(F(">> ")); Serial.println(nama); // Menampilkan inputan Nama

    Serial.println(F("\nMasukkan Kategori (0-15):"));
    while(!Serial.available()){}
    kategori = Serial.parseInt();
    Serial.print(F(">> ")); Serial.println(kategori); // Menampilkan inputan Kategori

    Serial.println(F("\nMasukkan Lokasi (0-63):"));
    while(!Serial.available()){}
    lokasi = Serial.parseInt();
    Serial.print(F(">> ")); Serial.println(lokasi); // Menampilkan inputan Lokasi

    Serial.println(F("\nMasukkan Jumlah Stok Tersedia:"));
    while(!Serial.available()){}
    tersedia = Serial.parseInt();
    Serial.print(F(">> ")); Serial.println(tersedia); // Menampilkan inputan Stok Tersedia

    Serial.println(F("\nMasukkan Jumlah Stok Dipinjam:"));
    while(!Serial.available()){}
    dipinjam = Serial.parseInt();
    Serial.print(F(">> ")); Serial.println(dipinjam); // Menampilkan inputan Stok Dipinjam

    Serial.println(F("\nMasukkan Jumlah Stok Rusak:"));
    while(!Serial.available()){}
    rusak = Serial.parseInt();
    Serial.print(F(">> ")); Serial.println(rusak); // Menampilkan inputan Stok Rusak

    // Membersihkan sisa buffer sebelum membaca string lagi
    while(Serial.available()) Serial.read(); 

    Serial.println(F("\nMasukkan Nama PIC (Maks 4 huruf):"));
    while(!Serial.available()){}
    Serial.readBytesUntil('\n', pic, 4);
    pic[4] = '\0';
    Serial.print(F(">> ")); Serial.println(pic); // Menampilkan inputan PIC

    // Memperbarui data ke dalam struct
    UpdateNamaKomponen(&catalog[id], nama);
    UpdateKategori(&catalog[id], kategori);
    UpdateLokasi(&catalog[id], lokasi);
    UpdateStatusTersedia(&catalog[id], tersedia);
    UpdateStatusDipinjam(&catalog[id], dipinjam);
    UpdateStatusRusak(&catalog[id], rusak);
    UpdatePIC(&catalog[id], pic);

    Serial.println(F("\nSUCCESS: Data barang berhasil ditambahkan!"));

    // Ringkasan akhir (opsional, bisa Anda hapus kalau merasa sudah cukup dengan echo di atas)
    Serial.println(F("\n=== RINGKASAN DATA YANG DITAMBAHKAN ==="));
    Serial.print(F("ID Barang   : ")); Serial.println(id);
    Serial.print(F("Nama Barang : ")); Serial.println(nama);
    Serial.print(F("Kategori    : ")); Serial.println(kategori);
    Serial.print(F("Lokasi      : ")); Serial.println(lokasi);
    Serial.print(F("Tersedia    : ")); Serial.println(tersedia);
    Serial.print(F("Dipinjam    : ")); Serial.println(dipinjam);
    Serial.print(F("Rusak       : ")); Serial.println(rusak);
    Serial.print(F("Nama PIC    : ")); Serial.println(pic);
    Serial.println(F("======================================="));
}