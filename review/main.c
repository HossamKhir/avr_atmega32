#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    // Declare variables
    long i = 0, j, k = 0;
    int T;
    scanf("%d", &T);
    char S[10000 * T], S0[10000];
    int l = 0;

    //Read inputs
    for (j = 0; j < T; j++)
    {
        scanf(" %[^\n]s", (S + i));
        while (S[i] != '\0')
        {
            i++;
        }
        i++;
    }

    // Print output
    i = 0;
    for (j = 0; j < T; j++)
    {
        k = 0;
        l = 0;
        while(S[i] != '\0')
        {
            if ( !(l % 2) )
            {
              printf("%c", S[i]);
              l++;
            }
            else
            {
                S0[k] = S[i];
                k++;
                l++;
            }
            i++;
        }
        i++;
        printf(" %s\n", S0);
        memset(S0, 0, strlen(S0));
    }
    return 0;
}
