#include <iostream>
#include <string>
#include "../head/roster.h"
#include <algorithm>
using namespace std;

string degreeProgramStrings2[] = { "SECURITY", "NETWORK", "SOFTWARE" }; //List of strings to help with calling later, implemented because of an earlier problem

//Accessors
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age,
    int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    classRosterArray[++counter] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    ++sizeRoster;
}//Adding each students increments the counter (index), adds all the necessary information in the proper order, and raises the sizeRoster variable

void Roster::remove(string studentID) {
    auto it = remove_if(classRosterArray, classRosterArray + sizeRoster, //If this student ID is found in classRosterArray, they student will be removed
        [studentID](const Student* student) {
            return student->GetStudentID() == studentID;
        });

    if (it != classRosterArray + sizeRoster) {
        cout << "Student ID " << studentID << " removed successfully." << endl;
    }
    else {
        cout << "Student ID " << studentID << " not found." << endl;
    }

    sizeRoster = sizeRoster - 1; //Lowering the sizeRoster if a student is removed
}
void Roster::parse(string studentData) { //Here we will be going through the data as it is presented in the studentData variable, and separating it so we can add it to our roster
    int k = studentData.find(",");          //Temporary variables k and l will be used
    string addID = studentData.substr(0, k);    //Here, 0 is the beginning of the string, k is the first comma. We will be taking a substring starting at index zero with a length of k

    int l = k + 1;              //Variable l is the index one beyond the last comma              
    k = studentData.find(",", l);   //k is the next comma
    string addFirst = studentData.substr(l, k - l); //This will be similar to the first step, except using variable l with the length between l and the next comma

    l = k + 1;
    k = studentData.find(",", l);
    string addLast = studentData.substr(l, k - l);  //Repeated

    l = k + 1;
    k = studentData.find(",", l);
    string addEmail = studentData.substr(l, k - l); //Repeated

    l = k + 1;
    k = studentData.find(",", l);
    int addAge = stoi(studentData.substr(l, k - l));//Repeated

    l = k + 1;
    k = studentData.find(",", l);
    int addD1 = stoi(studentData.substr(l, k - l));//Repeated

    l = k + 1;
    k = studentData.find(",", l);
    int addD2 = stoi(studentData.substr(l, k - l));//Repeated

    l = k + 1;
    k = studentData.find(",", l);
    int addD3 = stoi(studentData.substr(l, k - l));//Repeated

    l = k + 1;
    k = studentData.find(",", l);
    string addDegreeTemp = studentData.substr(l, k - l);    //Here we will continue, except using a temporary variable so we can add the degree program as a DegreeProgram object

    DegreeProgram addDegree = DegreeProgram::SOFTWARE;      //Initializing our addDegree variable

    if (addDegreeTemp == "SECURITY") {                      //Checking here for each of the 3 degree types
        addDegree = DegreeProgram::SECURITY;
    }
    else if (addDegreeTemp == "NETWORK") {
        addDegree = DegreeProgram::NETWORK;
    }
    else if (addDegreeTemp == "SOFTWARE") {
        addDegree = DegreeProgram::SOFTWARE;
    }
    else {
        cout << "Incorrect Degree Program entered for student " << addID << endl;       //Printing out a message if the degree program entered isn't one of the 3 we specified
    }

    add(addID, addFirst, addLast, addEmail, addAge, addD1, addD2, addD3, addDegree);    //Finally using our add function to get this into the classRosterArray
}

//Constructor
Roster::Roster() {  //Default constructor
}

//Destructor
Roster::~Roster() { //Incrementally destructing
    for (int i = 0; i < sizeRoster; ++i) {
        delete classRosterArray[i];
    }
    cout << "Roster destructed" << endl;
}

//Prints
void Roster::printAll() const {     //Incrementally printing each student
    for (int i = 0; i < sizeRoster; ++i) {
        classRosterArray[i]->print();
    }
}

void Roster::printAverageDaysInCourse(string studentID) const {
    for (int i = 0; i < sizeRoster; ++i) {  //For each in the size of the roster
        if (classRosterArray[i]->GetStudentID() == studentID) { //For each student ID in classRosterArray
            const int* daysInCourse = classRosterArray[i]->GetDaysInCourse();   //We get the days in course into a variable daysInCourse
            double averageDaysInCourse = (daysInCourse[0] + daysInCourse[1] + daysInCourse[2]) / 3.0;   //Add them up and divide by 3
            cout << "Average days in course for " << studentID << ": " << averageDaysInCourse << endl;  //And finally print them out with the student ID
        }
    }
}

void Roster::printInvalidEmails() const {
    for (int i = 0; i < sizeRoster; ++i) {  //For each student in the size of the roster
        string email = classRosterArray[i]->GetEmailAddress();  //We get the email as a string
        if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {    //If the email is missing an @ or period, or if it has a space, the email will be deemed in valid
            cout << "Invalid email: " << email << " for student " << classRosterArray[i]->GetStudentID() << endl;   //Each invalid email and that student's ID will be printed
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const {
    for (int i = 0; i < sizeRoster; ++i) {  //Again, for each student in the roster
        string temp;    //Here I decided to just call the temporary variable temp
        if (degreeProgram == DegreeProgram::SECURITY) { //And since I was having trouble simply printing the object, I will be mapping each of the 3 degree programs to a list I made
            temp = degreeProgramStrings2[0];
        }
        else if (degreeProgram == DegreeProgram::NETWORK) {
            temp = degreeProgramStrings2[1];
        }
        else if (degreeProgram == DegreeProgram::SOFTWARE) {
            temp = degreeProgramStrings2[2];
        }
        else temp = "NONE";
        if (classRosterArray[i]->GetDegreeProgram() == temp) {
            classRosterArray[i]->print();
        }
    }
}