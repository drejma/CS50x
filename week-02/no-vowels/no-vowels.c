// https://cs50.harvard.edu/x/2023/problems/2/no-vowels/
// Prints leetspeak-word based on given argument

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string word);

int main(int argc, string argv[])
{
    // If number of arguments <> 2 (1st argument = ./no-vowels + 2nd argument = word), return error (1) and end function
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }

    // Call replace function with 2nd argument value as input
    replace(argv[1]);
    printf("%s\n", argv[1]);

}

string replace(string word)
{
    // Loop through each character of a word
    for (int i = 0; i < strlen(word); i++)
    {
        // Check for a value of a character
        switch(word[i])
        {
            // In case character's value equals (a, e, i, or o), replace it with a leetspeak equivalent
            case 'a':
                word[i] = '6';
                break;
            case 'e':
                word[i] = '3';
                break;
            case 'i':
                word[i] = '1';
                break;
            case 'o':
                word[i] = '0';
                break;
            // Else value stays the same
            default:
                word[i] = word[i];
        }
    }
    return word;
}
