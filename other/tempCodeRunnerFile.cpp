#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] > pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to implement quicksort
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main() {
    int otps[] = {5, 9, 8, 0, 3, 4, 2, 1, 6, 7, 9, 0, 3, 1, 2, 7, 8, 4, 5, 6};
    int n = sizeof(otps) / sizeof(otps[0]);

    printf("Unsorted OTPs: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", otps[i]);
    }

    quicksort(otps, 0, n - 1);

    printf("\nSorted OTPs: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", otps[i]);
    }

    return 0;
}