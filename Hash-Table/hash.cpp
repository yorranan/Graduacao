#include <iostream>
#include <vector>
#include <string>
#include <ctime>
// Insere bibliotecas diferentes dependendo do sistema operacional
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#define MAX_NUMBER 1000

using namespace std;

// Definir o tamanho da tabela hash
const int TABLE_SIZE = 10;

// Definir uma estrutura para cada elemento da tabela hash
struct HashNode
{
    int value;
    HashNode(int v) : value(v) {}
};

// Definir a tabela hash como um vetor de listas
vector<HashNode> table[TABLE_SIZE];

// Função hash simples que retorna um índice baseado no valor
int hashFunc(int value)
{
    return value % TABLE_SIZE;
}

// Função para inserir um valor na tabela hash
void insert(int value)
{
    int index = hashFunc(value);
    table[index].push_back(HashNode(value));
}

// Função para buscar um valor na tabela hash
string search(int value)
{
    int index = hashFunc(value);
    for (int i = 0; i < table[index].size(); i++)
    {
        if (table[index][i].value == value)
        {
            return "Valor encontrado.";
        }
    }
    return "Valor nao encontrado.";
}

// Função para deletar um valor da tabela hash
void remove(int value)
{
    int index = hashFunc(value);
    for (int i = 0; i < table[index].size(); i++)
    {
        if (table[index][i].value == value)
        {
            table[index].erase(table[index].begin() + i);
            return;
        }
    }
}

// Função que insere números pseudoaleatórios de 0 a 1000 na tabela
void automatizeInserts(int count)
{
    srand(time(NULL));
    for (int i = 0; i < count; i++)
    {
        insert(rand() % MAX_NUMBER);
    }
}

// Função para imprimir a tabela hash
void printTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        cout << "Indice " << i << ": ";
        for (int j = 0; j < table[i].size(); j++)
        {
            cout << "[" << table[i][j].value << "]";
        }
        cout << endl;
    }
}

// Função principal que mostra um menu com as opções disponíveis
int main()
{
    int op;
    int value;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Inserir valor\n";
        cout << "2. Buscar valor\n";
        cout << "3. Deletar valor\n";
        cout << "4. Imprimir tabela hash\n";
        cout << "5. Inserir numeros automaticamente\n";
        cout << "6. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> op;

        switch (op)
        {
        case 1:
            cout << "Digite o valor: ";
            cin >> value;
            insert(value);
            break;
        case 2:
            cout << "Digite o valor: ";
            cin >> value;
            cout << search(value) << endl;
            break;
        case 3:
            cout << "Digite o valor: ";
            cin >> value;
            remove(value);
            break;
        case 4:
            printTable();
            break;
        case 5:
            cout << "Digite a quantidade de números a ser adicionada: ";
            cin >> value;
            automatizeInserts(value);
            break;
        case 6:
            cout << "Saindo..." << endl;
            sleep(2);
            cout << "See you later" << endl;
            break;
        default:
            cout << "Opcao invalida!" << endl;
        }

              
    } while (op != 6);

    return 0;
}
