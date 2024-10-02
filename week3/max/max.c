// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    printf("The max value is %i.\n", max(arr, n));
}

// TODO: return the max value
int max(int array[], int n)


{
    //variable to store temporary position of array elements
    int sort;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            //bubble sorting with max at the beginning
            if (array[j] < array[j + 1])
            {
                sort = array[j];
                //swaping placec of array elements
                array[j] = array[j + 1];
                array[j + 1] = sort;
            }
        }
    }
    return array[0];
    // int max = array[0];
    // for (int i = 0; i < n; i++)
    // {
    //     if (max < array[i])
    //     {
    //         max = array[i];
    //     }
    // }
    // return max;
}
