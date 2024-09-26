#include "BookList.h"
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

Book *BookList::findBook(int signature)const
{
    Element *current = head;
    while(current != nullptr)
    {
        if(current->ptr->getSignature() == signature)
        {
            return current->ptr;
        }
        else
        {
            current = current->next;
        }
    }
    return nullptr;
}

void BookList::createNewbook(Book &book)
{
    Element *newElement = new Element;
    newElement->ptr = &book; //link new element to new book 
        
    if(head == nullptr || head->ptr->getSignature() > newElement->ptr->getSignature())
    {
        newElement->next = head; //next = nullptr, the last place in the list is always nullptr
        head = newElement;
    }
    else
    {
        Element *current = head;
            
        while(current->next != nullptr && current->next->ptr->getSignature() < newElement->ptr->getSignature()) 
        {
            current = current->next;
        }
        
        newElement->next = current->next; //next = nullptr
        current->next = newElement;
    }
}



BookList::BookList() : head(nullptr){}; // default constructor to create an empty list

BookList::~BookList() //destructor that delete elements of the whole list
{   
    cout << "Deleting BookList" << endl; //debug
    Element *current = head;
    while(current != nullptr)
    {
            Element *temp = current->next;
            delete current->ptr;
            delete current;
            current = temp;
    }
}

void BookList::addBook(const char *title, int signature)
{
    Book *bookExists = findBook(signature);
    if(bookExists!= nullptr) //book is found
    {
        bookExists-> refNumber()++; //current->ptr->number
        return;
    }
    else //book is not on the list
    {
        Book *newBook = new Book(title, signature);
        createNewbook(*newBook);
    }
}

int &BookList::changeBook(const char *title, int signature)
{
    Book *bookExists = findBook(signature);
    if(bookExists != nullptr) //book is found
    {
        if(strcmp(bookExists->getTitle(), title) !=0) //titles are not equal
        {
            bookExists->changeTitle(title); //update title
            return bookExists->refNumber();
        } 
          
        return bookExists->refNumber(); 
    }
    
    else //book is not on the list
    {
        Book *newBook=new Book(title, signature);
        createNewbook(*newBook);
        return newBook->refNumber();
    }
}

void BookList::removeBook(int signature)
{
    Book *bookExists = findBook(signature);
    if(bookExists == nullptr)
    {
        cout << "Book with signature " << signature << " is not found!" << endl;
        return;
    }
    else
    {
        Element *current = head;
        Element *previous = nullptr;

        while(current->ptr != bookExists)
        {
            previous = current;
            current = current->next;
        } //go through the list until the book is found

        if(previous == nullptr) //in case the book is head
        {
            head = current->next;
        }
        else
        {
            previous->next = current->next; 
            //previous->next was current
            //after removing current, previous->next is current->next
        }

        delete current->ptr;
        delete current;
    }
}

/*void BookList::print()
{
    Element *current = head;
    while(current != nullptr)
    {
        cout << "Title: " << current->ptr->getTitle() << ", Signature: " << current->ptr->getSignature() << ", Number: " << current->ptr->refNumber() << endl;
        current = current->next;
    }
}*/

//task 4

BookList::BookList(const BookList & x)
{
    this->head = nullptr;
    Element *current = x.head;
    while (current != nullptr)
    {
        Book *copyBook = new Book(*(current->ptr));
        createNewbook(*copyBook);
        current = current->next;
    }
}

BookList &BookList::operator= (const BookList& x)
{
    if(this == &x) //case of self assignment
    {
        return *this;
    }

    while(this->head != nullptr) //case of copy to a non-empty list
    {
        Element *temp = head;
        head = head->next;
        delete temp->ptr;
        delete temp;
    } // first eliminate elements on list

    BookList tempList(x); //use copy constructor, copy x list to a temp list
    swap(this->head, tempList.head); //swap the head (=the entire list) of "this" and "temp"
    return *this;
} 

ostream & operator<< (ostream& os, const BookList& al)
{
    BookList::Element *current = al.head;
    while (current != nullptr)
    {
        os << *(current->ptr) << endl; //using the ostream operator defined in book
        current = current->next;
    }
    return os;
}


