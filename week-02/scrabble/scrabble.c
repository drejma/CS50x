// https://cs50.harvard.edu/x/2023/labs/2/
// Compares scrabble-like point gains from two words and declare a winner

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // Compute and return score for string
    int score = 0;
    int ascii_value = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // Check if character is A-Z, else ignore
        ascii_value = toupper(word[i]);
        if (ascii_value >= 65 && ascii_value <= 90)
        {
            // POINTS positions: A = 0, Z = 25 (ASCII value - 65)
            score += POINTS[ascii_value - 65];
        }
    }
    return score;
}
