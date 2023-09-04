// https://cs50.harvard.edu/x/2023/psets/1/hello/
// Prints hello with a name

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get a name
    string name = get_string("What's your name? ");
    // Print hello with a name
    printf("Hello, %s\n", name);
}