// Convert a normal matrix into it’s equivalent sparse matrix and perform addition of two
// such sparse matrices.


#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int i, j, n, c1 = 1, c2 = 1, count = 1;
    int a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], s[MAX_SIZE * MAX_SIZE][3], t[MAX_SIZE * MAX_SIZE][3], sum[MAX_SIZE * MAX_SIZE * 2][3];

    printf("\nEnter dimension:");
    scanf("%d", &n);

    printf("\nEnter elements of first matrix:");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }

    printf("\nEnter elements of second matrix:");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            scanf("%d", &b[i][j]);
    }

    // Convert first matrix to sparse form
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (a[i][j] != 0) {
                s[c1][0] = i;
                s[c1][1] = j;
                s[c1][2] = a[i][j];
                c1++;
            }
        }
    }

    // Convert second matrix to sparse form
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (b[i][j] != 0) {
                t[c2][0] = i;
                t[c2][1] = j;
                t[c2][2] = b[i][j];
                c2++;
            }
        }
    }

        // Display sparse form of first matrix
    printf("\nThe sparse matrix form of first matrix is:\n");
    for (i = 1; i < c1; i++) {
        printf("%d %d %d\n", s[i][0], s[i][1], s[i][2]);
    }

    // Display sparse form of second matrix
    printf("\nThe sparse matrix form of second matrix is:\n");
    for (i = 1; i < c2; i++) {
        printf("%d %d %d\n", t[i][0], t[i][1], t[i][2]);
    }


    // Add the sparse matrices
    i = 1;
    j = 1;
    while (i < c1 && j < c2) {
        if (s[i][0] < t[j][0] || (s[i][0] == t[j][0] && s[i][1] < t[j][1])) {
            sum[count][0] = s[i][0];
            sum[count][1] = s[i][1];
            sum[count][2] = s[i][2];
            i++;
            count++;
        } else if (s[i][0] > t[j][0] || (s[i][0] == t[j][0] && s[i][1] > t[j][1])) {
            sum[count][0] = t[j][0];
            sum[count][1] = t[j][1];
            sum[count][2] = t[j][2];
            j++;
            count++;
        } else { 
            sum[count][0] = s[i][0];
            sum[count][1] = s[i][1];
            sum[count][2] = s[i][2] + t[j][2];
            i++;
            j++;
            count++;
        }
    }

    while (i < c1) {
        sum[count][0] = s[i][0];
        sum[count][1] = s[i][1];
        sum[count][2] = s[i][2];
        i++;
        count++;
    }

    while (j < c2) {
        sum[count][0] = t[j][0];
        sum[count][1] = t[j][1];
        sum[count][2] = t[j][2];
        j++;
        count++;
    }

    // Printing the sparse matrix form of sum
    printf("\nThe sparse matrix form of sum is:\n");
    for (i = 1; i < count; i++) {
        printf("%d %d %d\n", sum[i][0], sum[i][1], sum[i][2]);
    }

    return 0;
}