#include <stdio.h>
#include <stdlib.h>

int main() {
      char name[100];
      
      printf("Enter your name: ");
      fgets(name, sizeof(name), stdin);
      
      printf("Your name is: %s", name);
      printf("Memory size allocated for name: %lu bytes\n", sizeof(name));
      
      return 0;
}