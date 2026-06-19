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

    unsigned short tersedia = GetStatusTersedia(&catalog[id]);
    unsigned short dipinjam = GetStatusDipinjam(&catalog[id]);
    unsigned short rusak = GetStatusRusak(&catalog[id]);

    GetNamaKomponen(&catalog[id], nama);

    Serial.println(F("DATA LAMA"));
    Serial.print(F("Nama: "));
    Serial.println(nama);
    Serial.print(F("Tersedia: "));
    Serial.println(tersedia);
    Serial.print(F("Dipinjam: "));
    Serial.println(dipinjam);
    Serial.print(F("Rusak: "));
    Serial.println(rusak);

    Serial.println(F("\nYakin ingin update status? (Y/N)"));

    while (!Serial.available()) {}
    char confirm = Serial.read();

    if (confirm != 'Y' && confirm != 'y') {
        Serial.println(F("UPDATE DIBATALKAN"));
        return;
    }

    unsigned short newTersedia, newDipinjam, newRusak;

    Serial.println(F("Masukkan status baru:"));

    Serial.print(F("Tersedia: "));
    while (!Serial.available()) {}
    newTersedia = Serial.parseInt();

    Serial.print(F("\nDipinjam: "));
    while (!Serial.available()) {}
    newDipinjam = Serial.parseInt();

    Serial.print(F("\nRusak: "));
    while (!Serial.available()) {}
    newRusak = Serial.parseInt();

    UpdateStatusTersedia(&catalog[id], newTersedia);
    UpdateStatusDipinjam(&catalog[id], newDipinjam);
    UpdateStatusRusak(&catalog[id], newRusak);

    Serial.println(F("\nDATA BERHASIL DIUPDATE"));

    GetNamaKomponen(&catalog[id], nama);

    Serial.print(F("Nama: "));
    Serial.println(nama);
    Serial.print(F("Tersedia: "));
    Serial.println(GetStatusTersedia(&catalog[id]));
    Serial.print(F("Dipinjam: "));
    Serial.println(GetStatusDipinjam(&catalog[id]));
    Serial.print(F("Rusak: "));
    Serial.println(GetStatusRusak(&catalog[id]));
}