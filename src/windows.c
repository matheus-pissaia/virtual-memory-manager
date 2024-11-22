#ifdef _WIN32
#include <windows.h>
#endif

/**
 * Enable ANSI escape codes on Windows.
 *
 * This function enables Virtual Terminal Processing on Windows so that ANSI
 * escape codes can be used to control the terminal.
 *
 * This function is a no-op if the program is not running on Windows.
 */
void enableAnsiOnWindows()
{
#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)
        return;

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode))
        return;

    // Enable Virtual Terminal Processing
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
#endif
}