#include <stdio.h>
#include <stdlib.h>
int main()
{
omp_set_num_threads(5);
#pragma omp parallel
{
printf("Hello World from thread = %d of %d\n", omp_get_thread_num(),
omp_get_num_threads());
}
return 0;
}