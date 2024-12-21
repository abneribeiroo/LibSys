#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

class Person
{
protected:
    string name;
    Date birthDate;
    int id;
    Date regDate;

public:
    Person();
    Person(string name, Date birthDate, int id, Date regDate) : name(name), birthDate(birthDate), id(id), regDate(regDate) {};

    virtual void showInfo() const
    {
        cout << "Name: " << name << endl;
        cout << "Birth Date: ";
        birthDate.showInfo();
        cout << "Id: " << id << endl;
        cout << "Registration Date: ";
        regDate.showInfo();
    }
    virtual ~Person();

    virtual string getCategory() const = 0;
    string getName() const { return name; }
    int getId() const { return id; }
    Date getBirthDate() const { return birthDate; }
    Date getRegDate() const { return regDate; }
    void setName(const string &newName) { name = newName; }
    virtual int getDiscount() const { return 0; }

    void setBirthDate(const Date &newDate) { birthDate = newDate; }

protected:
private:
};

#endif // PERSON_H
