//Autor: Yorranan Neves de Almeida Costa
//Função: Jogo de batalha naval humano VS computador
//Data: 01 nov. 2021
//Trabalho de Programação de Computadores I
#include <iostream>
#include <ctime>    //lib para rand e srand 
#include <string>   //para teste ASCII
#include <cstdlib>  //para color
#include <windows.h>//uso do sistema
#include <climits>  //para usar limites de variaveis, ex.: INT_MIN
#define DIMENSAO 8  //tamanho de linhas e colunas
#define MEMORIA 100 //número máximo de rodadas

using namespace std;

/*
Este registro armazena o nome do jogador e sua pontuação;
Ele é chamado durante a partida para a contagem de pontos do jogador e mostrar o nickname selecionado;
*/
typedef struct{
    string nome;
    int pontos;
} Jogador;

void mostrarDerrota()
{
    cout << "_________________________________________________________________________________"<< endl;
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
    cout << "MN0OOO000XNMMN0OOOOO0NN0OOO00KXWMMX0OOO000KXWMMMWXOxxxOXWMN0OOOOOOO0XN0OOOO0XMMM" << endl;
    cout << "Mk'    ...,xNO'     .kk'    ...:0Wx.     ...lKMKl.     .oKx.       .dx.    .oNMM" << endl;
    cout << "Mk.   ;,   'Ok.   ,coKk.   ;,   cXd   .;c'   oNl   'l.   oOo:.   .:okc      ;KMM" << endl;
    cout << "Mk.  .xd.  .kk.  .xWWMk.  .do   :Xd   .xKc   lK:   :O;   cNMX:   ;XMK;  ..  .OMM" << endl;
    cout << "Mk.  .xd.  .kk.   .,lKk.   ..  'kNd    ...  ;OX;   :O;   cNMX:   ;XMO.  ,:   oWM" << endl;
    cout << "Mk.  .xd.  .kk.   .'cKk.   '.  'kNd   .,;.  ;OX;   :O;   cNMX:   ;XWd.  cd.  :XM" << endl;
    cout << "Mk.  .xd.  .kk.  .dNWWk.  .xd   :Xd   .kXc   lK:   :O;   cNMX:   ;XNc   ',   '0M" << endl;
    cout << "Mk.  .lc   .kk.   ckkKx.  .xd.  ;Kd   'kXl   cXc   ,x,   lWMX;   ;XK,    .   .xM" << endl;
    cout << "Mk.        :Kk.      lx.  .xd.  ;Kd   'kXl   cNO,   .   ;0MMX:   ;Xk.   lO,   cN" << endl;
    cout << "MXdoooooodkXMXxoooooo0KxoodKKdookNKdooxXW0ooo0WMXklcccokXMMMWOoooOWKdoodKWOoookN" << endl;
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
}

void mostrarVitoria()
{
    cout << "_________________________________________________________________________________"<< endl;
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWWWWWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMKo;;ckNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
    cout << "MMWNNNNWMWWNNNWWNNNNWWNNNNNNNNNNWMMWXl.,cxXWMMMWNNNNWWWMMMMWNNNNWMMWWNNNNNWMMMMM" << endl;
    cout << "MMO;'''oNK:'''lx:'''dO:'''''''';OWOc'.....,l0WNo''''',,:dXM0:'''dNM0:''''':0MMMM" << endl;
    cout << "MM0'   ,0x.   :d.   cx,.      ..xx.   ''    ,0X;    ..   cNk.   cNWd.     .dWMMM" << endl;
    cout << "MMX:   .ko    ox.   cXK0l    :0KXc   .kd.   .dX:   .xl   '0k.   cNNc   .   cNMMM" << endl;
    cout << "MMWo   .l:   .kk.   cNMMd.   lWMNc   .kd.    dX;   .l;   ;Kk.   cNK,  .;.  '0MMM" << endl;
    cout << "MMMO.   ;,   ,0k.   cNMMd.   lWMN:   .kd..   oK:        ,kWk.   cNk.  .o,  .xMMM" << endl;
    cout << "MMMK;   ..   cNk.   cNMMd.   lWMNc   .kd..   oK;   .c,  .cXk.   cXd   'd;   lNMM" << endl;
    cout << "MMMWl        dWk.   cNMMd.   lWMNc   .kd..   dX;   .Oo   '0k.   cK:    .    ,KMM" << endl;
    cout << "MMMMk.      .OMk.   cNMMd.   lWMWo   .lc.   .xX;   'Oo   '0k.   cO,   .,.   .kMM" << endl;
    cout << "MMMMK,      ,KMk.   cNMMd.   oWMMKc.       .oXX:   'Oo   '0k.   cd.   :Xx.   oWM" << endl;
    cout << "MMMMW0dddddd0WMXkddd0WMMKxddxKWMMMW0xollloxKWMWOdddkXKxddkNXkddd0Kxddd0WXxddd0WM" << endl;
    cout << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM" << endl;
}

