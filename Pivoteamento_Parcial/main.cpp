#include <iostream>
#include <cmath>
#include <iomanip>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

void trocar_linhas(double **matriz, int tamanho_da_matriz, int linha_a, int linha_b);
void mostrar_matriz_aumentada(double **matriz, int tamanho_da_matriz);
void preencher_matriz(double **matriz, int tamanho_da_matriz);
void eliminacao_de_gauss(double **matriz, int tamanho_da_matriz, int linha_do_pivo);
double determinande_de_laplace(int tamanho_da_matriz, double **matriz);
void preencher_com_termo_idependente(double *vetor_do_termo_idependente, int tamanho_da_matriz);
void verificar_pivo_da_matriz(double **matriz, int tamanho_da_matriz, int coluna_do_pivo);
void preencher_matriz_aumentada(double **matriz_aumentada, double **matriz_b, double *vetor_do_termo_idependente, int tamanho_da_matriz);
void resolver_sistema(double **matriz, int tamanho_da_matriz, double *resultado_do_vetor);

int main()
{
	int op;
	do
	{
		op = -1;
		do
		{
			cout << endl;
			cout << "Escolha uma das opções abaixo: \n1 - Realizar operacao\n0 - Sair" << endl;
			cin >> op;
		} while (op < 0 || op > 1);
		

		switch (op)
		{
		case 0:
			cout << "Saindo..." << endl;
			sleep(2);
			cout << "Até mais" << endl;
			return 0;
			break;

		case 1:
			int i, j, lin, col, tamanho_da_matriz = 0;
			cout << "Defina o tamanho da matriz quadrada: {n*n : n > 1}" << endl;
			cin >> tamanho_da_matriz;
			double *resultado_do_vetor, *vetor_do_termo_idependente;
			double **matriz, **matriz_aumentada;

			matriz = new double *[tamanho_da_matriz];
			for (int i = 0; i < tamanho_da_matriz; i++)
			{
				matriz[i] = new double[tamanho_da_matriz];
			}

			matriz_aumentada = new double *[tamanho_da_matriz];
			
			for (int i = 0; i <= tamanho_da_matriz; i++)
			{
				matriz_aumentada[i] = new double[tamanho_da_matriz];
			}

			resultado_do_vetor = new double[tamanho_da_matriz];
			vetor_do_termo_idependente = new double[tamanho_da_matriz];

			preencher_matriz(matriz, tamanho_da_matriz);

			if (determinande_de_laplace(tamanho_da_matriz, matriz) == 0)
			{
				cout << endl;
				cout << "Determinante = " << determinande_de_laplace(tamanho_da_matriz, matriz) << endl;
				cout << "Não é possível resolver" << endl;
			}
			else
			{
				cout << endl;
				cout << "Determinante =  " << determinande_de_laplace(tamanho_da_matriz, matriz) << endl;
				preencher_com_termo_idependente(vetor_do_termo_idependente, tamanho_da_matriz);
				preencher_matriz_aumentada(matriz_aumentada, matriz, vetor_do_termo_idependente, tamanho_da_matriz);
				for (int i = 0; i < tamanho_da_matriz; i++)
				{
					mostrar_matriz_aumentada(matriz_aumentada, tamanho_da_matriz);
					verificar_pivo_da_matriz(matriz_aumentada, tamanho_da_matriz, i);
					cout << endl;
					eliminacao_de_gauss(matriz_aumentada, tamanho_da_matriz, i);
					cout << endl;
				}
				resolver_sistema(matriz_aumentada, tamanho_da_matriz, resultado_do_vetor);
				cout << endl;
			}
			break;
		}
	} while (op != 0);
	
}

void trocar_linhas(double **matriz, int tamanho_da_matriz, int linha_a, int linha_b)
{
	double aux = 0;
	cout << "L" << linha_a << " <=> L" << linha_b << endl;

	for (int i = 0; i <= tamanho_da_matriz; i++)
	{
		aux = matriz[linha_a][i];
		matriz[linha_a][i] = matriz[linha_b][i];
		matriz[linha_b][i] = aux;
	}
}

void mostrar_matriz_aumentada(double **matriz, int tamanho_da_matriz)
{
	cout << "Matriz :" << endl;

	for (int i = 0; i < tamanho_da_matriz; i++)
	{
		for (int j = 0; j <= tamanho_da_matriz; j++)
		{
			cout << fixed << setprecision(5)  << "[" << matriz[i][j] << "] ";
		}
		cout << endl;
	}
}

