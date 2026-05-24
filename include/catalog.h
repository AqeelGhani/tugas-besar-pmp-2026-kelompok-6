#ifndef CATALOG_H
#define CATALOG_H

#include <stdint.h>
#include "constant.h"

typedef struct {
    uint8_t nama_komponen[6];
    uint8_t jumlah_stock;
    uint8_t lokasi_dan_status;
    uint8_t kategori_dan_pic[3];
} CatalogItem;

unsigned short FindCharIndex (char character);

char FindChar (short index);

void ConvertStringToBitArray(char string[], uint8_t bitArray[], unsigned short size);

void CompressDataNamaKomponen(uint8_t initialData[8], uint8_t compressData[6]);

void UnCompressDataNamaKomponen(uint8_t compressData[6], uint8_t initialData[8]);

void ConvertBitArrayToString (uint8_t bitArray[], char string[], unsigned short size);

void UpdateNamaKomponen (CatalogItem *catalogItem, char namaKomponen[9]);

void GetNamaKomponen (CatalogItem *catalogItem, char namaKomponen[9]);

unsigned short GetJumlahStock (CatalogItem *catalogItem);

void UpdateJumlahStock (CatalogItem *catalogItem, unsigned short jumlahBaru);

unsigned short GetLokasi (CatalogItem *catalogItem);

void UpdateLokasi (CatalogItem *catalogItem, unsigned short newIndeksLokasi);

unsigned short GetStatus (CatalogItem *catalogItem);

void UpdateStatus (CatalogItem *catalogItem, unsigned short newStatus);

unsigned short GetKategori (CatalogItem *catalogItem);

void UpdateKategori (CatalogItem *catalogItem, unsigned short newKategori);

void UpperString(char string[], unsigned short len);

void CompressDataPIC(uint8_t initialData[4], uint8_t compressData[3]);

void UnCompressDataPIC(uint8_t compressData[3], uint8_t initialData[4]);

void UpdatePIC (CatalogItem *catalogItem, char namaPIC[5]);

void GetPIC (CatalogItem *catalogItem, char namaPIC[5]);

void DeleteCatalogItem (CatalogItem *catalogItem);

void InitializeCatalog(CatalogItem catalog[]);

#endif