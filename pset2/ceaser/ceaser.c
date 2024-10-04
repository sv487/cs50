#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

char cipher(char c, int n);

int main()
{
  char key[100];
  printf("enter");
  fgets(key, sizeof(key),stdin);

  
  for (int i = 0; key[i] != '\0' && key[i]!= '\n'; i++)
  {
    if (!isdigit(key[i]))
    { // checks if digit or not
      printf("enter a valid key");
      return 1;
    }
  }
  int shift = atoi(key);
  char plaintext[1000];
  printf("enter plaintext : ");
fgets(plaintext, sizeof(plaintext),stdin);

  printf("ciphertext :");
  for (int i = 0; plaintext[i] != '\0'; i++)
  {
    printf("%c", cipher(plaintext[i], shift));
  }
  printf("\n");

  return 0;
}
char cipher(char c, int n)
{
  if (isalpha(c))
  {
    char base = isupper(c) ? 'A' : 'a'; // shorthand if else if true returns upper else small

    return (c - base + n) % 26 + base;
  }

  return c;
}
