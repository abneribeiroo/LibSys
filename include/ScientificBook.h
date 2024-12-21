#ifndef SCIENTIFICBOOK_H
#define SCIENTIFICBOOK_H

#include "General.h"

class ScientificBook : public General
{
    string researchArea;

public:
    ScientificBook();
    ScientificBook(int id, string title, string author, Date publicationDate, string researchArea) : General(id, title, author, publicationDate), researchArea(researchArea) {};
    void showInfo() const override
    {
        General::showInfo();
        cout << "Research Area: " << researchArea << endl;
    };
    string getCategory() const override
    {
        return "ScientificBook";
    };
    string getResearchArea() const { return researchArea; }
    virtual ~ScientificBook();

protected:
private:
};

#endif // SCIENTIFICBOOK_H
