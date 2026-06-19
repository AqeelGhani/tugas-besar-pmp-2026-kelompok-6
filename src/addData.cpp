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
    unsigned short id = GetEmptyId(catalog, arraySize);
    
    Serial.print(F("ID barang: "));
    Serial.println(id);

    char nama[9]={'\0','\0','\0','\0','\0','\0','\0','\0','\0'};
    char pic[5]={'\0','\0','\0','\0','\0'};
    unsigned short lokasi, tersedia, dipinjam, rusak, kategori;

    Serial.println(F("\nMasukkan Nama Komponen (Maks 8 huruf):"));
    while(!Serial.available()){}
    Serial.readBytesUntil('\n', nama, 8);
    nama[8] = '\0'; 
    Serial.print(F(">> ")); Serial.println(nama);

    Serial.println(F("\n=== DAFTAR KATEGORI ==="));
    Serial.println(F("-----------------------------------"));
    Serial.println(F("| ID | Kategori  | ID | Kategori  |"));
    Serial.println(F("-----------------------------------"));
    Serial.println(F("| 0  | Mikon     |  8 | IC        |"));
    Serial.println(F("| 1  | SBC       |  9 | Driver    |"));
    Serial.println(F("| 2  | Sensor    | 10 | Power     |"));
    Serial.println(F("| 3  | Aktuator  | 11 | AlatUkur  |"));
    Serial.println(F("| 4  | Comm      | 12 | Instrumen |"));
    Serial.println(F("| 5  | Display   | 13 | Alat      |"));
    Serial.println(F("| 6  | Pasif     | 14 | Media     |"));
    Serial.println(F("| 7  | Semikon   | 15 | Connector |"));
    Serial.println(F("-----------------------------------"));

    // Variabel temporary untuk menampung inputan angka dan mengecek nilai negatif/overflow
    int tempInput; 

    // ==========================================
    // LOOP VALIDASI KATEGORI (0 - 15)
    // ==========================================
    while (true) {
        Serial.println(F("\nMasukkan Kategori (0-15):"));
        while(!Serial.available()){}
        tempInput = Serial.parseInt();
        
        if (tempInput >= 0 && tempInput <= 15) {
            kategori = tempInput;
            break; 
        } else {
            Serial.println(F("ERROR: ID Kategori tidak valid! Harap masukkan angka 0 - 15."));
            while(Serial.available()) Serial.read(); 
        }
    }
    
    Serial.print(F(">> ")); 
    Serial.print(kategori);
    Serial.print(F(" (")); 
    switch (kategori) {
        case 0:  Serial.print(F("Mikon")); break;
        case 1:  Serial.print(F("SBC")); break;
        case 2:  Serial.print(F("Sensor")); break;
        case 3:  Serial.print(F("Aktuator")); break;
        case 4:  Serial.print(F("Comm")); break;
        case 5:  Serial.print(F("Display")); break;
        case 6:  Serial.print(F("Pasif")); break;
        case 7:  Serial.print(F("Semikon")); break;
        case 8:  Serial.print(F("IC")); break;
        case 9:  Serial.print(F("Driver")); break;
        case 10: Serial.print(F("Power")); break;
        case 11: Serial.print(F("AlatUkur")); break;
        case 12: Serial.print(F("Instrumen")); break;
        case 13: Serial.print(F("Alat")); break;
        case 14: Serial.print(F("Media")); break;
        case 15: Serial.print(F("Connector")); break;
        default: Serial.print(F("Unknown")); break;
    }
    Serial.println(F(")"));

    // ==========================================
    // LOOP VALIDASI LOKASI (0 - 63)
    // ==========================================
    while (true) {
        Serial.println(F("\nMasukkan Lokasi (0-63):"));
        while(!Serial.available()){}
        tempInput = Serial.parseInt();
        
        if (tempInput >= 0 && tempInput <= 63) {
            lokasi = tempInput;
            Serial.print(F(">> ")); Serial.println(lokasi);
            break;
        } else {
            Serial.println(F("ERROR: Lokasi tidak valid! Harap masukkan angka 0 - 63."));
            while(Serial.available()) Serial.read();
        }
    }

    // ==========================================
    // LOOP VALIDASI STOK TERSEDIA (0 - 63)
    // ==========================================
    while (true) {
        Serial.println(F("\nMasukkan Jumlah Stok Tersedia (0-63):"));
        while(!Serial.available()){}
        tempInput = Serial.parseInt();
        
        if (tempInput >= 0 && tempInput <= 63) {
            tersedia = tempInput;
            Serial.print(F(">> ")); Serial.println(tersedia);
            break;
        } else {
            Serial.println(F("ERROR: Stock overflow/tidak valid! Harap masukkan angka 0 - 63."));
            while(Serial.available()) Serial.read();
        }
    }

    // ==========================================
    // LOOP VALIDASI STOK DIPINJAM (0 - 63)
    // ==========================================
    while (true) {
        Serial.println(F("\nMasukkan Jumlah Stok Dipinjam (0-63):"));
        while(!Serial.available()){}
        tempInput = Serial.parseInt();
        
        if (tempInput >= 0 && tempInput <= 63) {
            dipinjam = tempInput;
            Serial.print(F(">> ")); Serial.println(dipinjam);
            break;
        } else {
            Serial.println(F("ERROR: Stock overflow/tidak valid! Harap masukkan angka 0 - 63."));
            while(Serial.available()) Serial.read();
        }
    }

    // ==========================================
    // LOOP VALIDASI STOK RUSAK (0 - 63)
    // ==========================================
    while (true) {
        Serial.println(F("\nMasukkan Jumlah Stok Rusak (0-63):"));
        while(!Serial.available()){}
        tempInput = Serial.parseInt();
        
        if (tempInput >= 0 && tempInput <= 63) {
            rusak = tempInput;
            Serial.print(F(">> ")); Serial.println(rusak);
            break;
        } else {
            Serial.println(F("ERROR: Stock overflow/tidak valid! Harap masukkan angka 0 - 63."));
            while(Serial.available()) Serial.read();
        }
    }

    while(Serial.available()) Serial.read(); 

    Serial.println(F("\nMasukkan Nama PIC (Maks 4 huruf):"));
    while(!Serial.available()){}
    Serial.readBytesUntil('\n', pic, 4);
    pic[4] = '\0';
    Serial.print(F(">> ")); Serial.println(pic);

    // Memperbarui data ke dalam struct
    UpdateNamaKomponen(&catalog[id], nama);
    UpdateKategori(&catalog[id], kategori);
    UpdateLokasi(&catalog[id], lokasi);
    UpdateStatusTersedia(&catalog[id], tersedia);
    UpdateStatusDipinjam(&catalog[id], dipinjam);
    UpdateStatusRusak(&catalog[id], rusak);
    UpdatePIC(&catalog[id], pic);

    Serial.println(F("\nSUCCESS: Data barang berhasil ditambahkan!"));

    // Ringkasan Akhir
    Serial.println(F("\n=== RINGKASAN DATA YANG DITAMBAHKAN ==="));
    Serial.print(F("ID Barang   : ")); Serial.println(id);
    Serial.print(F("Nama Barang : ")); Serial.println(nama);
    
    Serial.print(F("Kategori    : ")); 
    Serial.print(kategori);
    Serial.print(F(" - ")); 
    switch (kategori) {
        case 0:  Serial.println(F("Mikon")); break;
        case 1:  Serial.println(F("SBC")); break;
        case 2:  Serial.println(F("Sensor")); break;
        case 3:  Serial.println(F("Aktuator")); break;
        case 4:  Serial.println(F("Comm")); break;
        case 5:  Serial.println(F("Display")); break;
        case 6:  Serial.println(F("Pasif")); break;
        case 7:  Serial.println(F("Semikon")); break;
        case 8:  Serial.println(F("IC")); break;
        case 9:  Serial.println(F("Driver")); break;
        case 10: Serial.println(F("Power")); break;
        case 11: Serial.println(F("AlatUkur")); break;
        case 12: Serial.println(F("Instrumen")); break;
        case 13: Serial.println(F("Alat")); break;
        case 14: Serial.println(F("Media")); break;
        case 15: Serial.println(F("Connector")); break;
        default: Serial.println(F("Unknown")); break;
    }
    
    Serial.print(F("Lokasi      : ")); Serial.println(lokasi);
    Serial.print(F("Tersedia    : ")); Serial.println(tersedia);
    Serial.print(F("Dipinjam    : ")); Serial.println(dipinjam);
    Serial.print(F("Rusak       : ")); Serial.println(rusak);
    Serial.print(F("Nama PIC    : ")); Serial.println(pic);
    Serial.println(F("======================================="));
}