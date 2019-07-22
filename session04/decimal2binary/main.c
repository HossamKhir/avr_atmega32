#include <stdio.h>
#include <stdlib.h>

void D2B (int num);

int main()
{
    int d;
    D2B(5);
    printf("\n");
    D2B(255);
    printf("\n");
    scanf("%d", &d);
    D2B(d);
    return 0;
}

/*
    using masking:
    int mask = 0x80000000;
    for(i = 0; i <= 31; i++)
    {
        ((num << 1) & ( mask )) ? printf("1"):printf("0");
    }
*/

void D2B (int num)
{
    int mask = 0x80000000, i;
    for(i = 0; i <= 31; i++)
    {
        ((num << i) & ( mask )) ? printf("1"):printf("0");
    }
}
