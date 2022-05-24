#include <stdio.h>
#include <stdlib.h>

void toRoman(int n)
{
  char *romanNumerals = "IVXLCDM";
  int numeralsValues[] = {1, 5, 10, 50, 100, 500, 1000};
  size_t valuesLen = 7;
  char output[16] = {0};
  size_t outputIndex = 0;

  while (n > 0)
  {
    for (int i = valuesLen - 1; i >= 0; i--)
    {
      if (n >= numeralsValues[i])
      {
        output[outputIndex++] = romanNumerals[i];
        n -= numeralsValues[i];
        break;
      }
      else if (i % 2 == 1)
      {
        if (n + numeralsValues[i - 1] >= numeralsValues[i] && i > 0)
        {
          output[outputIndex++] = romanNumerals[i - 1];
          output[outputIndex++] = romanNumerals[i];
          n -= numeralsValues[i] - numeralsValues[i - 1];
          break;
        }
      }
      else if (n + numeralsValues[i - 2] >= numeralsValues[i] && i > 1)
      {
        output[outputIndex++] = romanNumerals[i - 2];
        output[outputIndex++] = romanNumerals[i];
        n -= numeralsValues[i] - numeralsValues[i - 2];
        break;
      }
    }
  }
  printf("%s", output);
  return;
}

void main()
{
  int n = 2753;
  toRoman(n);
  return;
}