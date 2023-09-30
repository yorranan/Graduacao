#include <cmath>
#include <fstream>

using namespace std;

ofstream file;
// responsável por armazenar os resultados
void archive_results(double root, int interactions)
{
    file.open("results.txt", ios_base::app);
    file << "raiz: " << root << " quantidade de interacoes: " << interactions <<"\n";
    file.close();
}
// Abaixo está definido os cálculos das funções

//f(x) = e^(x^2) - cos(x)
double f(double x)
{
    double y;
    y = (exp(-pow(x, 2)) - cos(x));
    return y;
}
//f'(x) = (e^(x^2))(-2x) - sin(x)
double dx(double x)
{
    double y;
    y = exp(-pow(x, 2))*(-2*x) + sin(x);
    return y;
}
// phi = cos(x) - e^(-x^2)
double phi(double x)
{
    double phi;
    phi = cos(x) - exp(-pow(x, 2));
    return phi;
}

void bisection(double precision, double a, double b, int max_interactions)
{
    double fbegin, fmid, mid, root;
    int k = 0;
    if (fabs(b-a) < precision)
    {
        root = (a+b)/2;
        archive_results(root, k);
    }
    else
    {
        while (fabs(b-a) > precision && k < max_interactions)
        {
            k++;
            fbegin = f(a);
            mid = (a+b)/2;
            fmid = f(mid);
            if((fbegin*fmid) < 0){
                b = mid;
                root = b;
            }else{
                a = mid;
                root = a;
            }
            archive_results(root, k);
        }
        
    }
}

void FPI(double precision, double a, double b, int max_interactions)
{
    int k = 0;
    double root, x0 = a, x1 = b, module;
    if(fabs(x0) < precision){
        archive_results(x0, k);
    }else{
        do{
            k++;
            x1 = phi(x0);
            module = x1 - x0;
            x0 = x1;
            archive_results(x1, k);
        }while(fabs(f(x1)) > precision && fabs(module) > precision && k < max_interactions);
    }
}

void newton(double precision, double x0, int max_interactions)
{
    int k = 0;
    double root, fx_derivative, fx = f(x0), x1;
    if(fabs(fx) > precision)
    {
        k = 1;
        fx_derivative = dx(x0);
        x1 = x0 - (fx/fx_derivative);
        fx = f(x1);
        archive_results(x1, k);
        while(fabs(fx) > precision && fabs((x1-x0)) > precision && k <= max_interactions)
        {
            k++;
            x0 = x1;
            fx_derivative = dx(x0);
            x1 = x0 - (fx/fx_derivative);
            fx = f(x1);
            archive_results(x1, k);
        }
    }
    else
    {
        archive_results(x0, k);
    }
}

void secante (double precision, double x0, double x1, int max_interactions)
{
    int k = 0;
    double x2, root, fx1, fx0, module;
    if(fabs(f(x0)) < precision)
    {
        archive_results(x0, k);
    }
    else if (fabs(f(x1)) < precision || fabs((x1-x0)) < precision)
    {
        archive_results(x1, k);
    }
    else
    {
        do
        {
            k++;
            x2 = x1 - ((f(x1)*(x1-x0))/(f(x1)-f(x0)));
            module = x2 - x1;
            x0 = x1;
            x1 = x2;
            archive_results(x2, k);
        }while(fabs(f(x2)) > precision && fabs(module) > precision && k < max_interactions);
    } 
}

void regula_falsi (double precision_one, double a, double b, int max_interactions)
{
    double root, x, module;
    int k = 0;
    if(fabs((b-a)) < precision_one)
    {
        archive_results(((a+b)/2), k);
    }
    else if(fabs(f(a)) < precision_one)
    {
        archive_results(a, k);
    }else if(fabs(f(b)) < precision_one)
    {
        archive_results(b, k);
    }
    else
    {
        do
        {
            k++;
            module = f(a);
            x = ((a*f(b)) - (b*f(a)))/(f(b) - f(a));
            if(module*f(x)>0){
                a = x;
            }else{
                b = x;
            }
            if(fabs((b-a)) < precision_one){
                archive_results(((a+b)/2), k);
                break;
            }
            archive_results(x, k);
        }while(fabs(f(x)) > precision_one && k < max_interactions);

    }
        
}