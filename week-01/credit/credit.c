// https://cs50.harvard.edu/x/2023/psets/1/credit/
// Calculates validity and card network of a card number

#include <cs50.h>
#include <stdio.h>

long get_card_number(void);
int get_check_sum(long card_number);
bool get_check_sum_validity(int check_sum);
int get_check_number(long card_number);
int get_length(long card_number);

int main(void)
{
    long card_number = get_card_number();
    int check_sum = get_check_sum(card_number);
    bool is_valid = get_check_sum_validity(check_sum);
    int check_number = get_check_number(card_number);
    int check_length = get_length(card_number);

    // Test return values
    // printf("%i\n", check_sum);
    // printf("%i\n", check_number);
    // printf("%i\n", check_length);

    // Print card network, or "invalid" if doesn't match criteria
    if (is_valid)
    {
        if ((check_number == 34 || check_number == 37) && check_length == 15)
        {
            printf("AMEX\n");
        }
        else if (check_number >= 40 && check_number <= 49 && (check_length == 13 || check_length == 16))
        {
            printf("VISA\n");
        }
        else if (check_number >= 51 && check_number <= 55 && check_length == 16)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

long get_card_number(void)
{
    long i;

    // Prompt user to insert number
    do
    {
        i = get_long("Number: ");
    }
    while (i < 0);
    return i;
}

int get_check_sum(long card_number)
{
    int i = 0;

    // 2 * number on each odd position from the right, then sum products' digits
    for (long cur = card_number / 10; cur > 0; cur = cur / 100)
    {
        if (cur % 10 * 2 >= 10)
        {
            i = i + (cur % 10 * 2) / 10 + (cur % 10 * 2) % 10;
        }
        else
        {
            i = i + (cur % 10 * 2);
        }
    }

    // 1 * number on each even position from the right, then sum numbers and add to previous sum
    for (long cur = card_number; cur > 0; cur = cur / 100)
    {
        i = i + (cur % 10);
    }

    return i;
}

bool get_check_sum_validity(int check_sum)
{
    // Get card validity - valid if check_sum ends with 0
    if (check_sum % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int get_check_number(long card_number)
{
    long i = card_number;

    // Get first two digits from a card number
    while (i >= 100)
    {
        i = i / 10;
    }

    return i;
}


int get_length(long card_number)
{
    int i = 0;

    // Get length - count the number of card_number divisions by 10
    while (card_number > 1)
    {
        card_number = card_number / 10;
        i++;
    }

    return i;
}