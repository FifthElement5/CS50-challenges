#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //calculating color gray
            int average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //calculatin sepiaRed
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            if (sepiaRed >= 255)
            {
                sepiaRed = 255;
            }
            //calculating sepiaGreen
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            if (sepiaGreen >= 255)
            {
                sepiaGreen = 255;
            }
            //calculating sepiaBlue
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            if (sepiaBlue >= 255)
            {
                sepiaBlue = 255;
            }


            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;


        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //creats temporary variable
    RGBTRIPLE temporary;
    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width / 2; j++)
        {
            //changes intex in row from last to first
            temporary = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temporary;


        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //copy of image by declaring 2d array
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //variables for total red , green , blue + counter
            float count = 0;
            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;

            //loops over row in 'small box'
            for (int k = - 1; k < 2; k++)
            {
                //loops over column in 'small box'
                for (int m = - 1; m < 2; m++)
                {
                    int pixelK = i + k;
                    int pixelM = j + m;

                    //chiecking if pixels are valid
                    if (pixelK < 0 || pixelK > height - 1 || pixelM < 0 || pixelM > width - 1)
                    {
                        continue;
                    }

                    sumRed += image[pixelK][pixelM].rgbtRed;
                    sumGreen += image[pixelK][pixelM].rgbtGreen;
                    sumBlue += image[pixelK][pixelM].rgbtBlue;
                    count++;
                }
                //average of pixels around
                copy[i][j].rgbtRed = round(sumRed / count);
                copy[i][j].rgbtGreen = round(sumGreen / count);
                copy[i][j].rgbtBlue = round(sumBlue / count);
            }


        }
    }
    //copy back to image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
        }
    }
    return;
}
