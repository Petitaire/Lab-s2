#ifndef TRAINER_H
#define TRAINER_H
#include <iostream>
#include <string>
#include <vector>
#include "member.hpp"
#include "lesson.hpp"
#include "slot.hpp"
using namespace std;

class Member;
class Lesson;
class Slot;

class Trainer
{
    string name;
    char gender; //only m,f
    int age; //>18
    int phone; //>100,000,000
    int salaries; // >=5000
    int ID; //positive
    bool contractSigned;
    Member *myMember;
    Lesson *myLesson;
    vector<Slot*>schedule;


    public:
    Trainer(string &name, char gender, int age, int phone, int saleries, int ID)
    {
        this->name = name;
        this->gender = gender;
        this->age = age;
        this->phone = phone;
        this->salaries = saleries;
        this->ID = ID;

        //default setting
        contractSigned = true;
        myMember = nullptr;
        myLesson = nullptr;
    }

    ~Trainer()
    {
        schedule.clear();
    }

    string getName() const;
    char getGender() const;
    int getAge() const;
    int getPhone() const;
    int getSalaries() const;
    int getID() const;
    bool isContractSigned();
    Member *getMember() const;
    Lesson *getLesson() const;
    vector <Slot*>& getScheduel();
    Slot *findSlot(string &day, float t1, float t2);

    bool addSlot(string &day, float t1, float t2);
    bool removeSlot(string &day, float t1, float t2);
    void updateInfo(string &name, int age, int phone, int salaries);
    void setMember(Member *m);
    void setLesson(Lesson *l);
    void contractExpired();
    void signContract();
};
#endif