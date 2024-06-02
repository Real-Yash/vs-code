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

int binarySearch(int arr[], int left, int right, int target) {
      while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                  return mid;
            }

            if (arr[mid] < target) {
                  left = mid + 1;
            } else {
                  right = mid - 1;
            }
      }

      return -1;
}

int exponentialSearch(int arr[], int n, int target) {
      if (arr[0] == target) {
            return 0;
      }

      int i = 1;
      while (i < n && arr[i] <= target) {
            i *= 2;
      }

      return binarySearch(arr, i / 2, (i < n) ? i : n - 1, target);
}

int main() {
      int arr[] = {7, 4, 12, 6, 8, 3, 10, 14, 30, 18, 20};
      int n = sizeof(arr) / sizeof(arr[0]);
      int target = 12;
      bubbleSort(arr, n);
      int result = exponentialSearch(arr, n, target);

      if (result == -1) {
            printf("Element not found\n");
      } else {
            printf("Element found at index %d\n", result);
      }

      return 0;
}