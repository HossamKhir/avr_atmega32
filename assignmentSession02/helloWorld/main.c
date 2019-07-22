#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char input_string[105];

    scanf("%[^\n]s", &input_string);

    printf("Hello, World.\n");

    printf("%s", input_string);

    return 0;
}
