#ifndef LESSON_H
#define LESSON_H
#include <iostream>
#include <string>
#include <vector>
#include "trainer.hpp"
#include "slot.hpp"
using namespace std;

class Trainer;
class Slot;

class Lesson
{
    string name;
    int limit;
    int ID;
    vector<Slot*> schedule;
    Trainer *conductor;
    bool started;

public:
    Lesson(string &name, int limit, int ID)
    {
        this->name = name;
        this->limit = limit;
        this->ID = ID;
        conductor = nullptr;
    }

    ~Lesson()
    {
        if (!schedule.empty()) 
        {
            for (Slot* s : schedule) 
            {
                if (s)
                {
                    s->freeSlot(); 
                }
            }
            schedule.clear();
        }
    }

    string getName() const;
    int getLimit() const;
    int getID() const;
    vector <Slot*>& getScheduel();
    Trainer *getConductor() const;
    bool ifStarted() const;

    void updateInfo(string &name, int limit);
    void setConductor(Trainer *t);
    void setToStart();

};
#endif