#ifndef ROSTER_H
#define ROSTER_H

#include <iostream>
#include <string>
#include "student.h"
using namespace std;

class Roster {
public:
    int sizeRoster = 0; //The roster size will begin as zero, we will raise this variable as we add students
    int counter = -1; //This variable will be the index, being raised as students are added

    Student* classRosterArray[];

    //Mutators
    void add(string studentID, string firstName, string lastName, string emailAddress, int age,
        int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(string studentID);
    void parse(string studentData);

    //Constructor
    Roster();

    //Destructor
    ~Roster();

    //Print
    void printAll() const;
    void printAverageDaysInCourse(string studentID) const;
    void printInvalidEmails() const;
    void printByDegreeProgram(DegreeProgram degreeProgram) const;
};
#endif