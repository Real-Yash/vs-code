#include <stdio.h>

int main() {
    int OTP[] = {4,2,0,6,9,7,5,1,3,8,7,4,5,1,2,3,4,5,8,9};

    int n = 20;

    for (int i = 0; i < n-1; i++) {
        int max_idx = i;

        for (int j = i+1; j < n; j++)
            if (OTP[j] > OTP[max_idx])
                max_idx = j;

        if (max_idx != i) {
            int temp = OTP[max_idx];
            OTP[max_idx] = OTP[i];
            OTP[i] = temp;
        }
    }

    printf("The sorted OTP in descending order with Selection sorting is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", OTP[i]);
    printf("\n");

    return 0;
}