#include "catalog.h"

unsigned short FindCharIndex (char character){
    if (character == '\0' || character == '+') return 0;
    if (character == ' ' || character == '-') return 1;
    if (character >= 65 && character <= 90) return character-63;
    if (character >= 97 && character <= 122) return character-69;
    if (character >= 48 && character <= 57) return character+6;
}

char FindChar (short index){
    return CHAR_LOOKUP_TABLE[index];
}

void ConvertStringToBitArray(char string[], uint8_t bitArray[], unsigned short size){
    for (unsigned short i = 0; i<size; ++i){
        bitArray[i] = (uint8_t)(FindCharIndex(string[i]));
    }
}

void CompressDataNamaKomponen(uint8_t initialData[8], uint8_t compressData[6]){
    uint64_t buffer = 0;
    unsigned short bitCount = 0;
    unsigned short outId= 0;

    for (unsigned short i = 0; i<8; ++i){
        buffer = (buffer << 6) | (initialData[i] & 0x3F);
        bitCount += 6;

        while (bitCount >= 8){
            bitCount -=8;
            compressData[outId++] = (uint8_t)(buffer >> bitCount);
        }
    }
}

void UnCompressDataNamaKomponen(uint8_t compressData[6], uint8_t initialData[8]){
    uint64_t buffer = 0;

    for (short i = 0; i<6; ++i){
        buffer = (buffer<<8) | (uint64_t)compressData[i];
    }

    for (short i = 7; i>=0; --i){
        initialData[i] = (uint8_t)(buffer & 0x3F);
        buffer >>= 6;
    }
}

void ConvertBitArrayToString (uint8_t bitArray[], char string[], unsigned short size){
    for (unsigned short i = 0; i<size; ++i){
        char character = FindChar((short)(bitArray[i]));
        if (character == '+') string[i] = '\0';
        else string[i] = character;
    }
    string[size] = '\0';
}

void UpdateNamaKomponen (CatalogItem *catalogItem, char namaKomponen[9]){
    uint8_t convertedString[8];
    ConvertStringToBitArray(namaKomponen, convertedString, 8);

    CompressDataNamaKomponen(convertedString, catalogItem->nama_komponen);
}

void GetNamaKomponen (CatalogItem *catalogItem, char namaKomponen[9]){
    uint8_t unCompressBitArray[8];
    UnCompressDataNamaKomponen(catalogItem->nama_komponen, unCompressBitArray);

    ConvertBitArrayToString(unCompressBitArray, namaKomponen, 8);
}

unsigned short GetLokasi (CatalogItem *catalogItem){
    uint8_t binaryLokasi = (catalogItem->lokasi_dan_jumlah_status[0] >> 2);
    return (unsigned short)(binaryLokasi);
}

void UpdateLokasi (CatalogItem *catalogItem, unsigned short newIndeksLokasi){
    if (newIndeksLokasi<=63){
        uint8_t binaryLokasi = (uint8_t)newIndeksLokasi;
        catalogItem->lokasi_dan_jumlah_status[0] = (binaryLokasi << 2) | ((catalogItem->lokasi_dan_jumlah_status[0]) & 0x3); 
    }
}

unsigned short GetStatusTersedia (CatalogItem *catalogItem){
    uint8_t binaryStatusTersedia = ((catalogItem->lokasi_dan_jumlah_status[0] & 0x3) << 4) | (catalogItem->lokasi_dan_jumlah_status[1] >> 4);
    return (unsigned short)(binaryStatusTersedia);
}

void UpdateStatusTersedia (CatalogItem *catalogItem, unsigned short newStatusTersedia){
    if (newStatusTersedia<=63){
        uint8_t binaryStatusTersedia = (uint8_t)newStatusTersedia;
        catalogItem->lokasi_dan_jumlah_status[0] = (binaryStatusTersedia>>4) | ((catalogItem->lokasi_dan_jumlah_status[0]) & 0xFC);
        catalogItem->lokasi_dan_jumlah_status[1] = (binaryStatusTersedia<<4) | ((catalogItem->lokasi_dan_jumlah_status[1]) & 0xF);
    }
}

unsigned short GetStatusDipinjam (CatalogItem *catalogItem){
    uint8_t binaryStatusDipinjam = ((catalogItem->lokasi_dan_jumlah_status[1] & 0xF) << 2) | (catalogItem->lokasi_dan_jumlah_status[2] >> 6);
    return (unsigned short)(binaryStatusDipinjam);
}

