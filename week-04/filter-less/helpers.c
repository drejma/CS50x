// https://cs50.harvard.edu/x/2023/psets/4/filter/less/
// Functions to filter image (grayscale, sepia, reflect, blur)

#include "helpers.h"

#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average;
    // Loop through all image pixels (height, width)
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Calculate average RGB value of an image pixel
            // Note: "3.0" needed for getting correct base result; "round" function needed for correct rounding
            average = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0);

            // Assign average RGB value to an image pixel
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int originalRed, originalGreen, originalBlue;
    int sepiaRed, sepiaGreen, sepiaBlue;
    // Loop through all image pixels (height, width)
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Get original RGB values of an image pixel
            originalRed = image[i][j].rgbtRed;
            originalGreen = image[i][j].rgbtGreen;
            originalBlue = image[i][j].rgbtBlue;

            // Calculate sepia RGB values of an image pixel
            // Note: Each of these calculated values might exceed 255; RGB values must be integeres within 0-255 range
            sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // Assign sepia RGB values to an image pixel
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int originalRed[width], originalGreen[width], originalBlue[width];
    // Loop through height
    for (int i = 0; i < height; i++)
    {
        // First width loop to store original RGB values of each pixel
        for (int j = 0; j < width; j++)
        {
            originalRed[j] = image[i][j].rgbtRed;
            originalGreen[j] = image[i][j].rgbtGreen;
            originalBlue[j] = image[i][j].rgbtBlue;
        }
        // Second width loop to assign reflected RGB values to each image pixel
        for (int k = 0; k < width; k++)
        {
            image[i][k].rgbtRed = originalRed[width - k - 1];
            image[i][k].rgbtGreen = originalGreen[width - k - 1];
            image[i][k].rgbtBlue = originalBlue[width - k - 1];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width], blurColor;
    int leftBound, rightBound, topBound, bottomBound;
    int sumRed, sumGreen, sumBlue, count;

    // Copy image into temp for calculation purposes
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j].rgbtRed = image[i][j].rgbtRed;
            temp[i][j].rgbtGreen = image[i][j].rgbtGreen;
            temp[i][j].rgbtBlue = image[i][j].rgbtBlue;
        }
    }

    // Loop through all image pixels (height, width)
    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            // Reset sum and count values
            sumRed = 0, sumGreen = 0, sumBlue = 0, count = 0;

            // Define bounds for calculation purposes
            // Note: ?: ternary operator int variable = (bool-expression) ? 5 : 6;
            topBound = (k == 0) ? 0 : k - 1;
            bottomBound = (k == height - 1) ? height - 1 : k + 1;
            leftBound = (l == 0) ? 0 : l - 1;
            rightBound = (l == width - 1) ? width - 1 : l + 1;

            // Get variables for calculation purposes
            for (int m = topBound; m < bottomBound + 1; m++)
            {
                for (int n = leftBound; n < rightBound + 1; n++)
                {
                    sumRed += temp[m][n].rgbtRed;
                    sumGreen += temp[m][n].rgbtGreen;
                    sumBlue += temp[m][n].rgbtBlue;
                    count++;
                }
            }

            // Calculate blurred color for current image pixel
            blurColor.rgbtRed = round(sumRed / (float)count);
            blurColor.rgbtGreen = round(sumGreen / (float)count);
            blurColor.rgbtBlue = round(sumBlue / (float)count);

            // Assign color to original image pixel
            image[k][l].rgbtRed = blurColor.rgbtRed;
            image[k][l].rgbtGreen = blurColor.rgbtGreen;
            image[k][l].rgbtBlue = blurColor.rgbtBlue;
        }
    }
    return;
}