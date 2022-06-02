#include <stdio.h>
#include <string.h>

#include "ringbuffer.h"

int main()
{
  ringBufferInit();
  printf("Init\r\n");

  printf("FreeSpace - %d\r\n", ringBufferFreeSpace());

  char *data = "Hello";

  ringBufferWrite(data, strlen(data));
  printf("Writing %s ... \r\n", data);

  printf("FreeSpace - %d\r\n", ringBufferFreeSpace());
  printf("isEmpty - %d\r\n", ringBufferIsEmpty());

  char readData[6] = {0};
  ringBufferRead(readData, 5);
  printf("Read %s ... \r\n", readData);

  char *data2 = "Test";
  printf("FreeSpace:");
  printf("%d,", ringBufferFreeSpace());
  while (!ringBufferIsFull() && ringBufferWrite(data2, strlen(data2)) == 1)
  {
    printf("FreeSpace:");
    printf("%d,", ringBufferFreeSpace());
  };
  printf("\r\n");
  char readData2[101] = {0};
  int charsRead = ringBufferRead(readData2, 100);
  printf("Read %s ... Bytes Read %d \r\n", readData2, charsRead);

  printf("FreeSpace - %d\r\n", ringBufferFreeSpace());
  printf("isEmpty - %d\r\n", ringBufferIsEmpty());
};