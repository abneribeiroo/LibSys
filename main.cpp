#include <iostream>
#include "include/menu.h"
#include "include/Biblioteca.h"
#include "include/LivroCientifico.h"

Biblioteca *g_Bib = nullptr;

int main()
{
    cout << "\t\tBiblioteca-ESTGV!\n";

    g_Bib = new Biblioteca();
    g_Bib->LoadFile_Livros("./database/livros.txt");
    g_Bib->LoadFile_Livros_Leitores("./database/leitores.txt");
    g_Bib->LoadFile_Emprestimos("./database/emprestimos.txt");
    g_Bib->GerarMultas();

    int option;
    do
    {
        cout << "\n #----------------------------------------------------------------#";
        cout << "\n | (1) Gerir livros                                               |";
        cout << "\n | (2) Gerir Requisitantes                                        |";
        cout << "\n | (3) Gerir Requisições                                          |";
        cout << "\n | (4) Opções Avançadas                                           |";
        cout << "\n | (5) Sair                                                       |";
        cout << "\n | (0) Salvar e Sair                                              |";
        cout << "\n #----------------------------------------------------------------#";
        cout << "\nQual a sua opcao: ";
        cin >> option;

        switch (option)
        {
        case 1:
            MenuLivros();
            break;
        case 2:
            MenuRequisitantes();
            break;
        case 3:
            MenuRequisicoes();
            break;
        case 4:
        {
            MenuAvancado();
            break;
        }
        case 5:
        {
            cout << "\n\n ***** Saindo *****\n";
            break;
        }
        case 0:
            g_Bib->SaveToFile_Livros("./database/livros.txt");
            g_Bib->salvarEmprestimos("./database/emprestimos.txt");
            cout << "\n\n ***** Salvando os dados *****\n";
            cout << " ***** Saindo do programa *****\n";
            break;
        }
    } while (option != 0 && option != 5);

    return 0;
}
