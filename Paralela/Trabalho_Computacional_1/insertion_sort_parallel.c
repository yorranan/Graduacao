// -fopenmp -lpthread
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define N 10

void insertionSort(int vetorr[], int n)
{
	int i, indice, j;
	for (i = 1; i < n; i++)
	{
		indice = vetorr[i];
		j = i - 1;

		while (j >= 0 && vetorr[j] > indice)
		{
			vetorr[j + 1] = vetorr[j];
			j = j - 1;
		}
		vetorr[j + 1] = indice;
	}
}

int main()
{
	clock_t start = clock();
	setlocale(LC_ALL, "Portuguese");
	for (int rodada = 1; rodada <= 1000000 - 1; rodada *= 10)
	{
		int vetor[N * rodada];
		for (int i = 0; i < N; i++)
		{
			vetor[i] = rand() % N;
		}
		#pragma omp parallel
		{
			int nthreads = omp_get_num_threads();
			int chunck = N / nthreads;
			for (int i = 0; i < N; i++)
			{
				int first = i % nthreads;
				#pragma omp for schedule(static, chunck)
				for (int j = first; j < N - 1; j += nthreads)
				{
					insertionSort(vetor, N);
				}
			}
		}
		clock_t finish = clock();
		double time_spent = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("Rodada %i N = %i Tempo de execução: %.8lf\n", rodada, rodada * N, time_spent);
	}

	return 0;
}
