#include <stdio.h>

// User-defined function to find the length of a string
int stringLength(char str[]) {
    int i = 0;

    while(str[i] != '\0') {
        i++;
    }

    return i;
}

int main() {
    char str[100];

    printf("Enter a string: ");
    gets(str);

    printf("Length of the string: %d\n", stringLength(str));

    return 0;
}
