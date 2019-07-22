#include <stdio.h>
#include <stdlib.h>

int number_of_digits(int n);
int max(int n[], int m);
void prime(int n, int m);
int pow_recurr(int n, int m);
void swap3(int n, int m);
int rev_num(int n);

int main()
{
    int n = 0, m = 0;
    printf("insert the digit:\t");
    scanf("%d", &n);
    printf("%d\n", number_of_digits(n));

    printf("enter number of array elements:\t");
    scanf("%d", &n);
    printf("insert array elements:\n");
    int narr[n];
    for(m = 0; m < n; m++)
    {
        scanf("%d", &narr[m]);
    }
    printf("max number is %d\n", max(narr, n));

    printf("insert starting and ending of period:\n");
    scanf("%d%d", &n, &m);
    prime(n,m);

    printf("\ninsert the number and the exponenet:\n");
    scanf("%d%d", &n, &m);
    printf("%d^%d = %d\n", n, m, pow_recurr(n, m));

    printf("insert numbers to swap:\n");
    scanf("%d%d", &n, &m);
    swap3(n, m);

    printf("insert number to reverse:\t");
    scanf("%d", &n);
    printf("%d", rev_num(n));

    return 0;
}

int number_of_digits(int n)
{
    int sum = 0;
    while (n/=10)
    {
        sum++;
    }
    return ++sum;
}

int max(int n[], int m)
{
    int j = 0, max = n[0];
    for(j = 0; j < m; j++)
    {
        max = (n[j]>max)? n[j]:max;
    }
    return max;
}

void prime(int n, int m)
{
    int i = 0, j = 0, k = 0;
    for (i = n; i <= m; i++)
    {
        k = 0;
        for(j = 2; j < i; j++)
        {
            if(!(i%j))
            {
                k = 0;
                break;
            }
            else
            {
                k = 1;
            }
        }
        if(k)
        {
            printf("%d\t", i);
        }
    }
}

int pow_recurr(int n, int m)
{
    if(m > 1)
    {
        return n * pow_recurr(n, m-1);
    }
    else
    {
        return n;
    }
}

void swap3(int n, int m)
{
    printf("before swap: n = %d, m = %d\n", n, m);
    int temp = 0;
    temp = n;
    n = m;
    m = temp;
    printf("after 1st swap: n = %d, m = %d\n", n, m);
    n = n + m;
    m = n - m;
    n = n - m;
    printf("after 2nd swap: n = %d, m = %d\n", n, m);
    n = n ^ m;
    m = n ^ m;
    n = n ^ m;
    printf("after 3rd swap: n = %d, m = %d\n", n, m);

}

int rev_num(int n)
{
    int i = 0, j = 0, ex = 1;
    int *a = NULL;
    a = malloc(sizeof(int));
    do {
        a[i++] = n % 10;
        a = realloc(a, sizeof(int));
    } while(n/=10);
    for (j = (i-1); j >= 0; j--)
    {
        n += ex * a[j];
        ex *=10;
    }
    free(a);
    return n;
}
