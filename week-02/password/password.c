// https://cs50.harvard.edu/x/2023/problems/2/
// Checks if password contains at least one lowercase, uppercase, number and symbol

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

bool valid(string password)
{
    bool ucase = false, lcase = false, number = false, symbol = false;

    // Loop through each character of a word and check, if it's a number, lcase, ucase or symbol
    for (int i = 0; i < strlen(password); i++)
    {
        if isdigit(password[i])
        {
            number = true;
        }
        else if islower(password[i])
        {
            lcase = true;
        }
        else if isupper(password[i])
        {
            ucase = true;
        }
        else
        {
            symbol = true;
        }
    }

    // If all are contained in a password, return true
    if (ucase && lcase && number && symbol)
    {
        return true;
    }
    else
    {
        return false;
    }
}
