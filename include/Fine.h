// Fine.h
#ifndef Fine_H
#define Fine_H

#include <iostream>
using namespace std;

class Fine
{
public:
    Fine();
    ~Fine();
    void displayFine() const;
    Fine calculateFine(int daysLate, double baseRatePerDay, double discount);
    double getfinalAmount() const { return finalAmount; }
    void setpaid(bool estado) { paid = estado; }
    bool getpaid() const { return paid; }

private:
    int daysLate;
    double baseRatePerDay;
    double discount;
    double finalAmount;
    bool paid;
};

#endif // Fine_H
