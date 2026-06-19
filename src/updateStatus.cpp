// update status
#include "updateStatus.h"

void UpdateStatus(CatalogItem catalog[], unsigned short arraySize, unsigned short id)
{
    if (id >= arraySize) {
        Serial.println(F("ERROR: ID di luar batas"));
        return;
    }

    if (IsSlotEmpty(&catalog[id])) {
        Serial.println(F("ERROR: Data kosong"));
        return;
    }

    char nama[9];
    int temp;

    unsigned short tersedia = GetStatusTersedia(&catalog[id]);
    unsigned short dipinjam = GetStatusDipinjam(&catalog[id]);
    unsigned short rusak = GetStatusRusak(&catalog[id]);

    GetNamaKomponen(&catalog[id], nama);

    Serial.println(F("\n=== DATA LAMA ==="));
    Serial.print(F("Nama     : "));
    Serial.println(nama);
    Serial.print(F("Tersedia : "));
    Serial.println(tersedia);
    Serial.print(F("Dipinjam : "));
    Serial.println(dipinjam);
    Serial.print(F("Rusak    : "));
    Serial.println(rusak);

    Serial.println(F("\nYakin ingin update status? (Y/N):"));

    while (!Serial.available()) {}
    char confirm = Serial.read();
    Serial.print(F(">> ")); Serial.println(confirm); // Echo inputan Y/N

    // Membersihkan sisa buffer setelah membaca char
    while(Serial.available()) Serial.read();

    if (confirm != 'Y' && confirm != 'y') {
        Serial.println(F("\nINFO: UPDATE DIBATALKAN"));
        return;
    }

    unsigned short newTersedia, newDipinjam, newRusak;

    Serial.println(F("\nMasukkan status baru:"));
    while (true){
        Serial.println(F("Tersedia:"));
        while (!Serial.available()) {}
        temp = Serial.parseInt();
        
        if (temp >= 0 && temp <= 63){
            newTersedia = temp;
            Serial.print(F(">> ")); Serial.println(newTersedia);
            break;
        } else {
            Serial.println(F("ERROR: Stock overflow/tidak valid! Harap masukkan angka 0 - 63."));
            while(Serial.available()) Serial.read();
        }
    }

    while (true) {
        Serial.println(F("\nDipinjam:"));
        while (!Serial.available()) {}
        temp = Serial.parseInt();
        
        if (temp >= 0 && temp <= 63) {
            newDipinjam = temp;
            Serial.print(F(">> ")); Serial.println(newDipinjam);
            break;
        } else {
            Serial.println(F("ERROR: Stock overflow/tidak valid! Harap masukkan angka 0 - 63."));
            while(Serial.available()) Serial.read();
        }
    }

    while (true) {
        Serial.println(F("\nRusak:"));
        while(!Serial.available()){}
        temp = Serial.parseInt();
        
        if (temp >= 0 && temp <= 63) {
            newRusak = temp;
            Serial.print(F(">> ")); Serial.println(newRusak);
            break;
        } else {
            Serial.println(F("ERROR: Stock overflow/tidak valid! Harap masukkan angka 0 - 63."));
            while(Serial.available()) Serial.read();
        }
    }

    // Membersihkan sisa buffer setelah fungsi parseInt selesai digunakan
    while(Serial.available()) Serial.read();

    UpdateStatusTersedia(&catalog[id], newTersedia);
    UpdateStatusDipinjam(&catalog[id], newDipinjam);
    UpdateStatusRusak(&catalog[id], newRusak);

    Serial.println(F("\nSUCCESS: DATA BERHASIL DIUPDATE"));

    GetNamaKomponen(&catalog[id], nama);

    Serial.println(F("\n=== RINGKASAN DATA BARU ==="));
    Serial.print(F("Nama     : "));
    Serial.println(nama);
    Serial.print(F("Tersedia : "));
    Serial.println(GetStatusTersedia(&catalog[id]));
    Serial.print(F("Dipinjam : "));
    Serial.println(GetStatusDipinjam(&catalog[id]));
    Serial.print(F("Rusak    : "));
    Serial.println(GetStatusRusak(&catalog[id]));
    Serial.println(F("==========================="));
}