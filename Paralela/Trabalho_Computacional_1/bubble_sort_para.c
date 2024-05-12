#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define N 10

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


int main () {
	setlocale(LC_ALL, "Portuguese");

    for (int rodada = 1; rodada <= 100000; rodada*=10)
	{
		clock_t start = clock();

		int array[N*rodada];
		for (int i = 0; i < N; i++)
		{
			array[i] = rand() % N;
		}

		#pragma omp parallel for
		for(int i = 0; i < N-1; i++)
		{
			for(int j = 0; j < N-i-1; j++)
			{
				if(array[j] > array[j+1])
				{
					#pragma omp critical
					{
						swap(&array[j], &array[j+1]);
					}
				}
			}
		}
		clock_t finish = clock();
		double time_spent = (double)(finish - start)/CLOCKS_PER_SEC;
		printf("Rodada %i N = %i Tempo de execução: %f\n", rodada, rodada*N, time_spent);
	}
    return 0;
}
