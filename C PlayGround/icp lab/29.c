#include <stdio.h>
#include <string.h>

// User-defined function to concatenate two strings
void concatenate(char str1[], char str2[]) {
    strcat(str1, str2); // Concatenates str2 onto the end of str1
}

int main() {
    char str1[100], str2[100];

    printf("Enter the first string: ");
    gets(str1);

    printf("Enter the second string: ");
    gets(str2);

    concatenate(str1, str2);

    printf("Resultant string: %s\n", str1);

    return 0;
}
