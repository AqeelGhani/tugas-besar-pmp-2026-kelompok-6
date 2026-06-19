#include "updateStock.h"

void UpdateStock(CatalogItem catalog[], unsigned short arraySize, unsigned short id) {
    if (id >= arraySize) {
        Serial.println(F("ERROR: ID di luar batas memori!"));
        return;
    }

    if (IsSlotEmpty(&catalog[id])) {
        Serial.println(F("ERROR: ID tidak ditemukan!"));
        return;
    }

    char nama[9];
    GetNamaKomponen(&catalog[id], nama);
    unsigned short currentStock = GetStatusTersedia(&catalog[id]);

    Serial.println(F("\n=== UPDATE STOK TERSEDIA ==="));
    Serial.print(F("Nama Komponen      : ")); Serial.println(nama);
    Serial.print(F("Stok Tersedia Saat Ini : ")); Serial.println(currentStock);

    Serial.println(F("\nMasukkan jumlah stok yang akan ditambahkan/dikurangi."));
    Serial.println(F("(Gunakan tanda minus '-' untuk mengurangi stok, misal: -2)"));
    
    while (!Serial.available()) {}
    short stockChange = Serial.parseInt();

    if (stockChange < 0 && (short)currentStock + stockChange < 0) {
        Serial.println(F("ERROR: Stok tidak mencukupi untuk melakukan pengurangan tersebut!"));
        return;
    }
    
    if ((short)currentStock + stockChange > 63){
        Serial.println(F("ERROR: Stock tidak dapat ditambahkan karena overflow!"));
        return;
    }

    unsigned short newStock = (unsigned short)((short)currentStock + stockChange);
    
    UpdateStatusTersedia(&catalog[id], newStock);

    Serial.println(F("\nSUCCESS: Stok berhasil diperbarui!"));
    Serial.print(F("Stok Tersedia Baru : "));
    Serial.println(newStock);
}