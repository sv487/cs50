#include <stdio.h>
#include <string.h>

// Function to implement Luhn algorithm 
int luhn_checksum(const char *card_number) {
    int nDigits = strlen(card_number);
    int sum = 0;
    int isSecond = 0;

    // Start from the rightmost digit
    for (int i = nDigits - 1; i >= 0; i--) {
        int digit = card_number[i] - '0';  // Convert char to int using ascii values

        if (isSecond) {  // If it's a second digit (from right), double it
            digit = digit * 2;
            if (digit > 9) {
                digit = digit - 9;  // Subtract 9 if the result is greater than 9 to get the digit sum
            }
        }

        sum += digit;
        isSecond = !isSecond;  // Toggle isSecond to switch between doubling and not doubling
    }

    // Return true if sum is a multiple of 10
    return (sum % 10 == 0);
    }

    void print_card_type(const char *card_number) {
    // Extract the first two digits of the card number
    int first_digit = card_number[0] - '0';  // Convert char to int
    int first_two_digits = (card_number[0] - '0') * 10 + (card_number[1] - '0');  // Combine first two digits
    int length = strlen(card_number);

    // Check for card types
    if (first_digit == 4  && (length==13 || length == 16)) { // should satisfy both the conditions
        printf("VISA\n");
    } else if ((length == 16) && (first_two_digits >= 51 && first_two_digits <= 55)) {
        printf("MASTERCARD\n");
    } else if ((length == 15) && (first_two_digits == 34 || first_two_digits == 37)) {
        printf("AMEX\n");
    } else {
        printf("INVALID\n");
    }
}



int main() {
    char card_number[20];
    int length = strlen(card_number);


    // Input the card number as a string
    printf("Enter the card number: ");
    scanf("%s", card_number);

    // Call the function and display result
    if (luhn_checksum(card_number)) {
                print_card_type(card_number);

    }

else{
    printf("INVALID\n");
}
 return 0;
}
