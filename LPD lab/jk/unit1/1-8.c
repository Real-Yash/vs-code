#include <stdio.h>
#include <stdlib.h>

int stringLength(char *str) {
      int length = 0;
      while (*str != '\0') {
            length++;
            str++;
      }
      return length;
}

int main() {
      char *str;
      int length;

      // Allocate memory for the string
      str = (char *)malloc(sizeof(char) * 100);

      printf("Enter a string: ");
      scanf("%s", str);

      length = stringLength(str);

      printf("Length of the string: %d\n", length);

      // Free the allocated memory
      free(str);

      return 0;
}