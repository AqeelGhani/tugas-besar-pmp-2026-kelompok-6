#ifndef Ringkasan_H
#define Ringkasan_H

#include <Arduino.h>
#include "catalog.h" // include untuk tipe data CatalogItem

// Deklarasi fungsi
// Input:
// 1. Katalog
// 2. ArraySize (yang sudah dideklarasikan di main)
// Output:
// 1. Detail ringkasan dari jumlah slot dan total status barang

void showRingkasan(CatalogItem catalog[], unsigned short arraySize);

#endif