#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

long repeatedString(char* s, long n);

int main()
{
    char s[10];
    long n;
    scanf("%s%ld", s, &n);
    long a = repeatedString(s, n);
    printf("%ld", a);
    return 0;
}

long repeatedString(char* s, long n) {
    long count = 0, a = 0, rep = 0, rem = 0, sum = 0;
    int i;
    while ( *(s + count) != '\0')
    {
        count++;
    }
    rep = n / count;
    rem = n - (rep * count);
    for( i = 0; i < count; i++)
    {
        if(*(s + i) == 'a')
        {
            a++;
        }
    }
    sum = a * rep;
    for ( i = 0; i < rem; i++)
    {
        if(*(s + i) == 'a')
        {
            sum++;
        }
    }
    return sum;
}
