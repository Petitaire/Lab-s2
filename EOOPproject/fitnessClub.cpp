#include <iostream>
#include <string>
#include <vector>
#include "member.hpp"
#include "trainer.hpp"
#include "lesson.hpp"
#include "slot.hpp"
#include "fitnessClub.hpp"
using namespace std;

//private methods related to member
Member *FitnessClub::findMember(int ID)
{
    for(Member *m: members)
    {
        if(m->getID() == ID)
            return m;
    }
    
    return nullptr;
}

Member *FitnessClub::manageMember(string &name, char gender, int age, int phone, int subscription, int ID)
{
    char genderToLower = tolower(gender);
    /*check input data*/
    if (age < 18 || phone < 100000000 || (genderToLower != 'm' && genderToLower != 'f') || (subscription != 0 && subscription != 3 && subscription != 6 && subscription != 12) || ID <= 0)
    {
        return nullptr; /*not accepable data*/
    }

    Member *memberExists = findMember(ID);

    if(memberExists)
    {
        memberExists->updateInfo(name, age, phone, subscription);
        std::cout << "member found, updating information." << endl;
    }
    else
    {
        memberExists = new Member(name, gender, age, phone, subscription, ID);
        members.push_back(memberExists);
        std::cout << "member is not found, creating new member." << endl;
    }

    return memberExists;
}

//private methods related to trainer
Trainer *FitnessClub::findTrainer(int ID)
{
    for(Trainer *t: trainers)
    {
        if(t->getID() == ID)
            return t;
    }
    return nullptr;
}

Trainer *FitnessClub::manageTrainer(string &name, char gender, int age, int phone,int saleries, int ID)
{
    char genderToLower = tolower(gender);
    if (age < 18 || phone < 100000000 || (genderToLower != 'm' && genderToLower != 'f') || saleries < 5000 || ID <= 0)
    {
        return nullptr; 
    }

    Trainer *trainerExists = findTrainer(ID);

    if(trainerExists)
    {
        trainerExists->updateInfo(name, age, phone, saleries);
        std::cout << "trainer found, updating information." << endl;
    }
    else
    {
        trainerExists = new Trainer(name, gender, age, phone, saleries, ID);
        trainers.push_back(trainerExists);
        std::cout << "trainer is not found, creating new trainer." << endl;
    }

    return trainerExists;
}

//private methods related to lesson
Lesson *FitnessClub::findLesson(int ID)
{
    for(Lesson *l: lessons)
    {
        if(l->getID() == ID)
            return l;
    }
    return nullptr;
}

Lesson *FitnessClub::manageLesson(string &name, int limit, int ID)
{
    if( limit <= 5 || ID <= 0)
    {
        return nullptr;
    }

    Lesson *lessonExists = findLesson(ID);

    if(lessonExists)
    {
        lessonExists->updateInfo(name,limit);
        std::cout << "lesson found, updating information." << endl;
    }
    else
    {
        lessonExists = new Lesson(name, limit,ID);
        lessons.push_back(lessonExists);
        std::cout << "lesson is not found, creating new lesson." << endl;
    }

    return lessonExists;
}

//public methods related to member
bool FitnessClub::subscribeOrUpdateMember(string &name, char gender, int age, int phone, int subscription, int ID)
{
    Member *m = manageMember(name, gender, age, phone, subscription, ID);
    if(m)
    {
        std::cout << "member " << ID << " is subscribed/updated successfully." << endl;
        return true;
    }
    else 
    {
        std::cout << "member " << ID << " can't be subscribed/updated, please check the data." <<endl; 
        return false;
    }
}

bool FitnessClub::unsubscribeMember(int ID)
{
    Member *memberExists = findMember(ID);

    if(!memberExists)
    {
       std::cout << "member " << ID << " doesn't exist." << endl;
        return false;
    }

     Trainer* trainerExists = memberExists->getTrainer();
    if (trainerExists) 
    {
        trainerExists->setMember(nullptr);
    }
    memberExists->setTrainer(nullptr);

    auto m = find(members.begin(), members.end(), memberExists);
    members.erase(m); //remove member from the list

    delete memberExists;
    std::cout << "member " << ID << " is unsubscribed successfully." << endl;
    return true;
}


