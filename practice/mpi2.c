#include <mpi.h>
#include <stdio.h>
int main(int argc, char *argv[]){
    MPI_Init(NULL, NULL);
    //get number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    //get rank of process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    //get processor name
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);
    printf("processor %s \n rank %d \n processor %d", processor_name, world_rank, world_size);
    MPI_Finalize();
}