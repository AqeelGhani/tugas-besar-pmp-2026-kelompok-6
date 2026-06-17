#include "updateStatus.h"

void UpdateStatusWithConfirmation(CatalogItem catalog[], unsigned short arraySize, unsigned short id)
{
    if (id >= arraySize) {
        Serial.println("ERROR: ID di luar batas");
        return;
    }

    if (IsSlotEmpty(&catalog[id])) {
        Serial.println("ERROR: Data kosong");
        return;
    }

    char nama[9];

    unsigned short tersedia = GetStatusTersedia(&catalog[id]);
    unsigned short dipinjam = GetStatusDipinjam(&catalog[id]);
    unsigned short rusak = GetStatusRusak(&catalog[id]);

    GetNamaKomponen(&catalog[id], nama);

    Serial.println("DATA LAMA");
    Serial.print("Nama: ");
    Serial.println(nama);
    Serial.print("Tersedia: ");
    Serial.println(tersedia);
    Serial.print("Dipinjam: ");
    Serial.println(dipinjam);
    Serial.print("Rusak: ");
    Serial.println(rusak);

    Serial.println("\nYakin ingin update status? (Y/N)");

    while (!Serial.available()) {}
    char confirm = Serial.read();

    if (confirm != 'Y' && confirm != 'y') {
        Serial.println("UPDATE DIBATALKAN");
        return;
    }

    unsigned short newTersedia, newDipinjam, newRusak;

    Serial.println("Masukkan status baru:");

    Serial.print("Tersedia: ");
    while (!Serial.available()) {}
    newTersedia = Serial.parseInt();

    Serial.print("\nDipinjam: ");
    while (!Serial.available()) {}
    newDipinjam = Serial.parseInt();

    Serial.print("\nRusak: ");
    while (!Serial.available()) {}
    newRusak = Serial.parseInt();

    UpdateStatusTersedia(&catalog[id], newTersedia);
    UpdateStatusDipinjam(&catalog[id], newDipinjam);
    UpdateStatusRusak(&catalog[id], newRusak);

    Serial.println("\nDATA BERHASIL DIUPDATE");

    GetNamaKomponen(&catalog[id], nama);

    Serial.print("Nama: ");
    Serial.println(nama);
    Serial.print("Tersedia: ");
    Serial.println(GetStatusTersedia(&catalog[id]));
    Serial.print("Dipinjam: ");
    Serial.println(GetStatusDipinjam(&catalog[id]));
    Serial.print("Rusak: ");
    Serial.println(GetStatusRusak(&catalog[id]));
}