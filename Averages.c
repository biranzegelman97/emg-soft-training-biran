#include <stdint.h>
#include <stdio.h>

void comulativeAverages(const int* input, size_t size, int * output)
{
  size_t sum = 0;
  for (size_t i = 0; i < size; i++)
  {
    sum += input[i];
    output[i] = sum / (i + 1);
  }
}

void movingAverages(const int * input, size_t size, int * output, size_t window)
{
  for (size_t i = 0; i < size; i++)
  {
    size_t currentIndex = i;
    size_t currentWindow = 1;

    while (currentIndex > 0 && currentWindow < window)
    {
      currentIndex--;
      currentWindow++;
    }
    
    size_t sum = 0;
    for (currentIndex; currentIndex <= i; currentIndex++)
    {
      sum += input[currentIndex];
    }
    output[i] = sum / currentWindow;
  }
}



int main()
{
  const int numbers[] = {22, 21, 20, 40, 604444, 44, 43, 64, 65, 33};
  int comulativeAveragesOutput[10];
  int movingAveragesOutput[10];

  comulativeAverages(numbers, 10, comulativeAveragesOutput);
  movingAverages(numbers,10,movingAveragesOutput, 4);

  for (size_t i = 0; i < 10; i++)
  {
    printf("Index: %d , ComulativeAverage: %d \r\n", i, comulativeAveragesOutput[i]);
  }
  printf("\r\n");
  
  for (size_t i = 0; i < 10; i++)
  {
    printf("Index: %d , movingAverage: %d \r\n", i, movingAveragesOutput[i]);
  }

  return 0;
}