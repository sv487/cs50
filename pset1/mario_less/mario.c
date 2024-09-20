#include <stdio.h>
#include <cs50.h>
//functions like get_int can only be done via this header by harvard cs50

int main()
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    //number of rows + coloumns should be less than or equal to number of rows to print in later for loop

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((i + j) <= n)
                printf(" ");

            else
                printf("#");
        }

        printf("\n");
    }

    return 0;
}
