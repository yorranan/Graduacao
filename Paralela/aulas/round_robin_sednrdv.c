#include <mpi.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void round_robin(int rank, int procs)
{
	long int rand_mine, rand_prev;
	int rank_next = (rank + 1) % procs;
	int rank_prev = rank == 0 ? procs - 1 : rank - 1;
	MPI_Status status;
	srandom(time(NULL) + rank);
	rand_mine = random() / (RAND_MAX / 100);
	printf("%d: random is %ld\n", rank, rand_mine);
	printf("%d: sending %ld to %d\n", rank, rand_mine, rank_next);
	MPI_Barrier(MPI_COMM_WORLD);
	MPI_Sendrecv((void *)&rand_mine, 1, MPI_LONG, 
		rank_next, 1,
		(void *)&rand_prev, 1, MPI_LONG, 
		rank_prev, 1,
		MPI_COMM_WORLD , &status);
	printf("%d: receiving from %ld\n", rank, rand_prev);
	printf("%d: Had %ld, %d had %ld\n", rank, rand_mine, rank_prev, rand_prev);

}

int main(int argc, char **argv)
{

	// int num_procs;
	// int rank;
	int world_size;
	int world_rank;

	MPI_Init(&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

	printf("%d Hello (p=%d)\n", world_rank, world_size);
	round_robin(world_rank, world_size);
	printf("End\n");
	// Finalize the MPI environment.
	MPI_Finalize();

	return 0;
}