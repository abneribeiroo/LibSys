#include "../include/Library.h"
#include "../include/Utils.h"
#include "../include/Date.h"
#include <algorithm>
#include <limits>
#include <fstream>
#include <sstream>
#include <string.h>

using namespace std;

Library::Library() : highestId(0)
{
    // ctor
}

Library::~Library()
{
    for (auto &pair : BookCollection)
    {
        for (auto &book : pair.second)
        {
            delete book;
        }
    }
}

int Library::getNextId()
{
    return ++highestId;
}

bool Library::SaveToFile_Books(const string &filename)
{
    ofstream file(filename);
    if (!file.is_open())
    {
        cout << "Error opening file for writing." << endl;
        return false;
    }

    for (const auto &pair : BookCollection)
    {
        for (const General *book : pair.second)
        {
            file << book->getId() << ";"
                 << book->getCategory() << ";"
                 << book->getTitle() << ";"
                 << book->getAuthor() << ";"
                 << book->getPublicationDate() << ";";

            if (book->getCategory() == "ScientificBook")
            {
                const ScientificBook *sb = dynamic_cast<const ScientificBook *>(book);
                file << sb->getResearchArea();
            }
            else if (book->getCategory() == "FictionBook")
            {
                const FictionBook *fb = dynamic_cast<const FictionBook *>(book);
                file << fb->getGenre();
            }
            else if (book->getCategory() == "EducationalBook")
            {
                const EducationalBook *eb = dynamic_cast<const EducationalBook *>(book);
                file << eb->getEducationalLevel();
            }
            else if (book->getCategory() == "Magazine")
            {
                const Magazine *m = dynamic_cast<const Magazine *>(book);
                file << m->getEditionNumber();
            }
            else if (book->getCategory() == "Newspaper")
            {
                const Newspaper *n = dynamic_cast<const Newspaper *>(book);
                file << n->getEditor();
            }

            file << endl;
        }
    }

    file.close();
    cout << "Data successfully saved to file " << filename << endl;
    return true;
}

bool Library::LoadFile_Books(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Error opening file for reading: " << strerror(errno) << endl;
        return false;
    }

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);

        string category, title, author, dateStr, specificAttribute, editor;
        int id;
        Date publicationDate;

        string idStr;
        if (!getline(ss, idStr, ';'))
        {
            cout << "Error: Invalid line format." << endl;
            continue;
        }
        try
        {
            id = stoi(idStr);
            highestId = max(highestId, id);
        }
        catch (const invalid_argument &e)
        {
            cout << "Error: Invalid ID - " << idStr << endl;
            continue;
        }

        getline(ss, category, ';');
        getline(ss, title, ';');
        getline(ss, author, ';');
        getline(ss, dateStr, ';');
        getline(ss, specificAttribute, ';');

        publicationDate = publicationDate.readString(dateStr);

        General *book = nullptr;

        if (category == "ScientificBook")
        {
            book = new ScientificBook(id, title, author, publicationDate, specificAttribute);
        }
        else if (category == "FictionBook")
        {
            book = new FictionBook(id, title, author, publicationDate, specificAttribute);
        }
        else if (category == "EducationalBook")
        {
            book = new EducationalBook(id, title, author, publicationDate, specificAttribute);
        }
        else if (category == "Magazine")
        {
            book = new Magazine(id, title, author, publicationDate, stoi(specificAttribute));
        }
        else if (category == "Newspaper")
        {
            book = new Newspaper(id, title, author, publicationDate, specificAttribute);
        }

        if (book)
        {
            AddBook(book);
        }
    }

    file.close();
    //! cout << "Data successfully loaded from file " << filename << endl;
    return true;
}


bool Library::AddBook(General *book)
{
    if (book == nullptr)
    {
        cout << "Error: Attempt to add a null book!" << endl;
        return false;
    };
    string category = book->getCategory();
    BookCollection[category].push_back(book);
    return true;
}

