// https://cs50.harvard.edu/x/2023/problems/1/half/
// Calculates half of a restaurant bill

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

float half(float bill, float tax, int tip)
{
    float final = bill * (1 + tax / 100);
    float half_with_tip = final * (1 + (float) tip / 100) / 2;
    return half_with_tip;
}