void mostrarTitulo()
{
    cout << "MMMMMMMMMMMMMMNk;.    .,xNMMMMMMMMMMMMMM" << endl;
    cout << "MMMMMMMMMMMMMWd. .;lo:.  lNMMMMMMMMMMMMM" << endl;
    cout << "MMMMMMMMMMMMMX:  ;KMMX:  ,KMMMMMMMMMMMMM" << endl;
    cout << "MMMMMMMMMMMMMWx.  ,cc;. .dNMMMMMMMMMMMMM" << endl;
    cout << "MMMMMMMMMMMMMMWOc.    .:kNMMMMMMMMMMMMMM" << endl;
    cout << "MMMMMMMMMMN0kkkkx;    ,xkkkk0NMMMMMMMMMM" << endl;
    cout << "MMMMMMMMMMO'                .kMMMMMMMMMM" << endl;
    cout << "MMMMMMMMMMKc,,,,,.    .',,,,:0MMMMMMMMMM" << endl;
    cout << "MMMMMMMMMMMWWWWWNo    cXWWWWWMMMMMMMMMMM" << endl;
    cout << "MMMMMXKWMMMMMMMMWo    cNMMMMMMMMWKXWMMMM" << endl;
    cout << "MMMNx'.c0WMMMMMMWo    cNMMMMMMWKl..oXMMM" << endl;
    cout << "MW0;    .dNMMMMMWo    cNMMMMMNx'    ,OWM" << endl;
    cout << "MWOl'   .oXMMMMMWo    cNMMMMMNd.   .ckNM" << endl;
    cout << "MMMMO.  .dNMMMMMWo    cNMMMMMWk.  .xWMMM" << endl;
    cout << "MMMMWx.  .c0WMMMWo    cNMMMWKl.  .oNMMMM" << endl;
    cout << "MMMMMWk,   .:xKNWo    cNWKkc.   'xNMMMMM" << endl;
    cout << "MMMMMMMXx,    .';.    .;,.    'oKMMMMMMM" << endl;
    cout << "MMMMMMMMMNOo;.            .,lkXMMMMMMMMM" << endl;
    cout << "MMMMMMMMMMMMWXOxo,    'oxOXWMMMMMMMMMMMM" << endl;
    cout << "MMMMMMMMMMMMMMMMMXo;,lKMMMMMMMMMMMMMMMMM" << endl;
    cout << "MMMMMMMMMMMMMMMMMMWWWWMMMMMMMMMMMMMMMMMM" << endl;
    cout << "________________________________________" << endl;
    cout << "        B A T A L H A   N A V A L       " << endl;
    cout << "________________________________________" << endl;
}

