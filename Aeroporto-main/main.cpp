// Yorranan Neves de Almeida Costa - Turma C 

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "FilaPrioridadesLE.h"

using namespace std;

void mostrar_banner() {
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWKo,..kM" << endl;
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMXo.   ;KM" << endl;
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMXd.   .lXMM" << endl;
    cout << "MMMMMMWNNNNWWWMMMMMMMMMMMMMXx'    .xNMMM" << endl;
    cout << "MMMMW0c'.''',,;;::ccccllool'     ,0WMMMM" << endl;
    cout << "MMMWk'                          cXMMMMMM" << endl;
    cout << "MMMWXOxo:,.                    '0MMMMMMM" << endl;
    cout << "MMMMMMMMMWX0xoc,..              oWMMMMMM" << endl;
    cout << "MMMMMMMMMMMMMMMWX0d'            .OMMMMMM" << endl;
    cout << "MMMMMMMMMMMMMMMMMXl.             :XMMMMM" << endl;
    cout << "MMMMMMMMMMMMMMMM0;     .ld,       dWMMMM" << endl;
    cout << "MMMMMMMMMMMMMMWk'    .l0WMK:      'OMMMM" << endl;
    cout << "MMMMMMMMMMMMMNo.  .lx0WMMMMNd.     cNMMM" << endl;
    cout << "MMMMMWWMMMMMK:  .lKWMMMMMMMMWk'    .xWMM" << endl;
    cout << "MMMNx;,:lokx, .lKWMMMMMMMMMMMMK:    ,0MM" << endl;
    cout << "MMM0:.       'OWMMMMMMMMMMMMMMMNo.   dWM" << endl;
    cout << "MMMMWX0xo:.  .lXMMMMMMMMMMMMMMMMWk'.cKMM" << endl;
    cout << "MMMMMMMMMWKo.  ,0WMMMMMMMMMMMMMMMMKONMMM" << endl;
    cout << "MMMMMMMMMMMWO, .dWMMMMMMMMMMMMMMMMMMMMMM" << endl;
    cout << "MMMMMMMMMMMMM0:oNMMMMMMMMMMMMMMMMMMMMMMM" << endl;
    cout << "MMMM SISTEMA DE POUSOS E DECOLAGENS MMMM" << endl;
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
}

int prioridade_aleatoria() {
    int prioridade;
    prioridade = (rand()%4) + 1;
    return prioridade;
}

int main(void) {
    no *Fila_espera;
    no *Pista_pouso;
    no *Pista_decolagem;
    int informacao;
    int prioridade;
    int unidade_tempo; 
    int unidade_terceira_de_tempo = 0;
    bool continua = true;

    Fila_espera = inicializaFP(Fila_espera);
    Pista_pouso = inicializaFP(Pista_pouso);
    Pista_decolagem = inicializaFP(Pista_decolagem);

    srand(time(NULL));
    for(int i = 1; i <= 30; ++i) {
        Fila_espera = insereFilaChegada(Fila_espera, i, prioridade_aleatoria());
    }
    cout << "Fila de espera:" << endl;
    exibe(Fila_espera);
    cout << "\n" << endl;
    mostrar_banner();

    for(unidade_tempo = 1; continua; unidade_tempo++) {
        
        cout << "\n";
        if((unidade_terceira_de_tempo > 2) || (Pista_decolagem == NULL)) {
            unidade_terceira_de_tempo = 0;
        }
        bool verifica_selecionado_pouso = false;
        bool verifica_selecionado_decolagem = false;    
        cout << "----------------------------------------" << endl;
        cout << "--------- UNIDADE DE TEMPO: " << unidade_tempo << " ---------" << endl;
        for(int i = 0; i < 2; i++){
            if(!verificaSeVazia(Fila_espera)) {
                Fila_espera = removeFP(Fila_espera, &informacao, &prioridade);
                if (prioridade == 1 || prioridade == 2) {
                    Pista_pouso = insereFilaChegada(Pista_pouso, informacao, prioridade);
                    verifica_selecionado_pouso = true;
                } 
                else {
                    Pista_decolagem = insereFilaChegada(Pista_decolagem, informacao, prioridade);
                }
            }
        } 

        if((unidade_tempo%2 == 0) && (continua)) {
            if(!verificaSeVazia(Pista_pouso)) {
                cout << "\nPista de pouso lotada com: " << Pista_pouso->info << endl;
                Pista_pouso = removeFP(Pista_pouso, &informacao, &prioridade);
            }
        }
        else if (!verificaSeVazia(Pista_pouso)) {
            cout << "\nPista de pouso lotada com: " << Pista_pouso->info << endl;
        }

        if(unidade_terceira_de_tempo == 2) {
            if(!verificaSeVazia(Pista_decolagem)) {
                cout << "Pista de decolagem lotada com:" << Pista_decolagem->info << endl;
                Pista_decolagem = removeFP(Pista_decolagem, &informacao, &prioridade);
            }
        }
        else if ((!verificaSeVazia(Pista_decolagem)) && (unidade_terceira_de_tempo < 2)) {
            cout << "Pista de pouso decolagem com: " << Pista_decolagem->info << endl;
        }
        
        if (verificaSeVazia(Pista_pouso) && verificaSeVazia(Pista_decolagem)) {
            continua = false;
        }
        unidade_terceira_de_tempo++;
        
    }
    cout << "\nYorranan - 2022" << endl;
    return 0;

    }