#include <stdio.h>

#define MAX_TERMS 100

typedef struct {
      int row;
      int col;
      int value;
} Term;

void transpose(Term a[], Term b[]) {
      int numTerms = a[0].value;
      int numCols = a[0].col;
      int rowTerms[numCols];
      int startingPos[numCols];

      b[0].row = numCols;
      b[0].col = a[0].row;
      b[0].value = numTerms;

      if (numTerms > 0) {
            for (int i = 0; i < numCols; i++) {
                  rowTerms[i] = 0;
            }

            for (int i = 1; i <= numTerms; i++) {
                  rowTerms[a[i].col]++;
            }

            startingPos[0] = 1;

            for (int i = 1; i < numCols; i++) {
                  startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
            }

            for (int i = 1; i <= numTerms; i++) {
                  int j = startingPos[a[i].col]++;
                  b[j].row = a[i].col;
                  b[j].col = a[i].row;
                  b[j].value = a[i].value;
            }
      }
}

int main() {
      Term a[MAX_TERMS], b[MAX_TERMS];

      // Input the triplet matrix form
      printf("Enter the number of rows: ");
      scanf("%d", &a[0].row);
      printf("Enter the number of columns: ");
      scanf("%d", &a[0].col);
      printf("Enter the number of non-zero elements: ");
      scanf("%d", &a[0].value);

      printf("Enter the elements in triplet form (row, column, value):\n");
      for (int i = 1; i <= a[0].value; i++) {
            scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].value);
      }

      // Find the simple transpose
      transpose(a, b);

      // Output the simple transpose
      printf("Simple Transpose:\n");
      for (int i = 0; i <= b[0].value; i++) {
            printf("%d %d %d\n", b[i].row, b[i].col, b[i].value);
      }

      return 0;
}