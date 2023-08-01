void GetNumberOne(double *numOne, int operation)
{
    double temp;

    // A 2D array operations is defined, which holds strings representing different operations and their corresponding labels.
    char operations[4][2][20] = {
        {"first addend", "second addend"},
        {"minuend", "subtrahend"},
        {"multiplicand", "multiplier"},
        {"dividend", "divisor"}
    };

    // Prompt the user to enter the value for the first number by using the label associated with the specified operation.
    printf("\nKindly enter the value for your %s:\n\t\033[31mRESPONSE:\033[0m ", operations[operation - 1][0]);
    while (scanf("%lf", &temp) != 1) { // Read the user's input using scanf and store it in the temp variable.
        printf("Invalid Input. Please enter numbers only:\n\t\033[31mRESPONSE:\033[0m "); // Display an error message if the input is not a valid number.
        while (getchar() != '\n'); // Clear any remaining characters in the input buffer.
    }

    *numOne = temp; // Assign the value of temp to the variable pointed to by numOne.
}

void GetNumberTwo(double *numTwo, int operation)
{
    double temp;

    // A 2D array operations is defined, which holds strings representing different operations and their corresponding labels.
    char operations[4][2][20] = {
        {"first addend", "second addend"},
        {"minuend", "subtrahend"},
        {"multiplicand", "multiplier"},
        {"dividend", "divisor"}
    };

    // Prompt the user to enter the value for the second number by using the label associated with the specified operation.
    printf("\nKindly enter the value for your %s:\n\t\033[31mRESPONSE:\033[0m ", operations[operation - 1][1]);
    while (scanf("%lf", &temp) != 1) { // Read the user's input using scanf and store it in the temp variable.
        printf("Invalid Input. Please enter numbers only.\n\t\033[31mRESPONSE:\033[0m "); // Display an error message if the input is not a valid number.
        while (getchar() != '\n'); // Clear any remaining characters in the input buffer.
    }

    *numTwo = temp; // Assign the value of temp to the variable pointed to by numTwo.
}