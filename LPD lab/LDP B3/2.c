#include <stdio.h>
#include <stdlib.h>

int main()
{
      int rows, cols;
      int **array;

      printf("Enter the number of rows: ");
      scanf("%d", &rows);

      printf("Enter the number of columns: ");
      scanf("%d", &cols);

      array = (int**)malloc(rows * sizeof(int*));

      for (int i = 0; i < rows; i++) {
            array[i] = (int *)malloc(cols * sizeof(int));
      }

      if (array == NULL)
      {
            printf("Memory allocation failed\n");
            return 1;
      }

      printf("Enter elements\n");

      for (int i = 0; i < rows; i++)
      {
            for (int j = 0; j < cols; j++)
            {
                  scanf("%d", &array[i][j]);
            }
      }

      printf("Elements in the array are\n");
      for (int i = 0; i < rows; i++)
      {
            for (int j = 0; j < cols; j++)
            {
                  printf("%d ", array[i][j]);
            }
            printf("\n");
      }


      return 0;
}
