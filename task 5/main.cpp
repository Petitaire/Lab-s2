#include "Book.h"
#include "BookList.h"
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    BookList aList; //automatic object
    BookList *pList = new BookList(); //dynamic object

    cout << "Testing all list manipulations." << endl;
    cout << "\nRemoving book from empty pList: " << endl;
    pList->removeBook(1); 

    cout << "\nAdding books to pList: " << endl;
    pList->addBook("OOP1",1);
    pList->addBook("OOP2",2);
    pList->addBook("OOP2",2);
    pList->addBook("OOP3",3);
    cout << *pList << endl;

    cout << "\nUsing changeBook to add book and change books in pList: " << endl;
    pList->changeBook("OOP1",1)++; //change number
    pList->changeBook("OOP2_changed",2); //change title
    pList->changeBook("OOP4",4); //add new book
    pList->changeBook("OOP5",5)=6; //add new book and change number
    cout << *pList << endl;

    cout << "\nRemoving books from pList: " << endl;
    pList->removeBook(4);
    pList->removeBook(5);
    pList->removeBook(1);
    pList->removeBook(7); //remove a non existing book
    cout << "\nBooks left in pList: " << endl;
    cout << *pList << endl;
    pList->addBook("OOP4",4); //check if still possible to add book 

    cout <<"\nSelf assignment of pList: " << endl;
    (*pList) = (*pList);
    cout << *pList << endl;

    cout << "\nCopying pList to aList." << endl;
    aList = (*pList);  
    //here a deleting message will be printed because tempList is deleted automatically

    cout << "\nDeleting the whole pList: " << endl;
    delete pList;

    cout << "\naList after copying: " << endl;
    cout << aList << endl; 

    cout <<"\nSelf assignment of aList: " << endl;
    aList = aList;
    cout << aList << endl;

    cout << "\nModifying aList:" << endl;
    aList.removeBook(2);
    aList.addBook("OOP5",5);
    aList.changeBook("OOP6",6)++;
    cout << aList << endl;

    cout << "\nCopying aList:" << endl;
    BookList aList_copy = BookList(aList);
    cout << aList << endl;

    cout << "\nAutomatically deleting the whole list aList and aList_copy: " << endl;

    /*task 5*/
    BookList *l1 = new BookList();
    BookList *l2 = new BookList();

    l2->addBook("OOP1",1);
    cout << "\nTesting an empty list - a non empty list: " << endl;
    (*l1-*l2).print();

    cout << "Inserting elemetns to both list." << endl;
    l2->addBook("OOP2",2);
    l2->addBook("OOP3",3);
    l1->addBook("Book11",11);
    l1->addBook("Book12",12);
    l1->addBook("OOP1",1); //same book in l1 and l2
    l1->addBook("Book2",2);//same signature in l1 and l2

    cout << "\nPrinting l1: " << endl;
    l1->print();

    cout << "\nPrinting l2: " << endl;
    l2->print();

    cout << "\nTesting operation +: " << endl;
    BookList *resultL1 = new BookList();
    *resultL1 = *l1 + *l2;

    cout << "\nTesting operation - " << endl;
    BookList *resultL2 = new BookList();
    *resultL2 = *l1 - *l2;
    delete l1;
    delete l2;
    cout << "\nPrinting result L1: " << endl;
    resultL1->print();
    cout << "\nPrinting result L2: " << endl;
    resultL2->print();

    return 0;
}
