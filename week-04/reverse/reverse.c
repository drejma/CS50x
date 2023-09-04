// https://cs50.harvard.edu/x/2023/psets/4/reverse/
// Reverses a WAV file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    // Read header
    WAVHEADER wh;
    fread(&wh, sizeof(WAVHEADER), 1, input);

    // Use check_format to ensure WAV format
    if (!check_format(wh))
    {
        printf("Unsupported file format (must be .wav).\n");
        fclose(input);
        return 1;
    }

    // Open output file for writing
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not create %s.\n", argv[2]);
        fclose(input);
        return 1;
    }

    // Write header to file
    fwrite(&wh, sizeof(WAVHEADER), 1, output);

    // Use get_block_size to calculate size of block
    int block_size = get_block_size(wh);

    // Write reversed audio to file
    // Store current file position indicator = start of data sample
    long sample_start = ftell(input);

    // Create buffer to store read from input and write to output
    WORD buffer[block_size];

    // Jump to the last block in input file
    fseek(input, -block_size, SEEK_END);

    // Loop read blocks from input (end to start) and write blocks to output (start to end)
    while (ftell(input) >= sample_start)
    {
        fread(&buffer, block_size, 1, input);
        fwrite(&buffer, block_size, 1, output);
        fseek(input, (-2 * block_size), SEEK_CUR);
    }

    // Close opened files
    fclose(input);
    fclose(output);
}

int check_format(WAVHEADER header)
{
    // Check file format (.format must contain "WAVE")
    // Note: Must be done char by char
    char *wave = "WAVE";
    for (int i = 0; i < strlen(wave); i++)
    {
        if (header.format[i] != wave[i])
        {
            // Return false, if it doesn't
            return 0;
        }
    }
    // Otherwise, return true
    return 1;
}

int get_block_size(WAVHEADER header)
{
    return header.numChannels * (header.bitsPerSample / 8);
}