// https://cs50.harvard.edu/x/2023/psets/2/readability/
// Counts Coleman-Liau index from a given text

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    int index;
    float L, S;

    // Get text
    string text = get_string("Text: ");

    // Get number of letters, words and sentences (separate, reusable functions)
    // Count average number of (L) letters & (S) sentences per 100 words
    L = (float) count_letters(text) / count_words(text) * 100.0;
    S = (float) count_sentences(text) / count_words(text) * 100.0;

    // Count Coleman-Liau index
    index = round(0.0588 * L - 0.296 * S - 15.8);

    // Print grade results
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    int result = 0;
    // Count number of letters in a given text including ending nul (len + 1)
    for (int i = 0, n = strlen(text) + 1; i < n; i++)
    {
        // ASCII 65 = A, 90 = Z
        if (toupper(text[i]) >= 65 && toupper(text[i]) <= 90)
        {
            result++;
        }
    }
    return result;
}

int count_words(string text)
{
    int result = 0;
    // Count number of words in a given text including ending nul (len + 1)
    for (int i = 0, n = strlen(text) + 1; i < n; i++)
    {
        // ASCII 0 = nul, 32 = space
        if (text[i] == 0 || text[i] == 32)
        {
            result++;
        }
    }
    return result;
}

int count_sentences(string text)
{
    int result = 0;
    // Count number of sentences in a given text including ending nul (len + 1)
    for (int i = 0, n = strlen(text) + 1; i < n; i++)
    {
        // ASCII 33 = exclamation point, 46 = period, 63 = question mark
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            result++;
        }
    }
    return result;
}