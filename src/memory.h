#ifndef MEMORY_H
#define MEMORY_H

typedef struct
{
    int frame_size;       // Size of each frame (page).
    int total_frames;     // Total number of frames.
    int *frames;          // Fisical memory represented by frames.
    bool *frame_occupied; // Bitmap representing the occupied frames.
    int free_frames;      // Empty frames counter.
} Memory;

Memory *get_memory();

void init_memory();
void view_memory_usage();

#endif