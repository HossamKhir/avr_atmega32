#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N = 0;
    scanf("%d", &N);
    if (((N % 2) == 0) && (((N >= 2) && (N <= 5)) || (N > 20))) {
      printf("Not Weird");
    }
    else
    {
        printf("Weird");
    }
    return 0;
}
