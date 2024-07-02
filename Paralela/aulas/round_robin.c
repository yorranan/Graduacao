#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <mpi.h>

void round_robin(int rank, int procs){

	long int rand_mine, rand_prev;
	int rank_next = (rank + 1) % procs;
	int rank_prev = rank == 0 ? procs - 1 : rank - 1;
	MPI_Status status;

	srand(time(NULL));
	rand_mine = rand() / (RAND_MAX / 100);
	printf("%d: random is %ld\n", rank, rand_mine);

	if (rank % 2 == 0){
		printf("%d: sending %ld to %d\n"rank, rand_mine,rank_next);
		MPI_Send((void *)&rand_mine, 1, MPI_LONG, rank_next, 1, MPI_COMM_WORLD);
		MPI_Barrier(MPI_COMM_WORLD);
		MPI_Recv((void *)&rand_prev, 1, MPI_LONG, rank_prev, 1, MPI_COMM_WORLD, &status);
		printf("%d: receiving from %d\n"rank, rand_prev);
	} else {
		printf("%d: receiving from %d\n"rank, rand_prev);
		MPI_Recv((void *)&rand_prev, 1, MPI_LONG, rank_prev, 1, MPI_COMM_WORLD, &status);
		MPI_Barrier(MPI_COMM_WORLD);
		MPI_Send((void *)&rand_mine, 1, MPI_LONG, rank_next, 1, MPI_COMM_WORLD);
		printf("%d: sending %ld to %d\n"rank, rand_mine,rank_next);
	}
	printf("%d: Had %ld, %d had %ld\n", rank, rand_mine, rank_prev, rand_prev)
}


int main(int argc, char** argv) {

	int world_size;
	int world_rank;

    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    printf("%d Hello (p=%d)\n", world_rank, world_size);
    round_robin(world_rank, world_size)
    printf("End")
    // Finalize the MPI environment.
    MPI_Finalize();

    return 0;
}