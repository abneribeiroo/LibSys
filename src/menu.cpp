#include "../include/menu.h"
#include "../include/Uteis.h"
#include <iostream>
#include <string>

using namespace std;

Uteis *uteis = new Uteis();

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
        uteis->clearScreen();

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