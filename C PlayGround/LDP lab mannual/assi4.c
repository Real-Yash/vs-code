#include <stdio.h>

// Function to initialize the magic square matrix with zeros
void initializeMagicSquare(int size, int magicSquare[][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            magicSquare[i][j] = 0;
        }
    }
}

// Function to generate an odd-order magic square
void generateMagicSquare(int size, int magicSquare[][size]) {
    int num = 1;
    int i = 0, j = size / 2; // Start position for the number 1

    while (num <= size * size) {
        if (i < 0 && j == size) {z
            i += 2;
            j--;
        }
        if (i < 0) {
            i = size - 1;
        }
        if (j == size) {
            j = 0;
        }
        if (magicSquare[i][j] != 0) {
            i += 2;
            j--;
        }
        magicSquare[i][j] = num++;
        i--;
        j++;
    }
}

// Function to display the magic square
void displayMagicSquare(int size, int magicSquare[][size]) {
    printf("Magic Square of Order %d:\n", size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%3d ", magicSquare[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int size;
    printf("Enter the order of the magic square (odd number): ");
    scanf("%d", &size);

    if (size % 2 == 0) {
        printf("The order must be an odd number.\n");
        return 1;
    }

    int magicSquare[size][size];
    initializeMagicSquare(size, magicSquare);
    generateMagicSquare(size, magicSquare);
    displayMagicSquare(size, magicSquare);

    return 0;
}
