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
    int process_id;

    // Loop para garantir que um ID de processo único seja inserido
    while (1)
    {
        printf("Enter the process ID: ");
        process_id = get_user_input();

        // Verifica se o ID do processo já existe
        bool id_exists = false;
        for (int i = 0; i < num_processes; i++)
        {
            if (processes[i].process_id == process_id)
            {
                id_exists = true;
                break;
            }
        }

        if (id_exists)
        {
            printf("Error: A process with ID %d already exists. Please enter a unique process ID.\n", process_id);
        }
        else
        {
            // ID único encontrado, sai do loop
            break;
        }
    }

    Memory *memory = get_memory();

    int process_size;
    int num_pages;

    while (1)
    {
        printf("Enter the size of the process (in bytes): ");
        process_size = get_user_input();

        if (process_size <= 0)
        {
            printf("Error: The process size must be greater than zero.\n");
            continue;
        }

        num_pages = (process_size + memory->frame_size - 1) / memory->frame_size;

        if (num_pages > memory->free_frames)
        {
            printf("Insufficient memory to allocate the process. Available memory: %d bytes.\n", memory->free_frames * memory->frame_size);
            continue;
        }

        break;
    }

    if (num_processes >= MAX_PROCESSES)
    {
        printf("Maximum number of processes reached.\n");
        wait_for_enter();
        return;
    }

    // Prossegue com a criação do processo
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
    wait_for_enter();
}

Process *get_process_by_id(int process_id)
{
    for (int i = 0; i < num_processes; i++)
    {
        if (processes[i].process_id == process_id)
        {
            return &processes[i];
        }
    }
    return NULL;
}
