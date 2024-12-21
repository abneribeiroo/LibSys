#ifndef Date_H
#define Date_H
#include <iostream>
#include <string>
using namespace std;

class Date
{
public:
    Date();
    Date(int day, int month, int year);
    virtual ~Date();
    virtual void showInfo() const;
    int calculateAge() const;
    bool isValid() const;
    Date readDate();
    Date currentDate();
    Date readString(const string &DateStr);
    string toString() const;
    int getday() const { return day; };
    int getmonth() const { return month; };
    int getyear() const { return year; };
    Date addDays(int days);

private:
    int day;
    int month;
    int year;
};

#endif
