#include <stdint.h>


void ringBufferInit();

int ringBufferIsEmpty();

int ringBufferIsFull();

int ringBufferFreeSpace();

int ringBufferWrite(uint8_t * data, size_t dataSize);

int ringBufferRead(uint8_t * data, size_t dataSize);