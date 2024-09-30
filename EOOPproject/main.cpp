#include <iostream>
#include <string>
#include <vector>
#include "member.hpp"
#include "trainer.hpp"
#include "slot.hpp"
#include "fitnessClub.hpp"
using namespace std;

int main()
{
    FitnessClub club;
     
    //weekday
    string day1 = "Mon";
    string day2 = "Tue";
    string day3 = "Wed";
    string day4 = "Thur";
    string day5 = "Fri";
    string day6 = "Sat";
    string day7 = "Sun";

    //test before creating any object
    club.printAllMember();
    club.printAllLesson();
    club.printAllTrainer();

    club.unsubscribeMember(5);
    club.memberPaySubscription(5);
    club.memberPayTrainer(5);

    club.dismissTrainer(3);
    club.trainerContractExpired(3);
    club.trainerSignContract(3);
    club.trainerAddSlot(3, day1, 10.00, 11.00);
    club.trainerRemoveSlot(3, day1, 10.00, 11.00);
    
    club.deleteLesson(2);
    
    club.assignTrainerToLesson(5,3);
    club.memberBookSlot(5, day1, 10.00, 11.00);
    club.memberBookSlot(5, day1, 10.00, 11.00);
    club.freeTrainerFromMember(5);

    club.assignTrainerToLesson(10, 3);
    club.LessonBookSlot(10, day1, 10.00, 11.00);
    club.LessonCancelSlot(10, day1, 10.00, 11.00);
    club.freeTrainerFromLesson(10);
    club.lessonStarts(10, day1, 10.00, 11.00);
    club.addParticipants(10, day1, 10.00, 11.00);
    club.lessonEnds(10, day1, 10.00, 11.00);

    cout << endl;
    cout << "subscripting and updating members:  " << endl;
    string member1 = "Jane";
    string member2 ="Leo";
    string member3 = "Alex";
    club.subscribeOrUpdateMember(member1, 'f', 25, 879654321, 12, 1);
    club.subscribeOrUpdateMember(member2, 'm', 34, 456038123, 3, 2);
    club.subscribeOrUpdateMember(member3, 'm', 15, 671025402, 6, 3); //incorrect case: age < 18
    club.subscribeOrUpdateMember(member3, 'm', 18, 671025402, 6, 3); //corrected
    club.subscribeOrUpdateMember(member3, 'm', 19, 671025402, 12, 3); 
    cout << endl;
    club.printAllMember(); 

    cout << endl;
    cout << "members pay for trainers: " << endl;
    club.memberPayTrainer(1);
    club.memberPayTrainer(2);
    club.memberPayTrainer(6); //incorrect case: ID doesn't exist
    cout << endl;
    club.printAllMember(); 

    cout << endl;
    cout << "recruite trainers: " << endl;
    string trainer1 = "Celine";
    string trainer2 = "David";
    string trainer3 = "Louis";
    club.recruiteOrUpdateTrainer(trainer1, 'f', 27, 362538123, 6000, 101);
    club.recruiteOrUpdateTrainer(trainer2, 'm', 32, 456367898, 5080, 102);
    club.recruiteOrUpdateTrainer(trainer3, 'm', 30, 98271023, 5000, 103);  //incorrect case: phone number 
    club.recruiteOrUpdateTrainer(trainer3, 'm', 30, 987212645, 2500, 103); //incorrect case: saleries
    club.recruiteOrUpdateTrainer(trainer3, 'm', 30, 987212645, 7000, 103); //corrected
    club.recruiteOrUpdateTrainer(trainer3, 'm', 30, 987212645, 7500, 103); //update saleries
    cout << endl;
    club.printAllTrainer();

    cout << endl;
    cout << "trainers add slots" << endl;
    club.trainerAddSlot(101, day4, 16.00, 17.00);
    club.trainerAddSlot(101, day6, 12.00, 14.00);

    club.trainerAddSlot(102, day2, 9.00, 10.00);
    club.trainerAddSlot(102, day3, 18.00, 20.00);
    club.trainerAddSlot(102, day5, 14.00, 16.00);

    club.trainerAddSlot(103, day1, 11.00, 13.00);
    club.trainerAddSlot(103, day3, 10.00, 11.00);
    club.trainerAddSlot(103, day7, 17.30, 19.30);

    club.trainerAddSlot(104, day1, 11.00, 13.00); //incorrect case: trainer doesn't exist
    cout<<endl;
    club.printAllTrainer();

    cout << endl;
    cout << "create lessons: " << endl;
    string lesson1 = "Boxing";
    string lesson2 = "Yoga";
    string lesson3 = "Cardio";
    club.createOrUpdateLesson(lesson1, 20, 131);
    club.createOrUpdateLesson(lesson2, 30, 132);
    club.createOrUpdateLesson(lesson3, 4, 133); //incorrect case: limit <=5
    club.createOrUpdateLesson(lesson3, 30, -2); //incorrect case: ID < 0
    club.createOrUpdateLesson(lesson3, 30, 133);
    cout << endl;
    club.printAllLesson();

    cout << endl;
    cout << "members book trainers(without booking any slot): " << endl;
    club.assignTrainerToMember(1,101);
    club.assignTrainerToMember(2,103);
    club.assignTrainerToMember(1,102); //incorrect case: member already has another trainer
    club.assignTrainerToMember(3,103); //incorrect case: trainer already has another member
    club.assignTrainerToMember(4,102); //incorrect case: member doesn't exist
    club.assignTrainerToMember(3,105); //incorrect case,: trainer doesn't exist
    cout << endl;
    club.printAllMember();
    cout << endl;
    club.printAllTrainer();

    cout << endl;
    cout << "assign trainers to lessons: " << endl;
    club.assignTrainerToLesson(131, 101);
    club.assignTrainerToLesson(132, 102);
    club.assignTrainerToLesson(132, 103); //incorrect case: lesson already has another conductor
    club.assignTrainerToLesson(133, 101); //incorect case: trainer is aready assigned to another lesson
    club.assignTrainerToLesson(135, 103); //incorrect case: lesson doesn't exist
    club.assignTrainerToLesson(133, 105); //incorrect case: trainer doesn't exist
    cout << endl;
    club.printAllLesson();
    cout << endl;
    club.printAllTrainer();

    cout << endl;
    cout << "lessons book slots: " << endl;
    club.LessonBookSlot(131, day4, 16.00, 17.00);
    club.LessonBookSlot(131, day6, 12.00, 14.00);
    club.LessonBookSlot(132, day2, 9.00, 10.00);
    club.LessonBookSlot(132, day2, 9.00, 10.00);  //incorrect case: slot is not available
    club.LessonBookSlot(132, day1, 11.00, 13.00); //incorrect case: slot is not found
    club.LessonBookSlot(133, day1, 11.00, 13.00); //incorrect case: lesson without conductor
    club.LessonBookSlot(135, day1, 11.00, 13.00); //incorrect case: lesson doesn't exist
    cout << endl;
    club.printAllLesson();
    cout << endl;
    club.printAllTrainer();

    cout << endl;
    cout << "members book slots: " << endl;
    club.memberBookSlot(2, day7, 17.30, 19.30);
    club.memberBookSlot(2, day3, 10.00, 11.00);
    club.memberBookSlot(1, day4, 16.00, 17.00); //incorrect case: slot is not available
    club.memberBookSlot(1, day2, 16.00, 17.00); //incorrect case: slot doesn't exist
    club.memberBookSlot(3, day3, 10.00, 11.00); //incorrect case: member doesn't have a trainer
    club.memberBookSlot(5, day3, 10.00, 11.00); //incorrect case: member doesn't exist
    cout << endl;
    club.printAllMember();
    cout << endl;
    club.printAllTrainer();

    cout << endl;
    cout << "member cancels slot: " << endl;
    club.memberCancelSlot(2, day3, 10.00, 11.00);
    club.memberCancelSlot(2, day1, 11.00, 13.00); //incorrect case: member doesn't have this slot
    club.memberCancelSlot(2, day4, 16.00, 17.00); //incorrect case: slot is not found
     club.memberCancelSlot(3, day3, 10.00, 11.00); //incorrect case: member doesn't have a trainer
    club.memberCancelSlot(5, day3, 10.00, 11.00); //incorrect case: member doesn't exist
    cout << endl;
    club.printAllMember();
    cout << endl;
    club.printAllTrainer();

    cout << endl;
    cout << "lesson cancels slot: " << endl;
    club.LessonCancelSlot(131, day6, 12.00, 14.00);
    club.trainerAddSlot(101, day5, 15.00, 16.00); //add random slot for test
    club.LessonCancelSlot(131, day5, 15.00, 16.00); //incorrect case: lesson doesn't have this slot
    club.LessonCancelSlot(131, day3, 10.00, 11.00); //incorrect case: slot is not found
    club.LessonCancelSlot(133, day1, 11.00, 13.00); //incorrect case: lesson without conductor
    club.LessonCancelSlot(135, day1, 11.00, 13.00); //incorrect case: lesson doesn't exist
    cout << endl;
    club.printAllLesson();
    cout << endl;
    club.printAllTrainer();

    cout << endl;
    cout << "trainer removes slot: " << endl;
    club.trainerRemoveSlot(101, day4, 16.00, 17.00); //trainer removes a slot booked by lesson 
    club.trainerRemoveSlot(105, day4, 16.00, 17.00); //incorrect case: trainer doesn't exist
    club.trainerRemoveSlot(101, day2, 9.00, 10.00); //incorrect case: slot is not found
    cout << endl;
    club.printAllTrainer();
    cout << endl;
    club.printAllLesson();

    cout << endl;
    cout << "free trainer from member and clear the slots booked: " << endl;
    club.freeTrainerFromMember(2);
    club.freeTrainerFromMember(3); //incorrect case: member doesn't have trainer
    club.freeTrainerFromMember(5); //incorrect case: member doesn't exist
    cout << endl;
    club.printAllMember();
    cout << endl;
    club.printAllTrainer();

    cout << endl;
    cout << "free trainer from lesson and clear the scheduel: " << endl;
    club.freeTrainerFromLesson(131);
    club.freeTrainerFromLesson(133); //incorrect case: lesson doesn't have trainer
    club.freeTrainerFromLesson(135); //incorrect case: lesson doesn't exist
    //test a lesson exist
    cout << endl;
    club.printAllLesson();
    cout << endl;
    club.printAllTrainer();

     /////////test of deleting objects/////////
    cout << endl;
    cout << "unsubscribe a member(first book a trainer and a slot for this member): " << endl;
    club.assignTrainerToMember(2,103);
    club.memberBookSlot(2, day7, 17.30, 19.30);
    cout << endl;
    club.printAllMember();
    cout << endl;
    club.printAllTrainer();
    cout << endl;
    cout << "unsubscribe the member: " << endl;
    club.unsubscribeMember(2);
    club.unsubscribeMember(5); //incorrect case: member doesn't exist
    cout << endl;
    club.printAllMember();
    cout << endl;
    club.printAllTrainer();

    cout << endl;
    cout << "delete a lesson: " << endl;
    club.deleteLesson(132);
    club.deleteLesson(135); //incorrect case: lesson doesn't exist
    cout << endl;
    club.printAllLesson();
    cout << endl;
    club.printAllTrainer();

    cout << endl;
    cout << "dismiss a trainer(first make sure this trainer has lesson, member who booked slots: " << endl;
    club.assignTrainerToLesson(131, 101);
    club.memberBookSlot(1, day4, 16.00, 17.00);
    club.LessonBookSlot(131, day6, 12.00, 14.00);
    cout << endl;
    club.printAllMember();
    cout << endl;
    club.printAllLesson();
    cout << endl;
    club.printAllTrainer();
    cout << endl;
    cout << "dismiss the trainer: " << endl;
    club.dismissTrainer(101);
    club.dismissTrainer(105); //incorrect case: trainer doesn't exist
    cout << endl;
    club.printAllMember();
    cout << endl;
    club.printAllLesson();
    cout << endl;
    club.printAllTrainer();

    ///////test of start and end a lesson//////
    cout << endl;
    club.assignTrainerToLesson(133, 103);
    club.LessonBookSlot(133, day1, 11.00, 13.00);
    club.createOrUpdateLesson(lesson3, 6, 133); //change limit
    cout << endl;
    club.printAllLesson();
    cout << endl;
    club.printAllTrainer();
    
    cout << endl;
    cout << "starting a lesson: " << endl;
    club.lessonStarts(133, day1, 11.00, 13.00);
    club.lessonStarts(133, day2, 9.00, 10.00); //incorrect case: slot is not found
    club.lessonStarts(131, day1, 11.00, 13.00); // incorrect case: lesson has no conductor
    club.lessonStarts(135, day1, 11.00, 13.00); // incorrect case: lesson doesn't exist

    cout << endl;
    cout << "adding participants: " << endl;  
    club.printAllLesson();
    club.addParticipants(133, day1, 11.00, 13.00);
    club.addParticipants(133, day1, 11.00, 13.00);
    club.addParticipants(133, day1, 11.00, 13.00);
    club.addParticipants(133, day1, 11.00, 13.00);
    club.addParticipants(133, day1, 11.00, 13.00);
    club.addParticipants(133, day1, 11.00, 13.00); 
    club.addParticipants(133, day1, 11.00, 13.00);//incorrect case: participants reach limit
    club.addParticipants(133, day2, 9.00, 10.00); //incorrect case: slot is not found
    club.addParticipants(131, day1, 11.00, 13.00); // incorrect case: lesson has no conductor
    club.addParticipants(135, day1, 11.00, 13.00); // incorrect case: lesson doesn't exist
    club.printAllLesson();

    cout << endl;
    cout << "ending a lesson: " << endl;
    club.lessonEnds(133, day1, 11.00, 13.00);
    club.lessonEnds(133, day2, 9.00, 10.00); //incorrect case: slot is not found
    club.lessonEnds(131, day1, 11.00, 13.00); // incorrect case: lesson has no conductor
    club.lessonEnds(135, day1, 11.00, 13.00); // incorrect case: lesson doesn't exist
    return 0;
}