void Library::getCommonBookInfo(string &title, string &author, Date &publicationDate)
{
    cout << "Enter the title: ";
    getline(cin >> ws, title);
    cout << "Enter the author: ";
    getline(cin >> ws, author);
    while (!publicationDate.isValid())
    {
        cout << "Enter the publication date: ";
        publicationDate = publicationDate.readDate();
        if (!publicationDate.isValid())
        {
            cout << "Invalid date!";
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Library::registerNewBook()
{
    int type;
    string title, author, researchArea, editor, schoolGrade;
    int editionNumber;
    Date publicationDate;

    cout << "Select the category you want to list:" << endl;
    cout << "1. Scientific Book" << endl;
    cout << "2. Fiction Book" << endl;
    cout << "3. Educational Book" << endl;
    cout << "4. Magazine" << endl;
    cout << "5. Newspaper" << endl;
    cout << "Choice: ";
    cin >> type;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    getCommonBookInfo(title, author, publicationDate);

    int id = getNextId();
    cout << "Book ID: " << id << endl;
    General *newBook = nullptr;

    switch (type)
    {
    case 1: // Scientific Book
        cout << "Enter the research area: ";
        getline(cin >> ws, researchArea);
        newBook = new ScientificBook(id, title, author, publicationDate, researchArea);
        break;
    case 2: // Fiction Book
        cout << "Enter the genre: ";
        getline(cin >> ws, researchArea);
        newBook = new FictionBook(id, title, author, publicationDate, researchArea);
        break;
    case 3: // Educational Book
        cout << "Enter the school grade: ";
        getline(cin >> ws, schoolGrade);
        newBook = new EducationalBook(id, title, author, publicationDate, schoolGrade);
        break;
    case 4: // Magazine
        cout << "Enter the edition number: ";
        cin >> editionNumber;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        newBook = new Magazine(id, title, author, publicationDate, editionNumber);
        break;
    case 5: // Newspaper
        cout << "Enter the editor: ";
        getline(cin >> ws, editor);
        newBook = new Newspaper(id, title, author, publicationDate, editor);
        break;
    default:
        cout << "Invalid type!" << endl;
        return;
    }

    if (newBook)
    {
        if (AddBook(newBook))
        {
            cout << "Book added successfully!" << endl;
        }
        else
        {
            cout << "Error adding the book." << endl;
            delete newBook;
        }
    }
    else
    {
        cout << "Error creating the book!" << endl;
    }
}

bool Library::RemoveBook(const string &id)
{
    for (auto &pair : BookCollection)
    {
        auto &list = pair.second;
        for (auto it = list.begin(); it != list.end(); ++it)
        {
            if (to_string((*it)->getId()) == id)
            {
                delete *it;
                list.erase(it);
                return true;
            }
        }
    }
    return false;
}

General *Library::FindBook(const string &id) const
{
    for (const auto &pair : BookCollection)
    {
        for (const auto *book : pair.second)
        {
            if (to_string(book->getId()) == id)
            {
                return const_cast<General *>(book);
            }
        }
    }
    return nullptr;
}

void Library::ReportByCategory()
{
    int type;
    General *category = nullptr;
    string bookCategory;
    cout << "Select the type of book you want to list:" << endl;
    cout << "1. Scientific Book" << endl;
    cout << "2. Fiction Book" << endl;
    cout << "3. Educational Book" << endl;
    cout << "4. Magazine" << endl;
    cout << "5. Newspaper" << endl;
    cout << "Choice: ";
    cin >> type;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (type)
    {
    case 1:
        category = new ScientificBook();
        bookCategory = category->getCategory();
        Library::ListBooksByCategory(bookCategory);
        break;
    case 2:
        category = new FictionBook();
        bookCategory = category->getCategory();
        Library::ListBooksByCategory(bookCategory);
        break;
    case 3:
        category = new EducationalBook();
        bookCategory = category->getCategory();
        Library::ListBooksByCategory(bookCategory);
        break;
    case 4:
        category = new Magazine();
        bookCategory = category->getCategory();
        Library::ListBooksByCategory(bookCategory);
        break;
    case 5:
        category = new Newspaper();
        bookCategory = category->getCategory();
        Library::ListBooksByCategory(bookCategory);
        break;
    }
}

void Library::EditBook(const string &id)
{
    General *book = FindBook(id);
    if (book)
    {
        string newTitle, newAuthor;
        Date newDate;

        cout << book->getTitle() << endl;
        cout << "New title (or Enter to keep): ";
        cin.ignore();
        getline(cin, newTitle);
        if (!newTitle.empty())
            book->setTitle(newTitle);

        cout << book->getAuthor() << endl;
        cout << "New author (or Enter to keep): ";
        getline(cin, newAuthor);
        if (!newAuthor.empty())
            book->setAuthor(newAuthor);

        cout << book->getPublicationDate() << endl;
        cout << "New publication date (or 0 to keep): ";
        newDate = newDate.readDate();
        if (newDate.isValid())
            book->setPublicationDate(newDate);

        cout << "Book edited successfully!" << endl;
        book->showInfo();
    }
    else
    {
        cout << "Book not found." << endl;
    }
}

void Library::ListAllBooks() const
{
    for (const auto &pair : BookCollection)
    {
        cout << "Category: " << pair.first << endl;
        for (const auto *book : pair.second)
        {
            book->showInfo();
            cout << "--------------------" << endl;
        }
    }
}

void Library::ListBooksByCategory(const string &category) const
{
    auto it = BookCollection.find(category);
    if (it != BookCollection.end())
    {
        cout << "Category: " << category << endl;
        for (const auto *book : it->second)
        {
            book->showInfo();
            cout << "--------------------" << endl;
        }
    }
    else
    {
        cout << "Category not found." << endl;
    }
}

bool Library::AddReader(Person *P)
{
    if (P == nullptr)
    {
        cout << "Error: Attempt to add a null Person!" << endl;
        return false;
    };
    string category = P->getCategory();
    ReaderCollection[category].push_back(P);
    return true;
}

void Library::RegisterReader()
{
    int type, id, temp2;
    string name, temp;
    Date birthDate;
    Date regDate;

    cout << "Select the type of reader to add:" << endl;
    cout << "1. Student" << endl;
    cout << "2. Common Reader" << endl;
    cout << "3. Teacher" << endl;
    cout << "4. Senior" << endl;
    cout << "Choice: ";
    cin >> type;
    cin.ignore(); // Clear the keyboard buffer

    cout << "Enter the Name: ";
    getline(cin, name);
    while (!birthDate.isValid())
    {
        cout << "Enter the birth date: ";
        birthDate = birthDate.readDate();
        if (!birthDate.isValid())
        {
            cout << "Invalid date!" << endl;
        }
    }

    cin.ignore(); // Clear the buffer

    id = generateReaderID();

    regDate = regDate.currentDate();

    Person *newPerson = nullptr;

    switch (type)
    {
    case 1:
        cout << "Enter the course: ";
        getline(cin, temp);
        newPerson = new Student(name, birthDate, id, regDate, temp);
        break;
    case 2:
        newPerson = new CommonReader(name, birthDate, id, regDate);
        break;
    case 3:
        cout << "Enter the area: ";
        getline(cin, temp);
        newPerson = new Teacher(name, birthDate, id, regDate, temp);
        break;
    case 4:
        cout << "Enter the discount percentage: ";
        cin >> temp2;
        newPerson = new Senior(name, birthDate, id, regDate, temp2);
        break;
    default:
        cout << "Invalid option!" << endl;
        return;
    }
    if (newPerson != nullptr)
    {
        AddReader(newPerson);
        cout << "Reader registered successfully!" << endl;
    }
    else
    {
        cout << "Error registering reader!" << endl;
    }
}

bool Library::RemoveReader(int id)
{
    for (auto &pair : ReaderCollection)
    {
        auto &list = pair.second;
        for (auto it = list.begin(); it != list.end(); ++it)
        {
            if ((*it)->getId() == id)
            {
                delete *it;
                list.erase(it);
                return true;
            }
        }
    }
    return false;
}

Person *Library::FindReader(int id) const
{
    for (const auto &pair : ReaderCollection)
    {
        for (const auto *person : pair.second)
        {
            if (person->getId() == id)
            {
                return const_cast<Person *>(person);
            }
        }
    }
    return nullptr;
}

void Library::EditReader(int id) const
{
    Person *person = FindReader(id);
    if (person)
    {
        string newName;
        Date newDate;

        cout << "New Name (or Enter to keep): ";
        cin.ignore();
        getline(cin, newName);
        if (!newName.empty())
            person->setName(newName);

        cout << "New Date (or 0 to keep): ";

        newDate = newDate.readDate();

        if (newDate.isValid())
        {
            person->setBirthDate(newDate);
        }

        cout << "Person edited successfully!" << endl;
    }
    else
    {
        cout << "Person not found." << endl;
    }
}

void Library::ListReaders() const
{
    for (const auto &pair : ReaderCollection)
    {
        cout << "Category: " << pair.first << endl;
        for (const auto *person : pair.second)
        {
            person->showInfo();
            cout << "--------------------" << endl;
        }
    }
    cout << "Press enter to continue";
    cin.ignore();
}

void Library::FindReaderByCategory() const
{
    int type;
    cout << "Select the type of reader to list:" << endl;
    cout << "1. Student" << endl;
    cout << "2. Common Reader" << endl;
    cout << "3. Teacher" << endl;
    cout << "4. Senior" << endl;
    cout << "Choice: ";
    cin >> type;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string category;
    switch (type)
    {
    case 1:
        category = "Student";
        break;
    case 2:
        category = "CommonReader";
        break;
    case 3:
        category = "Teacher";
        break;
    case 4:
        category = "Senior";
        break;
    }
    auto it = ReaderCollection.find(category);
    if (it != ReaderCollection.end())
    {
        cout << "Category: " << category << endl;
        for (const auto *person : it->second)
        {
            person->showInfo();
            cout << "--------------------" << endl;
        }
    }
    else
    {
        cout << "Category not found." << endl;
    }
}

int Library::generateReaderID()
{
    int id = 0;
    for (auto &pair : ReaderCollection)
    {
        for (auto &person : pair.second)
        {
            if (person->getId() == id)
            {
                id++;
            }
        }
    }
    return id;
}

bool Library::SaveToFile_Readers(const string &filename)
{
    ofstream file(filename);
    if (!file.is_open())
    {
        cout << "Error opening file for writing." << endl;
        return false;
    }

    for (const auto &pair : ReaderCollection)
    {
        for (const Person *reader : pair.second)
        {
            file << reader->getId() << ";"
                 << reader->getCategory() << ";"
                 << reader->getName() << ";"
                 << reader->getBirthDate().toString() << ";"
                 << reader->getRegDate().toString() << ";";

            if (reader->getCategory() == "Student")
            {
                const Student *student = dynamic_cast<const Student *>(reader);
                file << student->getCourse();
            }
            else if (reader->getCategory() == "Teacher")
            {
                const Teacher *teacher = dynamic_cast<const Teacher *>(reader);
                file << teacher->getArea();
            }
            else if (reader->getCategory() == "Senior")
            {
                const Senior *senior = dynamic_cast<const Senior *>(reader);
                file << senior->getDiscount();
            }

            file << endl;
        }
    }
    return true;
}

bool Library::LoadFile_Readers(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Error opening file for reading." << endl;
        return false;
    }

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string category, name, birthDateStr, idStr, regDateStr, specificAttribute;
        int id;
        getline(ss, idStr, ';');
        id = stoi(idStr);
        getline(ss, category, ';');
        getline(ss, name, ';');
        getline(ss, birthDateStr, ';');
        getline(ss, regDateStr, ';');
        getline(ss, specificAttribute, ';');

        Date birthDate = birthDate.readString(birthDateStr);
        Date regDate = regDate.readString(regDateStr);

        Person *reader = nullptr;

        if (category == "CommonReader")
        {
            reader = new CommonReader(name, birthDate, id, regDate);
        }
        else if (category == "Student")
        {
            reader = new Student(name, birthDate, id, regDate, specificAttribute);
        }
        else if (category == "Teacher")
        {
            reader = new Teacher(name, birthDate, id, regDate, specificAttribute);
        }
        else if (category == "Senior")
        {
            reader = new Senior(name, birthDate, id, regDate, stoi(specificAttribute));
        }

        if (reader && birthDate.isValid() && regDate.isValid())
        {
            AddReader(reader);
        }
        else
        {
            cout << "Error loading reader (date format error) " << name << endl;
        }
    }
    //! cout << "Data successfully loaded from file " << filename << endl;
    return true;
}

bool Library::PerformLoan(General *book, Person *reader)
{
    if (!book->isAvailable())
    {
        cout << "Book is not available for loan." << endl;
        return false;
    }

    int loanLimit = 3; // Default for CommonReader
    if (reader->getCategory() == "Student" || reader->getCategory() == "Teacher")
    {
        loanLimit = 5;
    }

    int currentLoans = 0;

    for (const auto &[_, loansOfType] : LoanCollection)
    {
        for (const auto &loan : loansOfType)
        {
            if (loan->getReader() == reader && !loan->isReturned())
            {
                currentLoans++;
            }
        }
        if (currentLoans >= loanLimit)
        {
            cout << "Reader has reached the loan limit." << endl;
            return false;
        }
    }
    int id = 0;

    Loan *newLoan = new Loan(id, book, reader);
    newLoan->setReturned(false);
    book->setAvailability(false);
    Date newDate;
    newDate = newDate.currentDate();
    newLoan->setLoanDate(newDate);
    newLoan->calculateDueDate();

    string category = book->getCategory();
    LoanCollection[category].push_back(newLoan);

    book->setAvailability(false);
    cout << "Loan successfully performed." << endl;
    return true;
}

bool Library::LoadFile_Loans(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Error opening file for reading." << endl;
        return false;
    }

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string category, bookIdStr, readerIdStr, loanDateStr, returnDateStr, returnedStr, fineStr;
        int bookId, readerId;
        bool returned;

        getline(ss, category, ';');
        getline(ss, bookIdStr, ';');
        getline(ss, readerIdStr, ';');
        getline(ss, loanDateStr, ';');
        getline(ss, returnDateStr, ';');
        getline(ss, returnedStr, ';');
        getline(ss, fineStr, ';');

        bookId = stoi(bookIdStr);
        readerId = stoi(readerIdStr);
        returned = returnedStr == "1";

        General *book = FindBook(to_string(bookId));
        Person *reader = FindReader(readerId);

        if (book && reader)
        {
            Loan *loan = new Loan(getNextId(), book, reader);
            loan->setLoanDate(Date().readString(loanDateStr));
            loan->setReturnDate(Date().readString(returnDateStr));
            loan->setReturned(returned);
            loan->calculateDueDate();

            LoanCollection[category].push_back(loan);
        }
        else
        {
            return false;
        }
    }
    //! cout << "Data successfully loaded from file " << filename << endl;

    return true;
}

