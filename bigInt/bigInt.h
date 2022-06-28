#include <stdint.h>
#include <stdbool.h>
#define numLen 100

typedef struct {
  uint8_t number[numLen];
  size_t len;
} bigInt;

bool bigIntCreate(bigInt * bigInt, char * numStr);

void bigIntPrint(bigInt * bigInt);