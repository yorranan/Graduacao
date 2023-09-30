#include <iostream>
#include <fstream>
#include <string>
#define LIMITE 1000

using namespace std;
using std::stoi;


typedef struct
{
    int codigo_perfil_para_livro;
    string isbn_13;
    string isbn_10;
    string nome_lendo;
    int paginas_lendo;
    int ano;
    string idioma;
    string autor;
    string editora;
    int nota;
}
Leitura[LIMITE];

int criar_arquivo()
{
    ofstream arquivo ("arquivo.csv", ios::app);
    if (!arquivo)
    {
        cout << "ERRO na criacao do arquivo" << endl;
        return -1;
    }
    arquivo.close();  
}

int criar_arquivo_txt()
{
    ofstream exportacao ("exportado.txt");
    if (!exportacao)
    {
        cout << "ERRO na criacao do arquivo de exportacao" << endl;
        return -1;
    }
    exportacao.close();  
}

int contador_de_linhas()
{
    string linha;
    int tamanho_linhas = 0;
    ifstream arquivo("arquivo.csv");
        if(!arquivo.is_open()) 
        {
            cout << "O arquivo não pode ser aberto" << endl;
        }
        while (getline(arquivo, linha))
        {
            tamanho_linhas++;
        }
    arquivo.close();

    return tamanho_linhas;
}

void ler_registros(Leitura *livro, int tamanho)
{
    string codigo;
    string isbn13;
    string isbn10;
    string nome_livro;
    string paginas;
    string ano_publicacacao;
    string idioma;
    string autor;
    string nome_editora;
    string nota;
    int posicao = 0;
    ifstream arquivo ("arquivo.csv", ios::in);
    if(!arquivo.is_open()) 
    {
        cout << "Erro ao abrir o arquivo" << endl;
    }

    while(arquivo.peek() != EOF)
    {
    getline(arquivo, codigo,',');
    getline(arquivo, isbn13,',');
    getline(arquivo, isbn10,',');
    getline(arquivo, nome_livro,',');
    getline(arquivo, paginas,',');
    getline(arquivo, ano_publicacacao,',');
    getline(arquivo, idioma,',');
    getline(arquivo, autor,',');
    getline(arquivo, nome_editora,',');
    getline(arquivo, nota);
    livro[posicao]->codigo_perfil_para_livro = stoi(codigo);
    livro[posicao]->isbn_13 = isbn13;
    livro[posicao]->isbn_10 = isbn10;
    livro[posicao]->nome_lendo = nome_livro;
    livro[posicao]->paginas_lendo = stoi(paginas);
    livro[posicao]->ano = stoi(ano_publicacacao);
    livro[posicao]->idioma = idioma;
    livro[posicao]->autor = autor;
    livro[posicao]->editora = nome_editora;
    livro[posicao]->nota = stoi(nota);
    posicao++;
  
  }

}
void salvar_alteracoes(Leitura *livro, int tamanho)
{
    ofstream arquivo ("arquivo.csv", ios::out);
    for (int i = 0; i < tamanho; i++)
    {
        arquivo << livro[i]->codigo_perfil_para_livro << ','
            << livro[i]->isbn_13 << ','
            << livro[i]->isbn_10 << ','
            << livro[i]->nome_lendo << ','
            << livro[i]->paginas_lendo << ','
            << livro[i]->ano << ','
            << livro[i]->idioma << ','
            << livro[i]->autor << ','
            << livro[i]->editora << ','
            << livro[i]->nota << endl;
    }
    arquivo.close();
}  

void mostrar_registros(Leitura *livro, int tamanho)
{ 
    ifstream arquivo ("arquivo.csv", ios::in);
    if(!arquivo.is_open()) 
    {
        cout << "Erro ao abrir o arquivo" << endl;
    }
    cout << "Codigo ISBN 13    ISBN 10    Nome    Paginas   Ano    Idioma    Editora     Nota " << endl;
    for (int i = 0; i < tamanho; i++)
    {
        cout << livro[i]->codigo_perfil_para_livro << "  ";
        cout << livro[i]->isbn_13 << "  ";
        cout << livro[i]->isbn_10 << "  ";
        cout << livro[i]->nome_lendo << "  ";
        cout << livro[i]->paginas_lendo << "  ";
        cout << livro[i]->ano << "  ";
        cout << livro[i]->idioma << "  ";
        cout << livro[i]->autor << "  ";
        cout << livro[i]->editora << "  ";
        cout << livro[i]->nota << endl;
    }
}

