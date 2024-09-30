#include <iostream>
#include <string>
#include <iomanip>
#include "slot.hpp"

string Slot::getDay() const
{
    return day;
}

float Slot::getTimeStart() const
{
    return timeStart;
}

float Slot::getTimeEnd() const
{
    return timeEnd;
}

void Slot::printDetail()
{
    cout << fixed << setprecision(2);
    cout << "Day: " << day << ", start time: " << timeStart << ", end time: " << timeEnd << ", ";
    if(isAvailable)
        cout << "available." << endl;
    else
        cout<< "unavailable." << endl;
    cout << "number of participants: " << currentParticipants << endl;
}

bool Slot::getAvailability() const
{
    return isAvailable;
}

void Slot::slotTaken()
{
    isAvailable = false;
}

void Slot::freeSlot()
{
    isAvailable = true;
}

int &Slot::getParticipants()
{
    return currentParticipants;
}
