//KULVIR SINGH
//19BCE2074
#include <omp.h>
#include <stdio.h>

void main(int argc, char const *argv[])
{
    int i, sum = 0;
    int ARR_SIZE = 10000;
    int a[ARR_SIZE];
    double t1, t2;
    t1 = omp_get_wtime();
#pragma omp parallel for default(shared) reduction(+: sum)
    for (i = 0; i < ARR_SIZE; i++)
        sum += a[i];
    t2 = omp_get_wtime();
    printf("Sum = %d\n", sum);
    printf("Time = %f\n", (t2 - t1));
}
