#ifndef BOOK_H
#define BOOK_H

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
    
    //task 2
    int &refNumber();
    const char *getTitle();  
    void changeTitle(const char*title);
};

#endif