bool FitnessClub::memberPaySubscription(int ID)
{
    Member *memberExists = findMember(ID);
    if(memberExists)
    {
        memberExists->paySubscription();
        std::cout << "member " << ID << " subscription is paid." << endl;
        return true;
    }
    else
    {
        std::cout << "member " << ID << " doesn't exist." << endl;
        return false;
    }
}

bool FitnessClub::memberPayTrainer(int ID)
{
    Member *memberExists = findMember(ID);
    if(memberExists)
    {
        memberExists->payTrainer();
        std::cout << "member " << ID << " trainer is paid." << endl;
        return true;
    }
    else
    {
        std::cout << "member " << ID << " doesn't exist." << endl;
        return false;
    }
}

void FitnessClub::printAllMember()
{
    for(Member *m : members)
    {
        std::cout << "Member " << m->getID() << ", ";
        std::cout << "name: " << m->getName() << ", ";
        std::cout << "gender: " << m->getGender() << ", ";
        std::cout << "age: " << m->getAge() << ", ";
        std::cout << "phone: " << m->getPhone() << ", ";
        std::cout << "subscription: " << m->getSubscription() << ", ";

        if(m->isSubscriptionPaid())
            std::cout << "subscription is paid, ";
        else
            std::cout << "subscription is not paid, ";

        if(m->isTrainerPaid())
            std::cout << "trainer is paid, ";
        else
            std::cout << "trainer is not paid, ";
        
        if(m->getTrainer())
            std::cout << "trainer: " << m->getTrainer()->getName() << ", ";
        else 
            std::cout << "trainer: none,";

        std::cout << "Slot booked: " << endl;
        if(m->getSlot().empty())
            std::cout << "none.";
        else
        {
            for (Slot *s : m->getSlot())
            {
                s->printDetail();
            }
        }
        std::cout << endl;
    }

}

//public methods related to trainer
bool FitnessClub::recruiteOrUpdateTrainer(string &name, char gender, int age, int phone, int saleries, int ID)
{
    Trainer *t = manageTrainer(name, gender, age, phone, saleries, ID);
    if(t)
    {
        std::cout << "Trainer " << ID << " is recruited/updated successfully." << endl;
        return true;
    }
    else 
        std::cout << "Trainer " << ID << " is not recruited/updated, please check the data." << endl;  
        return false;
}

bool FitnessClub::dismissTrainer(int ID)
{
    Trainer *trainerExist = findTrainer(ID);
    if(!trainerExist)
    {
        std::cout << "trainer " << ID << " doesn't exist." << endl;
        return false;   
    }
    Member *memberExist = trainerExist->getMember();
    vector<Slot*>& trainerSlots = trainerExist->getScheduel();
    if(memberExist)
    {
        memberExist->setTrainer(nullptr);
        vector<Slot*>& memberSlots = memberExist->getSlot();
        for (Slot* s : memberSlots)
        {
            auto it = find(trainerSlots.begin(), trainerSlots.end(), s);
            if (it != trainerSlots.end())
            {
                trainerSlots.erase(it);
            }
            delete s;
        }
        memberSlots.clear();
    }
    trainerExist->setMember(nullptr);

    Lesson *lessonExist = trainerExist->getLesson();
    if(lessonExist)
    {
        lessonExist->setConductor(nullptr);
        vector<Slot*>& lessonSlots = lessonExist->getScheduel();
        for (Slot* s : lessonSlots)
        {
            auto it = find(trainerSlots.begin(), trainerSlots.end(), s);
            if (it != trainerSlots.end())
            {
                trainerSlots.erase(it);
            }
            delete s; 
        }
        lessonSlots.clear();
    }
    trainerExist->setLesson(nullptr);

    for (Slot* s : trainerSlots)
    {
        delete s; 
    }
    trainerSlots.clear();

    auto t = find(trainers.begin(), trainers.end(), trainerExist);
    trainers.erase(t); 
        
    delete trainerExist;
    std::cout << "trainer " << ID << " is dismissed successfully." << endl;
    return true;
}

