#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <omp.h>
#define SIZE 10

int main(int argc, char *argv[])
{

    float u[SIZE], v[SIZE], result;
    int i, j, tid, chunk;

    chunk = 5;
    result = 0.0;
    for (i = 0; i < SIZE; i++)
    {
        u[i] = 1.0 * (i + 1);
        v[i] = 2.0 * (i + 1);
    }
    printf("\n values of u vector and v vector:\n");

    for (i = 0; i < SIZE; i++)
    {
        printf(" u[%d]= %.1f\t v[%d]= %.1f\n", i, u[i], i, v[i]);
    }
#pragma omp parallel for default(shared) private(i) schedule(static, chunk) reduction(+: result)

    for (i = 0; i < SIZE; i++)
    {
        result = result += u[i] * v[i];
    }
    printf("\n dot product is %f\n", result);
}
