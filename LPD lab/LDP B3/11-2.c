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

            // Check if target is present at mid
            if (arr[mid] == target)
                  return mid;

            // If target greater, ignore left half
            if (arr[mid] < target)
                  left = mid + 1;

            // If target is smaller, ignore right half
            else
                  right = mid - 1;
      }

      // Target is not present in array
      return -1;
}

int main() {
      int arr[] = {7, 4, 12, 6, 8, 3, 10, 14, 30, 18, 20};
      int n = sizeof(arr) / sizeof(arr[0]);
      int target = 12;
      bubbleSort(arr, n);
      int result = binarySearch(arr, 0, n - 1, target);
      if (result == -1)
            printf("Element not found in array\n");
      else
            printf("Element found at index %d\n", result);
      return 0;
}