#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

string word_receiver(){
    string word_typed;
    cin >> word_typed;
    return word_typed;
}

bool comparar_palavras(char char_comparada, char char_comparadora) {
    if(char_comparada == char_comparadora) {
        return true;
    }
    else {
        return false;
    }
}

void embaralhar(string palavra1){
    string embaralhada = palavra1;
    random_shuffle( embaralhada.begin(), embaralhada.end());
    cout << "Palavra embaralhada:  " << embaralhada <<endl;
}

void revelarPalavra(string palavra1, string aux1){
    for (int i = 0; i < (palavra1.length() - aux1.length()); i++)
        cout << "_ ";
    for (int i = aux1.length(); i >= 0; i--)
        cout << aux1[i] << " ";
    cout <<endl;
}

void mostrarMenuEscolha(){
    cout << "-----------------------|L E T R O C A|-----------------------"<<endl;
    cout <<endl << "[1] - Chutar palavra" <<endl << "[2] - Reembaralhar palavra" <<endl << "[3] - Revelar letra" <<endl << "[4] - Sair" <<endl <<endl;
}