bool FitnessClub::trainerContractExpired(int ID)
{
    Trainer *trainerExits = findTrainer(ID);
    if(trainerExits)
    {
        trainerExits->contractExpired();
        return true;
    }

    return false; 
}

bool FitnessClub::trainerSignContract(int ID)
{
    Trainer *trainerExits = findTrainer(ID);
    if(trainerExits)
    {
        trainerExits->signContract();
        return true;
    }
    return false; 
}

bool FitnessClub::trainerAddSlot(int ID, string &day, float t1, float t2)
{
    Trainer *trainerExits = findTrainer(ID);
    if(trainerExits)
    {
        trainerExits->addSlot(day, t1, t2);
        std::cout << "Trainer " << ID << " slot is added." << endl;
        return true;
    }
    else
    {
        std::cout << "Trainer " << ID << " doesn't exist." << endl;
        return false;
    }
}

bool FitnessClub::trainerRemoveSlot(int ID, string &day, float t1, float t2)
{
    Trainer *trainerExist = findTrainer(ID);
    if(!trainerExist)
    {
        std::cout << "Trainer " << ID << " doesn't exist." << endl;
        return false;
    }
    
    Slot *s = trainerExist->findSlot(day, t1, t2);

    if (!s)
    {
        std::cout << "Slot not found in trainer's schedule." << std::endl;
        return false;
    }
  
    Member* memberExist = trainerExist->getMember();
    if (memberExist)
    {
        vector<Slot*>& memberSlots = memberExist->getSlot();
        auto memberSlotExist = find(memberSlots.begin(), memberSlots.end(), s);
        if (memberSlotExist != memberSlots.end())
        {
            memberSlots.erase(memberSlotExist);
        }
    }

    // Remove the slot from the lesson's schedule if it's booked by a lesson
    Lesson* lessonExists = trainerExist->getLesson();
    if (lessonExists)
    {
        vector<Slot*>& lessonSlots = lessonExists->getScheduel();
        auto lessonSlotExist = find(lessonSlots.begin(), lessonSlots.end(), s);
        if (lessonSlotExist != lessonSlots.end())
        {
            lessonSlots.erase(lessonSlotExist);
        }
    }

        trainerExist->removeSlot(day, t1, t2);
        std::cout << "Trainer " << ID << " slot is removed." << endl;
        return true;
}

void FitnessClub::printAllTrainer()
{
     for(Trainer *t : trainers)
    {
        std::cout << "Trainer " << t->getID() << ", ";
        std::cout << "name: " << t->getName() << ", ";
        std::cout << "gender: " << t->getGender() << ", ";
        std::cout << "age: " << t->getAge() << ", ";
        std::cout << "phone: " << t->getPhone() << ", ";
        std::cout << "salaries: " << t->getSalaries() << ", ";

        if(t->isContractSigned())
            std::cout << "contract is signed, ";
        else
            std::cout << "constract is not paid, ";

        if(t->getMember())
            std::cout << "member: " << t->getMember()->getName() << ", ";
        else
            std::cout << "member: none, ";
        
        if(t->getLesson())
            std::cout << "lesson: " << t->getLesson()->getName() << ", ";
        else 
            std::cout << "lesson: none, ";

        std::cout << "Schedule: " << endl;
        if(t->getScheduel().empty())
            std::cout << "none.";
        else
        {
            for (Slot *s : t->getScheduel())
            {
                s->printDetail();
            }
        }
        std::cout << endl;
    }
}

//public methods related to lesson
void FitnessClub::createOrUpdateLesson(string &name, int limit, int ID)
{
    Lesson *l = manageLesson(name, limit, ID);
    if(l)
        std::cout << "lesson " << ID << " is created/updated successfully." << endl; 
    else 
        std::cout << "lesson " << ID << " is not created/updated, please check the data." << endl; ;  
}