int selecionarDificuldade() 
//Essa função está usando retorno de parâmetros.
{
    int dificuldade = 0;    //para o 'if' de dificuldade
    for (int i = 0; i < 1; i++)
        {
            cout << "Selecione o nivel de dificuldade: " << endl;
            cout << "Digite o numero em questao!" << endl;
            cout << "1 - Normal" << endl;
            cout << "2 - Dificil" << endl;
            cin >> dificuldade;
            if (dificuldade == 1 || dificuldade == 2)
            {
                switch (dificuldade)
                {
                    case 1:
                        return 1;
                    break;
                    case 2:
                        return 2;
                    break;
                }
                system("cls");
            }
            else
            {
                system("pause");
            }
        }
}
//Função responsável por dizer se haverá ou não uma nova partida, a checagem é feita dentro do int(main).
bool testeContinuar(char resposta)
{
    //teste de continuação:
        if(resposta == 'S')
        {
            return true;
        }
        if(resposta == 'N')
        {
            return false;
        }
}

void mostrar_tabuleiro_jogador(char linha[DIMENSAO], char coluna[DIMENSAO], string tabuleiro[DIMENSAO][DIMENSAO])
{
    //Mostrar tabuleiro do jogador:
    // Atualiza conforme for se posicionando as peças, repitirá 4 vezes para posicionar submarinos e 2 para hidro.
    cout << endl;
    cout << endl;
    cout << "   ";
        for (int i = 0; i < DIMENSAO; i++)
            cout << coluna[i] << "  "; 
        cout << endl; 
        for (int l = 0; l < DIMENSAO; l++)
        {
            cout << linha[l] << " ";  
            for(int c = 0; c < DIMENSAO; c++)
            {
                if (tabuleiro[l][c] == "")
                {
                    tabuleiro[l][c] = " ~ ";
                }
                cout << tabuleiro[l][c]; 
            } 
        cout << endl;
        }     
        
        
}

void posicionamento_submarino_jogador(char aux, int linha, int aux_conv, string tabuleiro_jogador[DIMENSAO][DIMENSAO])
{
    cout << "Defina as posicoes dos Submarinos (tamanho 1):   " << endl;
    cout << "_________________________________________________________________________________"<< endl;
    cout << "*Representacao dos Submarinos:          S        " << endl;
    cout << "Posicao:" << endl;
    for (int i = 0; i < 1; i++)
    {
        cin >> aux;
        cin >> linha;
        aux_conv = ((int)aux) - 65;
        cout << "int aux:" << aux_conv << endl;
            if (linha >= 1 && linha <= 8)
            {
                if (aux_conv >= 0 && aux_conv <= 7)
                {
                    if (tabuleiro_jogador[linha-1][aux_conv] == " ~ ")
                    {
                        tabuleiro_jogador[linha-1][aux_conv] = " S ";
                    }
                    else
                    {
                        cout << "ERRO" << endl;
                        i--;
                    }
                }
                else
                {
                    cout << "tente novamente!" << endl;
                    i--;
                }
            }
            else
            {
                cout << "tente novamente!" << endl;
                i--;
            }
    }
    
    system("cls");
}

