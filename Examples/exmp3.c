#include <stdio.h>
#include <stdlib.h>
#include "../my_mem.h"

void allocateMemoryLeak() {
    // Allocate 1 MB of memory
    char *buffer = (char *)my_malloc(1024 * 1024);
    if (buffer == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    // Fill the allocated memory with data
    for (int i = 0; i < 1024 * 1024; i++) {
        buffer[i] = 'A';
    }
    // Intentionally forget to free the allocated memory
}

int main() {
    allocateMemoryLeak();
    printf("Program completed, but with a memory leak of 1 MB.\n");
    return 0;
}
