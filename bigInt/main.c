#include "bigInt.h"
#include <stdio.h>
#include <stdbool.h>

void main(){
  char numStr[numLen] = {0};
  bigInt bigInt1;
  bool created = bigIntCreate(&bigInt1, "41252135213512353");
  if(created){
    printf("Created\n\r");
  } else {
    printf("Failed\n\r");
  }
  bigIntPrint(&bigInt1);
  return;
}