void incluir_registro(Leitura *livro, int tamanho)
{
    string codigo;
    string isbn13;
    string isbn10;
    string nome_livro;
    string paginas;
    string ano_publicacacao;
    string idioma;
    string autor;
    string nome_editora;
    string nota;
    ofstream arquivo ("arquivo.csv", ios::app | ios::out);
    if(!arquivo)
    {
        cout << "falha ao abrir o arquivo!" << endl;
    }
    cout << "Digite o ISBN 13: " << endl;
    cin >> isbn13;
    cout << "Digite o ISBN 10: " << endl;
    cin >> isbn10;
    cout << "Digite o nome do livro: " << endl;
    cin.clear();
    cin.ignore();
    getline(cin, nome_livro);
    cout << "Digite o numero de paginas do livro: " << endl;
    cin >> paginas;
    cout << "Digite o ano de publicacao: " << endl; 
    cin >> ano_publicacacao;
    cout << "Digite o idioma (PT = portugues, EN = ingles, ES = espanhol): " << endl;
    cin >> idioma;
    cout << "Digite o nome do autor: "<< endl;
    cin.clear();
    cin.ignore();
    getline(cin, autor);
    cout << "Digite o nome da editora: " << endl;
    cin.clear();
    getline(cin, nome_editora);
    cin.clear();
    cout << "Digite sua nota de 0 a 10: " << endl;
    cin >> nota;
    codigo = to_string(contador_de_linhas()+1);
    arquivo << codigo << ',' << isbn13 << ',' << isbn10 << ',' << nome_livro << ',' << paginas << ',' << ano_publicacacao << ','
    << idioma << ',' << autor << ',' << nome_editora << ',' << nota << endl;
    ler_registros(livro, tamanho);
    arquivo.close();
}

int buscar_isbn_13(Leitura *livro, int tamanho, string isbn_13)
{
    for (int i = 0; i < tamanho; i++)
    {
        if(livro[i]->isbn_13 == isbn_13)
        {
            return i;
        }
    }
    cout << "Livro não encontrado" << endl;
    return 1;
}

void mostrar_pesquisa(Leitura *livro, int tamanho)
{  
    string isbn_13;
    cout << "Digite o isbn 13 do livro que deseja pesquisar:" << endl;
    cin >> isbn_13;
    int posicao = buscar_isbn_13(livro, tamanho, isbn_13);
    cout << "ISBN 13    ISBN 10    Nome    Paginas   Ano    Idioma    Editora     Nota " << endl;
    cout << livro[posicao]->codigo_perfil_para_livro << "  ";
    cout << livro[posicao]->isbn_13 << "  ";
    cout << livro[posicao]->isbn_10 << "  ";
    cout << livro[posicao]->nome_lendo << "  ";
    cout << livro[posicao]->paginas_lendo << "  ";
    cout << livro[posicao]->ano << "  ";
    cout << livro[posicao]->idioma << "  ";
    cout << livro[posicao]->autor << "  ";
    cout << livro[posicao]->editora << "  ";
    cout << livro[posicao]->nota << endl;
}

