#include "Book.h"
#include <iostream>
#include <cstring>
using namespace std;

Book::Book(const char *title, int signature) //constructor: create a new book
{
    this->title = new char[strlen(title)+1];
    strcpy(this->title,title);
        
    this->signature = signature;
        
    number = 1;
}

Book::~Book() //destructor: print book information and delete book
{
    cout << "Deleting Title: " << title << ", Signature: " << signature << ", Number: " << number << endl;
    delete[] title;
}

int Book::getSignature() 
{
    return signature;
}

void Book::numIncrement()
{
    number++;
}

//task 4

Book::Book(const Book & x) //copy constructor 
{
    this->title = new char[strlen(x.title)+1];
    strcpy(this->title, x.title);
    this->signature = x.signature;
    this->number = x.number;
}

 //overload operator<< function is defined outside Book class!
ostream & operator<< (ostream& os, const Book& a)
{
    os << "Title: " << a.title<< ", Signature: " << a.signature << ", Number: " << a.number;
    return os;
}

//task 2

int &Book::refNumber()
{
    return number;
}

const char *Book::getTitle() 
{
    return title;
}

void Book::changeTitle(const char*title)
{
    if(this->title != nullptr) //delete title only if it's not nullptr
    {
        delete[] this->title;
    }
    
    this->title = new char[strlen(title)+1];
    strcpy(this->title, title);
}

