// -fopenmp -lpthread
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

int main()
{
	clock_t start = clock();
	setlocale(LC_ALL, "Portuguese");
	for (int rodada = 1; rodada <= 100000 - 1; rodada *= 10)
	{
		int array[N * rodada];
		for (int i = 0; i < N; i++)
		{
			array[i] = rand() % N;
		}
		#pragma omp parallel
		{
			int nthreads = omp_get_num_threads();
			int chunck = N / nthreads;
			for (int i = 0; i < N; i++)
			{
				int first = i % nthreads;
				#pragma omp parallel for schedule(static, chunck)
				for (int j = first; j < N - 1; j += nthreads)
				{
					if (array[j] > array[j + 1])
					{
						#pragma omp critical
						{
							swap(&array[j], &array[j + 1]);
						}
					}
				}
			}
		}
		clock_t finish = clock();
		double time_spent = (double)(finish - start) / CLOCKS_PER_SEC;
		printf("N = %i Tempo de execução: %.8lf\n", rodada * N, time_spent);
	}

	return 0;
}
