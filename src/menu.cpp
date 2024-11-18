#include "../include/menu.h"
#include "../include/Biblioteca.h"
#include "../include/LivroCientifico.h"
#include "../include/LivroFiccao.h"
#include "../include/LivroEducativo.h"
#include "../include/Revista.h"
#include "../include/Jornal.h"
#include "../include/Geral.h"
#include "../include/Biblioteca.h"
#include "../include/Uteis.h"
#include <iostream>
#include <string>

using namespace std;

Uteis *uteis = new Uteis();

Biblioteca *Bib = new Biblioteca();

void adicionarLivro() {
    int tipo;
    string titulo, autor, areaPesquisa, editor;
    int anoPublicacao, edicao;

    // Apresenta as opções de tipo de livro
    cout << "Selecione o tipo de livro para adicionar:" << endl;
    cout << "1. Livro Científico" << endl;
    cout << "2. Livro de Ficção" << endl;
    cout << "3. Livro Educativo" << endl;
    cout << "4. Revista" << endl;
    cout << "5. Jornal" << endl;
    cout << "Escolha: ";
    cin >> tipo;
    cin.ignore(); // Limpa o buffer do teclado

    // Coleta informações comuns a todos os livros
    cout << "Digite o título: ";
    getline(cin, titulo);
    cout << "Digite o autor: ";
    getline(cin, autor);
    cout << "Digite o ano de publicação: ";
    cin >> anoPublicacao;
    cin.ignore(); // Limpa o buffer

    Geral* novoLivro = nullptr;

    // Criação do livro com base no tipo
    switch (tipo) {
    case 1: // Livro Científico
        cout << "Digite a área de pesquisa: ";
        getline(cin, areaPesquisa);
        novoLivro = new LivroCientifico(titulo, autor, anoPublicacao, areaPesquisa);
        break;
    case 2: // Livro de Ficção
        novoLivro = new LivroFiccao(titulo, autor, anoPublicacao, "Ficção");
        break;
    case 3: // Livro Educativo
        cout << "Digite a edição: ";
        cin >> edicao;
        cin.ignore();
        novoLivro = new LivroEducativo(titulo, autor, anoPublicacao, "Ensino Básico");
        break;
    case 4: // Revista
        cout << "Digite o editor: ";
        getline(cin, editor);
        novoLivro = new Revista(titulo, autor, anoPublicacao, 1);
        break;
    case 5: // Jornal
        cout << "Digite o editor: ";
        getline(cin, editor);
        novoLivro = new Jornal(titulo, autor, anoPublicacao,"12-10-2024", editor);
        break;
    default:
        cout << "Tipo inválido!" << endl;
        return;
    }

    // Adiciona o livro à biblioteca
    if (novoLivro) {
        //Escrever BIB
        Bib->Add_Livros(novoLivro);
        cout << "Livro adicionado com sucesso!" << endl;
    } else {
        cout << "Erro ao criar o livro!" << endl;
    }
}


void MenuLivros()
{
    int option;
    do
    {
        uteis->clearScreen();

        cout << "\n #-------------------------------------------------------------#";
        cout << "\n | (1) Adicionar livros                                        |";
        cout << "\n | (2) Remover livros                                          |";
        cout << "\n | (3) Editar livros                                           |";
        cout << "\n | (4) Listar livros (menu)                                    |";
        cout << "\n | (0) Voltar                                                  |";
        cout << "\n #-------------------------------------------------------------#";
        cout << "\nQual a sua opcao: ";
        cin >> option;

        uteis->clearScreen();
        switch (option)
        {
        case 1:
        {
            adicionarLivro();
            // Geral *livro1 = new LivroCientifico("Fisica Quantica", "Einstein", 1935, "Fisica");
            // BIB->Add_Livros(livro1);
            // BIB->Listagem_Livros();
            break;
        }
        case 2:

            break;
        case 3:

            break;
        case 4:
        {
            MenuListarLivros();
            break;
        }
        case 5:
        {
            break;
        }
        }
    } while (option != 0);
}

