#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <mpi.h>

char * sprint_intarray(int *nums, int n) {
    char *strintarray = malloc(sizeof(char)*n*2+2);
    int j = 0;
    for (int i=0;i<n;i++) {        
        j+=sprintf(&strintarray[j], "%d,", nums[i]);
    }
    return(strintarray);
}

int main(int argc, char** argv) {
    int pid, p;
    time_t t;
     
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);

    int n = atoi(argv[1]);
    int *rnums = malloc(sizeof(int)*n+2);

    int localmax=0; 
    srand((pid+1)*(unsigned) time(&t));
    for(int i=0;i<n;i++) {
        rnums[i] = rand() % 100;
        if (rnums[i] > localmax) 
            localmax = rnums[i];
    }
    printf("Node: [%d] - Local max of [%s] = %d\n", pid, sprint_intarray(rnums, n), localmax);

    int globalmax = 0;
    MPI_Reduce(&localmax, &globalmax, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
    
    if (pid==0) {
        printf("Global Max = %d\n", globalmax);
    }
    
    free(rnums);
    MPI_Finalize();
    return 0;
}