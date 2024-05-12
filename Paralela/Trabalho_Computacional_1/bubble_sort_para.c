#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100*1000

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void initializeArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % n;
    }
}

int main (int argc, char *argv[]) {
    clock_t start_time = clock();
	int array[N];
	initializeArray(array, N);
    printf("Array Desordenado: \n");
    for(int i = 0; i < N;i++)
	{
		printf("%d ",array[i]);
	}
	int first;
	double start, end;
	for(int i = 0; i < N-1; i++)
	{
		first = i % 2; 
		#pragma omp parallel for default(none), shared(A,first,N)
		for(int j = first; j < N-1; j += 1 )
		{
			if( array[j] > array[j+1] )
			{
				swap( &array[j], &array[j+1] );
			}
		}
	}
    printf("\nArray Ordenado: \n");
	for(int i = 0; i < N;i++)
	{
		printf("%d ",array[i]);
	}
    clock_t finish = clock();
	double time_spent = (double)(finish - start_time)/CLOCKS_PER_SEC;
	printf("\nTime de execucao: %f\n", time_spent);
}