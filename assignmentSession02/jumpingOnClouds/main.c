#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int jumpingOnClouds(int c_count, int* c);

int main()
{
    int j, i;
    scanf("%d", &j);
    int C[j];
    for (i = 0; i < j; i++)
    {
        scanf("%d", (C + i));
    }
    int mJumb = jumpingOnClouds(j, C);
    printf("%d", mJumb);
    return 0;
}

int jumpingOnClouds(int c_count, int* c) {
    int curPos = 0, nJump = 0;
    while( (curPos + 2) < c_count)
    {
        if ( *(c + curPos + 2) == 0)
        {
            nJump++;
            curPos += 2;
        }
        else
        {
            nJump += 2;
            curPos += 3;
        }
    }
    if ((c_count - curPos) == 2) {
      nJump++;
    }
    return nJump;
}
