#include <stdio.h>

int main() {
    int array[3][3], i, j, count = 0;

    printf("Enter elements of the 2D array:\n");

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            printf("Enter element at position [%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
            if(array[i][j] == 0)
                count++;
        }
    }

    if(count > ((3*3)/2))
        printf("The given matrix is a sparse matrix.\n");
    else
        printf("The given matrix is not a sparse matrix.\n");

    return 0;
}
