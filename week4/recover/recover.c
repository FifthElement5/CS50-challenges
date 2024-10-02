#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //must accept single command-line
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE.\n");
        return 1;
    }
    //open input file
    FILE *file = fopen(argv[1], "r");

    //check if file esists
    if (file == NULL)
    {
        printf("Could not ope file.\n");
        return 1;
    }
    //array to store the data
    BYTE buffer[512];
    //int to count files
    int file_number = 0;

    //pointer to write to
    FILE *img = NULL;
    char filename[9];

    //read 512 bytes into a buffer
    while (fread(buffer, sizeof(BYTE), 512, file) == 512)
    {
        //look for beggining og JPEG file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //if first jpeg starts
            if (file_number == 0)
            {
                //print the filenames with numbers
                sprintf(filename, "%03i.jpg", file_number);
                img = fopen(filename, "w");
                //write 512 bytes until a new jpeg
                fwrite(buffer, sizeof(BYTE), 512, img);
                //incrase number files
                file_number++;
            }
            else
            {
                //close a first file
                fclose(img);

                //print the file with numbers
                sprintf(filename, "%03i.jpg", file_number);
                img = fopen(filename, "w");
                //write 512 bytes until a new jpeg
                fwrite(buffer, sizeof(BYTE), 512, img);
                file_number++;

            }

        }

        else if (file_number != 0)
        {

            //write file
            fwrite(buffer, sizeof(BYTE), 512, img);

        }

    }

    // close infile
    fclose(file);

    //close outfile
    fclose(img);


    return 0;

}