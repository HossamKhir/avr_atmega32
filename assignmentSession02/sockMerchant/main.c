#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>


int sockMerchant(int n, int ar_count, int* ar);
int main()
{
    int numSock = 0, arrColour[100], pairs = 0;
    printf("Insert number of socks:\t");
    scanf("%d", &numSock);
    printf("\nInsert the colour order:\t");
    for (int i = 0; i < numSock; i++)
    {
        scanf("%d", &arrColour[i]);
    }
    pairs = sockMerchant(numSock, numSock, arrColour);
    printf("Number of pairs is:\t%d", pairs);
    return 0;
}

int sockMerchant(int n, int ar_count, int* ar) {
    int colours[ar_count], i = 0, j = 0;
    bool flag = 0;
    int nColours = 1, hits = 0;
    colours[0] = *ar;
    for ( i = 0; i < ar_count; i++)
    {
        for ( j = 0; j < nColours; j++)
        {
            if ( *(ar + i) == colours[j])
            {
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
        }
        if (flag == 1)
        {
            colours[nColours] = *(ar + i);
            nColours++;
        }
    }

    for ( i = 0; i < nColours; i++) {
        for ( j = 0; j < ar_count; j++){
          if (colours[i] == *(ar + j))
          {
              hits++;
          }
        }
        if ( (hits % 2) != 0)
        {
            hits -= (hits % 2);
        }
    }
    return (hits / 2) - (hits % 2);
}