void posicionamento_hidroaviao_jogador(char aux, int linha, int aux_conv, string tabuleiro_jogador[DIMENSAO][DIMENSAO])
{
    for(int i = 0; i < 1; i++)
    {
        cout << "Defina as posicoes dos Hidroavioes (tamanho 4): " << endl;
        cout << "Digite o ponto central do hidroaviao!" << endl;
        cout << "_________________________________________________________________________________"<< endl;
        cout << "*Representacao dos Hidroavioes:       H          " << endl;
        cout << "                                     HHH         " << endl;
        cout << "Posicao:" << endl;
        cin >> aux;
        cin >> linha;
        aux_conv = ((int)aux) - 65;
        if (linha >= 1 && linha <= 8)
        {
        if (aux_conv >= 1 && aux_conv <= 6)
        {
            if (tabuleiro_jogador[linha - 1][aux_conv] == " ~ " && 
            tabuleiro_jogador[linha - 1][aux_conv-1] == " ~ " && 
            tabuleiro_jogador[linha - 1][aux_conv+1] == " ~ ")
            {
                tabuleiro_jogador[linha - 1][aux_conv-1] = " H ";
                tabuleiro_jogador[linha - 1][aux_conv] = " H ";
                tabuleiro_jogador[linha - 1][aux_conv+1] = " H ";
                //O segundo 'if' verifica se todas as linhas possíveis estão vagas
                //A prioridade de inserção é a linha superior
                if (tabuleiro_jogador[linha - 2][aux_conv] == " ~ ")
                {
                    tabuleiro_jogador[linha - 2][aux_conv] = " H ";
                    i++;
                }
                else
                {
                    if (tabuleiro_jogador[linha][aux_conv] == " ~ ")
                        tabuleiro_jogador[linha][aux_conv] = " H ";
                    i++;
                }
            }
            else
            {
                cout << "tente novamente!" << endl;
                i--;
            }
        }
        else
        {
            cout << "tente novamente!" << endl;
            i--;
        }
        }
        else
        {
            cout << "tente novamente!" << endl;
            i--;
        }  
        system("cls");
    }
}
/*Essa função sorteia posições de submarinos e hidroaviões com srand(time(NULL)),
gerará números de 0 a 8 para as colunas e linha de submarinos, entretanto,
para hidroaviões ele verifica se existe espaço disponível e só posicionará em definitivo
se obedecer não encostar nas colunas 0 e 7.
Em sua chamada está variàveis globais usadas por outras funções durante o código.*/
void posicionamento_computador(int linha_numerica_computador, int coluna_numerica_computador, string tabuleiro_computador[DIMENSAO][DIMENSAO])
{
    srand(time(NULL));
    //Sorteio de submarino
    for (int i = 0; i < 4; i++)
    {
        linha_numerica_computador  = rand()%8;
        coluna_numerica_computador = rand()%8;
        if (tabuleiro_computador[linha_numerica_computador][coluna_numerica_computador] == "")
        {
            tabuleiro_computador[linha_numerica_computador][coluna_numerica_computador] = " S ";
        }
        else
        {
            i--;
        }
    }

    //Sorteio de posição de hidroavião do computador:
    for (int i = 0; i < 3; i++)
    {
        linha_numerica_computador  = rand()%8;
        coluna_numerica_computador = rand()%8;
        if(coluna_numerica_computador >= 1 && coluna_numerica_computador <= 6)
        {
            if (tabuleiro_computador[linha_numerica_computador][coluna_numerica_computador] == "" &&
            tabuleiro_computador[linha_numerica_computador][coluna_numerica_computador-1] == "" &&
            tabuleiro_computador[linha_numerica_computador][coluna_numerica_computador+1] == "" &&
            tabuleiro_computador[linha_numerica_computador+1][coluna_numerica_computador] == "") 
            {
                tabuleiro_computador[linha_numerica_computador][coluna_numerica_computador] = " H ";
                tabuleiro_computador[linha_numerica_computador][coluna_numerica_computador-1] = " H ";
                tabuleiro_computador[linha_numerica_computador][coluna_numerica_computador+1] = " H ";
                tabuleiro_computador[linha_numerica_computador+1][coluna_numerica_computador] = " H ";
            }
            else
            {
                if (tabuleiro_computador[linha_numerica_computador][coluna_numerica_computador] == "" &&
                tabuleiro_computador[linha_numerica_computador][coluna_numerica_computador-1] == "" &&
                tabuleiro_computador[linha_numerica_computador][coluna_numerica_computador+1] == "" &&
                tabuleiro_computador[linha_numerica_computador-1][coluna_numerica_computador] == "") 
                {
                    tabuleiro_computador[linha_numerica_computador][coluna_numerica_computador] = " H ";
                    tabuleiro_computador[linha_numerica_computador][coluna_numerica_computador-1] = " H ";
                    tabuleiro_computador[linha_numerica_computador][coluna_numerica_computador+1] = " H ";
                    tabuleiro_computador[linha_numerica_computador-1][coluna_numerica_computador] = " H ";
                } 
                else
                {
                    i--;
                }
        }
        }
        else
        {
            i--;
        }
    }
}
/*Esta função tem o objetivo de montar o tabuleiro do jogador durante os momentos da partida;
nela é chamado o registro do tipo Jogador e nomeado como jogador[MEMORIA], no caso essa parte apenas 
chama o nickname informado.*/
void montar_tabuleiro_jogador(Jogador jogador[MEMORIA], int memo, char linha[DIMENSAO], char coluna[DIMENSAO], string tabuleiro[DIMENSAO][DIMENSAO])
{
    cout << endl;
    cout << "_________________________________________________________________________________"<< endl;
    cout << jogador[memo].nome << ":"<< endl;
    cout << endl;
    cout << endl;
    cout << "   ";
    for (int i = 0; i < DIMENSAO; i++)
    {
        cout << coluna[i] << "  ";
    } 
    cout << endl;
    for (int l = 0; l < DIMENSAO; l++)
    {
        cout << linha[l] << " ";  
        for(int c = 0; c < DIMENSAO; c++)
        {
            cout << tabuleiro[l][c]; 
        }  
        cout << endl;
    }

}

