#include <stdio.h>
#include "screen.h"

/**
 * Move the cursor to a specific position on the screen.
 * @param row The row to move the cursor to
 * @param col The column to move the cursor to
 */
void move_cursor(int row, int col)
{
    printf("\033[%d;%dH", row, col);
}

/**
 * Clear the screen.
 *
 * ANSI escape code to clear the screen.
 */
void clear_screen()
{
    printf("\033[2J");
}