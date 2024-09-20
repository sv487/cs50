#include <cs50.h>
#include <stdio.h>
int calculate_quarters(int cents);//making respective functions for change owed for  respective coin category
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Prompt the user for change owed, in cents
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    int quarters = calculate_quarters(cents); //calling respective functions one by one now.
    cents = cents - (quarters * 25);// subtracting the amount from the money for forward evaluation.

    int dimes = calculate_dimes(cents);
    cents = cents - (dimes * 10);

    int nickels = calculate_nickels(cents);
    cents = cents - (nickels * 5);

    int pennies = calculate_pennies(cents);

    int coins = quarters + dimes + nickels + pennies;//adding all the coins now
    printf("%d\n", coins);//printing the coins
}

int calculate_quarters(int cents)
{
    int quarters = 0;
    while (cents >= 25)
    {
//setting the counter for number of quarters required till amount reaches below 25
        quarters++;
        cents -= 25;
    }
    return quarters;//returning the number of quarters used
}
int calculate_dimes(int cents)  // and so on for the rest of coins
{
    int dimes = 0;
    while (cents >= 10)
    {

        dimes++;
        cents -= 10;
    }
    return dimes;
}
int calculate_nickels(int cents)
{
    int nickels = 0;
    while (cents >= 5)
    {

        nickels++;
        cents -= 5;
    }
    return nickels;
}

int calculate_pennies(int cents)
{
    int pennies = 0;
    while (cents >= 1)
    {

        pennies++;
        cents -= 1;
    }
    return pennies;
}
