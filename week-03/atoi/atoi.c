// https://cs50.harvard.edu/x/2023/problems/3/atoi/
// Recursion of converting string numbers to ints (atoi)

#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // Get index of the last char of an input
    int index = strlen(input) - 1;

    // Get its value; ASCII '0' = 60, '1' = 61 etc.
    int value = input[index] - '0';

    // Replace the last char of an input with a null terminator (shortens the input)
    input[index] = '\0';

    // Base case
    if (index < 1)
        return value;

    // Recursive case
    return value + 10 * convert(input);

}