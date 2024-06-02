// Include necessary header files:
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to calculate the square of a number:
int square(int num)
{
      int square_value = num * num;
      return square_value;
}

int ten(int len)
{
      for (int i = 0; i < len; i++)
      {
            int len = len * 10;
      }
      return len;
}

// Function to extract the center digits from the generated result:
int extractCenterDigits(int num, int len)
{
      int center = (num / len) % 100;
      return center;
}

// Function to generate the hashed value using the given key value:
int midSquareHash(int key, int len)
{
      int square_value = square(key);
      int len1 = ten(len);
      int center = extractCenterDigits(square_value, len1);
      return center;
}

// Main function to test the mid square hashing:
int main()
{
      int key, len;
      printf("enter a number:\n");
      scanf("%d", &key);
      printf("enter a number of digite:\n");
      scanf("%d", &len);

      int hashed_value = midSquareHash(key, len);
      printf("Hashed value: %d\n", hashed_value);
      return 0;
}