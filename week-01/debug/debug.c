// https://cs50.harvard.edu/x/2023/problems/1/debug/
// Prints hello with two get_strings

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Ask for your name and where live
    string name = get_string("What is your name? ");
    string location = get_string("Where do you live? ");

    // Say hello
    printf("Hello, %s, from %s!\n", name, location);
}
