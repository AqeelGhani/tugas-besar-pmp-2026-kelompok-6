#include "showAllItem.h"

void ShowAllItems(CatalogItem catalog[], unsigned short arraySize)
{
    Serial.println(F("===== DAFTAR INVENTARIS ====="));

    for (unsigned short i = 0; i < arraySize && i <= 63; i++)
    {
        if (IsSlotEmpty(&catalog[i])) {
            continue;
        }

        char nama[9];
        char pic[5];

        GetNamaKomponen(&catalog[i], nama);
        GetPIC(&catalog[i], pic);

        unsigned short lokasi= GetLokasi(&catalog[i]);
        unsigned short tersedia= GetStatusTersedia(&catalog[i]);
        unsigned short dipinjam= GetStatusDipinjam(&catalog[i]);
        unsigned short rusak= GetStatusRusak(&catalog[i]);
        unsigned short kategori= GetKategori(&catalog[i]);

        Serial.println(F("---------------------------"));
        Serial.print(F("ID: "));
        Serial.println(i);

        Serial.print(F("Nama: "));
        Serial.println(nama);

        Serial.print(F("Kategori: "));
        Serial.println(kategori);

        Serial.print(F("Lokasi: "));
        Serial.println(lokasi);

        Serial.print(F("PIC: "));
        Serial.println(pic);

        Serial.print(F("Tersedia: "));
        Serial.println(tersedia);

        Serial.print(F("Dipinjam: "));
        Serial.println(dipinjam);

        Serial.print(F("Rusak: "));
        Serial.println(rusak);
    }

    Serial.println(F("===== SELESAI ====="));
}