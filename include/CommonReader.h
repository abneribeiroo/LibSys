#ifndef COMMONREADER_H
#define COMMONREADER_H

#include "Person.h"

class CommonReader : public Person
{
public:
    CommonReader();
    CommonReader(string name, Date birthDate, int id, Date regDate) : Person(name, birthDate, id, regDate) {};

    void showInfo() const
    {
        Person::showInfo();
        cout << "Reader Type: Common" << endl;
    }
    virtual ~CommonReader();
    string getCategory() const override
    {
        return "Common Reader";
    };

protected:
private:
};

#endif // COMMONREADER_H
