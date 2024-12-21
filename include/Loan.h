#ifndef LOAN_H
#define LOAN_H

#include "General.h"
#include "Person.h"
#include "Date.h"
#include "Fine.h"
#include <string>

class Loan
{
private:
    int id;
    General *book;
    Person *reader;
    Date loanDate;
    Date returnDate;
    Date dueDate;
    bool returned;
    Fine fineAmount;
    int extended;

public:
    Loan(int id, General *book, Person *reader);
    Loan();
    void calculateReturnDate();
    bool isOverdue() const;
    double calculateFine() const;
    void processReturn();

    // Getters
    int getId() const { return id; }
    General *getBook() const { return book; }
    Person *getReader() const { return reader; }
    std::string getLoanDate() const { return loanDate.toString(); }
    std::string getReturnDate() const { return returnDate.toString(); }
    std::string getDueDate() const { return dueDate.toString(); }
    bool isReturned() const { return returned; }
    bool getReturned() const { return returned; }
    Fine getFine() const { return fineAmount; }

    // Setters for loading Date
    void setId(int newId) { id = newId; }
    void setLoanDate(Date date) { loanDate = date; }
    void setReturnDate(Date date) { returnDate = date; }
    void setDueDate(Date date) { dueDate = date; }
    void setReturned(bool state) { returned = state; }

    void setFine(Fine newFine) { fineAmount = newFine; }

    void showInfo() const
    {
        std::cout << "ID: " << id << std::endl;
        std::cout << "Book: " << book->getTitle() << std::endl;
        std::cout << "Reader: " << reader->getName() << std::endl;
        std::cout << "Loan Date: " << loanDate.toString() << std::endl;
        std::cout << "Return Date: " << returnDate.toString() << std::endl;
        std::cout << "Due Date: " << dueDate.toString() << std::endl;
        std::cout << "Returned: " << (returned ? "Yes" : "No") << std::endl;
        if (fineAmount.getfinalAmount() > 0)
        {
            fineAmount.displayFine();
        }
    }
    void calculateDueDate();
    void extendLoan();
};

#endif // LOAN_H