bool FitnessClub::deleteLesson(int ID)
{
    Lesson *lessonExist = findLesson(ID);
    if(!lessonExist)
    {
       std::cout << "lesson " << ID << " doesn't exist." << endl;
        return false;
    }
    else
    {
        Trainer *conductorExist = lessonExist->getConductor();
        if(conductorExist)
        {
            conductorExist->setLesson(nullptr);
        }
        lessonExist->setConductor(nullptr);

        auto l = find(lessons.begin(), lessons.end(), lessonExist);
        lessons.erase(l); 
        
        delete lessonExist;
        std::cout << "lesson " << ID << " is deleted successfully." << endl;
        return true;
    }
}

void FitnessClub::printAllLesson()
{
    for(Lesson *l: lessons)
    {
        std::cout << "Lesson " << l->getID() << ", ";
        std::cout << "name: " << l->getName() << ", ";
        
        if(l->getConductor())
            std::cout << "conductor: " << l->getConductor()->getName() << ", ";
        else
            std::cout << "conductor: none, ";

        std::cout << "Schedule: " << endl;
        if(l->getScheduel().empty())
            std::cout << "none.";
        else
        {
            for (Slot *s : l->getScheduel())
            {
                s->printDetail();
            }
        }
        std::cout << endl;
    }
}
//interaction between member and trainer
bool FitnessClub::assignTrainerToMember(int memberID, int trainerID)
{
    Member *memberExist = findMember(memberID);
    Trainer *trainerExist = findTrainer(trainerID);
    if(!memberExist)
    {
        std::cout << "member " << memberID << " doesn't exits." << endl;
        return false;
    }
    if(!trainerExist)
    {
        std::cout << "trainer " << trainerID << " doesn't exits." << endl;
        return false;
    }
    
    if(memberExist->getTrainer())
    {
        std::cout << "member " << memberID << " alreay has a trainer." << endl;
        return false;
    }
    
    if(trainerExist->getMember())
    {
       std::cout << "The trainer " << trainerID << " already has a member "  <<  endl;
        return false;
    }

    memberExist->setTrainer(trainerExist);
    trainerExist->setMember(memberExist);
    std::cout << "trainer " << trainerID << " is successfully assigned to member " << memberID << endl;
    return true;
}

bool FitnessClub::memberBookSlot(int memberID, string &day, float t1, float t2)
{
    Member *memberExits = findMember(memberID);
    if(!memberExits)
    {
        std::cout << "member " << memberID << " doesn't exist." << endl;
        return false;
    }

    Trainer *trainerExits = memberExits->getTrainer();
    if(!trainerExits)
    {
        std::cout << "member " << memberID << " doesn't have trainer." << endl;
        return false;
    }

    Slot *slotExits = trainerExits->findSlot(day, t1, t2);
    if(!slotExits)
    {
        cout << "slot is not found" << endl;
        return false;
    }                
    if(!slotExits->getAvailability())
    {
        cout << "slot is not available" << endl;
        return false;
    }
        
    memberExits->getSlot().push_back(slotExits);
    slotExits->slotTaken();
    cout << "member " << memberID << " successfully booked a slot." << endl;
    return true;
}

bool FitnessClub::memberCancelSlot(int memberID, string &day, float t1, float t2)
{
    Member *memberExist = findMember(memberID);
    if(!memberExist)
    {
        cout << "member " << memberID << " doesn't exist." << endl;
        return false;
    }
    else
    {
        Trainer *trainerExist = memberExist->getTrainer();
        if(!trainerExist)
        {
            cout << "member " << memberID << " doesn't have trainer." << endl;
            return false;
        }
        else
        {
           Slot *slotExist = trainerExist->findSlot(day, t1, t2);
           if(!slotExist)
           {
                cout << "member " << memberID << " conductor doesn't have this slot." << endl;
                return false;
           }
           else
           {
                slotExist->freeSlot();
                auto& slots = memberExist->getSlot();
                auto s = find(slots.begin(), slots.end(), slotExist);
                if(s == slots.end()) 
                {
                    cout << "member " << memberID << " didn't book this slot." << endl;
                    return false;
                }
                else
                {
                    slots.erase(s); 
                    cout << "member " << memberID << " successfully canceled a slot." << endl;
                    return true;
                }
           }
        }
    }
}

