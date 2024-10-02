#include <stdio.h>

#define BITS 8


void binarny(int dzies)
{
    int reszta, i, j;

    int binary[BITS];
    for (i=0; i<BITS ; i++)
    {
        reszta = dzies % 2;
        binary[i] = reszta;
        // printf(" b%i", binary[i]);
        dzies /= 2;
    }
    for (j = BITS - 1; j >=0; j--)
    {
        printf(" %i", binary[j]);
    }
    printf("\n");

}

int main(void)
{

    binarny(7);

    return(0);
}
