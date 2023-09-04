// https://cs50.harvard.edu/x/2023/shorts/recursion/
// Collatz

#include <stdio.h>
#include <cs50.h>

int collatz(int n);

int main(void)
{
    int initial_value = get_int("Inital value: ");
    printf("Number of steps: %i\n", collatz(initial_value));
}

int collatz(int n)
{
    // Base case
    if (n == 1)
        return 0;

    // Recursive case
    // Even numbers
    else if (n % 2 == 0)
        return 1 + collatz(n / 2);
    // Odd numbers
    else
        return 1 + collatz(3 * n + 1);
}