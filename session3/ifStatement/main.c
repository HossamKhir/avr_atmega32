#include <stdio.h>
#include <stdlib.h>

void main()
{
    printf("Insert a number:\t");
    int c;
    scanf("%d", &c);
    if (c > 10)
    {
        printf("value greater than 10");
    }
    else if (c < 10)
    {
        printf("value less than 10");
    }
    else
    {
        printf("value equals 10");
    }
}
