#ifndef BOOKLIST_H
#define BOOKLIST_H
#include <iostream>
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
    void createNewbook(Book &book);

public:
    BookList();
    ~BookList();
    void addBook(const char* title, int signature);
    int &changeBook(const char* title, int signature);
    void removeBook(int signature);
    void print();

    //task 4
    BookList(const BookList & x); 
    BookList & operator= (const BookList& x); 
    friend ostream & operator<< (ostream& os, const BookList& al);

    //task 5
    BookList operator+ (const BookList& x) const;
    friend BookList operator- (const BookList& l1, const BookList& l2); 
};

#endif