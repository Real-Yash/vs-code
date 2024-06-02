#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// Function to calculate the folding hash value
int foldingHash(int key) {
      int sum = 0;
      while (key > 0) {
            sum += key % 100; // Add the last two digits of the key
            key /= 100; // Remove the last two digits of the key
      }
      return sum % TABLE_SIZE; // Return the hash value within the table size
}

int main() {
      int keys[] = {12345, 67890, 54321, 98765, 13579};
      int numKeys = sizeof(keys) / sizeof(keys[0]);

      // Create an array to store the hash table
      int hashTable[TABLE_SIZE] = {0};

      // Insert keys into the hash table
      for (int i = 0; i < numKeys; i++) {
            int hashValue = foldingHash(keys[i]);
            hashTable[hashValue] = keys[i];
      }

      // Print the hash table
      printf("Hash Table:\n");
      for (int i = 0; i < TABLE_SIZE; i++) {
            printf("%d: %d\n", i, hashTable[i]);
      }

      return 0;
}