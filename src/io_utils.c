#include <io_utils.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"
#define LOG_FILE_NAME "log.txt"

static FILE *_output_file, *_log_file;

void read_data_from_file(process_queue *queue, int *quantum, int *context_switch){
    FILE * processFile = fopen(INPUT_FILE_NAME , "r");
    char file_helper[MAX_ID_SIZE], end_line;

    // Quantum
    fscanf(processFile , "%s%d%c" , file_helper, quantum, &end_line);
    // Switch 
    fscanf(processFile , "%s%d%c" , file_helper, context_switch, &end_line);
    
    while (fscanf(processFile , "%s" , file_helper) != EOF){
        //allocate a memory for new process
        process * new_process = (process *) malloc(sizeof(process));
        if (new_process == NULL) //TODO: really must change this behaviour, 7mdy may kill me for this
            continue;
        strcpy(new_process->id, file_helper);
        fscanf(processFile , "%d%d%d%c" , &new_process->run_time, &new_process->arr_time
                , &new_process->mem_size, &end_line);
        enqueue(queue , new_process);
    }

    fclose(processFile);
    return;
}

void logger_init(void){
    _output_file = fopen(OUTPUT_FILE_NAME, "w");
    _log_file = fopen(LOG_FILE_NAME,"w");

    fprintf(_output_file, "process_id    "
                          "run_time      "
                          "arrival_time  "
                          "finish_time   "
                          "mem_size      "
                          "mem_start     "
                          "mem_end       \n");
}

void print_final_data(process *pro){
    fprintf(_output_file, "%14s%14d%14d%14d%14d%14d%14d\n",
     pro->id, pro->run_time, pro->arr_time, pro->finish_time, pro->mem_size,
     pro->mem_start, pro->mem_end);
}



