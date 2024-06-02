#include <stdio.h>


     // to count no of zero in mat
     // 2 loop for iterate if  X==0 countzero++
void checkSparseMatrix(int matrix[3][3]) {
    int i, j, countZeros = 0;
   
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (matrix[i][j] == 0) {
                countZeros++;
            }
        }
    }
        // if cz>9/2 then true else false
    if (countZeros > 9 / 2) {
        printf("The given matrix is sparse.\n");
    } else {
        printf("The given matrix is not sparse.\n");
    }
}


        // convert to triplet
        
void convertToTriplet(int matrix[3][3]) {
    int triplet[3][3], k = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] != 0) {
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    /*printf("The matrix in triplet form:\n");
    for (int i = 0; i < k; i++) {
        printf("%d %d %d\n", triplet[i][0], triplet[i][1], triplet[i][2]);
    }*/
    printf("The matrix in triplet form:\n");
    displayMatrix(3, 3, triplet);
    
}

// void displayMatrix(int rows, int cols, int matrix[rows][cols]); Function declaration

// addition of matt

void addSparseMatrices(int matrix1[3][3], int matrix2[3][3]) {
    int sumMatrix[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sumMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("The sum of two sparse matrices:\n");
    displayMatrix(3, 3, sumMatrix);
}



void displayMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix1[3][3], matrix2[3][3];

    printf("Enter elements for matrix1 :\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter elements for matrix2 :\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    checkSparseMatrix(matrix1);
    convertToTriplet(matrix1);
    addSparseMatrices(matrix1, matrix2);

    return 0;
}