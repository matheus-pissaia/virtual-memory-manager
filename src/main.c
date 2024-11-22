#include <stdio.h>
#include "screen.h"
#include "windows.h"

// Function to get user input
int getUserInput()
{
    int input;
    scanf("%d", &input);

    return input;
}

int main()
{
    enableAnsiOnWindows();

    clearScreen();

    printf("Main Menu\n");
    printf("1. Show memory\n");
    printf("2. Create Process\n");
    printf("3. Show page tables\n");

    printf("Select an option: ");
    int input = getUserInput();

    switch (input)
    {
    case 1:
        clearScreen();
        printf("Option 1 selected\n");
        break;
    case 2:
        clearScreen();
        printf("Option 2 selected\n");
        break;
    case 3:
        clearScreen();
        printf("Option 3 selected\n");
        break;
    default:
        printf("Invalid option!\n");
        break;
    }

    return 0;
}