void Library::ListLoans()
{
    for (const auto &pair : LoanCollection)
    {
        cout << "Category: " << pair.first << endl;
        for (const auto &loan : pair.second)
        {
            loan->showInfo();
            cout << "--------------------" << endl;
        }
    }
}

bool Library::SaveToFile_Loans(const string &filename) const
{
    ofstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file for writing." << endl;
        return false;
    }

    for (const auto &[category, loans] : LoanCollection)
    {
        for (const auto &loan : loans)
        {
            file << loan->getBook()->getCategory() << ";"
                 << loan->getBook()->getId() << ";"
                 << loan->getReader()->getId() << ";"
                 << loan->getLoanDate() << ";"
                 << loan->getReturnDate() << ";"
                 << loan->isReturned() << ";"
                 << loan->getFine().getfinalAmount() << endl;
        }
    }

    file.close();
    cout << "Data successfully saved to file " << filename << endl;
    return true;
}

int Library::subtractDate(Date d1, Date d2)
{
    int days = 0;

    int totalDaysD1 = d1.getyear() * 365 + d1.getmonth() * 30 + d1.getday();
    int totalDaysD2 = d2.getyear() * 365 + d2.getmonth() * 30 + d2.getday();

    days = totalDaysD1 - totalDaysD2;

    return days;
}

