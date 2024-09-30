#ifndef FITNESSCLUB_H
#define FITNESSCLUB_H
#include <iostream>
#include <string>
#include <vector>
#include "member.hpp"
#include "trainer.hpp"
#include "lesson.hpp"
#include "slot.hpp"
using namespace std;

class Member;
class Trainer;
class Lesson;
class Slot;

class FitnessClub
{
    vector<Member*> members;
    Member *findMember(int ID);
    Member *manageMember(string &name, char gender, int age, int phone, int subscription, int ID);

    vector<Trainer*> trainers;
    Trainer *findTrainer(int ID);
    Trainer *manageTrainer(string &name, char gender, int age, int phone, int saleries, int ID);

    vector<Lesson*> lessons;
    Lesson *findLesson(int ID);
    Lesson *manageLesson(string &name, int limit, int ID);

public:
    bool subscribeOrUpdateMember(string &name, char gender, int age, int phone, int subscription, int ID);
    bool unsubscribeMember(int ID);
    bool memberPaySubscription(int ID);
    bool memberPayTrainer(int memberID);
    void printAllMember();

    bool recruiteOrUpdateTrainer(string &name, char gender, int age, int phone, int saleries, int ID);
    bool dismissTrainer(int ID);
    bool trainerContractExpired(int trainerID);
    bool trainerSignContract(int ID);
    bool trainerAddSlot(int ID, string &day, float t1, float t2);
    bool trainerRemoveSlot(int ID, string &day, float t1, float t2);
    void printAllTrainer();

    void createOrUpdateLesson(string &name, int limit, int ID);
    bool deleteLesson (int ID);
    void printAllLesson();

    bool assignTrainerToMember(int memberID, int trainerID);
    bool memberBookSlot(int memberID, string &day, float t1, float t2);
    bool memberCancelSlot(int memberID, string &day, float t1, float t2);
    bool freeTrainerFromMember(int memberID);

    bool assignTrainerToLesson(int lessonID, int trainerID);
    bool LessonBookSlot(int lessonID, string &day, float t1, float t2);
    bool LessonCancelSlot(int lessonID, string &day, float t1, float t2);
    bool freeTrainerFromLesson(int lessonID);
    bool lessonStarts(int lessonID, string &day, float t1, float t2);
    bool addParticipants(int lessonID, string &day, float t1, float t2);
    bool lessonEnds(int lessonID, string &day, float t1, float t2);

};

#endif