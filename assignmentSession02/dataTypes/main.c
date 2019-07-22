#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i = 4;
    double d = 4.0;
    char s[] = "Sentence is: ";


    int i2;
    double d2;
    char s2[100];

    scanf("%d%lf", &i2, &d2);
    scanf(" %[^\n]s", s2);

    printf("%d\n", i + i2);

    printf("%.1f\n", d + d2);

    printf("%s%s", s, s2);

    return 0;
}
