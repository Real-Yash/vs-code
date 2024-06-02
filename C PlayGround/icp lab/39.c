#include <stdio.h>

int main() {
    char array_of_strings[3][20] = {"Hello", "World", "Bing"};
    char *pointer_to_string = array_of_strings[1];

    printf("Printing the 2D array:\n");
    for(int i = 0; i < 3; i++) {
        printf("%s\n", array_of_strings[i]);
    }

    printf("\nPrinting the string using the pointer:\n");
    printf("%s\n", pointer_to_string);

    return 0;
}
