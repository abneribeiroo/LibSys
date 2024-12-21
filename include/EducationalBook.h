#ifndef EDUCATIONALBOOK_H
#define EDUCATIONALBOOK_H

#include "General.h"
#include <string>
#include <iostream>

using namespace std;

class EducationalBook : public General
{
    string educationalLevel;

public:
    EducationalBook();
    EducationalBook(int id, string title, string author, Date publicationDate, string educationalLevel) : General(id, title, author, publicationDate), educationalLevel(educationalLevel) {};

    void showInfo() const
    {
        General::showInfo();
        cout << "Educational Level: " << educationalLevel << endl;
    };
    string getCategory() const override { return "EducationalBook"; };
    string getEducationalLevel() const { return educationalLevel; }
    virtual ~EducationalBook();

protected:
private:
};

#endif // EDUCATIONALBOOK_H
