#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <vector>
#include "Person.h"
#include "General.h"
#include "Magazine.h"
#include "Newspaper.h"
#include "ScientificBook.h"
#include "FictionBook.h"
#include "EducationalBook.h"
#include "Teacher.h"
#include "CommonReader.h"
#include "Student.h"
#include "Senior.h"
#include "Loan.h"
using namespace std;

class Library
{
private:
    map<string, list<General *>> BookCollection;
    map<string, list<Person *>> ReaderCollection;
    map<string, list<Loan *>> LoanCollection;

    int highestId;
    int getNextId();

    void getCommonBookInfo(std::string &title, std::string &author, Date &publicationDate);

public:
    Library();
    ~Library();

    // Books
    bool AddBook(General *book);
    void registerNewBook();
    bool RemoveBook(const string &id);
    General *FindBook(const string &id) const;
    void EditBook(const string &id);
    void ListAllBooks() const;
    void ListBooksByCategory(const string &category) const;
    void ReportByCategory();
    bool SaveToFile_Books(const string &filename);
    bool LoadFile_Books(const string &filename);

    // Readers
    bool AddReader(Person *P);
    bool RemoveReader(int id);
    Person *FindReader(int id) const;
    void EditReader(int id) const;
    void ListReaders() const;
    void RegisterReader();
    int generateReaderID();
    bool SaveToFile_Readers(const string &filename);
    bool LoadFile_Readers(const string &filename);
    void FindReaderByCategory() const;

    // Loans
    bool PerformLoan(General *book, Person *reader);
    bool SaveToFile_Loans(const string &filename) const;
    bool LoadFile_Loans(const string &filename);
    void ListLoans();
    int subtractDate(Date d1, Date d2);
    bool compareDates(const Date &date1, const Date &date2);
    bool GenerateFines();
    bool ReturnBook(int id);
    void ListLateReaders();
    void ExtendLoans();
    void ListLoansByReader();
    void ListPendingFines();
    void PayFine();
};

#endif // LIBRARY_H
