//KULVIR SINGH
//19BCE2074
#include <omp.h>
#include <stdio.h>

void main(int argc, char *argv[])
{
    int i, n, chunk = 5;
    float a[100], b[100], result;
    n = 20;
    result = 0.0;
    for (i = 0; i < n; i++)
    {
        a[i] = (i+1) * 1.0;
        b[i] = (i+1) * 2.0;
    }
#pragma omp parallel for default(shared) private(i) schedule(static, chunk) reduction(-: result)
    for (i = 0; i < n; i++)
    {
        result = result - b[i] - a[i];
        printf(" result is %f\n", result);
    }

    printf("Final result is %f\n", result);
}