#include <iostream>
#include "include/menu.h"
#include "include/Library.h"
#include "include/ScientificBook.h"

Library *g_Bib = nullptr;

int main()
{
    cout << "\n\t\tWelcome to the Library System!\n";

    g_Bib = new Library();
    g_Bib->LoadFile_Books("./database/books.txt");
    g_Bib->LoadFile_Readers("./database/readers.txt");
    g_Bib->LoadFile_Loans("./database/loans.txt");
    g_Bib->GenerateFines();

    int option;
    do
    {
        cout << "\n #----------------------------------------------------------------#";
        cout << "\n | (1) Manage Books                                               |";
        cout << "\n | (2) Manage Readers                                             |";
        cout << "\n | (3) Manage Loans                                               |";
        cout << "\n | (4) Advanced Options                                           |";
        cout << "\n | (5) Exit                                                       |";
        cout << "\n | (0) Save and Exit                                              |";
        cout << "\n #----------------------------------------------------------------#";
        cout << "\nWhat is your option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            BooksMenu();
            break;
        case 2:
            RequestersMenu();
            break;
        case 3:
            RequestsMenu();
            break;
        case 4:
        {
            AdvancedMenu();
            break;
        }
        case 5:
        {
            cout << "\n\n ***** Exiting *****\n";
            break;
        }
        case 0:
            g_Bib->SaveToFile_Books("./Database/books.txt");
            g_Bib->SaveToFile_Loans("./Database/loans.txt");
            cout << "\n\n ***** Saving data *****\n";
            cout << " ***** Exiting the program *****\n";
            break;
        }
    } while (option != 0 && option != 5);

    return 0;
}
