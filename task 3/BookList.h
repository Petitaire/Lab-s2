#ifndef BOOKLIST_H
#define BOOKLIST_H
#include "Book.h"

class BookList
{
    struct Element
    {
        Book *ptr;
        Element *next;
        Element():ptr(nullptr), next(nullptr){} //default constructor?
    };

    Element *head;
    Book *findBook (int signature) const; 
    Book *createNewbook(const char *title, int signature);

public:
    BookList();
    ~BookList();
    void addBook(const char* title, int signature);
    int &changeBook(const char* title, int signature);
    void removeBook(int signature);
    void print();
};

#endif