#include <stdio.h>
#include <stdbool.h>
#include "input.h"
#include "screen.h"
#include "windows.h"
#include "memory.h"
#include "process.h"

void show_main_menu()
{
    clear_screen();

    printf("Main Menu\n");
    printf("1. View memory usage\n");
    printf("2. Create Process\n");
    printf("3. Show page tables\n");
    printf("4. Exit program\n");
    printf("Select an option: ");
}

int main()
{
    enable_ansi_on_windows();
    init_memory();

    int option = 0;

    do
    {
        show_main_menu();

        option = get_user_input();

        switch (option)
        {
        case 1:
            view_memory_usage();
            break;
        case 2:
            create_process();
            break;
        case 3:
            clear_screen();
            printf("TODO: Implement page tables\n");
            break;
        case 4:
            printf("Bye bye\n");
            break;
        default:
            printf("Invalid option!\n");
            break;
        }
    } while (option != 4);

    return 0;
}
