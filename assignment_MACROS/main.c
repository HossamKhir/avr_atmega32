#include <stdio.h>
#include <stdlib.h>

#define MAX(A,B) (A>B)? A:B
#define MIN(C,D) ((C)<(D) ? (C):(D))

int main()
{
    int i = 10, j = 12, k;
    k = MAX(i,j);
    printf("%d\n", k);
    // o/p is 12 as 12>10
    k = MAX(j,i) * 2;
    printf("%d\n", k);
    /* o/p is 12 as after preprocessing it becomes: (j>i)? j:i*2;
    meaning that i is the variable that is multiplied by 2*/
    k = MIN(i,j) * 3;
    printf("%d\n", k);
    /* o/p is 30 as after preprocessing it becomes: (((i)<(j))? (i):(j))*3;
    meaning that whichever comes out of this comparison is to be multiplied by 3*/
    k = MIN(i--,j--);
    /* o/p is 9 as after preprocessing it becomes ((i--)<(j--)? (i--):(j--));
    which means that both variables were decremented twice, but there is a trick*/
    printf("%d\n", k);
    return 0;
}
