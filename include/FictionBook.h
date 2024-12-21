#ifndef FICTIONBOOK_H
#define FICTIONBOOK_H

#include "General.h"
using namespace std;

class FictionBook : public General
{
    string genre;

public:
    FictionBook();
    FictionBook(int id, string title, string author, Date publicationDate, string genre) : General(id, title, author, publicationDate), genre(genre) {};
    void showInfo() const
    {
        General::showInfo();
        cout << "Genre: " << genre << endl;
    };
    string getCategory() const override { return "FictionBook"; }
    string getGenre() const { return genre; }
    virtual ~FictionBook();

protected:
private:
};

#endif // FICTIONBOOK_H
