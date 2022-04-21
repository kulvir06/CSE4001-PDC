#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main(){
    int chunk = 100;
    int mat[10][10];
    int v[10];
    int i,j;
    int k=1;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++)
        mat[i][j] = k++;
    }
    int res[10];
    k=1;
    for(i=0;i<10;i++)
    v[i]=k++;
    #pragma omp parallel shared(mat, v, res, chunk) private(i,j)
    {
        #pragma omp for schedule(static, chunk)
        for(i=0;i<10;i++)
        {
            int temp = 0;
            for(j=0;j<10;j++){
                temp += v[j]*mat[i][j];
            }
            res[i] = temp;
        }
    }
    for(i = 0;i<10;i++)
    printf("%d\n",res[i]);

}