#include <iostream>
#include "include/menu.h"
#include "include/Biblioteca.h"

int main() {
   cout << "\t\tBiblioteca-ESTGV!\n";

    int option;
    do {
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

        switch (option) {
            case 1:
                MenuLivros();
                break;
            case 2:
                MenuRequisitantes();
                break;
            case 3:
                MenuRequisicoes();
                break;
            case 4: {
                MenuAvancado();
                break;
            }
            case 5: {
                break;
            }
            case 0:
                cout << "\n\n ***** Salvando os dados *****\n";
                cout << " ***** Saindo do programa *****\n";
                break;
        }
    } while (option != 0);

    return 0; 


}


// int main()
// {
//     cout << "Hello world! Código funcionando" << endl;
//   //  Biblioteca *BIB = new Biblioteca();


//     // BIB->LoadFile("dados.txt");


//     return 0;
// }