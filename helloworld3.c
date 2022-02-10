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
        int j, tid;
#pragma omp single nowait
        {
            for (j = 0; j < 100000; j++)
                numt = omp_get_num_threads();
        }
        tid = omp_get_thread_num();
        printf("Hello World from thread %d of %d \n", tid, numt);
    }
}