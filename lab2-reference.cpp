#include <iostream>
#include <cstring>
using namespace std;

class Book
{
    char *title;
    int signature;
    int number;
    
    public:
    Book(const char *title, int signature)
    {
        this->title = new char[strlen(title)+1];
        strcpy(this->title,title);
        
        this->signature = signature;
        
        number = 1;
    }
    
    ~Book()
    {
        delete[] title;
    }
    
    void print() //this print() prints data of one book
    {
        cout << "Title: " << title << ", Signature: " << signature << ", Number: " << number << endl;
    }
    
    int getSignature() //to avoid direct access to data!(signatrue and number are private)
    {
        return signature;
    }
    
    void numIncrement()
    {
        number++;
    }
    
    //task 2
    int &refNumber()
    {
        return number;
    }
    
    const char *getTitle() 
    {
        return title;
    }
    
    void changeTitle(const char *title)
    {
        delete[] this->title;
        this->title = new char[strlen(title)+1];
        strcpy(this->title, title);
    }
    
 
};

struct Element //element is a linked list
{
    Book *ptr;
    Element *next;
};

struct Element *head = nullptr;

Book* findBook (int signature)
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

Book* createNewbook(const char *title, int signature)
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

void addBook(const char *title, int signature)
{
    Book *bookExists = findBook(signature);
    if(bookExists!= nullptr) //book is found
    {
        bookExists-> numIncrement(); //current->ptr->number
        return;
    }
    else //book is not on the list
    {
       createNewbook(title, signature);
    }
}

//task 2
int &changeBook(const char *title, int signature)
{
    //search book with a given signature
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

void print()
{
    Element *current = head;
    while (current != nullptr)
    {
        current->ptr->print();
        current = current->next;
    }
}

int main()
{
   
    cout << "Testing an empty list." << endl;
    print();
    
    cout << "\nTesting task 1." << endl;
    
    cout << "\nAdding a new element to an empty list: " << endl;
    addBook("Book13", 13); //begining
    addBook("Book17", 17); //middle
    addBook("Book19", 19); //end
    print();
    
    cout << "\nAdding an existing element: " << endl; 
    addBook("Book13", 13); //begining 
    addBook("Book17", 17); //middle
    addBook("Book19", 19); //end
    print();

    cout << "\nAdding a new element to a non-emptry list: " << endl; 
    addBook("Book12", 12); //begining
    addBook("Book15", 15); //middle
    addBook("Book40", 40); //end
    print();
    
    //now the list has book 12,13,15,17,19,40
    
    cout << "\nTesting task 2." << endl;
    cout << "\nUsing changeBook to add new elements: " << endl;
    changeBook("Book11", 11);  //beginings
    changeBook("Book14", 14);  //middle
    changeBook("Book50",50); //end
    print(); 
    
    //now the list has book 11,12,13,14,15,17,19,40,50
    
    cout << "\nUpdating title and number: " << endl;
    changeBook("OOP1", 11); //begining
    changeBook("OOP4", 14); //middle
    changeBook("OOP11", 50); //end
    print();
    
    cout << "\nUpdating book number: " << endl;
    changeBook("OOP1",11) = 5; //begining
    changeBook("OOP4", 14)++; //middle
    changeBook("OOP11", 50) = 10; //end
    print();

    cout << "\nAdding new elements and updating number: " << endl;
    changeBook("Book10",10) = 3; //begining
    changeBook("Book21", 21)++; //middle
    changeBook("Book60", 60) = 8; //end
    print();
      
      
    return 0;
}


