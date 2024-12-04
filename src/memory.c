#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "memory.h"
#include "screen.h"
#include "input.h"

Memory memory;

Memory *get_memory()
{
    return &memory;
}

void init_memory()
{
    printf("Configuração inicial:\n");
    printf("Informe o tamanho da memória física (em bytes): ");

    int memory_size = get_user_input();

    printf("Informe o tamanho do quadro (em bytes): ");

    int frame_size = get_user_input();

    if (memory_size % frame_size != 0)
    {
        printf("Erro: O tamanho da memória deve ser múltiplo do tamanho do quadro.\n");
        exit(1);
    }

    memory.frame_size = frame_size;
    memory.total_frames = memory_size / frame_size;
    memory.frames = (int *)calloc(memory.total_frames, sizeof(int));
    memory.frame_occupied = (bool *)calloc(memory.total_frames, sizeof(bool));
    memory.free_frames = memory.total_frames;
}

void view_memory_usage()
{
    clear_screen();

    printf("Memory Usage (%d%% free):\n", (memory.free_frames * 100) / memory.total_frames);

    for (int i = 0; i < memory.total_frames; i++)
    {
        printf("Frame %d: %s\n", i, memory.frame_occupied[i] ? "occupied" : "empty");
    }

    wait_for_enter();
}