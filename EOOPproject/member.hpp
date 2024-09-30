#ifndef MEMBER_H
#define MEMBER_H
#include <iostream>
#include <string>
#include <vector>
#include "trainer.hpp"
#include "slot.hpp"
using namespace std;

class Trainer;
class Slot;

class Member
{
    string name;
    char gender; //only m,f
    int age; //>18
    int phone; //>100,000,000
    int subscription; //only 0,3,6,12
    int ID; //positive
    bool subscriptionPaid;
    bool trainerPaid;
    Trainer *myTrainer;
    vector<Slot*>slotBooked;

    public:
    Member(string &name, char gender, int age, int phone, int subscription, int ID)
    {
        this->name = name;
        this->gender = gender;
        this->age = age;
        this->phone = phone;
        this->subscription = subscription;
        this->ID = ID;

        //default setting
        subscriptionPaid = true;
        trainerPaid = false;
        myTrainer = nullptr;
    }

    ~Member()
    {
        if (!slotBooked.empty()) 
        {
            for (Slot* s : slotBooked) 
            {
                if (s)
                {
                    s->freeSlot(); 
                }
            }
            slotBooked.clear(); 
        }
    }

    string getName() const;
    char getGender() const;
    int getAge() const;
    int getPhone() const;
    int getSubscription() const;
    int getID() const;
    bool isSubscriptionPaid();
    bool isTrainerPaid();
    Trainer *getTrainer() const; 
    vector<Slot*>& getSlot() ;

    void updateInfo(string &name, int age, int phone, int subscription);
    void setTrainer(Trainer *t);
    void setSubscription(int subscription);
    void paySubscription();
    void payTrainer();
};

#endif