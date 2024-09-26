#include "Book.h"
#include "BookList.h"
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    BookList l1; //automatic object
    
    cout << "\nRemoving book from empty l1: " << endl;
    l1.removeBook(1); //remove book from an empty list

    cout << "\nAdding books to l1: " << endl;
    l1.addBook("Book1",1);
    l1.addBook("Book2",2);
    l1.addBook("Book2",2); //adding an existing elements
    l1.addBook("Book3",3);
    l1.print();

    cout << "\nChanging titles and number in l1: " << endl;
    l1.changeBook("Book1_changed",1)++;
    l1.changeBook("Book2_changed",2)=6;
    l1.changeBook("Book3_changed",3)++;
    l1.print();

    cout << "\nUsing changeBook to add and change book number in l1: " << endl;
    l1.changeBook("Book4",4);
    l1.changeBook("Book5",5)++; //add a new book and change its number 
    l1.changeBook("Book6",6);
    l1.print();

    cout << "\nRemoving books from l1: " << endl;
    l1.removeBook(1);
    l1.removeBook(5);
    l1.removeBook(6);
    l1.removeBook(7); //remove a non-existing book
    cout << "\nBooks remain in l1: " << endl;
    l1.print();

    BookList *l2 = new BookList(); //dynamic object
    
    cout << "\nRemoving book from empty l2: " << endl;
    l2->removeBook(1); 

    cout << "\nAdding books to l2: " << endl;
    l2->addBook("OOP1",1);
    l2->addBook("OOP2",2);
    l2->addBook("OOP2",2);
    l2->addBook("OOP3",3);
    l2->print();

   cout << "\nUsing changeBook to add book and change books in l2: " << endl;
    l2->changeBook("OOP1",1)++; //change number
    l2->changeBook("OOP2_changed",2); //change title
    l2->changeBook("OOP4",4); //add new book
    l2->changeBook("OOP5",5)=6; //add new book and change number
    l2->print();

    cout << "\nRemoving books from l2: " << endl;
    l2->removeBook(4);
    l2->removeBook(5);
    l2->removeBook(1);
    l2->removeBook(7); //remove a non existing book
    cout << "\nBooks remain in l2: " << endl;
    l2->print();

    cout << "\nDeleting the whole list l2: " << endl;
    delete l2;

    cout << "\nAutomatically deleting the whole list l1: " << endl;
    return 0;
}
