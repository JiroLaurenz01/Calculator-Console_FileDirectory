#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
// #include "C:\Users\JIRO\Desktop\FUNCTIONS\instruction.c"
// #include "C:\Users\JIRO\Desktop\FUNCTIONS\getNumber.c"

int getQuotient(double *result, bool ifResult, char userName[]) {
    double dividend, divisor;
    char userChoice = 'Y', choiceResult;
    int decimalPlaces;

    printf("\t\033[36m============================\033[0m");
    printf("\n\t\033[31m=== CALCULATOR: DIVISION ===\033[0m\n");
    printf("\t\033[36m============================\033[0m\n\n");

    Instruction(4, userName); // It then calls the Instruction() function to print the instructions for the division calculator.

    while (userChoice == 'Y') { // The function then enters a loop that continues as long as the user enters Y when asked if they want to continue using the division calculator.
        if ((ifResult || choiceResult == 'Y') && choiceResult != 'N') { // Checks if ifResult or choiceResult is true and choiceResult is not 'N'. 
            GetNumberTwo(&divisor, 4); // The function checks the value of the ifResult argument. If ifResult is true, the function will use the previous result as the first number.
            dividend = *result;
        } else {
            GetNumberOne(&dividend, 4); // Otherwise, the function will prompt the user to enter the first number.
            GetNumberTwo(&divisor, 4); // The function then prompts the user to enter the second number.
        }

        if (divisor == 0) { // The function then checks if the divisor is equal to 0. If it is, the function prints the following message
            printf("\033[30m--------------------------------------------\033[0m");
            printf("\nInvalid operation. Division by zero is not allowed.\n");
            printf("\033[30m--------------------------------------------\033[0m");
            continue;
        }

        *result = dividend / divisor; // If the divisor is not equal to 0, the function divides the dividend by the divisor and stores the result in *result. 
        printf("\n\033[30m--------------------------------------------\033[0m");
        printf("\nHow many decimal places do you want to show?\n\t\033[31mRESPONSE:\033[0m ");
        while (scanf("%d", &decimalPlaces) != 1) {
            printf("Invalid input. Please enter a number:\n\t\033[31mRESPONSE:\033[0m ");
            while (getchar() != '\n')
                ;
        }
        // The function prints the result to the console.
        printf("\n\033[30m--------------------------------------------\033[0m");
        printf("\n\033[31m|%g / %g = %.*f|\033[0m", dividend, divisor, decimalPlaces, *result);
        printf("\nTherefore, The%squotient of %g divided by %g is \033[31m'%.*f'\033[0m.\n",
               (ifResult || userChoice == 'Y' ? " new " : " "), dividend, divisor, decimalPlaces, *result);
        printf("\033[30m--------------------------------------------\033[0m");

        do { // // The code prompts the user if they want to continue using the subtraction operation and reads their response. It ensures that the user enters either 'Y' or 'N' and converts the input to uppercase using toupper.
            printf("\n\nWould you like to continue using the division?");
            printf("\nEnter [Y] for YES, [N] for NO:\n\t\033[31mRESPONSE:\033[0m ");
            char response;
            if (scanf(" %c", &response) != 1) {
                printf("\nInvalid input. Please enter either 'Y' or 'N'.");
                while (getchar() != '\n');
                continue;
            }

            userChoice = toupper(response);

            if (userChoice != 'Y' && userChoice != 'N') {
                printf("\nInvalid input. Please enter either 'Y' or 'N'.");
            }
        } while (userChoice != 'Y' && userChoice != 'N');

        if (userChoice == 'Y') { // If the user chooses to continue ('Y'), the last result is displayed, and the code prompts the user if they want to add the result again. 
            printf("\n\033[30m--------------------------------------------\033[0m");
            printf("\n\033[31mThe last result is '%.*f'.\033[0m\n", decimalPlaces, *result);
            printf("\033[30m--------------------------------------------\033[0m");

            do { 
                printf("\n\nWould you like to add the result again?");
                printf("\nEnter [Y] for YES, [N] for NO:\n\t\033[31mRESPONSE:\033[0m ");
                char resultResponse;
                if (scanf(" %c", &resultResponse) != 1) {
                    printf("\nInvalid input. Please enter either 'Y' or 'N'.");
                    while (getchar() != '\n');
                    continue;
                }

                choiceResult = toupper(resultResponse);

                if (choiceResult != 'Y' && choiceResult != 'N') {
                    printf("\nInvalid input. Please enter either 'Y' or 'N'.");
                }
            } while (choiceResult != 'Y' && choiceResult != 'N');
        }
    }

    system("cls"); // The system("cls") function is called to clear the console screen.
}

// int main()
// {
//     system("cls");

//     char userName[20], resultChoice;
//     double result = 0;

//     printf("Please, enter your name: ");
//     gets(userName);

//     getQuotient(&result, 0, userName);

//     printf("\nThank you, Mr./Ms. %s for using our Cool-Culator's Division!\n", userName);
// }
