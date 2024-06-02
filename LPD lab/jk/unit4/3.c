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

int ternarySearch(int arr[], int left, int right, int key) {
      if (right >= left) {
            int mid1 = left + (right - left) / 3;
            int mid2 = right - (right - left) / 3;

            if (arr[mid1] == key) {
                  return mid1;
            }

            if (arr[mid2] == key) {
                  return mid2;
            }

            if (key < arr[mid1]) {
                  return ternarySearch(arr, left, mid1 - 1, key);
            } else if (key > arr[mid2]) {
                  return ternarySearch(arr, mid2 + 1, right, key);
            } else {
                  return ternarySearch(arr, mid1 + 1, mid2 - 1, key);
            }
      }

      return -1;
}

int main() {
      int arr[] = {7, 4, 12, 6, 8, 3, 10, 14, 30, 18, 20};
      int n = sizeof(arr) / sizeof(arr[0]);
      int key = 3;

      bubbleSort(arr, n);
      int result = ternarySearch(arr, 0, n - 1, key);

      if (result == -1) {
            printf("Element not found\n");
      } else {
            printf("Element found at index %d\n", result);
      }

      return 0;
}