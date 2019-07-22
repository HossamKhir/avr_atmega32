#include <stdio.h>
#include <stdlib.h>

void* q038(void* a, void* b, int r0, int c0r1, int c1);

int main()
{
    float a[2][2] = {{1,0},{0,1}}, b[2][2] = {{1,2},{3,4}};
    void* p = &b;
    printf("%f\n", *(float*)(p+0)+1);
    return 0;
}

void* q038(void* a, void* b, int r0, int c0r1, int c1) //multiply 2 matrices
{
    float* a0 = (float*)a;
    float* b0 = (float*)b;
    float c[r0][c1];
    int x = 0, y = 0, z = 0;
    for (x = 0; x < r0; x++)
    {
        for (y = 0; y < c1; y++)
        {
            for (z = 0; z < c0r1; z++)
            {
                c[x][y] += *((a0+x)+z) * *((b0+z)+y);
            }
        }
    }
    for(x = 0; x < r0; x++)
    {
        for(y = 0; y < c1; y++)
        {
            printf("%f ", c[x][y]);
        }
        printf("\n");
    }
    return &c;
}