void preencher_matriz(double **matriz, int tamanho_da_matriz)
{
	double valor = 0;

	for (int i = 0; i < tamanho_da_matriz; i++)
	{
		for (int j = 0; j < tamanho_da_matriz; j++)
		{
			cout << "Insira o valor da posicao a" << i + 1 << j + 1 << endl;
			cin >> valor;
			matriz[i][j] = valor;
		}
	}
}

void eliminacao_de_gauss(double **matriz, int tamanho_da_matriz, int linha_do_pivo)
{
	double multiplicador = 1;

	for (int i = linha_do_pivo + 1; i < tamanho_da_matriz; i++)
	{
		multiplicador = matriz[i][linha_do_pivo] / matriz[linha_do_pivo][linha_do_pivo];
		for (int j = 0; j <= tamanho_da_matriz; j++)
		{
			matriz[i][j] = matriz[i][j] - multiplicador * matriz[linha_do_pivo][j];
		}
	}
}

double determinande_de_laplace(int tamanho_da_matriz, double **matriz)
{
	if (tamanho_da_matriz == 1)
	{
		return matriz[0][0];
	}
	else
	{
		double determinante = 0.0;
		int j, k, aux_j, aux_i;

		for (int i = 0; i < tamanho_da_matriz; i++)
		{
			if (matriz[0][i] != 0)
			{
				double **aux;
				double fator;
				aux = new double *[tamanho_da_matriz];

				for (int i = 0; i < tamanho_da_matriz; i++)
				{
					aux[i] = new double[tamanho_da_matriz];
				}

				int aux_i = 0;
				int aux_j = 0;

				for (j = 1; j < tamanho_da_matriz; j++)
				{
					for (k = 0; k < tamanho_da_matriz; k++)
					{
						if (k != i)
						{
							aux[aux_i][aux_j] = matriz[j][k];
							aux_j++;
						}
					}
					aux_i++;
					aux_j = 0;
				}

				if (i % 2 == 0) {
					fator = matriz[0][i];
				} else {
					fator = -matriz[0][i];
				}

				determinante = determinante + fator * determinande_de_laplace(tamanho_da_matriz - 1, aux);
			}
		}
		return determinante;
	}
}

void preencher_com_termo_idependente(double *vetor_do_termo_idependente, int tamanho_da_matriz)
{
	double valor = 0;

	cout << "Insira os termos independentes " << endl;
	for (int i = 0; i < tamanho_da_matriz; i++)
	{
		cout << "alpha" << i+1 << endl;
		cin >> valor;
		vetor_do_termo_idependente[i] = valor;
	}
}

void verificar_pivo_da_matriz(double **matriz, int tamanho_da_matriz, int coluna_do_pivo)
{
	double pivo;
	int linha_do_pivo;

	for (int i = coluna_do_pivo; i <= (tamanho_da_matriz - 1); i++)
	{
		pivo = matriz[coluna_do_pivo][coluna_do_pivo];
		linha_do_pivo = coluna_do_pivo;
		if ((fabs(matriz[i][coluna_do_pivo])) > (fabs(pivo)))
		{
			pivo = matriz[i][coluna_do_pivo];
			linha_do_pivo = i;
			cout << "pivo " << pivo << " linha pivo " << linha_do_pivo << endl;
			trocar_linhas(matriz, tamanho_da_matriz, coluna_do_pivo, linha_do_pivo);
			cout << endl;
		}
	}
}

void preencher_matriz_aumentada(double **matriz_aumentada, double **matriz_b, double *vetor_do_termo_idependente, int tamanho_da_matriz)
{
	for (int j = 0; j < tamanho_da_matriz; j++)
	{
		for (int i = 0; i < tamanho_da_matriz; i++)
		{
			matriz_aumentada[j][i] = matriz_b[j][i];
			matriz_aumentada[j][i + 1] = vetor_do_termo_idependente[j];
		}
	}
}

void resolver_sistema(double **matriz, int tamanho_da_matriz, double *resultado_do_vetor)
{
	double numerador;
	for (int i = 1; i <= tamanho_da_matriz; ++i)
	{
		numerador = matriz[tamanho_da_matriz - i][tamanho_da_matriz];
		for (int j = 1; j < i; ++j)
		{
			numerador -= (matriz[tamanho_da_matriz - i][tamanho_da_matriz - j] * resultado_do_vetor[tamanho_da_matriz - j]);
		}
		resultado_do_vetor[tamanho_da_matriz - i] = numerador / matriz[tamanho_da_matriz - i][tamanho_da_matriz - i];
	}
	for (int i = 0; i < tamanho_da_matriz; ++i)
	{
		cout << " x" << i + 1 << " = " << resultado_do_vetor[i];
		cout << endl;
	}
	cout << endl;
}

