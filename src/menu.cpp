#include "../include/menu.h"
#include "../include/Library.h"
#include "../include/ScientificBook.h"
#include "../include/FictionBook.h"
#include "../include/EducationalBook.h"
#include "../include/Magazine.h"
#include "../include/Newspaper.h"
#include "../include/General.h"
#include "../include/Utils.h"
#include <iostream>
#include <string>

using namespace std;

extern Library *g_Bib;

void BooksMenu()
{
    int option;
    do
    {
        // Utils::clearScreen();

        cout << "\n #-------------------------------------------------------------#";
        cout << "\n | (1) Add books                                               |";
        cout << "\n | (2) Remove books                                            |";
        cout << "\n | (3) Edit books                                              |";
        cout << "\n | (4) List books (menu)                                       |";
        cout << "\n | (0) Back                                                    |";
        cout << "\n #-------------------------------------------------------------#";
        cout << "\nWhat is your option: ";
        cin >> option;

        // Utils::clearScreen();
        string id;
        switch (option)
        {
        case 1:
        {
            g_Bib->registerNewBook();
            break;
        }
        case 2:
            cout << "Enter the ID of the book to remove: ";
            cin >> id;
            if (g_Bib->RemoveBook(id))
            {
                cout << "Book removed successfully!" << endl;
            }
            else
            {
                cout << "Book not found." << endl;
            }
            break;
        case 3:
            cout << "Enter the ID of the book to edit: ";
            cin >> id;
            g_Bib->EditBook(id);
            break;
        case 4:
        {
            ListBooksMenu();
            break;
        }
        }
    } while (option != 0);
}

void ListBooksMenu()
{
    int option;
    string ID;
    do
    {

        cout << "\n #-------------------------------------------------------------#";
        cout << "\n | (1) List books by category                                  |";
        cout << "\n | (2) List books grouped by category                          |";
        cout << "\n | (3) Search book                                             |";
        cout << "\n | (0) Back                                                    |";
        cout << "\n #-------------------------------------------------------------#";
        cout << "\nWhat is your option: ";
        cin >> option;

        Utils::clearScreen();
        switch (option)
        {
        case 1:
            g_Bib->ListAllBooks();
            break;
        case 2:
            g_Bib->ReportByCategory(); // Replace "category" with the actual category if needed
            break;
        case 3:
            cout << "Enter the ID of the book to search: ";
            cin >> ID;

            General *book = g_Bib->FindBook(ID);
            if (book)
                book->showInfo();
            else
                cout << "Book not found." << endl;
            break;
        }
    } while (option != 0);
}

void RequestersMenu()
{
    int option, ID;
    do
    {
        // Utils::clearScreen();

        cout << "\n | ---------------------READERS-------------------------------|";
        cout << "\n | (1) Add readers                                            |";
        cout << "\n | (2) Edit reader                                            |";
        cout << "\n | (3) Remove reader                                          |";
        cout << "\n | (4) List readers                                           |";
        cout << "\n | (0) EXIT                                                   |";
        cout << "\n #------------------------------------------------------------#";
        cout << "\nWhat is your option: ";
        cin >> option;


        switch (option)
        {
        case 1:
            g_Bib->RegisterReader();
            break;
        case 2:
            cout << "Enter the ID to update: ";
            cin >> ID;
            g_Bib->EditReader(ID);
            break;
        case 3:
            cout << "Enter the ID to remove: ";
            cin >> ID;
            g_Bib->RemoveReader(ID);
            break;
        case 4:
            ListRequestersMenu();
            break;
        }

    } while (option != 0);
}

