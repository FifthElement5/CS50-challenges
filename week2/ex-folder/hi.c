#include <stdio.h>
#include <cs50.h>

int main(void)
{
   //    string s = "HI!";
   //    string t = "BYE!";
   string words[2];

   words[0] = "HHII!!";
   words[1] = "BYE!";

//    printf("%s\n", words[0]);//s
    printf("%s\n", words[1]);//t
    printf("%i%c%i%c\n", words[0][0], words[0][1], words[0][2], words[0][3]);
    printf("%c%c%c%c\n", words[1][0], words[1][1], words[1][2], words[1][3]);

}
