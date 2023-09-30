#include <stdio.h>
#include <xmmintrin.h> // SSE
#include <emmintrin.h> // SSE2
#include <pmmintrin.h> // SSE3
#include <smmintrin.h> // SSE4.1
#include <time.h>
#define TAMANHO_VETOR 8 // assume-se que o tamanho é multiplo de quatro -- registradores irão armazenar 4 elementos

void mostrarOpcoes();
void adicionar_instrinsics(float *a, float *b, float *c);
void multiplicacao_paralela(float *a, float *b, float *c);

int main(int argc, char *argv[])
{
    float *a __attribute__ ((aligned(16))) = (float*)malloc (sizeof(float) * TAMANHO_VETOR);
    float *b __attribute__ ((aligned(16))) = (float*)malloc (sizeof(float) * TAMANHO_VETOR);
    float *c __attribute__ ((aligned(16))) = (float*)malloc (sizeof(float) * TAMANHO_VETOR);

    for (int i = 0; i < TAMANHO_VETOR; ++i) {
        a[i] = i + 0.0;
        b[i] = i + 0.0;
    }

    printf("Iniciando...\n");
    float soma = 0;
    clock_t start_sse = clock();
    for(int i = 0; i < TAMANHO_VETOR; ++i) //produto escalar sequencial
	{	
    	multiplicacao_paralela(a+i, b+i, c+i);
	}
	for(int i = 0; i < TAMANHO_VETOR; ++i)
	{	
    	soma += c[i];
	}
	printf("Produto escalar: %f\n", soma);
    clock_t end_sse = clock();
    float seconds_sse = (float)(end_sse - start_sse)/CLOCKS_PER_SEC;
}

void mostrarOpcoes() {
    printf("--------------------------------\n");
    printf("1 - Produto Escalar Simples\n");
    printf("2 - Produto Escalar Impar\n");
    printf("3 - Multiplicacao por Escalar\n");
    printf("--------------------------------\n");
}

void adicionar_instrinsics(float *a, float *b, float *c) {
    __m128 varA = _mm_load_ps(a);
    __m128 varB = _mm_load_ps(b);
    __m128 varC = _mm_add_ps(varA, varB);
    _mm_store_ps(c, varC);
    /* Equivalente Assembly
     ** mov eax, a
     ** mov edx, b
     ** mov ecx, c
     ** movaps xmm0, XMMWORD PTR [eax]
     ** addps xmm0, XMMWORD PTR [edx]
     ** movaps XMMWORD PTR [ecx], xmm0
     */
}

void multiplicacao_paralela(float *a, float *b, float *c) {
    __m128 varA = _mm_load_ps (a);
    __m128 varB = _mm_load_ps (b);
    __m128 varC = _mm_mul_ps (varA, varB);
    _mm_store_ps(c, varC);
}
