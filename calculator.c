#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include "C:\Users\JIRO\Desktop\FUNCTIONS\addition.c"
#include "C:\Users\JIRO\Desktop\FUNCTIONS\subtraction.c"
#include "C:\Users\JIRO\Desktop\FUNCTIONS\multiplication.c"
#include "C:\Users\JIRO\Desktop\FUNCTIONS\division.c"

void PrintBorder(); // The PrintBorder() function is declared.

int main()
{   
    system("cls"); // The system("cls") command is used to clear the console screen.
    
    char userName[20]; // (a character array to store the user's name)
    char userChoice = 'Y'; // (a character variable to store the user's operation choice)
    char resultChoice, exitChoice; // (a character variable to store the user's choice regarding reusing the result)
    int userMenu = 1;
    double result = 0; //(a double variable to store the result of calculations)
    bool ifResult = false; //(a boolean variable to determine if the result should be used again).

    //Several printf() statements are used to display a welcome message and prompt the user to enter their name.
    printf("    \033[36m====================================\033[0m");
    printf("\n    \033[31m=== Welcome to the Cool-Culator! ===\033[0m\n");
    printf("    \033[36m====================================\033[0m\n\n");
    printf("Please enter your name: "); 
    gets(userName);


    while (1){
        printf("\n\033[30m--------------------------------------------\033[0m");
        printf("\n\t\033[31m<=== Cool-Culator MENU ===>\033[0m");
        printf("\n\033[30m--------------------------------------------\033[0m");
        printf("\nCHOOSE AN OPERATION: \n\tENTER [1] for ADDITION\n\tENTER [2] for SUBTRACTION\n\tENTER [3] for MULTIPLICATION\n\tENTER [4] for DIVISION\n\tENTER [5] for EXIT\n");
        printf("\033[30m--------------------------------------------\033[0m");
        printf("\nEnter 1 - 5 to proceed\n\t\033[31mRESPONSE:\033[0m ");
        
        // If the input is invalid (not a single character between '1' and '5'), the program displays an error message.
        while (scanf(" %c", &userChoice) != 1 || userChoice < '1' || userChoice > '5') { 
            printf("\nINVALID INPUT! Please enter a number between 1 and 5:\n\t\033[31mRESPONSE:\033[0m ");

            while (getchar() != '\n') 
                continue;
        }

        if (result != 0 && userChoice != '5'){ // If the result is not zero and the user's choice is not '5' (exit), the program displays the last result and prompts the user to reuse it.
             
            printf("\n\033[31mThe last result is '%g'\033[0m\n", result);
            printf("\033[30m--------------------------------------------\033[0m");

                do {
                    printf("\n\nWould you like to add the result again?");
                    printf("\nEnter [Y] for YES, [N] for NO:\n\t\033[31mRESPONSE:\033[0m ");
                    if (scanf(" %c", &resultChoice) != 1 || (toupper(resultChoice) != 'Y' && toupper(resultChoice) != 'N')) {
                        printf("\nInvalid input. Please enter either 'Y' or 'N'.");
                        while (getchar() != '\n');
                    }

                    resultChoice = toupper(resultChoice);
                } while (resultChoice != 'Y' && resultChoice != 'N');

            ifResult = (resultChoice == 'Y'); // The ifResult variable is updated based on the user's choice.
        }

        if (userChoice != '5') // If the user's choice is not '5', the console screen is cleared using system("cls").
            system("cls");

        // The program uses a switch statement to perform the chosen operation based on the user's input.
        switch (userChoice){
            case '1':
                getSum(&result, ifResult, userName); // Call the function for Addition.
                break;
            case '2':
                getDifference(&result, ifResult, userName); // Call the function for Subtraction.
                break;
            case '3':
                getProduct(&result, ifResult, userName); // Call the function for Multiplication.
                break;
            case '4':
                getQuotient(&result, ifResult, userName); //Call the function for Division.
                break;
            case '5': // If the user's choice is '5', the program displays a farewell message, including the user's name, and returns 0, indicating successful program termination.
                do {
                    printf("\033[30m--------------------------------------------\033[0m");
                    printf("\n\nAre you sure you want to exit?");
                    printf("\nEnter [Y] for YES, [N] for NO:\n\t\033[31mRESPONSE:\033[0m ");
                    if (scanf(" %c", &exitChoice) != 1 || (toupper(exitChoice) != 'Y' && toupper(resultChoice) != 'N')) {
                        printf("\nInvalid input. Please enter either 'Y' or 'N'.");
                        while (getchar() != '\n');
                    }

                    exitChoice = toupper(exitChoice);
                } while (exitChoice != 'Y' && exitChoice != 'N');

                if (exitChoice == 'Y'){
                    printf("\033[30m--------------------------------------------\033[0m");
                    printf("\n\n\033[31mThank you, Mr./Ms. %s for using our Cool-Culator!\033[0m\n\n", userName);
                    return 0;
                }
        }
    }
}

void PrintBorder() { // The PrintBorder() function definition is provided, which prints a border line.
    printf("\n<================================================>\n");
}