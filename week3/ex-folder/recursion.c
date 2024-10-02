#include <cs50.h>
#include <stdio.h>

 void draw(int n);

int main(void)
{
    //get height of pyramis
    int height = get_int("Height: ");

    //Draw pyramid
    draw(height);
}

void draw(int n)
{
    //If nothing to draw
    if (n <= 0)
    {
        return;
    }

    //Draw pyramid of height n - 1
    draw(n - 1);

    //draw one more row of width n
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    for (int j = 0; j < n; j++)
    {
        printf("*");
    }
    printf("\n");


}
