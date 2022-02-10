//KULVIR SINGH
//19BCE2074
#include<stdio.h>
#include<omp.h>

void main() {
        printf("19BCE2074 \nKULVIR SINGH\n");
	int i, tid, numt, sum=0;
	double t1, t2;
	int ARR_SIZE=10000;
	int a[ARR_SIZE];
	
	t1 = omp_get_wtime();
	#pragma omp parallel default( shared ) private( i, tid ) 
	{
		int from, to;
		tid = omp_get_thread_num();
		numt = omp_get_num_threads();
		from = ( ARR_SIZE/numt )*tid;
		to = ( ARR_SIZE/numt )*( tid+1 )-1;
		if( tid == numt-1 ) to = ARR_SIZE-1;
		for(i=from; i<=to; i++)
		#pragma omp critical
		sum+= a[i];
		t2=omp_get_wtime();
	}
	printf("Sum  = %d \n",sum);
	printf("Time = %g \n",t2-t1);
	
	
}
