#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int countingValleys(int n, char* s);

int main()
{
    int n;
    char s[100];
    scanf("%d %[^\n]s", &n, s);
    int v = countingValleys(n, s);
    printf("%d\n", v);
    return 0;
}

int countingValleys(int n, char* s) {
    int sum = 0, nValley = 0, i = 0;
    for ( i = 0; i < n; i++)
    {
        if ( *(s + i) == 'D')
        {
            sum--;
        }
        else
        {
            sum++;
        }
        if ( sum == 0 && *(s + i) == 'U')
        {
            nValley++;
        }
    }
    return nValley;
}
