#ifndef SENIOR_H
#define SENIOR_H
#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

class Senior : public Person
{
private:
    int discount; // in percentage e.g., 20 for 20%
public:
    Senior();
    Senior(string name, Date birthDate, int id, Date regDate, int discount) : Person(name, birthDate, id, regDate), discount(discount) {};

    void showInfo() const
    {
        Person::showInfo();
        cout << "Discount: " << discount << "%" << endl;
        cout << "Reader Type: Senior" << endl;
    }
    virtual ~Senior();
    int getDiscount() const { return discount; }
    string getCategory() const override
    {
        return "Senior";
    };
};

#endif // SENIOR_H