void MenuListarLivros()
{
    int option;
    do
    {
        // uteis->clearScreen();

        cout << "\n #-------------------------------------------------------------#";
        cout << "\n | (1) Listar livros por categoria                             |";
        cout << "\n | (2) Listar livros agrupados por categoria                   |";
        cout << "\n | (0) Voltar                                                  |";
        cout << "\n #-------------------------------------------------------------#";
        cout << "\nQual a sua opcao: ";
        cin >> option;

        uteis->clearScreen();
        switch (option)
        {
        case 1:
        {
            Bib->Listagem_Livros();
            break;
        }
        case 2:

            break;
        }
    } while (option != 0);
    MenuLivros();
}

void MenuRequisitantes()
{
    int option;
    do
    {
        uteis->clearScreen();

        cout << "\n | ---------------------REQUISITANTES-----------------------------|";
        cout << "\n | (1) Adicionar requisitantes                                    |";
        cout << "\n | (2) Editar requisitante                                        |";
        cout << "\n | (3) Remover requisitante                                       |";
        cout << "\n | (4) Listar requisitante                                        |";
        cout << "\n | (0) SAIR                                                       |";
        cout << "\n #----------------------------------------------------------------#";
        cout << "\nQual a sua opcao: ";
        cin >> option;

        uteis->clearScreen();

        switch (option)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            MenuListarRequisitantes();
            break;
        }

    } while (option != 0);
}

void MenuListarRequisitantes()
{
    int option;
    do
    {
        uteis->clearScreen();
        cout << "\n | ---------------------REQUISITANTES-----------------------------|";
        cout << "\n | (1) Listar requisitantes com livros em atraso                  |";
        cout << "\n | (2) Listar requisitante por categoria                          |";
        cout << "\n | (0) SAIR                                                       |";
        cout << "\n #----------------------------------------------------------------#";
        cout << "\nQual a sua opcao: ";
        cin >> option;

        uteis->clearScreen();
        switch (option)
        {
        case 1:
            break;
        case 2:
            break;
        }
    } while (option != 0);
    MenuRequisitantes();
}

void MenuRequisicoes()
{
    int option;
    do
    {
        uteis->clearScreen();

        cout << "\n #----------------------------------------------------------------#";
        cout << "\n | (1) Requisitar Livro (sistema de reserva*)                     |";
        cout << "\n | (2) Devolver livro (E controle de multas)                      |";
        cout << "\n | (3) Listar Requisições(menu)                                   |";
        cout << "\n | (4) Prorrogar Empréstimos(Estudantes e Professores)            |";
        cout << "\n | (0) SAIR                                                       |";
        cout << "\n #----------------------------------------------------------------#";
        cout << "\nQual a sua opcao: ";
        cin >> option;

        uteis->clearScreen();
        switch (option)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            MenuListarRequisicoes();
            break;
        case 4:
            break;
        }
    } while (option != 0);
}

void MenuListarRequisicoes()
{
    int option;
    do
    {
        uteis->clearScreen();

        cout << "\n #----------------------------------------------------------------#";
        cout << "\n | (1) Listar Livros Requisitados de um leitor                    |";
        cout << "\n | (2) Listar Livros Requisitados de todos leitores               |";
        cout << "\n | (3) Listar multas pendentes                                    |";
        cout << "\n | (0) SAIR                                                       |";
        cout << "\n #----------------------------------------------------------------#";
        cout << "\nQual a sua opcao: ";
        cin >> option;

        uteis->clearScreen();

        switch (option)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        }
    } while (option != 0);
    MenuRequisicoes();
}

void MenuAvancado()
{
    int option;
    do
    {
        uteis->clearScreen();

        cout << "\n #----------------------------------------------------------------#";
        cout << "\n | (1) Gravar num dado ficheiro (introduzido pelo utilizador)     |";
        cout << "\n | (2) Ler de um ficheiro                                         |";
        cout << "\n | (3) Relátorio de otimização                                    |";
        cout << "\n | (0) SAIR                                                       |";
        cout << "\n #----------------------------------------------------------------#";
        cout << "\nQual a sua opcao: ";
        cin >> option;

        uteis->clearScreen();

        switch (option)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        }
    } while (option != 0);
}
