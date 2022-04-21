#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int main(){
    int arr[100];
    omp_set_num_threads(4);
    for(int i=1;i<=100;i++)
    arr[i-1]=i;
    int tid, i, numt, sum=0;
    double t1 = omp_get_wtime();
    #pragma omp parallel default(shared) private(i,tid)
    {
        int from, to, psum=0;
        tid = omp_get_thread_num();
        numt = omp_get_num_threads();
        from = (100/numt)*tid;
        to = (100/numt)*(tid+1)-1;
        if(tid==numt-1)
        to = 100-1;
        printf("%d of %d from = %d to = %d\n", tid,numt,from,to);
        for(i=from;i<to;i++)
        psum+=arr[i];
        #pragma omp critical
        sum +=psum;
    }    
    double t2 = omp_get_wtime();
    printf("sum = %d and t = %f\n",sum, t2-t1);
}