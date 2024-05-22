#include <stdio.h>
#include <time.h>
double step;
static long num_steps = 1000000;
int main()
{
    clock_t begin = clock();
    int i, nt;
    double x, pi, sum = 0.0;  
    step = 1.0 / (double)num_steps;
        for (i = 0; i < num_steps; i++)
        {
            x = (i + 0.5) * step;
            sum = sum + 4.0 / (1.0 + x * x);
        }
        pi = step * sum;
    printf("pi: = %.8lf\n", pi);
    clock_t end = clock();
    double finish = (double)(end-begin)/CLOCKS_PER_SEC;
    printf("%lf\n", finish);
    return 0;
}
