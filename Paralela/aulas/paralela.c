#include <stdio.h>
#include "omp.h"
int main () 
{
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        printf("Hello (%d)", id);
        printf(" World! (%d) \n", id);
    }
}