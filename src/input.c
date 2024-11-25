#include <stdio.h>

/**
 * Reads an integer from the user and returns it.
 *
 * @return The integer read from the user.
 */
int get_user_input()
{
    int input;
    scanf("%d", &input);

    return input;
}