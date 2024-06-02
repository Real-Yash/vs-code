#include <stdio.h>

int main() {
      int num = 10;
      int *ptr = &num;
      int **ptr2 = &ptr;

      printf("Value of num: %d\n", num);
      printf("Value of *ptr: %d\n", *ptr);
      printf("Value of **ptr2: %d\n", **ptr2);

      return 0;
}