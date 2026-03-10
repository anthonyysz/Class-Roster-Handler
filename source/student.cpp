#include "../head/student.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Accessors; getting the variables when we need them
string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" }; //list of strings to help with calling degree programs later

string Student::GetStudentID() const {
    return studentID;
}

string Student::GetFirstName() const {
    return firstName;
}

string Student::GetLastName() const {
    return lastName;
}

string Student::GetEmailAddress() const {
    return emailAddress;
}

int Student::GetAge() const {
    return age;
}

const int* Student::GetDaysInCourse() const {
    return daysInCourse;
}

string Student::GetDegreeProgram() const {      //I will be getting these using my degreeProgramStrings array because of issues printing the enumerated class
    if (degreeProgram == DegreeProgram::SECURITY) {
        return degreeProgramStrings[0];
    }
    else if (degreeProgram == DegreeProgram::NETWORK) {
        return degreeProgramStrings[1];
    }
    else if (degreeProgram == DegreeProgram::SOFTWARE) {
        return degreeProgramStrings[2];
    }
    else return "NONE";
}

//Mutators; editting the variables as needed
void Student::SetStudentID(string tempstudentID) {
    studentID = tempstudentID;
}

void Student::SetFirstName(string tempfirstName) {
    firstName = tempfirstName;
}

void Student::SetLastName(string templastName) {
    lastName = templastName;
}

void Student::SetEmailAddress(string tempemailAddress) {
    emailAddress = tempemailAddress;
}

void Student::SetAge(int tempage) {
    age = tempage;
}

void Student::SetDaysInCourse(int tempdaysInCourse1, int tempdaysInCourse2, int tempdaysInCourse3) {
    daysInCourse[0] = tempdaysInCourse1;
    daysInCourse[1] = tempdaysInCourse2;
    daysInCourse[2] = tempdaysInCourse3;
}

void Student::SetDegreeProgram(DegreeProgram tempdegreeProgram) {
    degreeProgram = tempdegreeProgram;
}

//Constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age,
    int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    SetStudentID(studentID);
    SetFirstName(firstName);
    SetLastName(lastName);
    SetEmailAddress(emailAddress);
    SetAge(age);
    SetDaysInCourse(daysInCourse1, daysInCourse2, daysInCourse3);
    SetDegreeProgram(degreeProgram);

}

//Print
void Student::print() const {
    cout << GetStudentID() << " First Name: " << GetFirstName() << " Last Name: " << GetLastName()
        << " Age: " << GetAge() << " Days in Course: " << GetDaysInCourse()[0] << ", "
        << GetDaysInCourse()[1] << ", " << GetDaysInCourse()[2] << " Degree Program: " << GetDegreeProgram() << endl;
}