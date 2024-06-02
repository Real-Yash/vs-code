#include <stdio.h>

int stringLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int main() {
    char str[] = "Hello, world!";
    printf("The length of the string is: %d\n", stringLength(str));
    return 0;
}
