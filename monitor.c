#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <ncurses.h>
#include "my_mem.h"

#define MAX_PROCESSES 1024

void cleanup(){
    cleanup_memory_tracker();
}

int main() {
    initialize_process();
    initialize_memory_tracker();
    atexit(cleanup);
    // Shared Memory for count and map
    int count_shm_id = shmget(ftok("/tmp/shmfile_count", 64), sizeof(int), IPC_CREAT | 0666);
    process_count = (int *)shmat(count_shm_id, NULL, 0);
    
    int shm_id = shmget(12345, sizeof(ProcessMemoryInfo) * MAX_PROCESSES, IPC_CREAT | 0666);
    process_map = (ProcessMemoryInfo *)shmat(shm_id, NULL, 0);
    
    while (1) {
        printf("\033[H\033[J"); // Clear Previous Screen Output
        for (int i = 0; i < *process_count; i++) {
            if (!process_map[i].pid) {
                remove_process(process_map[i].pid); // Remove terminated process
            }
        }
        print_memory_info(); // Display the memory usage info
        sleep(2);  // Update every 2 seconds
    }
    return 0;
}

