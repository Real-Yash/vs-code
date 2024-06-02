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

int interpolationSearch(int arr[], int n, int x) {
      int low = 0, high = (n - 1);
  
      while (low <= high && x >= arr[low] && x <= arr[high]) {
            if (low == high) {
                  if (arr[low] == x)
                        return low;
                  return -1;
            }
            
            int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]));
            
            if (arr[pos] == x)
                  return pos;
            
            if (arr[pos] < x)
                  low = pos + 1;
            else
                  high = pos - 1;
      }
      
      return -1;
}

int main() {
      int arr[] = {7, 4, 12, 6, 8, 3, 10, 14, 30, 18, 20};
      int n = sizeof(arr) / sizeof(arr[0]);
      int x = 10;
      
      bubbleSort(arr, n);
      int index = interpolationSearch(arr, n, x);
      
      if (index != -1)
            printf("Element found at index %d\n", index);
      else
            printf("Element not found\n");
      
      return 0;
}