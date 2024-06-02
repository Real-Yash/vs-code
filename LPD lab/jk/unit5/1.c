#include <stdio.h>

#define TABLE_SIZE 10

int hash(int key) {
      return key % TABLE_SIZE;
}

int main() {
      int key;
      printf("Enter a key: ");
      scanf("%d", &key);

      int index = hash(key);
      printf("Hash value: %d\n", index);

      return 0;
}