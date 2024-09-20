#include <stdio.h>
#include <cs50.h>

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
            if ((i + j) <= n)//to print the spaces or identation
                printf(" ");

            else
                printf("#"); // printing hashes
        }

        printf("  ");//printing wall gap

        for(int k=0 ; k<i;k++){
            printf("#");//printing right side of wall
        }

        printf("\n");
    }

    return 0;
}
