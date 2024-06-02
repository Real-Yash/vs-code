#include <stdio.h>

// User-defined function to copy a string
void copyString(char str1[], char str2[]) {
    int i = 0;

    while(str1[i] != '\0') {
        str2[i] = str1[i];
        i++;
    }

    str2[i] = '\0'; // Null terminate str2
}

int main() {
    char str1[100], str2[100];

    printf("Enter a string: ");
    gets(str1);

    copyString(str1, str2);

    printf("Copied string: %s\n", str2);

    return 0;
}
