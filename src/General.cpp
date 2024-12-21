#include "../include/General.h"

using namespace std;

General::General() : id(0), title(""), author(""), publicationDate(), available(true) {}

General::General(int id, string title, string author, Date publicationDate)
    : id(id), title(title), author(author), publicationDate(publicationDate), available(true) {}

void General::showInfo() const
{
    cout << "ID: " << id << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Publication Date: ";
    publicationDate.showInfo();
    cout << endl;
    cout << "Available: " << (available ? "Yes" : "No") << endl;
}
