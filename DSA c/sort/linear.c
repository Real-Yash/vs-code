#include <stdio.h>

void linearSort(int arr[], int n) {
      for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                  if (arr[j] < arr[i]) {
                        int temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                  }
            }
      }
}

int main() {
      int arr[] = {5, 2, 8, 1, 3};
      int n = sizeof(arr) / sizeof(arr[0]);

      printf("Before sorting: ");
      for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
      }

      linearSort(arr, n);

      printf("\nAfter sorting: ");
      for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
      }

      return 0;
}