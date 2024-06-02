#include <stdio.h>

void selectionSort(int OTP[], int n) {
    int i, j, min_num;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++) {
        // Find the minimum element in unsorted array
        min_num = i;
        for (j = i+1; j < n; j++)
            if (OTP[j] < OTP[min_num])
                min_num = j;

        // Swap the found minimum element with the first element
        if (min_num != i) {
            int temp = OTP[min_num];
            OTP[min_num] = OTP[i];
            OTP[i] = temp;
        }
    }
}

// function to print an array
void printArray(int OTP[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", OTP[i]);
    printf("\n");
}

// main function
int main() {
    int OTP[] = {4, 2, 0, 6, 9, 7, 5, 1, 3, 8, 7, 4, 5, 1, 2, 3, 4, 5, 8, 9};
    
    int size = sizeof(OTP) / sizeof(OTP[0]);

    printf("Original Array:\n");
    printArray(OTP, size);


    selectionSort(OTP, size);
    printf("Sorted array in ascending order:\n");
    printArray(OTP, size);

    return 0;
}
