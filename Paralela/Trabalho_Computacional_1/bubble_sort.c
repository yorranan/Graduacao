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
    setlocale(LC_ALL, "Portuguese");
    clock_t start_time = clock();

    for (int n = 0; n <= 100000; n += 10000)
    {
        int array[n];
        for (int i = 0; i < n; i++)
        {
            array[i] = rand() % n;
        }

        int i, j;
        unsigned short int swapped;
        for (i = 0; i < n - 1; i++)
        {
            swapped = 0;
            for (j = 0; j < n - i - 1; j++)
            {
                if (array[j] > array[j + 1])
                {
                    swap(&array[j], &array[j + 1]);
                    swapped = 1;
                }
            }
            if (!swapped)
            {
                i = n;
            }
        }
  
        clock_t finish = clock();
        double time_spent = (double)(finish - start_time) / CLOCKS_PER_SEC;
        printf("N = %i Tempo de execução: %f\n", n, time_spent);
    }
    return 0;
}
