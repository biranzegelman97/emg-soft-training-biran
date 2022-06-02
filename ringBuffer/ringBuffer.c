#include <stdint.h>
#define bufferSize 100

uint8_t buffer[bufferSize];

size_t head;
size_t tail;

void ringBufferInit(){
  head = 0;
  tail = 0;
};

int ringBufferIsEmpty(){
  if (head == tail)
  {
    head = tail = 0;
    return 1;
  }
  return 0;
};

int ringBufferIsFull(){
  return head + bufferSize - 1 == tail;
};

int ringBufferFreeSpace(){
  if (ringBufferIsEmpty())
  {
    return bufferSize;
  }
  return bufferSize - tail + head;
};

int ringBufferWrite(uint8_t * data, size_t dataSize){
  if (ringBufferFreeSpace() < dataSize)
  {
    return 0;
  }

  for (size_t i = 0; i < dataSize; i++)
  {
    buffer[tail % bufferSize] = data[i];
    tail++;
  }
  return 1;
};

int ringBufferRead(uint8_t * data, size_t dataSize){
  size_t bytesRead = 0;
  if (ringBufferIsEmpty())
  {
    return bytesRead;
  }
  
  for (size_t i = 0; i < dataSize && !ringBufferIsEmpty(); i++)
  {
    data[i] = buffer[head % bufferSize];
    bytesRead++;
    head++;
  }
  
  return bytesRead;
};