void UpdateStatusDipinjam (CatalogItem *catalogItem, unsigned short newStatusDipinjam){
    if (newStatusDipinjam<=63){
        uint8_t binaryStatusDipinjam = (uint8_t)newStatusDipinjam;
        catalogItem->lokasi_dan_jumlah_status[1] = (binaryStatusDipinjam>>2) | ((catalogItem->lokasi_dan_jumlah_status[1]) & 0xF0);
        catalogItem->lokasi_dan_jumlah_status[2] = (binaryStatusDipinjam<<6) | ((catalogItem->lokasi_dan_jumlah_status[2]) & 0x3F);
    }
}

unsigned short GetStatusRusak (CatalogItem *catalogItem){
    uint8_t binaryStatusRusak = (catalogItem->lokasi_dan_jumlah_status[2] & 0x3F);
    return (unsigned short)(binaryStatusRusak);
}

void UpdateStatusRusak (CatalogItem *catalogItem, unsigned short newStatusRusak){
    if (newStatusRusak<=63){
        uint8_t binaryStatusRusak = (uint8_t)newStatusRusak;
        catalogItem->lokasi_dan_jumlah_status[2] = (binaryStatusRusak) | ((catalogItem->lokasi_dan_jumlah_status[2]) & 0xC0);
    }
}

unsigned short GetJumlahStock (CatalogItem *catalogItem){
    return GetStatusTersedia(catalogItem) + GetStatusDipinjam(catalogItem) + GetStatusRusak(catalogItem);
}

unsigned short GetKategori (CatalogItem *catalogItem){
    uint8_t binaryKategori = (catalogItem->kategori_dan_pic[0] >> 4);
    return (unsigned short)(binaryKategori);
}

void UpdateKategori (CatalogItem *catalogItem, unsigned short newKategori){
    if (newKategori<=15){
        uint8_t binaryKategori = (uint8_t)newKategori;
        catalogItem->kategori_dan_pic[0] = (binaryKategori << 4) | ((catalogItem->kategori_dan_pic[0]) & 0xF);
    }
}

void UpperString(char string[], unsigned short len){
    ++len;
    while(len--){
        if (string[len-1] >= 97 && string[len-1] <= 122) string[len-1] -= 32;
    }
}

void CompressDataPIC(uint8_t initialData[4], uint8_t compressData[3]){
    uint32_t buffer = 0;

    buffer = (compressData[0] >> 4) & 0x0F;

    for (unsigned short i = 0; i<4; ++i){
        buffer = (buffer << 5) | (initialData[i] & 0x1F);
    }

    compressData[0] = (uint8_t)(buffer >> 16);
    compressData[1] = (uint8_t)(buffer >> 8);
    compressData[2] = (uint8_t)(buffer);
}

void UnCompressDataPIC(uint8_t compressData[3], uint8_t initialData[4]){
    uint32_t buffer = ((uint32_t)compressData[0] << 16) | ((uint32_t)compressData[1] << 8) | ((uint32_t)compressData[2]);

    for (short i = 3; i>=0; --i){
        initialData[i] = (uint8_t)(buffer & 0x1F);
        buffer >>= 5;
    }
}

void UpdatePIC (CatalogItem *catalogItem, char namaPIC[5]){
    UpperString(namaPIC, 4);
    uint8_t convertedString[4];
    
    ConvertStringToBitArray(namaPIC, convertedString, 4);
    

    CompressDataPIC(convertedString, catalogItem->kategori_dan_pic);
}

void GetPIC (CatalogItem *catalogItem, char namaPIC[5]){
    uint8_t convertedString[4];
    UnCompressDataPIC(catalogItem->kategori_dan_pic, convertedString);

    ConvertBitArrayToString(convertedString, namaPIC, 4);
}

void DeleteCatalogItem (CatalogItem *catalogItem){
    catalogItem->nama_komponen[0] = 0;
    catalogItem->nama_komponen[1] = 0;
    catalogItem->nama_komponen[2] = 0;
    catalogItem->nama_komponen[3] = 0;
    catalogItem->nama_komponen[4] = 0;
    catalogItem->nama_komponen[5] = 0;
    catalogItem->lokasi_dan_jumlah_status[0] = 0;
    catalogItem->lokasi_dan_jumlah_status[1] = 0;
    catalogItem->lokasi_dan_jumlah_status[2] = 0;
    catalogItem->kategori_dan_pic[0] = 0;
    catalogItem->kategori_dan_pic[1] = 0;
    catalogItem->kategori_dan_pic[2] = 0;
}

void InitializeCatalog(CatalogItem catalog[], unsigned short arraySize){
    for (unsigned short i = 0; i < arraySize; ++i){
        DeleteCatalogItem(catalog+i);
    }
}