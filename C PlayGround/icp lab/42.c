#include <stdio.h>
#include <string.h>

void concatenateStrings(char *str1, char *str2, char *result) {
    int i = 0, j = 0;

    // Copy str1 to result
    while (str1[i] != '\0') {
        result[i] = str1[i];
        i++;
    }

    // Copy str2 to result
    while (str2[j] != '\0') {
        result[i + j] = str2[j];
        j++;
    }

    result[i + j] = '\0';  // Null terminate the result string
}

int main() {
    char str1[100], str2[100], result[200];

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strlen(str1) - 1] = '\0';  // Remove newline character

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strlen(str2) - 1] = '\0';  // Remove newline character

    concatenateStrings(str1, str2, result);

    printf("Concatenated string: %s\n", result);

    return 0;
}
