#include <omp.h>
#include <stdio.h>
#define N 10
#define CHUNKSIZE 100

void main(int argc, char *argv[])
{
    int i, chunk;
    float a[N], b[N], c[N];
    for (i = 0; i < N; i++)
        a[i] = b[i] = i * 1.0;
    chunk = CHUNKSIZE;

#pragma omp parallel shared(a, b, c, chunk) private(i)
    {
#pragma omp for schedule(dynamic, chunk) nowait
        for (i = 0; i < N; i++)
            c[i] = a[i] + b[i];
    }
    printf("A\t\t\t+\t\tB\t\t\t=\t\tC\n");
    for (i = 0; i < N; i++)
        printf("%f\t\t+\t\t%f\t\t=\t\t%f\n", a[i], b[i], c[i]);
}