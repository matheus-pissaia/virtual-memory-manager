#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "memory.h"
#include "process.h"
#include "screen.h"
#include "input.h"

int num_processes = 0;
Process processes[MAX_PROCESSES];

void create_process()
{
    clear_screen();

    printf("Enter the process ID: ");
    int process_id = get_user_input();

    printf("Enter the size of the process (in bytes): ");
    int process_size = get_user_input();

    if (num_processes >= MAX_PROCESSES)
    {
        printf("Maximum number of processes reached.\n");
        return;
    }

    Memory *memory = get_memory();

    if (process_size % memory->frame_size != 0)
    {
        printf("The process size must be a multiple of the frame size (%d).\n", memory->frame_size);
        return;
    }

    int num_pages = process_size / memory->frame_size;

    if (num_pages > memory->free_frames)
    {
        printf("Insufficient memory to alocate the process.\n");
        return;
    }

    Process *p = &processes[num_processes++];
    p->process_id = process_id;
    p->process_size = process_size;
    p->num_pages = num_pages;
    p->page_table = (int *)malloc(num_pages * sizeof(int));

    for (int i = 0, allocated_pages = 0; i < memory->total_frames && allocated_pages < num_pages; i++)
    {
        if (!memory->frame_occupied[i])
        {
            memory->frame_occupied[i] = true;
            memory->free_frames--;
            p->page_table[allocated_pages++] = i;
        }
    }
    printf("Process %d created with %d pages.\n", process_id, num_pages);
}
