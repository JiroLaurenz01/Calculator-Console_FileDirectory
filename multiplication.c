#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
// #include "C:\Users\JIRO\Desktop\FUNCTIONS\instruction.c"
// #include "C:\Users\JIRO\Desktop\FUNCTIONS\getNumber.c"

int getProduct(double *result, bool ifResult, char userName[]) {
    double multiplicand, multiplier; //  The function first declares three variables: multiplicand, multiplier, and userChoice. multiplicand and multiplier will store the two numbers that are being multiplied,
    char userChoice = 'Y', choiceResult; // And userChoice will store the user's response to the prompt asking whether they want to continue using the multiplication function.

    printf("\t\033[36m==============================\033[0m");
    printf("\n\t\033[31m= CALCULATOR: MULTIPLICATION =\033[0m\n");
    printf("\t\033[36m==============================\033[0m\n\n");

    Instruction(3, userName); // The function then calls the Instruction() function to print the instructions for using the multiplication function.

    while (userChoice == 'Y') { // The function then enters a loop that will continue as long as the user wants to continue using the subtraction function.
        if ((ifResult || choiceResult == 'Y') && choiceResult != 'N') { // Checks if ifResult or choiceResult is true and choiceResult is not 'N'. 
            GetNumberTwo(&multiplier, 3); // The function checks the value of the ifResult argument. If ifResult is true, the function will use the previous result as the first number.
            multiplicand = *result;
        } else {
            GetNumberOne(&multiplicand, 3); // Otherwise, the function will prompt the user to enter the first number.
            GetNumberTwo(&multiplier, 3); // The function then prompts the user to enter the second number.
        }

        *result = multiplicand * multiplier; // The function multiplies the second number by the first number and stores the result in the result variable.

        // The function prints the result to the console.
        printf("\n\033[30m--------------------------------------------\033[0m");
        printf("\n\033[31m|%g x %g = %g|\033[0m", multiplicand, multiplier, *result);
        printf("\nTherefore, The%sproduct of %g multiplied by %g is \033[31m'%g'\033[0m.\n", (ifResult || userChoice == 'Y' ? " new " : " "), multiplicand, multiplier, *result);
        printf("\033[30m--------------------------------------------\033[0m");

        do { // The code prompts the user if they want to continue using the multiplication operation and reads their response. It ensures that the user enters either 'Y' or 'N' and converts the input to uppercase using toupper.
            printf("\n\nWould you like to continue using the multiplication?");
            printf("\nEnter [Y] for YES, [N] for NO:\n\t\033[31mRESPONSE:\033[0m ");
            if (scanf(" %c", &userChoice) != 1 || (toupper(userChoice) != 'Y' && toupper(userChoice) != 'N')) {
                printf("Invalid input. Please enter either 'Y' or 'N'.\n");
                while (getchar() != '\n');
            }

            userChoice = toupper(userChoice);
        } while (userChoice != 'Y' && userChoice != 'N');

        if (userChoice == 'Y') { // If the user chooses to continue ('Y'), the last result is displayed, and the code prompts the user if they want to add the result again. 
            printf("\n\033[30m--------------------------------------------\033[0m");
            printf("\n\033[31mThe last result is '%g'.\033[0m\n", *result);
            printf("\033[30m--------------------------------------------\033[0m");

            do {
                printf("\n\nWould you like to multiply the result again?");
                printf("\nEnter [Y] for YES, [N] for NO:\n\t\033[31mRESPONSE:\033[0m ");
                if (scanf(" %c", &choiceResult) != 1 || (toupper(choiceResult) != 'Y' && toupper(choiceResult) != 'N')) {
                    printf("Invalid input. Please enter either 'Y' or 'N'.\n");
                    while (getchar() != '\n');
                }

                choiceResult = toupper(choiceResult);
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

//     getProduct(&result, resultChoice == 'Y', userName);

//     printf("\nThank you, Mr./Ms. %s for using our Cool-Culator's Multiplication!\n", userName);
// }