#include <io_utils.h>

int main(int argc, char **argv){

    process_queue *queue = init();
    int quantum, context_switch;

    read_data_from_file(queue, &quantum, &context_switch);

    return 0;
}
