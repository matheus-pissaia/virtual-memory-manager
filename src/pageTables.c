#include <stdio.h>
#include "pageTables.h"
#include "screen.h"
#include "input.h"
#include "process.h"

void view_page_tables()
{
    clear_screen();
    int process_id;
    Process *process;

    while (1)
    {
        printf("Enter the process ID: ");
        process_id = get_user_input();

        process = get_process_by_id(process_id);

        if (process)
            break;

        printf("Process %d not found.\n", process_id);
    }

    printf("Process size: %d bytes\n", process->process_size);
    printf("Process %d page table:\n", process_id);

    for (int j = 0; j < process->num_pages; j++)
    {
        printf("Page %d -> Frame %d\n", j, process->page_table[j]);
    }

    wait_for_enter();
}
