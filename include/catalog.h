#ifndef CATALOG_H
#define CATALOG_H

#include <stdint.h>
#include "constant.h"

typedef struct {
    uint8_t nama_komponen[6];
    uint8_t lokasi_dan_jumlah_status[3];
    uint8_t kategori_dan_pic[3];
} CatalogItem;

// Fungsi mencari index karakter (Tidak digunakan untuk fungsi lain selain fungsi catalog)
unsigned short FindCharIndex (char character);

// Fungsi mencari karakter (Tidak digunakan untuk fungsi lain selain fungsi catalog)
char FindChar (short index);

// Prosedur mengubah string menjadi bit array (Tidak digunakan untuk fungsi lain selain fungsi catalog)
void ConvertStringToBitArray(char string[], uint8_t bitArray[], unsigned short size);

// Prosedur mengompres nama komponen (Tidak digunakan untuk fungsi lain selain fungsi catalog)
void CompressDataNamaKomponen(uint8_t initialData[8], uint8_t compressData[6]);

// Prosedur menguncompres nama komponen (Tidak digunakan untuk fungsi lain selain fungsi catalog)
void UnCompressDataNamaKomponen(uint8_t compressData[6], uint8_t initialData[8]);

// Prosedur mengubah bit array menjadi string (Tidak digunakan untuk fungsi lain selain fungsi catalog)
void ConvertBitArrayToString (uint8_t bitArray[], char string[], unsigned short size);

// Prosedur Mengubah Nama Komponen
// Input : 
// 1. catalogItem : Item yang ingin diubah namanya, berberntuk pointer (Tips : untuk mendapatkan pointer dari elemen array dapat dilakukan hal berikut : array+indeks. Contoh : catalog+i)
// 2. namaKomponen : Nama baru untuk komponen. Berbentuk string dengan banyak 8 karakter (plus null)
// Output :
// 1. catalogItem (Updated)
void UpdateNamaKomponen (CatalogItem *catalogItem, char namaKomponen[9]);

// Prosedur Mendapat Nama Komponen
// Input : 
// 1. catalogItem : Item yang ingin diambil namanya, berberntuk pointer (Tips : untuk mendapatkan pointer dari elemen array dapat dilakukan hal berikut : array+indeks. Contoh : catalog+i)
// 2. namaKomponen : Nama komponen (Isinya masih kosong). Berbentuk string dengan banyak 8 karakter (plus null)
// Output :
// 1. namaKomponen : Nama komponen (Sudah terisi). Berbentuk string dengan banyak 8 karakter (plus null)
void GetNamaKomponen (CatalogItem *catalogItem, char namaKomponen[9]);

// Fungsi mendapatkan lokasi item
// Input :
// 1. catalogItem : Item yang ingin dicari lokasinya, berberntuk pointer (Tips : untuk mendapatkan pointer dari elemen array dapat dilakukan hal berikut : array+indeks. Contoh : catalog+i)
// Output :
// 2. lokasi (keluaran fungsi) : integer dari 0-63
unsigned short GetLokasi (CatalogItem *catalogItem);

// Prosedur mengupdate lokasi item
// Input
// 1. catalogItem : Item yang ingin diubah lokasinya, berberntuk pointer (Tips : untuk mendapatkan pointer dari elemen array dapat dilakukan hal berikut : array+indeks. Contoh : catalog+i)
// 2. newIndeksLokasi : lokasi baru untuk item (integer dari 0-63)
// Output :
// 1. catalogItem (Updated)
void UpdateLokasi (CatalogItem *catalogItem, unsigned short newIndeksLokasi);

// Fungsi mendapatkan jumlah item dengan status tersedia
// Input :
// 1. catalogItem : Item yang ingin dicari jumlah status tersedianya, berberntuk pointer (Tips : untuk mendapatkan pointer dari elemen array dapat dilakukan hal berikut : array+indeks. Contoh : catalog+i)
// Output :
// 2. jumlah item dengan status tersedia (keluaran fungsi) : integer dari 0-63
unsigned short GetStatusTersedia (CatalogItem *catalogItem);

