// https://cs50.harvard.edu/x/2023/psets/2/bulbs/
// Converts message into binary (bulbs)

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // Prompt a user to enter a message
    string message = get_string("Message: ");

    // Loop through each charater of a message
    for (int i = 0; i < strlen(message); i++)
    {
        // Get character's ASCII value
        int ascii_value = message[i];

        // Loop through each bit, from max to min
        for (int j = BITS_IN_BYTE; j > 0; j--)
        {
            // Check if bit should be on or off
            // 8th bit calculates as exp2(7), 1st bit as exp2(0)
            if (ascii_value >= (int) exp2(j - 1))
            {
                // If on, decrease targeted value
                print_bulb(1);
                ascii_value -= (int) exp2(j - 1);
            }
            else
            {
                print_bulb(0);
            }
        }

        // Print newline for next character
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
