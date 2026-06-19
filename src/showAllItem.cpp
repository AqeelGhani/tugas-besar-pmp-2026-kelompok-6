#include "showAllItem.h"

void ShowAllItems(CatalogItem catalog[], unsigned short arraySize)
{
    Serial.println("===== DAFTAR INVENTARIS =====");

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

        Serial.println("---------------------------");
        Serial.print("ID: ");
        Serial.println(i);

        Serial.print("Nama: ");
        Serial.println(nama);

        Serial.print("Kategori: ");
        Serial.println(kategori);

        Serial.print("Lokasi: ");
        Serial.println(lokasi);

        Serial.print("PIC: ");
        Serial.println(pic);

        Serial.print("Tersedia: ");
        Serial.println(tersedia);

        Serial.print("Dipinjam: ");
        Serial.println(dipinjam);

        Serial.print("Rusak: ");
        Serial.println(rusak);
    }

    Serial.println("===== SELESAI =====");
}