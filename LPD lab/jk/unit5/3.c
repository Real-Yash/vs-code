#include <stdio.h>

#define TABLE_SIZE 10

int hash(int key) {
      int square = key * key;
      int hash_value = (square / 100) % TABLE_SIZE;
      return hash_value;
}

int main() {
      int keys[] = {12, 34, 56, 78, 90, 23, 45, 67, 89, 10};
      int i;

      int hash_table[TABLE_SIZE] = {0};

      for (i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
            int key = keys[i];
            int index = hash(key);
            hash_table[index] = key;
      }

      printf("Hash Table:\n");
      for (i = 0; i < TABLE_SIZE; i++) {
            printf("%d: %d\n", i, hash_table[i]);
      }

      return 0;
}