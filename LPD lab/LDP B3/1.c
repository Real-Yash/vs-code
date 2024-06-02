#include <stdio.h>
#include <stdlib.h>
int main()
{
      int size;
      int *Array;

      printf("Enter the size of the array: ");
      scanf("%d", &size);

      Array = (int *)malloc(size * sizeof(int));

      printf("Enter %d elements\n", size);

      for (int i = 0; i < size; i++)
      {
            scanf("%d", &Array[i]);
      }

      printf("Elements in the array are\n");

      for (int i = 0; i < size; i++)
      {
            printf("%d ", Array[i]);
      }
      printf("\n");


      if (Array == NULL)
      {
            printf("Memory allocation failed\n");
            return 1;
      }

      free(Array);
      return 0;
}