// Prosedur mengupdate jumlah item dengan status tersedia
// Input
// 1. catalogItem : Item yang ingin diubah jumlah status tersedianya, berberntuk pointer (Tips : untuk mendapatkan pointer dari elemen array dapat dilakukan hal berikut : array+indeks. Contoh : catalog+i)
// 2. newStatusTersedia : jumlah status tersedia baru untuk item (integer dari 0-63)
// Output :
// 1. catalogItem (Updated)
void UpdateStatusTersedia (CatalogItem *catalogItem, unsigned short newStatusTersedia);

// Fungsi mendapatkan jumlah item dengan status dipinjam
// Input :
// 1. catalogItem : Item yang ingin dicari jumlah status dipinjamnya, berberntuk pointer (Tips : untuk mendapatkan pointer dari elemen array dapat dilakukan hal berikut : array+indeks. Contoh : catalog+i)
// Output :
// 2. jumlah item dengan status dipinjam (keluaran fungsi) : integer dari 0-63
unsigned short GetStatusDipinjam (CatalogItem *catalogItem);

// Prosedur mengupdate jumlah item dengan status dipinjam
// Input
// 1. catalogItem : Item yang ingin diubah jumlah status dipinjamnya, berberntuk pointer (Tips : untuk mendapatkan pointer dari elemen array dapat dilakukan hal berikut : array+indeks. Contoh : catalog+i)
// 2. newStatusDipinjam : jumlah status dipinjam baru untuk item (integer dari 0-63)
// Output :
// 1. catalogItem (Updated)
void UpdateStatusDipinjam (CatalogItem *catalogItem, unsigned short newStatusDipinjam);

// Fungsi mendapatkan jumlah item dengan status rusak
// Input :
// 1. catalogItem : Item yang ingin dicari jumlah status rusaknya, berberntuk pointer (Tips : untuk mendapatkan pointer dari elemen array dapat dilakukan hal berikut : array+indeks. Contoh : catalog+i)
// Output :
// 2. jumlah item dengan status rusak (keluaran fungsi) : integer dari 0-63
unsigned short GetStatusRusak (CatalogItem *catalogItem);

// Prosedur mengupdate jumlah item dengan status rusak
// Input
// 1. catalogItem : Item yang ingin diubah jumlah status rusaknya, berberntuk pointer (Tips : untuk mendapatkan pointer dari elemen array dapat dilakukan hal berikut : array+indeks. Contoh : catalog+i)
// 2. newStatusRusak : jumlah status rusak baru untuk item (integer dari 0-63)
// Output :
// 1. catalogItem (Updated)
void UpdateStatusRusak (CatalogItem *catalogItem, unsigned short newStatusRusak);

// Fungsi mendapatkan jumlah stock item
// Input :
// 1. catalogItem : Item yang ingin dicari jumlah stocknya, berberntuk pointer (Tips : untuk mendapatkan pointer dari elemen array dapat dilakukan hal berikut : array+indeks. Contoh : catalog+i)
// Output :
// 2. jumlah stock item (keluaran fungsi) : integer dari 0-189
unsigned short GetJumlahStock (CatalogItem *catalogItem);

// Fungsi mendapatkan kategori item
// Input :
// 1. catalogItem : Item yang ingin dicari kategorinya, berberntuk pointer (Tips : untuk mendapatkan pointer dari elemen array dapat dilakukan hal berikut : array+indeks. Contoh : catalog+i)
// Output :
// 2. Kategori Item (keluaran fungsi) : integer dari 0-15
unsigned short GetKategori (CatalogItem *catalogItem);