int alterar_item(Leitura *livro, int tamanho)
{
    int opcao, indice; 
    string busca, alteracao;
    cout << "Qual o ISBN 13 do livro que deseja alterar?" << endl;
    cin >> busca;
    indice = buscar_isbn_13(livro, tamanho, busca);
    cout << "O que deseja alterar? (Digite o numero correspondente" << endl;
    cout << "1) ISBN 13" << endl;
    cout << "2) ISBN 10" << endl;
    cout << "3) Nome do livro" << endl;
    cout << "4) Paginas" << endl;
    cout << "5) Ano de publicacao" << endl;
    cout << "6) Idioma" << endl;
    cout << "7) Autor" << endl;
    cout << "8) Editora" << endl;
    cout << "9) Nota" << endl;
    cin >> opcao;
    cout << "Qual o novo valor para o item?" << endl;
    cin.ignore();
    getline(cin, alteracao);
    switch (opcao)
    {
    case 1:
        livro[indice]->isbn_13 = alteracao;
        salvar_alteracoes(livro, tamanho);
        break;
    case 2:
        livro[indice]->isbn_10 = alteracao;
        salvar_alteracoes(livro, tamanho);
        break;
    case 3:
        livro[indice]->nome_lendo = alteracao;
        salvar_alteracoes(livro, tamanho);
        break;
    case 4:
        livro[indice]->paginas_lendo = stoi(alteracao);
        salvar_alteracoes(livro, tamanho);
        break;
    case 5:
        livro[indice]->ano = stoi(alteracao);
        salvar_alteracoes(livro, tamanho);
        break;
    case 6:
        livro[indice]->idioma = alteracao;
        salvar_alteracoes(livro, tamanho);
        break;
    case 7:
        livro[indice]->autor = alteracao;
        salvar_alteracoes(livro, tamanho);
        break;
    case 8:
        livro[indice]->editora = alteracao;
        salvar_alteracoes(livro, tamanho);
        break;
    case 9:
        livro[indice]->nota = stoi(alteracao);
        salvar_alteracoes(livro, tamanho);
        break;
    default:
        return -1;
        break;
    }
    salvar_alteracoes(livro, tamanho);
    return 0;
}

void exportar_txt(Leitura *arquivos, int tamanho)
{
    criar_arquivo_txt();
    ofstream exportacao("exportado.txt", ios::out);
    if(!exportacao.is_open())
    {
        cout << "Erro ao abrir arquivo para exportar" << endl;
    }
    exportacao << " CODIGO ISBN 13    ISBN 10    PAGINAS    NOME    ANO DE PUBLICACAO    IDIOMA    AUTOR    EDITORA   NOTA " << endl;    
    for (int i = 0; i < tamanho; i++)
    {
        exportacao << arquivos[i]->codigo_perfil_para_livro << "    "
            << arquivos[i]->isbn_13 << "    "
            << arquivos[i]->isbn_10 << "    "
            << arquivos[i]->nome_lendo << "    "
            << arquivos[i]->paginas_lendo << "    " 
            << arquivos[i]->nome_lendo << "    " 
            << arquivos[i]->ano << "    " 
            << arquivos[i]->idioma << "    " 
            << arquivos[i]->autor << "    " 
            << arquivos[i]->editora << "    " 
            << arquivos[i]->nota << endl;
    }
    
}

int troca(Leitura *livro_a, Leitura *livro_b, int j, int k)
{
    int codigo_perfil_para_livro = livro_a[j]->codigo_perfil_para_livro;
    string isbn_13 = livro_a[j]->isbn_13;
    string isbn_10 = livro_a[j]->isbn_10;
    string nome_lendo = livro_a[j]->nome_lendo;
    int paginas_lendo = livro_a[j]->paginas_lendo;
    int ano = livro_a[j]->ano;
    string idioma = livro_a[j]->idioma;
    string autor = livro_a[j]->autor;
    string editora = livro_a[j]->editora;
    int nota = livro_a[j]->nota;
    livro_a[j]->codigo_perfil_para_livro = livro_b[k]->codigo_perfil_para_livro;
    livro_a[j]->isbn_13 = livro_b[k]->isbn_13;
    livro_a[j]->isbn_10 = livro_b[k]->isbn_10;
    livro_a[j]->nome_lendo = livro_b[k]->nome_lendo;
    livro_a[j]->paginas_lendo = livro_b[k]->paginas_lendo;
    livro_a[j]->ano = livro_b[k]->ano;
    livro_a[j]->idioma = livro_b[k]->idioma;
    livro_a[j]->editora = livro_b[k]->editora;
    livro_a[j]->nota = livro_b[k]->nota;
    livro_b[k]->codigo_perfil_para_livro = codigo_perfil_para_livro;
    livro_b[k]->isbn_13 = isbn_13;
    livro_b[k]->isbn_10 = isbn_10;
    livro_b[k]->nome_lendo = nome_lendo;
    livro_b[k]->paginas_lendo = paginas_lendo;
    livro_b[k]->ano = ano;
    livro_b[k]->idioma = idioma;
    livro_b[k]->autor = autor;
    livro_b[k]->editora = editora;
    livro_b[k]->nota = nota;
}

