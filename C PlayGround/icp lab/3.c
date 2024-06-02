#include <stdio.h>

int main() {
    char ch;

    printf("Enter a character: ");
    scanf("%c", &ch);

    // print ASCII value
    printf("ASCII value of %c = %d", ch, ch);

    return 0;
}
