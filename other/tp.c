#include <stdlib.h>

int main() {
    // Calculate the number of bytes in 10 GB
    size_t size = 10L * 1024 * 1024 * 1024;

    // Allocate the memory
    char* buffer = (char*)malloc(size);

    // Check if the memory was successfully allocated
    if (buffer == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Use the memory...
    // Don't forget to free the memory when you're done
   free(buffer);

    return 0;
}
