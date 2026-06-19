#ifndef UPDATE_STOCK_H
#define UPDATE_STOCK_H

#include <Arduino.h>
#include "catalog.h"

void UpdateStock(CatalogItem catalog[], unsigned short arraySize, unsigned short id);

#endif