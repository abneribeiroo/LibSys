#include "../include/Library.h"
#include "../include/Date.h"
#include <cstring>
#include <iostream>
#include <ctime>

using namespace std;

Date::Date() : day(0), month(0), year(0) {}

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

Date::~Date()
{
}

int Date::calculateAge() const
{
    time_t t = time(0);
    tm *now = localtime(&t);
    int currentYear = now->tm_year + 1900;
    int currentMonth = now->tm_mon + 1;
    int currentDay = now->tm_mday;

    int age = currentYear - year;

    if (currentMonth < month ||
        (currentMonth == month && currentDay < day))
    {
        age--;
    }

    return age;
}

Date Date::currentDate()
{
    time_t t = time(0);
    tm *now = localtime(&t);
    int day = now->tm_mday;
    int month = now->tm_mon + 1;
    int year = now->tm_year + 1900;

    return Date(day, month, year);
}

void Date::showInfo() const
{
    cout << "Date: " << day << "/" << month << "/" << year << endl;
}

Date Date::readDate()
{
    int day, month, year;

    cout << "Enter the day: ";
    cin >> day;
    if (day == 0)
    {
        return Date(0, 0, 0);
    }

    cout << "Enter the month: ";
    cin >> month;

    cout << "Enter the year: ";
    cin >> year;

    // Returns the Date object with the read values
    return Date(day, month, year);
}

Date Date::readString(const string &dateStr)
{
    char *cstr = new char[dateStr.length() + 1];
    strcpy(cstr, dateStr.c_str());

    char *token = strtok(cstr, "/");
    int day = atoi(token);

    token = strtok(nullptr, "/");
    int month = atoi(token);

    token = strtok(nullptr, "");
    int year = atoi(token);

    delete[] cstr;

    return Date(day, month, year);
}

string Date::toString() const
{
    return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}

bool Date::isValid() const
{
    // Verifica o year
    if (year < 1900)
    {
        return false;
    }

    // Verifica o mês
    if (month < 1 || month > 12)
    {
        return false;
    }

    // Verifica os days do mês
    if (day < 1)
    {
        return false;
    }

    // Número de days em cada mês
    int daysNomonth[] = {31, 29, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Verifica se o day é válido para o mês correspondente
    if (day > daysNomonth[month - 1])
    {
        return false;
    }

    return true;
}

Date Date::addDays(int days)
{
    // Number of days in each month
    int daysInMonth[] = {31, 29, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    day += days;

    while (day > daysInMonth[month - 1])
    {
        day -= daysInMonth[month - 1];
        month++;

        if (month > 12)
        {
            month = 1;
            year++;
        }
    }
    return Date(day, month, year);
}
