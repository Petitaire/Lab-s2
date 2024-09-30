#include <iostream>
#include <string>
#include <vector>
#include "member.hpp"
#include "lesson.hpp"
#include "trainer.hpp"

string Trainer::getName() const
{
    return name;
}

char Trainer::getGender() const
{
    return gender;
}

int Trainer::getAge() const
{
    return age;
}

int Trainer::getPhone() const
{
    return phone;
}

int Trainer::getSalaries() const
{
    return salaries;
}

int Trainer::getID() const
{
    return ID;
}

bool Trainer::isContractSigned()
{
    return contractSigned;
}

Member *Trainer::getMember() const
{
    return myMember;
}

Lesson *Trainer::getLesson() const
{
    return myLesson;
}

vector<Slot *>& Trainer::getScheduel()
{
    return schedule;
}

Slot *Trainer::findSlot(string &day, float t1, float t2)
{
    if(!schedule.empty())
    {
        for(Slot *s : schedule)
        {
            if (s->getDay() == day && s->getTimeStart() == t1 && s->getTimeEnd () == t2)
            {
                return s;
            }
        }
    }
    
    return nullptr;
}

bool Trainer::addSlot(string &day, float t1, float t2)
{
    if(findSlot(day, t1, t2) == nullptr)
    {
        Slot *newSlot = new Slot(day, t1, t2);
        schedule.push_back(newSlot);
        return true;
    }

    return false;
}

bool Trainer::removeSlot(string &day, float t1, float t2)
{
    Slot *slotExists = findSlot(day, t1, t2);
    if(slotExists != nullptr)
    {
        auto s = find(schedule.begin(), schedule.end(), slotExists);
        schedule.erase(s);
        delete slotExists;
        return true;
    }
    return false;
}

void Trainer::updateInfo(string &name, int age, int phone, int salaries)
{
    this->name = name;
    this->age = age;
    this->phone = phone;
    this->salaries = salaries;
}

void Trainer::setMember(Member *m)
{
    myMember = m;
}

void Trainer::setLesson(Lesson *l)
{
    myLesson = l;
}

void Trainer::contractExpired()
{
    contractSigned = false;
}

void Trainer::signContract()
{
    contractSigned = true;
}
