// https://cs50.harvard.edu/x/2023/labs/1/
// Calculates number of years to go from X-size population to Y-size population

#include <cs50.h>
#include <stdio.h>

int get_start_size(void);
int get_end_size(int b);

int main(void)
{
    // Prompt for start size
    int i = get_start_size();
    // Prompt for end size
    int j = get_end_size(i);
    // Calculate number of years until we reach threshold
    int years = 0;
    while (i < j)
    {
        years++;
        i += i / 3 - i / 4;
    }
    // Print number of years
    printf("Years: %i\n", years);
}

int get_start_size(void)
{
    int a;
    do
    {
        a = get_int("Start size: ");
    }
    while (a < 9);
    return a;
}

int get_end_size(int b)
{
    int a;
    do
    {
        a = get_int("End size: ");
    }
    while (a < b);
    return a;
}
