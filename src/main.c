#include <stdio.h>
#include "screen.h"
#include "windows.h"

// Function to get user input
int get_user_input()
{
    int input;
    scanf("%d", &input);

    return input;
}

int main()
{
    enable_ansi_on_windows();

    clear_screen();

    printf("Main Menu\n");
    printf("1. Show memory\n");
    printf("2. Create Process\n");
    printf("3. Show page tables\n");

    printf("Select an option: ");
    int input = get_user_input();

    switch (input)
    {
    case 1:
        clear_screen();
        printf("Option 1 selected\n");
        break;
    case 2:
        clear_screen();
        printf("Option 2 selected\n");
        break;
    case 3:
        clear_screen();
        printf("Option 3 selected\n");
        break;
    default:
        printf("Invalid option!\n");
        break;
    }

    return 0;
}
