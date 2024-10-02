#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //prompt user for input
    string text;
    do
    {
        text = get_string("Text: ");
    }
    while (text < 0);
    printf("Text: %s\n", text);
    // printf("%i letters\n", count_letters(text));
    // printf("%i words\n", count_words(text));
    // printf("%i sentences\n", count_sentences(text));

    float averageL = ((float) count_letters(text) / (float) count_words(text)) * 100;
    float averageS = ((float) count_sentences(text) / (float) count_words(text)) * 100;

    //Coleman-Liau formula
    float index = 0.0588 * averageL - 0.296 * averageS - 15.8;
    //grade level computed by formula
    int x = round(index);
    //prints the output
    if (x < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (x >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", x);
    }




}
//analyze input

int count_letters(string text)
{
    //calculate letters
    int letters = 0;
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (isupper(text[i]))
        {
            letters++;
        }
        else if (islower(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    //calculate words
    int words = 0;
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (isblank(text[i]))
        {
            words++;
        }
    }
    return words + 1;

}
int count_sentences(string text)
{
    //calculate sentences
    int sentences = 0;
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        //check if it's .! or ?
        if (ispunct(text[i]) && (text[i] == '.' || text[i] == '!' || text[i] == '?'))
        {
            sentences++;
        }
    }
    return sentences;
}