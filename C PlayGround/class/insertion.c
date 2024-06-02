#include <stdio.h>

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) { 
    int min_index = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_index]) {
        min_index = j;
      }
    }
    swap(&arr[min_index], &arr[i]);
  }
}

// Function to print an array
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// Main function
int main() {
  // Sample array
  int arr[] = {10, 6 , 5, 1, 7, 9, 3};
  int n = sizeof(arr) / sizeof(arr[0]);

  // Print the original array
  printf("Original array: \n");
  printArray(arr, n);

  // Sort the array using selection sort
  selectionSort(arr, n);

  // Print the sorted array
  printf("Sorted array: \n");
  printArray(arr, n);

  return 0;
}
