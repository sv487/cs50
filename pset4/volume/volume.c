// Modifies the volume of an audio file

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

    uint8_t header[HEADER_SIZE]; // an array of unsigned integer with bytes equal to header size

    // TODO: Copy header from input file to output file use fread here and fwrite to write 44 bytes
    // in the o/p file

    fread(header, HEADER_SIZE, 1, input);   // initially was doing an error here by using while loop , which was running indefinitely and crashing the code

    fwrite(header, HEADER_SIZE, 1, output);


    // TODO: Read samples from input file and write updated data to output file

    int16_t buffer; // stores 2 byte sample which is going to get modified.

    while (fread(&buffer, sizeof(int16_t), 1, input))
    {

        buffer= buffer * factor;           // volume changed

        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    fclose(input);
    fclose(output);
    return 0;
}
