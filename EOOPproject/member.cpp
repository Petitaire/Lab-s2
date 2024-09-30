#include <iostream>
#include <string>
#include <vector>
#include "trainer.hpp"
#include "member.hpp"
using namespace std;

string Member::getName() const
{
    return name;
}

char Member::getGender() const
{
    return gender;
}

int Member::getAge() const
{
    return age;
}

int Member::getPhone() const
{
    return phone;
}

int Member::getSubscription() const
{
    return subscription;
}

int Member::getID() const
{
    return ID;
}

bool Member::isSubscriptionPaid()
{
    return subscriptionPaid;
}

bool Member::isTrainerPaid()
{
    return trainerPaid;
}

Trainer* Member::getTrainer() const
{
    return myTrainer;
}

vector<Slot *>& Member::getSlot() 
{
    return slotBooked;
}

void Member::updateInfo(string &name, int age, int phone, int subscription)
{
    this->name = name;
    this->age = age;
    this->phone = phone;
    this->subscription = subscription;
    /*assume only info above can be changed*/
}

void Member::setTrainer(Trainer *t)
{
    myTrainer = t;
}

void Member::setSubscription(int subscription)
{
    this->subscription = subscription;
}

void Member::paySubscription()
{
     subscriptionPaid = true;
}

void Member::payTrainer()
{
     trainerPaid = true;
}
