#ifndef GENERAL_H
#define GENERAL_H
#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

class General
{
protected:
    int id;
    string title;
    string author;
    Date publicationDate;
    bool available;

public:
    General();
    General(int id, string title, string author, Date publicationDate);

    void setTitle(const string &newTitle) { title = newTitle; }
    void setAuthor(const string &newAuthor) { author = newAuthor; }
    void setPublicationDate(const Date &newDate) { publicationDate = newDate; }

    virtual void showInfo() const;
    virtual ~General() = default;
    virtual string getCategory() const = 0;

    int getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getPublicationDate() const { return publicationDate.toString(); }
    bool isAvailable() const { return available; }
    void setAvailability(bool avail) { available = avail; }

protected:
private:
};

#endif // GENERAL_H