bool Library::compareDates(const Date &date1, const Date &date2)
{
    if (date1.getyear() > date2.getyear())
    {
        return true;
    }
    else if (date1.getyear() == date2.getyear())
    {
        if (date1.getmonth() > date2.getmonth())
        {
            return true;
        }
        else if (date1.getmonth() == date2.getmonth())
        {
            if (date1.getday() > date2.getday())
            {
                return true;
            }
        }
    }
    return false;
}

bool Library::GenerateFines()
{
    for (const auto &pair : LoanCollection)
    {
        for (const auto &loan : pair.second)
        {
            if (!Date().readString(loan->getReturnDate()).isValid())
            {
                int daysLate = subtractDate(Date().currentDate(), Date().readString(loan->getDueDate()));
                Fine fine;
                fine = fine.calculateFine(daysLate, 0.5, (loan->getReader()->getDiscount()) * 0.01);
                loan->setFine(fine);
            }
            else
            {
                int daysLate = subtractDate(Date().readString(loan->getReturnDate()), Date().readString(loan->getDueDate()));
                Fine fine;
                fine = fine.calculateFine(daysLate, 0.5, (loan->getReader()->getDiscount()) * 0.01);
                loan->setFine(fine);
            }
        }
    }
    return true;
}

bool Library::ReturnBook(int id)
{
    for (auto &pair : LoanCollection)
    {
        for (auto &loan : pair.second)
        {
            if (loan->getId() == id)
            {
                loan->processReturn();
                return true;
            }
        }
    }
    return false;
}

