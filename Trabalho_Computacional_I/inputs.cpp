#include <iostream>

using namespace std;

// Função responsável por mostrar o menu e retornar a opção selecionada
int select_operation()
{
    int option;
    do
    {
        printf("\n");
        printf("Escolha um dos metodos a seguir: \n");
        printf("1 - Bisseccao\n");
        printf("2 - MIL\n");
        printf("3 - Newton - Raphson\n");
        printf("4 - Secante\n");
        printf("5 - Regula Falsi\n");
        printf("6 - Sair\n");
        scanf("%d", &option);
    } while (option < 1 || option > 6);
    return option;
}

/*
    As três funções abaixo recebem os valores necessários para serem ultilizadas nas funções, para isso ela chama os endereços de cada parâmetro ao invés de copiar os valor em uma passagem de parâmetros tradicional.
*/
void regula_falsi_input(double *left_interval, double *right_interval, double *precision, int *max_interactions)
{
    printf("\n");
    printf("DIgite o primeiro valor do intervalo:\n");
    cin >> *left_interval;
    printf("DIgite o segundo valor do intervalo:\n");
    cin >> *right_interval;
    printf("Digite o numero maximo de interacoes:\n");
    cin >> *max_interactions;
    printf("Digite a precisao desejada:\n");
    cin >> *precision;
}

void secante_FPI_and_bisection_input(double *precision, double *left_interval, double *right_interval, int *max_interactions)
{
    printf("\n");
    printf("Digite o primeiro valor do intervalo:\n");
    cin >> *left_interval;
    printf("Digite o segundo valor do intervalo:\n");
    cin >> *right_interval;
    printf("Digite o numero maximo de interacoes:\n");
    cin >> *max_interactions;
    printf("Digite a precisao desejada:\n");
    cin >> *precision;
}

void newton_input(double *precision, double *aprox, int *max_interactions)
{
    printf("\n");
    printf("Digite o primeiro valor do aproximado:\n");
    cin >> *aprox;
    printf("Digite o numero maximo de interacoes:\n");
    cin >> *max_interactions;
    printf("Digite a precisao desejada:\n");
    cin >> *precision;
}
