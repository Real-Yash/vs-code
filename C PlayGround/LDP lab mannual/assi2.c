#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 100
// Structure to represent a record in the database
struct Record {
      char name[50];
      int age;
      float salary;
};

// Function to accept information for a record
void acceptRecord(struct Record *record) {
      printf("Enter name: ");
      scanf("%s", record->name);

      printf("Enter age: ");  
      scanf("%d", &record->age);
      
      printf("Enter salary: ");
      scanf("%f", &record->salary);
}

// Function to display information for a record
void displayRecord(const struct Record *record) {
      printf("Name: %s\n", record->name);
      printf("Age: %d\n", record->age);
      printf("Salary: %.2f\n", record->salary);
}

int main() {
      int numRecords;
      printf("Enter the number of records: ");
      scanf("%d", &numRecords);
      
      // Dynamic memory allocation for the array of structures
      struct Record *database = (struct Record *)malloc(numRecords *
      sizeof(struct Record));

      if (database == NULL) {
       printf("Memory allocation failed. Exiting.\n");
       return 1;
      }

      // Accept information for each record
      for (int i = 0; i < numRecords; i++) {
       printf("\nEnater details for record %d:\n", i + 1);
       acceptRecord(&database[i]);
      }

      // Display information for each record
      printf("\nDatabase Contents:\n");
      for (int i = 0; i < numRecords; i++) {
       printf("\nRecord %d:\n", i + 1);
       displayRecord(&database[i]);
      }

  // Free dynamically allocated memory
 free(database);
 return 0;
}