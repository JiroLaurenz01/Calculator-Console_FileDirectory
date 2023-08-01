void Instruction(int operation, char userName[]) {
    // The operations array is a 2D array that stores the names of the two operands for each type of operation.
    char operations[4][2][20] = {
        {"first addend", "second addend"},
        {"minuend", "subtrahend"},
        {"multiplicand", "multiplier"},
        {"dividend", "divisor"}
    };

    // The operationName array stores the names of the four operations.
    char operationName[4][20] = {"addition", "subtraction", "multiplication", "division"};

    // This line of code prints a welcome message to the user and provides instructions on how to use the program for the specified operation.
    // The userName variable is used to print the user's name, and the operationName[operation - 1] variable is used to print the name of the operation.
    printf("Great, Mr./Ms. %s! Let me guide you on how to use this program for %s:\n", userName, operationName[operation - 1]);
    printf("\n\t1. Enter a number for the %s and a number for the %s. Make sure to avoid using letters or other non-numeric characters, as it will be considered invalid.", operations[operation - 1][0], operations[operation - 1][1]);
    printf("\n\t2. Once you've entered both numbers successfully, the program will perform the %s and display the result for you.\n", operationName[operation - 1]);
    printf("\n\033[30m--------------------------------------------\033[0m");
}