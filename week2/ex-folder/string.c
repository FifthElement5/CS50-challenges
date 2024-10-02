#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
  string word = "Emma";
  for (int i = 0; i < strlen(word); i++)
  {

    printf("%i%c \n", word[i], word[i]);
  }
  printf("\n");
}