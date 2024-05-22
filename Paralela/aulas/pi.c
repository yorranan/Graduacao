#include <stdio.h>
#include <omp.h>
#include <time.h>

#define NUM_THREADS 2
double step;
static long num_steps = 1000000;

int main (){
	clock_t start = clock();
	
	int i, nthreads; 
	double x, pi;
	step = 1.0/(double)num_steps;
	omp_set_num_threads(NUM_THREADS);

	#pragma omp parallel 
	{
        int i, id, nthrds;
        double x, sum;
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();
        if (id == 0) nthreads = nthrds;
	    for (i=id, sum=0.0; i <num_steps; i=i+nthrds)
        {
            x = (i + 0.5) * step;
            sum += 4.0/(1.0+x*x);
		}
        #pragma omp atomic
	        pi += step * sum;
        
	}

	printf("Pi or Sum of the integral value is: (%.8lf)\n", pi);
	
	clock_t finish = clock();
	double time_spent = (double)(finish - start)/CLOCKS_PER_SEC;
	printf("Time spent: %f\n", time_spent);
	return 0;
}