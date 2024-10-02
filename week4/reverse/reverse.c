#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Usage: ./reverse INPUT_file OUTPUT_file.\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 2;
    }

    // Read header
    // TODO #3
    WAVHEADER header;
    fread(&header, sizeof(WAVHEADER), 1, input);


    // Use check_format to ensure WAV format
    // TODO #4
    check_format(header);

    // Open output file for writing
    // TODO #5
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        fclose(input);
        printf("Could not create file.\n");
        return 4;
    }

    // Write header to file
    // TODO #6
    fwrite(&header, sizeof(WAVHEADER), 1, output);


    // Use get_block_size to calculate size of block
    // TODO #7
    int block = get_block_size(header);

    // Write reversed audio to file
    // TODO #8
    fseek(input, block, SEEK_END);
    BYTE buffer[block];
    while (ftell(input) - block > sizeof(header))
    {
        if (fseek(input, block * -2, SEEK_CUR))
        {
            return 1;
        }
        fread(buffer, block, 1, input);

        fwrite(buffer, block, 1, output);

    }

    fclose(input);
    fclose(output);
}

int check_format(WAVHEADER header)
{
    // TODO #4
    if (header.format[0] != 'W' && header.format[1] != 'A'
        && header.format[2] != 'V' && header.format[3] != 'E')
    {

        printf("Unsupported file format.\n");
        return 3;
    }

    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    int block = header.numChannels * (header.bitsPerSample / 8);
    return block;
}