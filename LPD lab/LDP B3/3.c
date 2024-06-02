#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Record {
      int id;
      char name[50];
      int age;
      int salary;
};

void acceptData(struct Record *database, int size) {
      for (int i = 0; i < size; i++) {
            printf("Enter details for record %d:\n", i + 1);
            printf("ID: ");
            scanf("%d", &database[i].id);
            printf("Name: ");
            scanf("%s", database[i].name);
            printf("Age: ");
            scanf("%d", &database[i].age);
            printf("salaray: ");
            scanf("%d", &database[i].salary);

      }
}

void displayData(struct Record *database, int size) {
      printf("Database records:\n");
      for (int i = 0; i < size; i++) {
            printf("Record %d:\n", i + 1);
            printf("ID: %d\n", database[i].id);
            printf("Name: %s\n", database[i].name);
            printf("Age: %d\n", database[i].age);
            printf("Age: %d\n", database[i].salary);

      }
}

int main() {
      int size;
      struct Record *database;

      printf("Enter the number of records: ");
      scanf("%d", &size);

      // Dynamically allocate memory for the database array
      database = (struct Record *)malloc(size * sizeof(struct Record));

      if (database == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
      }

      acceptData(database, size);
      displayData(database, size);

      // Free the dynamically allocated memory
      free(database);

      return 0;
}
