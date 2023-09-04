// https://cs50.harvard.edu/x/2023/psets/2/caesar/
// Encrypts a message using Caesar's cipher

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>  // isdigit()
#include <stdlib.h> // atoi()
#include <string.h> // strlen()

bool arg_digits_only(string arg);
char rotate(int c, int n);

int main(int argc, string argv[])
{
    // Check if contains 2 arguments (name + number)
    // Check if 2nd argument contains numbers only
    if (argc != 2 || !arg_digits_only(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert 2nd argument to number
    int key = atoi(argv[1]);

    // Prompt user to input initial (plain) text
    string plain_text = get_string("plaintext: ");

    // Loop through each character of a text and convert it via rotate function
    // Print cipher text
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plain_text); i++)
    {
        printf("%c", rotate(plain_text[i], key));
    }
    printf("\n");

}

bool arg_digits_only(string arg)
{
    for (int i = 0; i < strlen(arg); i++)
    {
        if (!isdigit(arg[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(int c, int n)
{
    // For alphabetical char, rotate; for other chars, keep the value
    if (isalpha(c))
    {
        // Get reference number, ignore x rotations through an alphabet (n % 26)
        int ref = c + (n % 26);

        // 90 = Z, 122 = z
        // Check if reference number doesn't exceed "z" or "Z", otherwise subtract 26
        if ((c <= 90 && ref > 90) || (c <= 122 && ref > 122))
        {
            return ref - 26;
        }
        else
        {
            return ref;
        }
    }
    else
    {
        return c;
    }
}