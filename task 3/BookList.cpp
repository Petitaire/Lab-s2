#include "BookList.h"
#include <iostream>
#include <cstring>
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

Book *BookList::createNewbook(const char *title, int signature)
{
    Book *newBook = new Book(title, signature);
    Element *newElement = new Element;
    newElement->ptr = newBook; //link new element to new book 
        
    if(head == nullptr || head->ptr->getSignature() > signature)
    {
        newElement->next = head; //next = nullptr, the last place in the list is always nullptr
        head = newElement;
    }
    else
    {
        Element *current = head;
            
        while(current->next != nullptr && current->next->ptr->getSignature() < signature) 
        {
            current = current->next;
        }
            //when current is the last, or current->next has a larger signature 
            //(which means that new book should be insert right after current, 
            //the original current->next should be moved after new book)
        
        newElement->next = current->next; //next = nullptr
        current->next = newElement;
    }
    
    return newBook;
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
       createNewbook(title, signature);
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
        Book *newBook=createNewbook(title, signature);
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

void BookList::print()
{
    Element *current = head;
    while(current != nullptr)
    {
        cout << "Title: " << current->ptr->getTitle() << ", Signature: " << current->ptr->getSignature() << ", Number: " << current->ptr->refNumber() << endl;
        current = current->next;
    }
}

