#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
// set the value of each pixel as the average of each pixel in the current form to make that level
// of grayscale.
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg =
                round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
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
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen +
                                 .189 * image[i][j].rgbtBlue);

            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen +
                                   .168 * image[i][j].rgbtBlue);

            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen +
                                  .131 * image[i][j].rgbtBlue);

            image[i][j].rgbtRed = (sepiaRed > 255) ? 255 : sepiaRed;   // capping the value at 255
            image[i][j].rgbtBlue = (sepiaBlue > 255) ? 255 : sepiaBlue; 
            image[i][j].rgbtGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {

            temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height]
                  [width]; // making a copy so that it wont ruin the original image in the process

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

            int tred, tblue, tgreen;
            tred = tblue = tgreen = 0;
            float counter = 0.0;

            // gettting neighbour values
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {

                    int currentx = i + x;
                    int currenty = j + y;
                    // checking if neighbour is valid

                    if (currentx < 0 || currentx > (height - 1) || currenty < 0 ||
                        currenty > (width - 1))
                    {
                        continue;
                    }

                    // putting it into image value
                    tred += image[currentx][currenty].rgbtRed;
                    tblue += image[currentx][currenty].rgbtBlue;
                    tgreen += image[currentx][currenty].rgbtGreen;
                    counter++;
                }

                // taking avearge now;
                copy[i][j].rgbtRed = round(tred / counter);
                copy[i][j].rgbtBlue = round(tblue / counter);
                copy[i][j].rgbtGreen = round(tgreen / counter);
            }
        }
    }

    // putting them back into original image

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            image[i][j].rgbtRed = copy[i][j].rgbtRed;
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
        }
    }
    return;
}
