#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "C:\Users\JIRO\Desktop\FUNCTIONS\instruction.c"
#include "C:\Users\JIRO\Desktop\FUNCTIONS\getNumber.c"

// *result: A pointer to a double variable that will store the result of the division.
// ifResult: A boolean variable that indicates whether the function is being called to calculate a new result or to add the result of a previous calculation.
// userName: A character array that stores the user's name.
int getSum(double *result, bool ifResult, char userName[]) {
    double addendOne, addendTwo; // The function first declares three variables: minuend, subtrahend, and userChoice. addendOne and addendTwo will store the two numbers that are being added, 
    char userChoice = 'Y', choiceResult; // and userChoice will store the user's response to the prompt asking whether they want to continue using the subtraction function.

    printf("\t\033[36m============================\033[0m");
    printf("\n\t\033[31m=== CALCULATOR: ADDITION ===\033[0m\n");
    printf("\t\033[36m============================\033[0m\n\n");

    Instruction(1, userName); // The function then calls the Instruction() function to print the instructions for using the subtraction function.

    while (userChoice == 'Y') { // The function then enters a loop that will continue as long as the user wants to continue using the subtraction function.
        if ((ifResult || choiceResult == 'Y') && choiceResult != 'N') { // Checks if ifResult or choiceResult is true and choiceResult is not 'N'.
            GetNumberTwo(&addendTwo, 1); // The function checks the value of the ifResult argument. If ifResult is true, the function will use the previous result as the first number.
            addendOne = *result;
        } else { 
            GetNumberOne(&addendOne, 1); // Otherwise, the function will prompt the user to enter the first number.
            GetNumberTwo(&addendTwo, 1); // The function then prompts the user to enter the second number.
        }

        *result = addendOne + addendTwo; // The function add the second number from the first number and stores the result in the result variable.

        // The result of the addition is displayed using printf statements.
        printf("\n\033[30m--------------------------------------------\033[0m");
        printf("\n\033[31m|%g + %g = %g|\033[0m", addendOne, addendTwo, *result);
        printf("\nTherefore, The%ssum of %g added by %g is \033[31m'%g'\033[0m.\n", (ifResult || userChoice == 'Y' ? " new " : " "), addendOne, addendTwo, *result);
        printf("\033[30m--------------------------------------------\033[0m");

        do { // The code prompts the user if they want to continue using the addition operation and reads their response. It ensures that the user enters either 'Y' or 'N' and converts the input to uppercase using toupper.
            printf("\n\nWould you like to continue using the addition?");
            printf("\nEnter [Y] for YES, [N] for NO:\n\t\033[31mRESPONSE:\033[0m ");
            if (scanf(" %c", &userChoice) != 1 || (toupper(userChoice) != 'Y' && toupper(userChoice) != 'N')) {
                printf("\nInvalid input. Please enter either 'Y' or 'N'.");
                while (getchar() != '\n');
            }

            userChoice = toupper(userChoice);
        } while (userChoice != 'Y' && userChoice != 'N');

        if (userChoice == 'Y') { // If the user chooses to continue ('Y'), the last result is displayed, and the code prompts the user if they want to add the result again. 
            printf("\n\033[30m--------------------------------------------\033[0m");
            printf("\n\033[31mThe last result is '%g'.\033[0m\n", *result);
            printf("\033[30m--------------------------------------------\033[0m");

            do {
                printf("\n\nWould you like to add the result again?");
                printf("\nEnter [Y] for YES, [N] for NO:\n\t\033[31mRESPONSE:\033[0m ");
                if (scanf(" %c", &choiceResult) != 1 || (toupper(choiceResult) != 'Y' && toupper(choiceResult) != 'N')) {
                    printf("\nInvalid input. Please enter either 'Y' or 'N'.");
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

//     getSum(&result, resultChoice == 'Y', userName);

//     printf("\nThank you, Mr./Ms. %s for using our Cool-Culator's Addition!\n", userName);
// }


