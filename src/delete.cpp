// fungsi delete
#include "delete.h"

void DeleteItem(CatalogItem catalog[], unsigned short arraySize, unsigned short id)
{
    if (id >= arraySize) {
        Serial.println(F("ERROR: ID di luar batas array"));
        return;
    }

    // ini untuk cek slot kosong
    if (IsSlotEmpty(&catalog[id])) {
        Serial.println(F("ERROR: Data kosong, tidak bisa dihapus!"));
        return;
    }

    char nama[9];

    // untuk verifikasi
    GetNamaKomponen(&catalog[id], nama);

    Serial.println(F("KONFIRMASI DELETE"));
    Serial.print(F("ID: "));
    Serial.println(id);
    Serial.print(F("Nama Komponen: "));
    Serial.println(nama);

    Serial.println("Yakin ingin menghapus? (Y/N)");

    while (!Serial.available()) {}

    char confirm = Serial.read();

    if (confirm == 'Y' || confirm == 'y') {

        catalog[id].nama_komponen[0] = 0;

        Serial.println(F("DATA BERHASIL DIHAPUS (nama komponen direset)"));
    }
    else {
        Serial.println(F("DELETE DIBATALKAN"));
    }
}