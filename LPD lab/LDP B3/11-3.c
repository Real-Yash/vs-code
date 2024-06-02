#include <stdio.h>

void bubbleSort(int arr[], int n) {
      for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                  if (arr[j] > arr[j + 1]) {
                        // Swap arr[j] and arr[j+1]
                        int temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                  }
            }
      }
}

int fibonacciSearch(int arr[], int n, int x)
{
      int fib2 = 0; // (m-2)th Fibonacci number
      int fib1 = 1; // (m-1)th Fibonacci number
      int fib = fib2 + fib1; // mth Fibonacci number

      while (fib < n)
      {
            fib2 = fib1;
            fib1 = fib;
            fib = fib2 + fib1;
      }

      int offset = -1;

      while (fib > 1)
      {
            int i = (offset + fib2) < (n - 1) ? (offset + fib2) : (n - 1);

            if (arr[i] < x)
            {
                  fib = fib1;
                  fib1 = fib2;
                  fib2 = fib - fib1;
                  offset = i;
            }
            else if (arr[i] > x)
            {
                  fib = fib2;
                  fib1 = fib1 - fib2;
                  fib2 = fib - fib1;
            }
            else
            {
                  return i;
            }
      }

      if (fib1 && arr[offset + 1] == x)
      {
            return offset + 1;
      }

      return -1;
}

int main()
{
      int arr[] = {7, 4, 12, 6, 8, 3, 10, 14, 30, 18, 20};
      int n = sizeof(arr) / sizeof(arr[0]);
      int x = 10;

      bubbleSort(arr, n);
      int index = fibonacciSearch(arr, n, x);

      if (index >= 0)
      {
            printf("Element found at index %d\n", index);
      }
      else
      {
            printf("Element not found\n");
      }

      return 0;
}