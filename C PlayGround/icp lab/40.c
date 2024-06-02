#include <stdio.h>

int main() {
    char str[] = "Hello, World!";
    int len = sizeof(str) / sizeof(char);

    printf("Printing the string using array notation:\n");
    for(int i = 0; i < len; i++) {
        printf("%c", str[i]);
    }

    return 0;
}
