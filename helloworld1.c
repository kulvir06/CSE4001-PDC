//KULVIR SINGH
//19BCE2074
#include <omp.h>
#include <stdio.h>

int main(int *argc, char *argv[])
{
    printf("19BCE2074\nKulvir Singh\n");
    int numt;
#pragma omp parallel default(shared)
    {
        int tid = omp_get_thread_num();
        if (tid == 0)
            numt = omp_get_num_threads();
        printf("Hello World from thread %d of %d \n", tid, numt);
    }
}