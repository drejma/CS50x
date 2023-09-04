// https://cs50.harvard.edu/x/2023/psets/1/mario/more/
// Draws two-sided Mario pyramid based on given height

#include <cs50.h>
#include <stdio.h>

int get_height();
void print_blank_or_hash(int number, bool is_blank);

int main(void)
{
    int height = get_height();
    // Loop until height met
    // Starting with row = 1 instead of row = 0 intentionally (used as print_blank_or_hash parameter)
    for (int row = 1; row < height + 1; row++)
    {
        // First row = (height - 1) blanks, (1) hash
        // Last row = (0) blanks, (height) hashes
        // Mirror print, with 2 spaces in between
        print_blank_or_hash(height - row, true);
        print_blank_or_hash(row, false);
        print_blank_or_hash(2, true);
        print_blank_or_hash(row, false);
        // print_blank_or_hash(height - row, true); // Unnecessary?
        printf("\n");
    }
}

int get_height()
{
    int i;
    // Loop until user inserts number between 1 and 8 (inclusive)
    do
    {
        i = get_int("Height: ");
    }
    while (i < 1 || i > 8);
    return i;
}

void print_blank_or_hash(int number, bool is_blank)
{
    // Loop print in a row number-times
    // Printed symbol based on bool input (true = blank, false = hash)
    for (int i = 0; i < number; i++)
    {
        if (is_blank)
        {
            printf(" ");
        }
        else
        {
            printf("#");
        }
    }
}