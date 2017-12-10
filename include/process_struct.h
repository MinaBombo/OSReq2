#pragma once

#define MAX_ID_SIZE 32

struct _process{
    char id[MAX_ID_SIZE];
    int run_time, arr_time, rem_time, finish_time;
    int mem_size, mem_start, mem_end;
};
typedef struct _process process;