#ifndef SLOT_H
#define SLOT_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Slot
{
    string day;
    float timeStart;
    float timeEnd;
    bool isAvailable;
    int currentParticipants;

public:
    Slot(string day, float t1, float t2)
    {
        this->day = day;
        timeStart = t1;
        timeEnd = t2;
        isAvailable = true;
        currentParticipants = 0;
    }

    ~Slot(){}

    string getDay() const;
    float getTimeStart() const;
    float getTimeEnd() const;
    void printDetail();
    bool getAvailability() const;
    void slotTaken();
    void freeSlot();
    int &getParticipants();
};

#endif