#ifndef SearchByID_H
#define SearchByID_H

#include <Arduino.h>
#include "catalog.h" // include untuk tipe data CatalogItem

// Deklarasi fungsi
// Input:
// 1. Catalog Array
// 2. arraySize dari main (dengan MAX_ITEM ataupun masukkan manual ke variabel), dilakukan agar size tidak pointer dari array catalog
// 3. ID yang ingin dicari 
//

void SearchByID(CatalogItem catalog[], unsigned short arraySize, unsigned short searchID);

#endif