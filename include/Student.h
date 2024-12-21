#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : public Person
{
    string course;

public:
    Student();
    Student(string name, Date birthDate, int id, Date regDate, string course) : Person(name, birthDate, id, regDate), course(course) {};

    void showInfo() const
    {
        Person::showInfo();
        cout << "Course: " << course << endl;
        cout << "Reader Type: Student" << endl;
    }
    virtual ~Student();
    string getCourse() const { return course; }
    string getCategory() const override
    {
        return "Student";
    };

protected:
private:
};

#endif // STUDENT_H
