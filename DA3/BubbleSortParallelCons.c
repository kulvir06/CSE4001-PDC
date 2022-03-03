#include<omp.h>
#include<stdio.h>
int main(int argc, char *argv[]){
    int SIZE = 10;
    int A[SIZE];
    printf("Before Sorting\n");
    for(int i=0;i<SIZE;i++){
        A[i] = rand()%SIZE;
        printf(" %d",A[i]);
    }
    printf("\nAfter Sorting\n");
    int N = SIZE;
    int i=0, j=0;
    int first;
    double start, end;
    start = omp_get_wtime();
    for(i=0;i<N-1;i++){
        first = i%2;
        #pragma omp parallel for default(none), shared(A,first,N)
        for(j=first; j<N-1;j++){
            if(A[j]>A[j+1]){
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
    end = omp_get_wtime();
    for(i=0;i<N;i++)
	{
		printf(" %d",A[i]);
	}

    printf("\n-------------------------\n Time Parallel= %f\n",(end-start));

}