// Prosedur mengupdate kategori Item
// Input
// 1. catalogItem : Item yang ingin diubah kategorinya, berberntuk pointer (Tips : untuk mendapatkan pointer dari elemen array dapat dilakukan hal berikut : array+indeks. Contoh : catalog+i)
// 2. newKategori : kategori baru untuk item (integer dari 0-15)
// Output :
// 1. catalogItem (Updated)
void UpdateKategori (CatalogItem *catalogItem, unsigned short newKategori);

// Prosedur membuat kapital seluruh karakter string (Tidak digunakan untuk fungsi lain selain fungsi catalog)
void UpperString(char string[], unsigned short len);

// Prosedur mengcompress data PIC (Tidak digunakan untuk fungsi lain selain fungsi catalog)
void CompressDataPIC(uint8_t initialData[4], uint8_t compressData[3]);

// Prosedur menuncompress data PIC (Tidak digunakan untuk fungsi lain selain fungsi catalog)
void UnCompressDataPIC(uint8_t compressData[3], uint8_t initialData[4]);

// Prosedur Mengubah PIC
// Input : 
// 1. catalogItem : Item yang ingin diubah PICnya, berberntuk pointer (Tips : untuk mendapatkan pointer dari elemen array dapat dilakukan hal berikut : array+indeks. Contoh : catalog+i)
// 2. namaPIC : Nama baru PICnya. Berbentuk string dengan banyak 4 karakter (plus null)
// Output :
// 1. catalogItem (Updated)
void UpdatePIC (CatalogItem *catalogItem, char namaPIC[5]);

// Prosedur Mendapat PIC
// Input : 
// 1. catalogItem : Item yang ingin diambil PICnya, berberntuk pointer (Tips : untuk mendapatkan pointer dari elemen array dapat dilakukan hal berikut : array+indeks. Contoh : catalog+i)
// 2. namaPIC : Nama PIC (Isinya masih kosong). Berbentuk string dengan banyak 4 karakter (plus null)
// Output :
// 1. namaPIC : Nama PIC (Sudah terisi). Berbentuk string dengan banyak 4 karakter (plus null)
void GetPIC (CatalogItem *catalogItem, char namaPIC[5]);

// Prosedur Mendelete Item
// Input : 
// 1. catalogItem : Item yang ingin didelete, berberntuk pointer (Tips : untuk mendapatkan pointer dari elemen array dapat dilakukan hal berikut : array+indeks. Contoh : catalog+i)
// Output :
// 1. catalogItem (Updated)
void DeleteCatalogItem (CatalogItem *catalogItem);

// Prosedur Inisialisasi Katalog atau delete all item
// Input : 
// 1. catalog : array dari catalog
// 2. arraySize : Besar Array (Masukin aja 85)
// Output :
// 1. catalog (Updated)
void InitializeCatalog(CatalogItem catalog[], unsigned short arraySize);

// Fungsi Menentukan Apakah Slot dalam Katalog Kosong
// Input : 
// 1. catalogItem : lokasi item yang ingin diketahui apakah kosong atau tidak (Tips : untuk mendapatkan pointer dari elemen array dapat dilakukan hal berikut : array+indeks. Contoh : catalog+i)
// Output :
// 1. Kosong atau tidak (1 jika kosong, 0 jika terisi)
unsigned short IsSlotEmpty (CatalogItem *catalogItem);

// Fungsi Menghitung Slot Kosong
// Input : 
// 1. catalog : array dari catalog
// 2. arraySize : Besar Array (Masukin aja 85)
// Output :
// 1. Junmlah Slot Kosong (output fungsi)
unsigned short GetEmptySlotCount (CatalogItem catalog[], unsigned short arraySize);

// Fungsi Mencari Id Slot Kosong
// Input : 
// 1. catalog : array dari catalog
// 2. arraySize : Besar Array (Masukin aja 85)
// Output :
// 1. Id Slot Kosong (output fungsi)
unsigned short GetEmptyId (CatalogItem catalog[], unsigned short arraySize);

#endif