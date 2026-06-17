#include "updateStock.h"

void UpdateStock(CatalogItem catalog[], unsigned short arraySize, unsigned short id) {
    if (id >= arraySize) {
        Serial.println("ERROR: ID di luar batas memori!");
        return;
    }

    if (IsSlotEmpty(&catalog[id])) {
        Serial.println("ERROR: ID tidak ditemukan!");
        return;
    }

    char nama[9];
    GetNamaKomponen(&catalog[id], nama);
    unsigned short currentStock = GetStatusTersedia(&catalog[id]);

    Serial.println("\n=== UPDATE STOK TERSEDIA ===");
    Serial.print("Nama Komponen      : "); Serial.println(nama);
    Serial.print("Stok Tersedia Saat Ini : "); Serial.println(currentStock);

    Serial.println("\nMasukkan jumlah stok yang akan ditambahkan/dikurangi.");
    Serial.println("(Gunakan tanda minus '-' untuk mengurangi stok, misal: -2)");
    
    while (!Serial.available()) {}
    long stockChange = Serial.parseInt();

    if (stockChange < 0 && (long)currentStock + stockChange < 0) {
        Serial.println("ERROR: Stok tidak mencukupi untuk melakukan pengurangan tersebut!");
        return;
    }

    unsigned short newStock = (unsigned short)((long)currentStock + stockChange);
    
    UpdateStatusTersedia(&catalog[id], newStock);

    Serial.println("\nSUCCESS: Stok berhasil diperbarui!");
    Serial.print("Stok Tersedia Baru : ");
    Serial.println(newStock);
}