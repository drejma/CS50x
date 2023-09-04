// https://cs50.harvard.edu/x/2023/labs/4/volume/
// Modifies a volume of a WAV file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // Declare temp array to store 44 bytes of header (HEADER_SIZE)
    uint8_t header[HEADER_SIZE - 1];

    // Read input header into temp array
    // Note: array is a pointer, no need for &
    fread(header, sizeof(uint8_t), HEADER_SIZE, input);

    // Write temp array into output header
    fwrite(header, sizeof(uint8_t), HEADER_SIZE, output);

    // Declare temp int to store 2-byte samples
    int16_t buffer;

    // Loop-read 2-byte samples from input and store them into buffer
    // Note: fread remembers where it stopped previous reading, no need to point it to 45th byte of an input
    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        // Multiply buffer value to increase/decrease its volume
        buffer *= factor;

        // Write buffer value into output
        // Note: fwrite remembers where it stopped previous writting, no need to point it to 45th byte of an output
        fwrite(&buffer, sizeof(int16_t), 1, output) ;
    };

    // Close files
    fclose(input);
    fclose(output);
}
