// https://cs50.harvard.edu/x/2023/problems/3/max/
// Finds max value within an array

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    printf("The max value is %i.\n", max(arr, n));
}

int max(int array[], int n)
{
    int max_value = array[0];
    for (int i = 0; i < n; i++)
    {
        if (array[i] > max_value)
            max_value = array[i];
    }
    return max_value;
}
