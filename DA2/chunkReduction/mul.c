// KULVIR SINGH
// 19BCE2074
#include <omp.h>
#include <stdio.h>

void main(int argc, char *argv[])
{
    int chunk = 5;
    int ARR_SIZE = 10;
    int a[10];
    int i = 0;
    int p = 1;
    for (i = 0; i < ARR_SIZE; i++)
    {
        a[i] = i+1;
    }
#pragma omp parallel for default(shared) private(i) schedule(static, chunk) reduction(*: p)
    for (i = 0; i < ARR_SIZE; i++)
    {
        p *= a[i];
        printf(" result is %d\n", p);
    }
    printf("Final result is %d\n", p);
}