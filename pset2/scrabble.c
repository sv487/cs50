#include <stdio.h>
#include <string.h>
#include <ctype.h>
//for this prob take 1. input from both players 1 and 2
//2. calculate their score
//3. and compare their score

int points[] = { 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10 };
int calculatescore( char word[]);

int main(void)
{
char player1[50];
printf("Player 1: ");
scanf("%s",&player1);
char player2[50];
printf("Player 2: ");
scanf("%s",&player2);

int a = calculatescore(player1);
int b = calculatescore(player2);
if (a>b)
{
    printf("Player 1 wins");
}
else if (a<b)
{
    printf("Player 2 wins");
}

else
    printf("TIE");

}
int calculatescore(char word[]){
    int score = 0;
    for (int i = 0,len = strlen(word); i < len; i++)
    {
      
    if (isupper(word[i]))
    {
        score += points[(word[i])-'A'];
            }

    else if (islower(word[i]))
    {
        score+= points[(word[i])-'a'];
    }
    }

    return score;
    
    

}