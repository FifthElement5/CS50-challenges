#include <stdio.h>
#include <cs50.h>

const int N = 3;

float average(int length, int array[]);

int main(void)
{
    // int score1 = 72;
    // int score2 = 73;
    // int score3 = 33;

    // int scores[3];
    // scores[0] = get_int("Score: "); //72;
    // scores[1] = get_int("Score: "); //73;
    // scores[2] = get_int("Score: "); //33;

    int scores[N];
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: ");
    }


   // printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / (float)3);
   printf("Average: %f\n", average(N, scores));
}

float average(int length, int array[])
{
  //return (scores[0] + scores[1] + scores[2]) / (float)3;
  int sum = 0;
  for (int i = 0; i < length; i++)
  {
    sum += array[i];
  }
  return sum / (float) length;
}