// https://cs50.harvard.edu/x/2023/labs/4/smiley/
// Changes all black pixels to a color of choosing

#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop vertically (height)
    for (int i = 0; i < height; i++)
    {
        // Loop horizontally (width)
        for (int j = 0; j < width; j++)
        {
            // Check if pixel is black (RGB = 000 000 000)
            if (image[i][j].rgbtRed == 0x00 && image[i][j].rgbtGreen == 0x00 && image[i][j].rgbtBlue == 0x00)
            {
                image[i][j].rgbtRed = 0xBA;
                image[i][j].rgbtGreen = 0xDA;
                image[i][j].rgbtBlue = 0x55;
            }
        }
    }
}
