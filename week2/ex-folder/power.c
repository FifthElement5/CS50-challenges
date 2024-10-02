#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int size;
    do
    {

      size = get_int("Size: ");
    }
    while (size < 1);

    //declare our array
    int twice[size];

    //set the first value
     twice[0] = 1;
     printf("%i\n", twice[0]);
     //rest of array
     for (int i = 1; i < size; i++)
     {
      //make the current element twice the size of previous
      twice[i] = 2 * twice[i - 1];

      //print the current element
      printf("%i\n", twice[i]);
     }
}