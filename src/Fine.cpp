#include "../include/Fine.h"

Fine::Fine() : daysLate(0), baseRatePerDay(0.5), discount(0.0), finalAmount(0.0), paid(true) {}

Fine::~Fine() {}

void Fine::displayFine() const
{
    cout << "Calculated Fine:\n";
    cout << " - Days Late: " << daysLate << "\n";
    cout << " - Base Rate per Day: " << baseRatePerDay << " EUR\n";
    cout << " - Discount Applied: " << discount * 100 << "%\n";
    cout << " - Final Amount: " << finalAmount << " EUR\n";
}

Fine Fine::calculateFine(int daysLate, double baseRatePerDay, double discount)
{
    Fine Fine;
    Fine.daysLate = daysLate;
    Fine.baseRatePerDay = baseRatePerDay;
    Fine.discount = discount;
    Fine.finalAmount = daysLate * baseRatePerDay * (1 - discount);
    if (Fine.finalAmount > 0)
    {
        Fine.paid = false;
    }
    return Fine;
}
