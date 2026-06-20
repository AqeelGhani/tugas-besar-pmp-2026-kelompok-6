#ifndef serialUI_H
#define serialUI_H

#include <Arduino.h>
#include "catalog.h"

// Fungsi menampilkan menu
// input: -
// output: pilihan menu yang ada
//
void showMenu();

// Fungsi mengambil/parsing input user, dengan menunggu input
// input: input angka user
// output: nilai input dari user dalam unsigned short
unsigned short BacaInputAngka();

// Fungsi menjalankan sistem
// input: mengambil input menu dari user (parsing)
// output: menjalankan fungsi dari menu yang dipilih
void runSystem(CatalogItem catalog[], unsigned short arraySize);

#endif