#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100*1000

void initializeArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % n;
    }
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    unsigned short int swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) 
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (swapped == 0)
        {
            break;
        }
    }
}

int main()
{
    clock_t start_time = clock();
    int array[N];
    initializeArray(array, N);
    printf("Array Desordenado: \n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", array[i]);
    }
    int i, j;
    unsigned short int swapped;
    for (i = 0; i < N - 1; i++) 
    {
        swapped = 0;
        for (j = 0; j < N - i - 1; j++) {
            if (array[j] > array[j + 1]) 
            {
                swap(&array[j], &array[j + 1]);
                swapped = 1;
            }
        }
        if (swapped == 0)
        {
            break;
        }
    }
    printf("\nArray Ordenado: \n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", array[i]);
    }
    clock_t finish = clock();
	double time_spent = (double)(finish - start_time)/CLOCKS_PER_SEC;
	printf("\nTime de execucao: %f\n", time_spent);
    return 0;
}