void mostrar_tabuleiro_capa(char linha[DIMENSAO], char coluna[DIMENSAO], string tabuleiro[DIMENSAO][DIMENSAO])
{
    cout << "_________________________________________________________________________________"<< endl;
    cout << "Computador:"<< endl;
    cout << endl;
    cout << endl;
    cout << "   ";
    for (int i = 0; i < DIMENSAO; i++)
    {
        cout << coluna[i] << "  ";
    }
    cout << endl;
    for (int l = 0; l < DIMENSAO; l++)
    {
        cout << linha[l] << " ";  
        for(int c = 0; c < DIMENSAO; c++)
        {
            if (tabuleiro[l][c] == "")
            {
                tabuleiro[l][c] = " ~ ";
            }
            cout << tabuleiro[l][c];
        }  
        cout << endl;
    }
    cout << endl;
    cout << endl;
    cout << endl;
}

void ataques_humano(int rodada[MEMORIA], string tabuleiro_capa[DIMENSAO][DIMENSAO], string tabuleiro_computador[DIMENSAO][DIMENSAO], int pontos[MEMORIA], int memo)
{
    int conv_atk;
    int linha_atk;
    char aux_atk;

    cout << "_________________________________________________________________________________"<< endl;
    cout << " RODADA " << rodada[memo] << endl;
    cout << "_________________________________________________________________________________"<< endl;
    cout << "Qual casa deseja atacar?" << endl;
    cout << "Posicao:" << endl;
    cin.get();
    cin >> aux_atk;
    cin >> linha_atk;
    conv_atk = ((int)aux_atk) - 65;
    for (int i = 0; i < 1; i++)
    {
        if (linha_atk >= 1 && linha_atk <= 8)
        {
            if (conv_atk >= 0 && conv_atk <= 7)
            {
                if (tabuleiro_capa[linha_atk - 1][conv_atk] == " S " ||
                    tabuleiro_capa[linha_atk - 1][conv_atk] == " H " ||
                    tabuleiro_capa[linha_atk - 1][conv_atk] == " * ")
                {
                    cout << "Ataque outro quadrante" << endl;
                    i--;
                }
                else
                {
                    if (tabuleiro_computador[linha_atk - 1][conv_atk] == "")
                    {
                        tabuleiro_capa[linha_atk - 1][conv_atk] = " * ";
                        i++;
                    }
                    else
                    {
                        tabuleiro_capa[linha_atk - 1][conv_atk] = tabuleiro_computador[linha_atk - 1][conv_atk];
                        pontos[memo]++;
                    }
                }  
            }
        }
    }
}

