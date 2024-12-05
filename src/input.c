#include <stdio.h>
#include "input.h"

/**
 * Reads an integer from the user and returns it.
 *
 * @return The integer read from the user.
 */
int get_user_input()
{
    int input;
    int result;

    while (1)
    {
        result = scanf("%d", &input);
        if (result == 1)
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            return input;
        }
        else
        {
            printf("Invalid input. Please enter a valid integer: ");
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
        }
    }
}


void wait_for_enter()
{
    printf("Press Enter to continue...");
    fflush(stdout);
    while (getchar() != '\n');
}
