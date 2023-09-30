/*
Problema 1067 - Números pares - aceito
*/
#include <iostream>
 
using namespace std;
 
int main() {
 
    int X, i;
    cin >> X;
    for (i = 1; i <= X; i++)
    {
        if ((i%2)!=0)
        {
            if(i>=6) {
                cout << i-6 << endl;
            }
            cout << i << endl;
        }
    }
 
    return 0;
}