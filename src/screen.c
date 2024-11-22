#include <stdio.h>

void moveCursor(int row, int col);
void clearScreen();

/**
 * Move the cursor to a specific position on the screen.
 * @param row The row to move the cursor to
 * @param col The column to move the cursor to
 */
void moveCursor(int row, int col)
{
    printf("\033[%d;%dH", row, col);
}

/**
 * Clear the screen.
 *
 * ANSI escape code to clear the screen.
 */
void clearScreen()
{
    printf("\033[2J");
}