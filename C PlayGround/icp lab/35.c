#include <stdio.h>

int main() {
    char array_of_strings[3][20] = {"Hello", "World", "Bing"};

    for(int i = 0; i < 3; i++) {
        printf("%s\n", array_of_strings[i]);
    }

    return 0;
}
