#include "bigInt.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool bigIntCreate(bigInt * bigInt, char * numStr){
  size_t i = 0;
  for ( i ; numStr[i] != 0 ; i++)
  {
    if (numStr[i] < 48 || numStr[i] > 57)
    {
      return false;
    }
  }
  if (i > numLen - 2)
  {
    return false;
  }

  bigInt->len = i + 1;
  i++;
  for(i; i > 0; i--){
    bigInt->number[bigInt->len - i] = numStr[i - 1];
  }
  bigInt->number[bigInt->len] = 0;
  return true;
}

void bigIntPrint(bigInt * bigInt){
  char numStr[numLen];
  for (size_t i = bigInt->len; i > 0 ; i--)
  {
    printf("%c",bigInt->number[i - 1]);
  }
  return;
}