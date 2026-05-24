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

unsigned short GetJumlahStock (CatalogItem *catalogItem){
    return (unsigned short)catalogItem->jumlah_stock;
}

void UpdateJumlahStock (CatalogItem *catalogItem, unsigned short jumlahBaru){
    if (jumlahBaru<=255) catalogItem->jumlah_stock = (uint8_t)jumlahBaru;
}

unsigned short GetLokasi (CatalogItem *catalogItem){
    uint8_t binaryLokasi = (catalogItem->lokasi_dan_status >> 2);
    return (unsigned short)(binaryLokasi);
}

void UpdateLokasi (CatalogItem *catalogItem, unsigned short newIndeksLokasi){
    if (newIndeksLokasi<=63){
        uint8_t binaryLokasi = (uint8_t)newIndeksLokasi;
        catalogItem->lokasi_dan_status = (binaryLokasi << 2) | ((catalogItem->lokasi_dan_status) & 0x3); 
    }
}

unsigned short GetStatus (CatalogItem *catalogItem){
    uint8_t binaryStatus = (catalogItem->lokasi_dan_status) & 0x3;
    return (unsigned short)(binaryStatus);
}

void UpdateStatus (CatalogItem *catalogItem, unsigned short newStatus){
    if (newStatus<=3){
        uint8_t binaryStatus = (uint8_t)newStatus;
        catalogItem->lokasi_dan_status = (binaryStatus) | ((catalogItem->lokasi_dan_status) & 0xFC);
    }
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

void InitializeCatalog(CatalogItem catalog[]){
    for (unsigned short i = 0; i < 93; ++i){
        catalog[i].nama_komponen[0] = 0;
        catalog[i].nama_komponen[1] = 0;
        catalog[i].nama_komponen[2] = 0;
        catalog[i].nama_komponen[3] = 0;
        catalog[i].nama_komponen[4] = 0;
        catalog[i].nama_komponen[5] = 0;
        catalog[i].jumlah_stock = 0;
        catalog[i].lokasi_dan_status = 0;
        catalog[i].kategori_dan_pic[0] = 0;
        catalog[i].kategori_dan_pic[1] = 0;
        catalog[i].kategori_dan_pic[2] = 0;
    }
}