#include "../include/Loan.h"
#include "../include/Newspaper.h"
#include "../include/Magazine.h"
#include "../include/EducationalBook.h"
#include "../include/ScientificBook.h"
#include "../include/FictionBook.h"
#include "../include/Senior.h"
#include "../include/Student.h"
#include "../include/Person.h"
#include "../include/CommonReader.h"
#include <sstream>
#include <iomanip>

Loan::Loan(int id, General* book, Person* reader)
    : id(id), book(book), reader(reader) {
    calculateDueDate();
    extended = 0;
}

void Loan::calculateDueDate() {
    dueDate = loanDate;
    dueDate = dueDate.addDays(5);
}

void Loan::processReturn() {
    returned = true;
    returnDate = returnDate.currentDate();
    book->setAvailability(true);
    if(fineAmount.getfinalAmount() > 0){
        cout << "Pay fine of " << fineAmount.getfinalAmount() << " EUR" << endl;
        cout << "Fine paid? (Y/N): ";
        char option;
        cin >> option;
        if(option == 'Y' || option == 'y'){
            fineAmount.setpaid(true);
        } else {
            fineAmount.setpaid(false);
        }
    }
}

void Loan::extendLoan() {
    if((reader->getCategory() == "Student" || reader->getCategory() == "Professor") && extended < 2) {
        dueDate = dueDate.addDays(5);
        extended++;
    } else {
        if(extended >= 2) {
            cout << "Extension limit reached for this loan." << endl;
        }
    }
    if(extended < 1 && !(reader->getCategory() == "Student" || reader->getCategory() == "Professor")) {
        dueDate = dueDate.addDays(3);
        extended++;
    } else {
        cout << "Extension limit reached for this loan." << endl;
    }
}
