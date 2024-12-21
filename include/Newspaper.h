#ifndef NEWSPAPER_H
#define NEWSPAPER_H

#include "General.h"
using namespace std;

class Newspaper : public General
{
    string editor;

public:
    Newspaper();
    Newspaper(int id, string title, string author, Date publicationDate, string editor) : General(id, title, author, publicationDate), editor(editor) {};

    void showInfo() const
    {
        General::showInfo();
        cout << "Editor: " << editor << endl;
    }
    string getCategory() const override
    {
        return "Newspaper";
    }
    string getPublicationDate() const { return publicationDate.toString(); }
    string getEditor() const { return editor; }
    virtual ~Newspaper();

protected:
private:
};

#endif
