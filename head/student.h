#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"
#include <string>
using namespace std;

class Student {
private:    //Initializing our variables
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysInCourse[3];
    DegreeProgram degreeProgram;

public:
    // Accessors; getting our variables when we need them
    string GetStudentID() const;
    string GetFirstName() const;
    string GetLastName() const;
    string GetEmailAddress() const;
    int GetAge() const;
    const int* GetDaysInCourse() const;
    string GetDegreeProgram() const;

    //Mutators; editting the variables as is needed
    void SetStudentID(string tempid);
    void SetFirstName(string tempfirstName);
    void SetLastName(string templastName);
    void SetEmailAddress(string tempemailAddress);
    void SetAge(int tempage);
    void SetDaysInCourse(int tempdaysInCourse1, int tempdaysInCourse2, int tempdaysInCourse3);
    void SetDegreeProgram(DegreeProgram tempdegreeProgram);

    //Constructor
    Student(string studentID, string firstName, string lastName, string emailAddress, int age,
        int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

    //Print
    void print() const;
};
#endif