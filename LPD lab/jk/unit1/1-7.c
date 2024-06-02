#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
      char *source = "Hello, world!";  // Source string
      char *destination;  // Destination string

      // Allocate memory for destination string
      destination = (char *)malloc(strlen(source) + 1);

      // Check if memory allocation was successful
      if (destination == NULL) {
            printf("Memory allocation failed!");
            return 1;
      }

      // Copy source string to destination string
      strcpy(destination, source);

      // Print the copied string
      printf("Copied string: %s\n", destination);

      // Free the allocated memory
      free(destination);

      return 0;
}