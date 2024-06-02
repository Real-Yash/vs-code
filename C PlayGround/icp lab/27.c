#include <stdio.h>

int main() {
    int array[3][3], sparse[10][3];
    int i, j, k = 1, m, n;

    printf("Enter the number of rows and columns of the matrix:\n");
    scanf("%d%d", &m, &n);

    printf("Enter elements of the matrix:\n");

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            printf("Enter element at position [%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    sparse[0][0] = m;
    sparse[0][1] = n;

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            if(array[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = array[i][j];
                k++;
            }
        }
    }

    sparse[0][2] = k-1;

    printf("\nSparse Matrix in Triplet form:\n");

    for(i = 0; i < k; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ", sparse[i][j]);
        }
        printf("\n");
    }

    return 0;
}
