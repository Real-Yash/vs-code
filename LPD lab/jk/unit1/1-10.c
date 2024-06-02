#include <stdio.h>

int main() {
      int num1 = 10, num2 = 20, num3 = 30;
      int *ptrArray[3]; // Array of pointers

      // Assigning addresses of variables to the array elements
      ptrArray[0] = &num1;
      ptrArray[1] = &num2;
      ptrArray[2] = &num3;

      // Accessing and printing values using pointers
      printf("Value at ptrArray[0]: %d\n", *ptrArray[0]);
      printf("Value at ptrArray[1]: %d\n", *ptrArray[1]);
      printf("Value at ptrArray[2]: %d\n", *ptrArray[2]);

      return 0;
}