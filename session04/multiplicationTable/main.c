#include <stdio.h>
#include <stdlib.h>

void mtFOR();
void mtWHILE();
void mtDO();

int i , j;

int main()
{
    mtFOR();
    mtWHILE();
    mtDO();
    return 0;
}

void mtFOR()
{
    for ( i = 1; i <= 12; i++)
    {
        for ( j = 1; j <= 12; j++)
        {
            printf("%d*%d=%d\n", i, j, i *j);
        }
        printf("\n");
    }
}

void mtWHILE()
{
    i = 1;
    while (i <= 12)
    {
        j = 1;
        while (j <= 12)
        {
            printf("%d*%d=%d\n", i, j, i * j);
            j++;
        }
        printf("\n");
        i++;
    }
}

void mtDO()
{
    i = 1;

    do
    {
        j = 1;
        do
        {
            printf("%d*%d=%d\n", i, j, i * j);
            j++;
        } while (j < 12);
        printf("\n");
        i++;
    } while (i < 12);
}
