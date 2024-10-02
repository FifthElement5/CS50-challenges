#include <stdio.h>
#include <cs50.h>

int main(void)
{
   // Get size of grid
    int n;
    do
    {
      n = get_int("Size: ");
    }
    while (n < 1);

    // Print grid of bricks
   // first loop - row
   for (int i = 0; i < n; i++)
   {
    for (int x = 0; x < n-i-1; x++)
    {
    printf(".");
    }
      //second loop - heigth
    for (int j = 0; j <= i; j++)
    {
       printf("#");
    }
    printf("\n");
   }
   //second m
   for (int i = 0; i < n; i++)
   {
    for (int x = 0; x < n-i-1; x++)
    {
    printf(".");
    }
      //second loop - heigth
    for (int j = 0; j <= i; j++)
    {
       printf("#");
    }
     //inner loop for dots
    for (int k = 0; k < 2; k++)
    {
       printf(".");
    }
    //inner loop for second #
    for (int l = 0; l <= i; l++)
    {
      printf("#");
    }
    printf("\n");
   }
}