void Library::ListLateReaders()
{
    for (const auto &pair : LoanCollection)
    {
        for (const auto &loan : pair.second)
        {
            if (!Date().readString(loan->getReturnDate()).isValid())
            {
                int daysLate = subtractDate(Date().currentDate(), Date().readString(loan->getDueDate()));
                if (daysLate > 0)
                {
                    loan->getReader()->showInfo();
                    cout << "Days late: " << daysLate << endl;
                }
            }
        }
    }
}

void Library::ExtendLoans()
{
    int id;
    cout << "Enter the ID of the loan you want to extend: ";
    cin >> id;
    for (auto &pair : LoanCollection)
    {
        for (auto &loan : pair.second)
        {
            if (loan->getId() == id)
            {
                loan->extendLoan();
                return;
            }
        }
    }
}

void Library::ListLoansByReader()
{
    int id;
    cout << "Enter the reader's ID: ";
    cin >> id;

    for (const auto &pair : LoanCollection)
    {
        for (const auto &loan : pair.second)
        {
            if (loan->getReader()->getId() == id)
            {
                loan->showInfo();
                cout << "--------------------" << endl;
            }
        }
    }
}

void Library::ListPendingFines()
{
    for (const auto &pair : LoanCollection)
    {
        for (const auto &loan : pair.second)
        {
            if (loan->getFine().getpaid() == false)
            {
                loan->showInfo();
                cout << "--------------------" << endl;
            }
        }
    }
}

void Library::PayFine()
{
    int id = 0;
    cout << "Enter the ID of the loan you want to pay the fine for: ";
    cin >> id;
    for (auto &pair : LoanCollection)
    {
        for (auto &loan : pair.second)
        {
            if (loan->getId() == id && loan->isReturned())
            {
                loan->getFine().setpaid(true);
                return;
            }
        }
    }
}