void ListRequestersMenu()
{
    int option;
    do
    {
        // Utils::clearScreen();
        cout << "\n #------------------------------------------------------------#";
        cout << "\n | (1) List readers with overdue books                        |";
        cout << "\n | (2) List readers by category                               |";
        cout << "\n | (3) List readers grouped by category                       |";
        cout << "\n | (4) Search reader by ID                                    |";
        cout << "\n | (0) EXIT                                                   |";
        cout << "\n #------------------------------------------------------------#";
        cout << "\nWhat is your option: ";
        cin >> option;

        // Utils::clearScreen();
        switch (option)
        {
        case 1:
            g_Bib->ListLateReaders();
            break;
        case 2:
            g_Bib->ListReaders();
            break;
        case 3:
            g_Bib->FindReaderByCategory();
            break;
        case 4:
            int id;
            cout << "Enter the ID of the reader to search: ";
            cin >> id;
            g_Bib->FindReader(id)->showInfo();
            break;
        }
    } while (option != 0);
}

void RequestsMenu()
{
    int option;
    do
    {
        Utils::clearScreen();

        cout << "\n # ---------------------BORROWERS-----------------------------#";
        cout << "\n | (1) Request Book (reservation system*)                     |";
        cout << "\n | (2) Return book (And control of Fines)                     |";
        cout << "\n | (3) List Requests (menu)                                   |";
        cout << "\n | (4) Extend Loans (Students and Teachers)                   |";
        cout << "\n | (5) Pay Pending Fine                                       |";
        cout << "\n | (0) EXIT                                                   |";
        cout << "\n #------------------------------------------------------------#";
        cout << "\nWhat is your option: ";
        cin >> option;

        Utils::clearScreen();
        switch (option)
        {
        case 1:
        {
            string bookID, readerID;
            cout << "Enter the ID of the book to request: ";
            cin >> bookID;
            cout << "Enter the ID of the reader: ";
            cin >> readerID;

            int readerID_int = stoi(readerID);
            if (g_Bib->FindBook(bookID) && g_Bib->FindReader(readerID_int))
            {
                g_Bib->PerformLoan(g_Bib->FindBook(bookID), g_Bib->FindReader(readerID_int));
            }
            else
            {
                if (!g_Bib->FindBook(bookID))
                    cout << "Book not found." << endl;
                if (!g_Bib->FindReader(readerID_int))
                    cout << "Reader not found." << endl;
            }
            break;
        }
        case 2:
            int ID;
            cout << "Enter the ID of the book to return: ";
            cin >> ID;
            g_Bib->ReturnBook(ID);
            break;
        case 3:
            ListRequestsMenu();
            break;
        case 4:
            g_Bib->ExtendLoans();
            g_Bib->GenerateFines();
            break;
        case 5:
            g_Bib->PayFine();
            break;
        }
    } while (option != 0);
}

void ListRequestsMenu()
{
    int option;
    do
    {
        // Utils::clearScreen();

        cout << "\n #------------------------------------------------------------#";
        cout << "\n | (1) List Books Requested by a reader                       |";
        cout << "\n | (2) List Books Requested by all readers                    |";
        cout << "\n | (3) List Pending Fines                                     |";
        cout << "\n | (0) EXIT                                                   |";
        cout << "\n #------------------------------------------------------------#";
        cout << "\nWhat is your option: ";
        cin >> option;

        // Utils::clearScreen();

        switch (option)
        {
        case 1:
            g_Bib->ListLoansByReader();
            break;
        case 2:
            g_Bib->ListLoans();
            break;
        case 3:
            g_Bib->ListPendingFines();
            break;
        }
    } while (option != 0);
}

void AdvancedMenu()
{
    int option;
    do
    {
        Utils::clearScreen();

        cout << "\n #------------------------------------------------------------#";
        cout << "\n | (1) Save to a given file (entered by the user)             |";
        cout << "\n | (2) Read from a file                                       |";
        cout << "\n | (3) Optimization report                                    |";
        cout << "\n | (0) EXIT                                                   |";
        cout << "\n #------------------------------------------------------------#";
        cout << "\nWhat is your option: ";
        cin >> option;

        Utils::clearScreen();

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