void apagar_registro(Leitura *registro, int indice)
{
    registro[indice]->codigo_perfil_para_livro = 0;
    registro[indice]->isbn_13 = '\0';
    registro[indice]->isbn_10 = '\0';
    registro[indice]->nome_lendo = '\0';
    registro[indice]->paginas_lendo = 0;
    registro[indice]->ano = 0;
    registro[indice]->idioma = '\0';
    registro[indice]->autor = '\0';
    registro[indice]->editora = '\0';
    registro[indice]->nota = 0;
}

void ordenar_arquivos(Leitura *livros, int tamanho)
{
    int i = tamanho-1, j;
    for(i; i > 0; i--)
    {
        for(j = 0; j < i; j++)
        {
            if(livros[j]->codigo_perfil_para_livro > livros[j+1]->codigo_perfil_para_livro)
            {
                troca(livros, livros, j, j+1);
            }
        }
    }
    salvar_alteracoes(livros, tamanho);
}

int verificacao_de_integridade(Leitura *livros, int tamanho)
{
    cout << "Atencao! O aplicativo sera fechado apos a operacao. Continuar? (S/N)" << endl;
    int i = tamanho-1, j;
    for(i; i > 0; i--)
    {
        for(j = 0; j < i; j++)
        {
            if(livros[j]->codigo_perfil_para_livro == livros[j+1]->codigo_perfil_para_livro)
            {
                apagar_registro(livros, j+1);
            }
        }
    }
    salvar_alteracoes(livros, tamanho);
  
}

void excluir_arquivo(Leitura *livro, int tamanho)
{
    delete[] livro;
    salvar_alteracoes(livro, tamanho);
}

int menu(Leitura *livro, int tamanho)
{
    int selecao;
    cout << "1) Incluir Registro" << endl;
    cout << "2) Buscar Leitura" << endl;
    cout << "3) Editar Leitura" << endl;
    cout << "4) Mostrar Registro" << endl;
    cout << "5) Exportar para .txt" << endl;
    cout << "6) Excluir este arquivo" << endl;
    cout << "7) Ordenar arquivos" << endl;
    cout << "8) Verificar integridade" << endl;
    cout << "9) Fechar programa" << endl;
    cin >> selecao;
    switch (selecao)
    {
    case 1:
        incluir_registro(livro, tamanho);
        break;
    case 2:
        mostrar_pesquisa(livro, tamanho);
        break;
    case 3:
        alterar_item(livro, tamanho);
        cout << "Item alterado com suceso!" << endl;
        break;
    case 4:
        mostrar_registros(livro, tamanho);
        break;
    case 5:
        exportar_txt(livro, tamanho);
        cout << "arquivo exportado!" << endl;
        break;
    case 6:
        excluir_arquivo(livro, tamanho);
        cout << "Arquivo excluido!" << endl;
        break;
    case 7:
        ordenar_arquivos(livro, tamanho);
        cout << "Ordenacao realizada!" << endl;
        break;
    case 8:
        verificacao_de_integridade(livro, tamanho);
    case 9:
        return EOF;
        break;
    default:
        return -1;
        break;
    }
}

int main()
{
    Leitura *livro;
    int tamanho = contador_de_linhas();
    livro =  new (nothrow) Leitura[tamanho];
    criar_arquivo();
    ler_registros(livro, tamanho);
    while(menu(livro, tamanho) != EOF){}
    return 0;
}