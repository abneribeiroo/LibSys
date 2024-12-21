#ifndef TEACHER_H
#define TEACHER_H

#include "Person.h"

class Teacher : public Person
{
    string area;

public:
    Teacher();
    Teacher(string name, Date birthDate, int id, Date regDate, string area) : Person(name, birthDate, id, regDate), area(area) {};

    void showInfo() const
    {
        Person::showInfo();
        cout << "Area: " << area << endl;
        cout << "Reader Type: Teacher" << endl;
    }
    virtual ~Teacher();
    string getArea() const { return area; }
    string getCategory() const override
    {
        return "Teacher";
    };

protected:
private:
};

#endif // TEACHER_H
