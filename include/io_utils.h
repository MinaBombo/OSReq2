#pragma once

#include <process_queue.h>

void read_data_from_file(process_queue *queue, int *quantum, int *context_switch);
void logger_init(void);
void print_final_data(process *pro);