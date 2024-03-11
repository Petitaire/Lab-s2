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

void addBook(const char *title, int signature)
{
    Book *bookExists = findBook(signature);
    if(bookExists!= nullptr) //book is found in the list
    {
        bookExists-> numIncrement(); //current->ptr->number
        return;
    }
    else //book is not in the list
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
            //when current is the last, or current->next has a larger signature (which means that new book should be insert right after current, the original current->next should be moved after new book)
            newElement->next = current->next; //next = nullptr
            current->next = newElement;
        }
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
    //test an emptry list
    print();
    
    cout << "\nThe test result of adding a new element to an empty list: " << endl;

    //at the begining
    addBook("Book1", 1);
  
    //at the end
    addBook("Book4", 4);
    
    //in the middle
    addBook("Book2", 2);
    
    print();
    
    cout << "\nThe test result of adding an existing element: " << endl; 

    //at the begining
    addBook("Book1", 1);
  
    //at the end
    addBook("Book4", 4);
    
    //in the middle
    addBook("Book2", 2);
    
    print();

    cout << "\nThe test result of adding a new element to a non-emptry list: " << endl; 

    //at the begining
    addBook("Book0", 0);
  
    //at the end
    addBook("Book5", 5);
    
    //in the middle
    addBook("Book3", 3);

    print();
    
    return 0;
}