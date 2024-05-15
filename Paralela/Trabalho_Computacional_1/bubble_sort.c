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
    setlocale(LC_ALL, "Portuguese");
    clock_t start_time = clock();

    for (int rodada = 1; rodada <= 100000; rodada += 1000)
    {
        int array[N];
        for (int i = 0; i < N; i++)
        {
            array[i] = rand() % N;
        }

        int i, j;
        unsigned short int swapped;
        for (i = 0; i < N - 1; i++)
        {
            swapped = 0;
            for (j = 0; j < N - i - 1; j++)
            {
                if (array[j] > array[j + 1])
                {
                    swap(&array[j], &array[j + 1]);
                    swapped = 1;
                }
            }
            if (!swapped)
            {
                i = N;
            }
        }
  
        clock_t finish = clock();
        double time_spent = (double)(finish - start_time) / CLOCKS_PER_SEC;
        printf("Rodada %i N = %i Tempo de execução: %f\n", rodada, rodada * N, time_spent);
    }
    return 0;
}