void sorteio_ataques_computador(int dificuldade, int ataques_computador, int pontos_computador, int linha_numerica_computador, int coluna_numerica_computador, string tabuleiro_jogador[DIMENSAO][DIMENSAO])
{

    if (dificuldade == 2)
    {
        ataques_computador = 0;
        while (ataques_computador < 2)
        {
            linha_numerica_computador  = rand()%8;
            coluna_numerica_computador = rand()%8;
            if ((tabuleiro_jogador[linha_numerica_computador][coluna_numerica_computador] == " S " )
            || (tabuleiro_jogador[linha_numerica_computador][coluna_numerica_computador] == " H " ))
            {
                tabuleiro_jogador[linha_numerica_computador][coluna_numerica_computador] = " @ ";
                pontos_computador++;
                ataques_computador = ataques_computador + 3;
            }
            else
            {
                tabuleiro_jogador[linha_numerica_computador][coluna_numerica_computador] = " * ";
                ataques_computador++;
            }
        }
    }
    else
    {
        linha_numerica_computador  = rand()%8;
        coluna_numerica_computador = rand()%8;
        if ((tabuleiro_jogador[linha_numerica_computador][coluna_numerica_computador] == " S " )
        || (tabuleiro_jogador[linha_numerica_computador][coluna_numerica_computador] == " H " ))
        {
            tabuleiro_jogador[linha_numerica_computador][coluna_numerica_computador] = " @ ";
            pontos_computador++;
        }
        else
        {
            tabuleiro_jogador[linha_numerica_computador][coluna_numerica_computador] = " * ";
        }
    }
}

