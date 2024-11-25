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

extern Biblioteca *g_Bib;




void MenuLivros()
{
    int option;
    do
    {
        // Uteis::clearScreen();

        cout << "\n #-------------------------------------------------------------#";
        cout << "\n | (1) Adicionar livros                                        |";
        cout << "\n | (2) Remover livros                                          |";
        cout << "\n | (3) Editar livros                                           |";
        cout << "\n | (4) Listar livros (menu)                                    |";
        cout << "\n | (0) Voltar                                                  |";
        cout << "\n #-------------------------------------------------------------#";
        cout << "\nQual a sua opcao: ";
        cin >> option;

        // Uteis::clearScreen();
        string isbn;
        switch (option)
        {
        case 1:
        {
            g_Bib->registrarNovoLivro();

            break;
        }
        case 2:
            cout << "Digite o ISBN do livro a remover: ";
            cin >> isbn;
            if (g_Bib->Remove_Livro(isbn))
            {
                cout << "Livro removido com sucesso!" << endl;
            }
            else
            {
                cout << "Livro não encontrado." << endl;
            }
            break;
        case 3:
            cout << "Digite o ISBN do livro a editar: ";
            cin >> isbn;
            g_Bib->Editar_Livro(isbn);
            break;
        case 4:
        {
            MenuListarLivros();
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
        // Uteis::clearScreen();

        cout << "\n #-------------------------------------------------------------#";
        cout << "\n | (1) Listar livros por categoria                             |";
        cout << "\n | (2) Listar livros agrupados por categoria                   |";
        cout << "\n | (3) Buscar livro                                            |";
        cout << "\n | (0) Voltar                                                  |";
        cout << "\n #-------------------------------------------------------------#";
        cout << "\nQual a sua opcao: ";
        cin >> option;

       // Uteis::clearScreen();
        Uteis::clearScreen();
        switch (option)
        {
        case 1:
        {
            g_Bib->Listagem_Livros();
            break;
        }
        case 2:

            break;
        case 3:
            break;
            // cout << "Digite o ISBN do livro a buscar: ";
            // cin >> isbn;
            // {
            //     Geral* livro = g_Bib->Buscar_Livro(isbn);
            //     if (livro) {
            //         livro->mostrarInfo();
            //     } else {
            //         cout << "Livro não encontrado." << endl;
            //     }
        }

    } while (option != 0);
}

void MenuRequisitantes()
{
    int option;
    do
    {
        //Uteis::clearScreen();

        cout << "\n | ---------------------REQUISITANTES-----------------------------|";
        cout << "\n | (1) Adicionar requisitantes                                    |";
        cout << "\n | (2) Editar requisitante                                        |";
        cout << "\n | (3) Remover requisitante                                       |";
        cout << "\n | (4) Listar requisitante                                        |";
        cout << "\n | (0) SAIR                                                       |";
        cout << "\n #----------------------------------------------------------------#";
        cout << "\nQual a sua opcao: ";
        cin >> option;

       // Uteis::clearScreen();

        switch (option)
        {
        case 1:
            g_Bib->registarLeitor();
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
};

void MenuListarRequisitantes()
{
    int option;
    do
    {
       // Uteis::clearScreen();
        cout << "\n | ---------------------REQUISITANTES-----------------------------|";
        cout << "\n | (1) Listar requisitantes com livros em atraso                  |";
        cout << "\n | (2) Listar requisitante por categoria                          |";
        cout << "\n | (0) SAIR                                                       |";
        cout << "\n #----------------------------------------------------------------#";
        cout << "\nQual a sua opcao: ";
        cin >> option;

        //Uteis::clearScreen();
        switch (option)
        {
        case 1:
            break;
        case 2:
            g_Bib->Listagem_Leitores();
            break;
        }
    } while (option != 0);
}

void MenuRequisicoes()
{
    int option;
    do
    {
        Uteis::clearScreen();

        cout << "\n #----------------------------------------------------------------#";
        cout << "\n | (1) Requisitar Livro (sistema de reserva*)                     |";
        cout << "\n | (2) Devolver livro (E controle de multas)                      |";
        cout << "\n | (3) Listar Requisições(menu)                                   |";
        cout << "\n | (4) Prorrogar Empréstimos(Estudantes e Professores)            |";
        cout << "\n | (0) SAIR                                                       |";
        cout << "\n #----------------------------------------------------------------#";
        cout << "\nQual a sua opcao: ";
        cin >> option;

        Uteis::clearScreen();
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
        Uteis::clearScreen();

        cout << "\n #----------------------------------------------------------------#";
        cout << "\n | (1) Listar Livros Requisitados de um leitor                    |";
        cout << "\n | (2) Listar Livros Requisitados de todos leitores               |";
        cout << "\n | (3) Listar multas pendentes                                    |";
        cout << "\n | (0) SAIR                                                       |";
        cout << "\n #----------------------------------------------------------------#";
        cout << "\nQual a sua opcao: ";
        cin >> option;

        Uteis::clearScreen();

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

void MenuAvancado()
{
    int option;
    do
    {
        Uteis::clearScreen();

        cout << "\n #----------------------------------------------------------------#";
        cout << "\n | (1) Gravar num dado ficheiro (introduzido pelo utilizador)     |";
        cout << "\n | (2) Ler de um ficheiro                                         |";
        cout << "\n | (3) Relátorio de otimização                                    |";
        cout << "\n | (0) SAIR                                                       |";
        cout << "\n #----------------------------------------------------------------#";
        cout << "\nQual a sua opcao: ";
        cin >> option;

        Uteis::clearScreen();

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
