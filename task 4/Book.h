#ifndef BOOK_H
#define BOOK_H
#include <iostream>
using namespace std;

class Book
{
    char *title;
    int signature;
    int number;
    
public:
    Book(const char *title, int signature);
    ~Book();
    int getSignature();
    void numIncrement();

    //task 4
    Book(const Book & x);
    friend ostream & operator<< (ostream& os, const Book& a);
    /*use friend keyword becasue this funciton is not defined in class*/
    
    //task 2
    int &refNumber();
    const char *getTitle();  
    void changeTitle(const char*title);
};

#endif