int main()
{
    Jogador jogador[MEMORIA];
    char linha_capa[DIMENSAO] = {'1', '2', '3', '4', '5', '6', '7', '8'};           //posição da linha na matriz capa
    char coluna_capa[DIMENSAO] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int linha_atk;                                                                  //variável para linhas a serem atacadas
    int teste_atk;                                                               //conversor de char para int do ataque do jogador
    int dificuldade = 0;                                                            //para o 'if' de dificuldade
    int memo = 0;                                                                   //posição da memória
    int pontos[MEMORIA] = {0};                                                      //pontos armazenados por memoria
    int pontos_computador = 0;                                                      //pontuação do computador
    int rodada[MEMORIA] = {0};                                                      //contador de rodadas
    int pontos_def[MEMORIA] = {0};                                                  //conversor de pontos de rodada (não essencial)
    int linha_numerica_computador = 0;                                              //linha para matriz computador
    int coluna_numerica_computador = 0;  
    char linha_jogador[DIMENSAO] = {'1', '2', '3', '4', '5', '6', '7', '8'};        //posição da linha de jogador
    char coluna_jogador[DIMENSAO] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};       //posição da coluna de jogador
    int linha;                                                                      //variável multípla para linhas
    int aux_conv;                                                                   //conversor do posicionamento do jogador
    int ataques_computador;                                                         //número de ataques do computador, serve para 
    int top1 = INT_MIN;                                                             //valor minimo para não ter problemas no ranking
    char resposta;                                                                  //resposta S ou N se é desejavel continuar
    char aux;                                                                       //auxiliar de posicionamento
    char aux_atk;                                                                   //auxiliar nos ataques
    bool continuar = true;                                                          //verifica se é preciso continuar o programa e exibir a mensagem
    system("color B0");
    //Interface inicial:
    while ((continuar == true) && (memo < MEMORIA))
    {
        ataques_computador = 0;
        bool jogador_1 = false;                                                         //booleano para verificar o jogador com o recorde                                            //booleano para verificar de o humano ganhou
        bool sorteio_verdadeiro = false;                                                //booleano para verificar se o sorteio da casa é válido
        string tabuleiro[DIMENSAO][DIMENSAO] = {""};                                    //inicializando tabuleiro de capa
        string tabuleiro_jogador[DIMENSAO][DIMENSAO] = {""};                            //inicializando tabuleiro do jogador
        string tabuleiro_computador[DIMENSAO][DIMENSAO] = {""};                         //inicializando tabuleiro do computador
        mostrarTitulo();
        cout << endl;
        cout << "Deseja continuar? Se sim digite 'S',\n";
        cout << "caso contrario digite 'N'\n";
        cin >> resposta;
        continuar = testeContinuar(resposta); 

        system("cls");
        //Armazenamento do nome:
        cin.get();
        cout << "Digite um nickname:" << endl;
        getline(cin, jogador[memo].nome);
        system("cls");
        dificuldade = selecionarDificuldade();
        //Posicionamento do submarinos do jogador
        //São 4 submarinos a serem posicionados
        //Apenas mudará a posição para 0 se o número armazenado na posição for diferente,
        //evitando armazenar mais de duas vezes
        for (int i = 0; i < 4; i++)
        {
            mostrar_tabuleiro_jogador(linha_jogador, coluna_jogador, tabuleiro_jogador);
            posicionamento_submarino_jogador(aux, linha, aux_conv, tabuleiro_jogador);
            //Usa as variáveis: aux, linha, auxconv, tabuleiro_jogador
        } 

        
        
         for(int i = 0; i < 3; i++)
        {
            mostrar_tabuleiro_jogador(linha_jogador, coluna_jogador, tabuleiro_jogador);
            posicionamento_hidroaviao_jogador(aux, linha, aux_conv, tabuleiro_jogador);
        }

        // Posicionamento de submarinos e hidroaviões do computador:
        posicionamento_computador(linha_numerica_computador, coluna_numerica_computador, tabuleiro_computador);
        //Partida 
        while (rodada[memo] < 64 && pontos[memo] < 16 && pontos_computador < 16)
        {
            montar_tabuleiro_jogador(jogador, memo, linha_jogador, coluna_jogador, tabuleiro_jogador);
            mostrar_tabuleiro_capa(linha_capa, coluna_capa, tabuleiro);
            //Sistema similar ao de seleção, com switch e if embutido para a confirmação.
            //Sistema bugado  
            ataques_humano(rodada, tabuleiro, tabuleiro_computador, pontos, memo);
            sorteio_ataques_computador(dificuldade, ataques_computador, pontos_computador, linha_numerica_computador, coluna_numerica_computador, tabuleiro_jogador);
            rodada[memo]++;
            pontos_def[memo] = pontos[memo];
            system("cls");
            cout << "_________________________________________________________________________________"<< endl;
            cout << "rodada:" << rodada[memo] << endl;
            cout << "pontos:" << pontos_def[memo] << endl;
            if (dificuldade == 1)
            {
                cout << "dificuldade: normal" << endl;
            }
            else
            {
                cout << "dificuldade: dificil" << endl;
            }
        }
        //Vitória ou derrota
        if ((pontos_computador > pontos[memo]) && (pontos_computador >= 15)) 
        {
            mostrarDerrota();
            break;
        }
        if ((pontos[memo] > pontos_computador) && (pontos[memo] >= 15))
        {
            mostrarVitoria();
            break;
        }
        memo++;    
    }
    cout << "_________________________________________________________________________________"<< endl;
    for (int i = 0; i < memo; i++)
    {
        cout << "_________________________________________________________________________________"<< endl;
        cout << "Sua pontuacao = " << pontos_def[i] << endl;
        cout << "rodada:" << rodada[i] << endl;
    }
    for (int i = 0; i < memo; i++)
    {
        cout << "Rodada " << i << " : " <<  jogador[i].nome << ".................pontos: " << pontos[i] << endl;
    }
    system("pause");
	
    return 0;
}