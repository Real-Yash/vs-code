#include <stdio.h>

// Function to find the maximum element in the array
int findMax(int arr[], int n) {
      int max = arr[0];
      for (int i = 1; i < n; i++) {
            if (arr[i] > max) {
                  max = arr[i];
            }
      }
      return max;
}

// Function to perform counting sort on the array based on a specific digit
void countingSort(int arr[], int n, int exp) {
      int output[n];
      int count[10] = {0};

      // Store count of occurrences in count[]
      for (int i = 0; i < n; i++) {
            count[(arr[i] / exp) % 10]++;
      }

      // Change count[i] so that count[i] contains the actual position of this digit in output[]
      for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
      }

      // Build the output array
      for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
      }

      // Copy the output array to arr[] so that arr[] contains sorted numbers according to the current digit
      for (int i = 0; i < n; i++) {
            arr[i] = output[i];
      }
}

// Function to perform bucket sort (radix sort)
void bucketSort(int arr[], int n) {
      // Find the maximum element to determine the number of digits
      int max = findMax(arr, n);

      // Perform counting sort for every digit
      for (int exp = 1; max / exp > 0; exp *= 10) {
            countingSort(arr, n, exp);
      }
}

// Function to print the array
void printArray(int arr[], int n) {
      for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
      }
      printf("\n");
}

// Driver code
int main() {
      int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
      int n = sizeof(arr) / sizeof(arr[0]);

      printf("Original array: ");
      printArray(arr, n);

      bucketSort(arr, n);

      printf("Sorted array: ");
      printArray(arr, n);

      return 0;
}