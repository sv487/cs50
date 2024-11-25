#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])   // in this , task was to recover deleted files from the memory card given as card.raw
{

    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    if (!card)
    {
        return 1;
    }
    typedef uint8_t BYTE;
    BYTE buffer[512];  // creating a buffer to manipulate data

    // While there's still data left to read from the memory card
    char filename[8];
    FILE *currentf = NULL;
    int jpeg_found = 0; // using it as a flag bit

    // size_t elementsread = fread(buffer, 1, 512, card);
    // FILE *img = fopen(buffer, "w"); why happen in the 1 place
    int filecount = 0;
    while (fread(buffer, 1, 512, card) == 512)

    {
        // jpeg starts with header first 3 bytes are 0xff , 0xd8 , 0xff and ends with 0xe0,0xe1,0xe2

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (jpeg_found)
            {
                fclose(currentf);
            }
            else
            {
                jpeg_found = 1;
            }

            sprintf(filename, "%03i.jpg", filecount);
            currentf = fopen(filename, "w");
            if (!currentf)
            {
                fclose(card);
                return 1;
            }
            filecount++;
            // create a new file each time u encounter and write a new blockb

        }
        if(currentf != NULL)
         fwrite(buffer, sizeof(BYTE), 512, currentf); 

    }

        // close files
        fclose(currentf);
        fclose(card);
        return 0;
}
