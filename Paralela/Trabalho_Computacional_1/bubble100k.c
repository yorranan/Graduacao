// -fopenmp -lpthread
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main()
{
    clock_t start = clock();
    int n = 100000;
    setlocale(LC_ALL, "Portuguese");
    int array[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % 1000;
    }
#pragma omp parallel
    printf("n threads: %i\n",  omp_get_num_threads());
    {
        int nthreads = omp_get_num_threads();
        int chunck = n / nthreads;
        for (int i = 0; i < n; i++)
        {
            int first = i % nthreads;
#pragma omp parallel for schedule(auto)
            for (int j = first; j < n - 1; j += nthreads)
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
    printf("N = %i Tempo de execução: %.8lf\n", n, time_spent);

    return 0;
}
