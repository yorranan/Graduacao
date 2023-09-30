#include <iostream>
#include "inputs.cpp"
#include "methods.cpp"
#define EXIT 6

using namespace std;

void archive_results(double root, int interactions);
int main()
{
    int option_selected;
    
    do
    {
        double a, b, left_interval, right_interval, precision;
        int max_interactions;
        // Recebe o int da opção selecionada que será usada no switch-case
        option_selected = select_operation(); 
        switch (option_selected)
        {
            /*
            Em todos os casos do switch é feito uma requisição de dados através das funções input, elas são definidas no arquivo inputs.cpp
            */

        case 1:
            secante_FPI_and_bisection_input(&precision, &left_interval, &right_interval, &max_interactions);
            bisection(precision, left_interval, right_interval, max_interactions);
            break;
        case 2:
            secante_FPI_and_bisection_input(&precision, &left_interval, &right_interval, &max_interactions);
            FPI(precision, left_interval, right_interval, max_interactions); 
            break;
        case 3:
            newton_input(&precision, &left_interval, &max_interactions);
            newton(precision, left_interval, max_interactions);
            break;
        case 4:
            secante_FPI_and_bisection_input(&precision, &left_interval, &right_interval, &max_interactions);
            secante(precision, left_interval, right_interval, max_interactions);
            break;
        case 5:
            regula_falsi_input(&left_interval, &right_interval, &precision,&max_interactions);
            regula_falsi(precision, left_interval, right_interval, max_interactions);
            break;

        default:
            break;
        }
    } while (option_selected != EXIT);
    printf("Por favor verifique os resultados no arquivo de texto\n");
    return 0;
}

