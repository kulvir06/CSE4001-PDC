#include <omp.h>
#include <stdio.h>
#define N 20
void main(int arc, char *arv[])
{
    int i;
    float a[N], b[N], c[N], d[N];
    for (i = 0; i < N; i++)
    {
        a[i] = i * 1.5;
        printf("a[%d] = %f   ", i, a[i]);
        b[i] = i * 22.35;
        printf("b[%d] = %f \n", i, b[i]);
    }

#pragma omp parallel shared(a, b, c, d) private(i)
    {
#pragma omp sections nowait
        {
#pragma omp section
            for (i = 0; i < N; i++)
            {
                c[i] = a[i] + b[i];
                printf("c[%d] = %f  \n", i, c[i]);
            }

#pragma omp section
            for (i = 0; i < N; i++)
            {
                d[i] = a[i] * b[i];
                printf("d[%d] = %f \n", i, d[i]);
            }
        }
    }
}