bool FitnessClub::freeTrainerFromMember(int memberID)
{
    Member *memberExist = findMember(memberID);
    if(!memberExist)
    {
        cout << "member " << memberID << " doesn't exist." << endl;
        return false;
    }
    else
    {
        Trainer *trainerExist = memberExist->getTrainer();
        if(!trainerExist)
        {
            cout << "member " << memberID << " doesn't have trainer." << endl;
            return false;
        }
        else
        {
            vector<Slot*>& slots = memberExist->getSlot();
            for (auto s = slots.begin(); s != slots.end(); )
            {
                (*s)->freeSlot();
                s = slots.erase(s); 
            }
            memberExist->setTrainer(nullptr);
            trainerExist->setMember(nullptr);
            cout << "the trainer of " << "member " << memberID << " is free." << endl;
            return true;
        }
    }
}

//interaction between trainer and lesson
bool FitnessClub::assignTrainerToLesson(int lessonID, int trainerID)
{
    Lesson *lessonExist = findLesson(lessonID);
    Trainer *conductorExist = findTrainer(trainerID);
    if(!lessonExist)
    {
        std::cout << "lesson " << lessonID << " doesn't exist." << endl;
        return false;
    }
    else if(!conductorExist)
    {
        std::cout << "conductor " << trainerID << " doesn't exist." << endl;
        return false;
    }

    else
    {
        Trainer *lessonHasConductor = lessonExist->getConductor();
        Lesson *conductorHasLesson = conductorExist->getLesson();
        
        if(lessonHasConductor)
        {
            std::cout << "lesson " << lessonID << " has another conductor " << lessonHasConductor->getID() << ", please remove the trainer first." << endl;
            return false;
        }
        else if(conductorHasLesson)
        {
            std::cout << "conductor " << trainerID << " has been assigned to another lesson " << conductorHasLesson->getID() << ", please free the trainer from lesson first." << endl;
            return false;
        }
        else
        {
            lessonExist->setConductor(conductorExist);
            conductorExist->setLesson(lessonExist);
            std::cout << "trainer " << trainerID << " is successfully assigned to lesson " << lessonID << endl;
            return true;
        }
    }
}

bool FitnessClub::LessonBookSlot(int lessonID, string &day, float t1, float t2)
{
    Lesson *lessonExist = findLesson(lessonID);
    if(!lessonExist)
    {
        cout << "lesson " << lessonID << " doesn't exist." << endl;
        return false;
    }
 
    Trainer *conductorExist = lessonExist->getConductor();
    if(!conductorExist)
    {
        cout << "lesson " << lessonID << " doesn't have conductor." << endl;
        return false;
    }
  
    Slot *slotExist = conductorExist->findSlot(day, t1, t2);
    if(!slotExist)
    {
        cout << "slot is not found." << endl;
        return false;
    }

    if(!slotExist->getAvailability())  
    {
        cout << "slot is not available." << endl;
        return false;
    }
    lessonExist->getScheduel().push_back(slotExist);
    slotExist->slotTaken();
    cout << "lesson " << lessonID << " successfully booked a slot." << endl;
    return true;
}


bool FitnessClub::LessonCancelSlot(int lessonID, string &day, float t1, float t2)
{
    Lesson *lessonExist = findLesson(lessonID);
    if(!lessonExist)
    {
        cout << "lesson " << lessonID << " doesn't exist." << endl;
        return false;
    }
    else
    {
        Trainer *trainerExist = lessonExist->getConductor();
        if(!trainerExist)
        {
            cout << "lesson " << lessonID << " doesn't have conductor." << endl;
            return false;
        }
        else
        {
           Slot *slotExist = trainerExist->findSlot(day, t1, t2);
           if(!slotExist)
           {
                cout << "lesson " << lessonID << " conductor doesn't have this slot" << endl;
                return false;
           }
           else
           {
                slotExist->freeSlot();
                auto& slots = lessonExist->getScheduel();
                auto s = find(slots.begin(), slots.end(), slotExist);
                if(s == slots.end()) 
                {
                    cout << "lesson " << lessonID << " didn't book this slot." << endl;
                    return false;
                }
                else
                {
                    slots.erase(s); 
                    cout << "lesson " << lessonID << " successfully canceled a slot." << endl;
                    return true;
                }
           }
        }
    }
}

