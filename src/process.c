#include <stdio.h>
#include <stdbool.h>
#include "process.h"
#include "input.h"

int num_processes = 0;
Process processes[MAX_PROCESSES];

void create_process()
{
    printf("Informe o ID do processo: ");
    int process_id = get_user_input();

    printf("Informe o tamanho do processo (em bytes): ");
    int process_size = get_user_input();

    if (num_processes >= MAX_PROCESSES)
    {
        printf("Maximum number of processes reached.\n");
        return;
    }

    // if (process_size % physical_memory.frame_size != 0)
    // {
    //     printf("The process size must be a multiple of the frame size (%d).\n", physical_memory.frame_size);
    //     return;
    // }

    // int num_pages = process_size / physical_memory.frame_size;

    // if (num_pages > physical_memory.free_frames)
    // {
    //     printf("Insufficient memory to alocate the process.\n");
    //     return;
    // }

    // Process *p = &processes[num_processes++];
    // p->process_id = process_id;
    // p->process_size = process_size;
    // p->num_pages = num_pages;
    // p->page_table = (int *)malloc(num_pages * sizeof(int));

    // for (int i = 0, allocated_pages = 0; i < physical_memory.total_frames && allocated_pages < num_pages; i++)
    // {
    //     if (!physical_memory.frame_occupied[i])
    //     {
    //         physical_memory.frame_occupied[i] = true;
    //         physical_memory.free_frames--;
    //         p->page_table[allocated_pages++] = i;
    //     }
    // }
    // printf("Process %d created with %d pages.\n", process_id, num_pages);
}
