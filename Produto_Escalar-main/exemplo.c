#include <stdio.h>
#include <xmmintrin.h> // SSE (Required to use the __m128, and __m128d type)
#include <emmintrin.h> // SSE2 (Required to use the __m128i type)
#include <pmmintrin.h> // SSE3
#include <smmintrin.h> // SSE4.1
#include <time.h>

#define VECTOR_SIZE 268435456//8

void add_intel_intrinsics(float *a, float *b, float *c)
{
  __m128 va = _mm_load_ps (a);
  __m128 vb = _mm_load_ps (b);
  __m128 vc = _mm_add_ps (va, vb);
  _mm_store_ps(c, vc);

  /* Equivalente Assembly 
  ** mov eax, a
  ** mov edx, b 
  ** mov ecx, c
  ** movaps xmm0, XMMWORD PTR [eax]
  ** addps xmm0, XMMWORD PTR [edx]
  ** movaps XMMWORD PTR [ecx], xmm0
  */
}

void add_sequential(float *a, float *b, float *c)
{
	*c = *a + *b; 
}

void mul_sequential(float *a, float *b, float *c)
{
	*c = *a * *b; 
}

void mul_intel_intrinsics(float *a, float *b, float *c) {
__m128 va = _mm_load_ps (a);
__m128 vb = _mm_load_ps (b);
__m128 vc = _mm_mul_ps (va, vb);
_mm_store_ps(c, vc);
}

int main (int argc, char *argv[])
{
  float *a __attribute__ ((aligned(16))) = (float*)malloc (sizeof(float) * VECTOR_SIZE); //aloca um vetor de 16bytes (128bits) alinhado em endereços múltiplos de 16bytes.
  float *b __attribute__ ((aligned(16))) = (float*)malloc (sizeof(float) * VECTOR_SIZE);
  float *c __attribute__ ((aligned(16))) = (float*)malloc (sizeof(float) * VECTOR_SIZE);  
  	  
  for (int i = 0; i < VECTOR_SIZE; ++i) {
    a[i] = 1.0;//i;
    b[i] = 1.0;//i;
  }

  printf("Sequencial\n");
  clock_t start = clock();

  for (int i = 0; i < VECTOR_SIZE; ++i)
  {
  	add_sequential(a+i, b+i, c+i);
  	mul_sequential(a+i, b+i, c+i);
  }

  clock_t end = clock();
  float seconds = (float)(end - start) / CLOCKS_PER_SEC;
  printf("Tempo da versao sequencial: %f\n", seconds);

  //for (i = 0; i < VECTOR_SIZE; ++i) {
    //printf("%f\n", c[i]);
  //}
  
  for (int i = 0; i < VECTOR_SIZE; ++i) {
    a[i] = 1.0;//i;
    b[i] = 1.0;//i;
  }
	
  printf("Intel Intrinsics\n");
  clock_t start_sse = clock();

  for (int i = 0; i < VECTOR_SIZE; i+=4)
  {
  	add_intel_intrinsics(a+i, b+i, c+i);
  	mul_intel_intrinsics(a+i, b+i, c+i);
  }

  clock_t end_sse = clock();
  float seconds_sse = (float)(end_sse - start_sse) / CLOCKS_PER_SEC;
  printf("%f\n", seconds_sse);

//mul_intel_intrinsics(a,b,c);

  //for (int i = 0; i < VECTOR_SIZE; ++i) {
   // printf("%f\n", c[i]);
  //}
  
  free(a);
  free(b);
  free(c); 

  return 0;
}
