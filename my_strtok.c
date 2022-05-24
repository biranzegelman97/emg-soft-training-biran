#include <stdio.h>
#include <stdbool.h>

bool isCharInDelimiters(char c, const char *delimiters)
{
  if (c == 0)
  {
    return false;
  }
  for (int i = 0; delimiters[i] != 0; i++)
  {
    if (delimiters[i] == c)
    {
      return true;
    }
  }
  return false;
}

char *my_strtok(char *str, const char *delimiters)
{
  static char *prev;
  char *p;
  if (str != NULL)
  {
    p = str;
  }
  else
  {
    if (prev == NULL)
    {
      return NULL;
    }
    p = prev;
  }

  while (isCharInDelimiters(*p, delimiters))
  {
    p++;
  }
  unsigned int tokenLength = 0;
  while (!isCharInDelimiters(*(p + tokenLength), delimiters) && *(p + tokenLength) != 0)
  {
    tokenLength++;
  }
  if (*(p + tokenLength) == 0)
  {
    prev = NULL;
  }
  else
  {
    *(p + tokenLength) = 0;
    prev = p + tokenLength + 1;
  }
  return p;
}

int main()
{
  char str[] = "- This, a sample string.";
  char *pch;
  printf("Splitting string \"%s\" into tokens:\n", str);
  pch = my_strtok(str, " ,.-");
  while (pch != NULL)
  {
    printf("%s\n", pch);
    pch = my_strtok(NULL, " ,.-");
  }
  return 0;
}