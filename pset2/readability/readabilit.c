#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
double calculateL(char *text);
double calculateS(char *text);

int main(void)
{
    char text[10000];
    printf("enter here");
    fgets(text, sizeof(text), stdin);

    double L = calculateL(text); // previuosly it showed one grade level less becasue of int so changed it to double and then rounded it later on
    double S = calculateS(text);
    double grade = ((0.0588 * L) - (0.296 * S) - 15.8);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }

    if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
        printf("Grade %d\n", (int)round(grade));
}

// to calculate L (average letters per 100 words)
double calculateL(char *text)
{
    int letterCount = 0, wordCount = 0;
    int i;

    for (i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        { // counting letters
            letterCount++;
        }

        if (isspace(text[i]) || text[i + 1] == '\0')
        { // counting words
            wordCount++;
        }
    }

    // returning L
    return (letterCount / (double)wordCount) * 100;
}
// to calculate S (average sentences per 100 words)
double calculateS(char *text)
{
    int wordCount = 0, sentenceCount = 0;
    int i;

    for (i = 0; text[i] != '\0'; i++)
    { // count words

        if (isspace(text[i]) || text[i + 1] == '\0')
        {
            wordCount++;
        }

        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        { // count sentence
            sentenceCount++;
        }
    }

    // returning s
    return (sentenceCount / (double)wordCount) * 100;
}
