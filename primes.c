#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int n)
{
  for (size_t i = 2; i <= sqrt((double)n); i++)
  {
    if (n % i == 0)
    {
      return false;
    }
  }
  return true;
}

int nthPrime(int n)
{
  int counter = 0;
  int i = 2;
  while (counter < n)
  {
    if (isPrime(i))
    {
      counter++;
    }
    i++;
  }
  return i - 1;
}

void main()
{
  int prime = nthPrime(10001);
  printf("%d", prime);
}