#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "General.h"
using namespace std;

class Magazine : public General
{
    int editionNumber;

public:
    Magazine();
    Magazine(int id, string title, string author, Date publicationDate, int editionNumber) : General(id, title, author, publicationDate), editionNumber(editionNumber) {};
    void showInfo() const override
    {
        General::showInfo();
        cout << "Edition Number: " << editionNumber << endl;
    }
    string getCategory() const override
    {
        return "Magazine";
    }
    int getEditionNumber() const { return editionNumber; }
    virtual ~Magazine();

protected:
private:
};

#endif // MAGAZINE_H
