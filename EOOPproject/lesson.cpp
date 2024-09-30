#include "lesson.hpp"

string Lesson::getName() const
{
    return name;
}

int Lesson::getLimit() const
{
    return limit;
}

int Lesson::getID() const
{
    return ID;
}

vector<Slot *>& Lesson::getScheduel() 
{
    return schedule;
}

Trainer *Lesson::getConductor() const
{
    return conductor;
}

bool Lesson::ifStarted() const
{
    return started;
}

void Lesson::updateInfo(string &name, int limit)
{
    this->name = name;
    this->limit = limit;
}

void Lesson::setConductor(Trainer *t)
{
    conductor = t;
}

void Lesson::setToStart()
{
    started = true;
}
