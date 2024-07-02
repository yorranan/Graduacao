#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define N 10

void countingSort(int arr[], int n, int max)
{
    int i;

    int *count = (int *)calloc(max + 1, sizeof(int));
    int *output = (int *)malloc(n * sizeof(int));

#pragma omp parallel for
    for (i = 0; i < n; i++)
    {
#pragma omp atomic
        count[arr[i]]++;
    }

    for (i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

#pragma omp parallel for
    for (i = n - 1; i >= 0; i--)
    {
        int idx = __sync_sub_and_fetch(&count[arr[i]], 1);
        output[idx] = arr[i];
    }

#pragma omp parallel for
    for (i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }

    free(count);
    free(output);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    for (int n = 0; n <= 100000; n += 10000)
    {
    clock_t start = clock();
        int array[n];
        int max = 0;

        srand(time(NULL));
        for (int i = 0; i < n; i++)
        {
            array[i] = rand() % n;
            if (array[i] > max)
            {
                max = array[i];
            }
        }
        // if (n == 1)
        // {
        //     printf("\n");
        //     for (int i = 0; i < N * n; i++)
        //     {
        //         printf("%i ", array[i]);
        //     }
        // }

        countingSort(array, n, max);

        clock_t finish = clock();
        double time_spent = (double)(finish - start) / CLOCKS_PER_SEC;
        printf("N = %i Tempo de execução: %.8lf\n", n, time_spent);

        // if (n == 1)
        // {
        //     printf("\n");
        //     for (int i = 0; i < N * n; i++)
        //     {
        //         printf("%i ", array[i]);
        //     }
        // }
    }
    return 0;
}