bool FitnessClub::freeTrainerFromLesson(int lessonID)
{
    Lesson *lessonExist = findLesson(lessonID);
    if(!lessonExist)
    {
        cout << "lesson " << lessonID << " doesn't exist." << endl;
        return false;
    }
    else
    {
        Trainer *trainerExist = lessonExist->getConductor();
        if(!trainerExist)
        {
            cout << "lesson " << lessonID << " doesn't have trainer." << endl;
            return false;
        }
        else
        {
            vector<Slot*>& slots = lessonExist->getScheduel();
            for (auto s = slots.begin(); s != slots.end(); )
            {
                (*s)->freeSlot();
                s = slots.erase(s); 
            }
            lessonExist->setConductor(nullptr);
            trainerExist->setLesson(nullptr);
            cout << "the trainer of " << "lesson " << lessonID << " is free." << endl;
            return true;
        }
    }
}

//methods related to lesson
bool FitnessClub::lessonStarts(int lessonID, string &day, float t1, float t2)
{
    Lesson *lessonExits = findLesson(lessonID);
    if(!lessonExits)
    {
        cout << "lesson " << lessonID << " doesn't exist" << endl;
        return false;
    }
    Trainer *conductorExits = lessonExits->getConductor();
    if(!conductorExits)
    {
        cout << "lesson " << lessonID << " doesn't have a conductor" << endl;
        return false;
    }
    Slot *slotExits = conductorExits->findSlot(day, t1, t2);
    if(!slotExits)
    {
        cout << "slot is not found." << endl;
        return false;
    } 
    
    if(slotExits->getParticipants() != 0)
    {
        cout << "lesson had already started." << endl;
        return false;
    }
    
    lessonExits->setToStart();
    cout << "lesson is set to start." << endl;
    return true;
}

bool FitnessClub::addParticipants(int lessonID, string &day, float t1, float t2)
{
    Lesson *lessonExits = findLesson(lessonID);
    if(!lessonExits)
    {
        cout << "lesson " << lessonID << " doesn't exist" << endl;
        return false;
    }
    
    if(!lessonExits->ifStarted()) //lesson started = the conductor/slot exits, no need to check 
    {
        cout << "lesson " << lessonID << " hasn't started" << endl;
        return false;
    }
    Slot *slot = lessonExits->getConductor()->findSlot(day, t1, t2);
    if(!slot)
    {
        cout << "slot is not found." << endl;
        return false;
    }
    if(slot->getParticipants() == lessonExits->getLimit())
    {
        cout << "participants reach limit." << endl;
        return false;
    }

    slot->getParticipants()++;
    cout << "partcipant added. current participants: " << slot->getParticipants() << endl;
    return true;
}


bool FitnessClub::lessonEnds(int lessonID, string &day, float t1, float t2)
{
    Lesson *lessonExits = findLesson(lessonID);
    if(!lessonExits)
    {
        cout << "lesson " << lessonID << " doesn't exist" << endl;
        return false;
    }
    
    if(!lessonExits->ifStarted()) //lesson started = the conductor/slot exits, no need to check 
    {
        cout << "lesson " << lessonID << " hasn't started" << endl;
        return false;
    }
    
    Slot *slot = lessonExits->getConductor()->findSlot(day, t1, t2);
    if(!slot)
    {
        cout << "slot is not found." << endl;
        return false;
    }
    slot->getParticipants() = 0;
    cout << "lesson is set to end." << endl;
    return true;
}
