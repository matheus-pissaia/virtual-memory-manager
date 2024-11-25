#ifndef PROCESS_H
#define PROCESS_H

#define MAX_PROCESSES 100

typedef struct
{
    int process_id;
    int process_size; // Size in bytes.
    int num_pages;    // Number of pages.
    int *page_table;  // Page map -> frames.
} Process;

void create_process();

#endif