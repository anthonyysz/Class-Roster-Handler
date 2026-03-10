#include <iostream>
#include "../head/roster.h"
using namespace std;

int main() {
    // Print out course title, programming language, WGU student ID, and name
    cout << "Course Title: Scripting and Programming Applications\n";
    cout << "Programming Language: C++\n";
    cout << "WGU Student ID: 011239490\n";
    cout << "Name: Anthony Szabo\n";

    //Construct classRoster
    Roster classRoster;

    //Add each student
    const string studentDataArray[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Anthony,Szabo,anthony_szabo@hotmail.com,22,10,20,15,SOFTWARE"};
    for (int i = 0; i < 5; ++i) {
        classRoster.parse(studentDataArray[i]);
    }
    //Print each student, then print the students with invalid email addresses
    classRoster.printAll();
    classRoster.printInvalidEmails();

    for (int i = 0; i < 5; ++i) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentID());
    }
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE); //Print each in the software degree program
    classRoster.remove("A3"); //Remove student A3
    classRoster.printAll(); //Print each student
    classRoster.remove("A3"); //Try removing student A3 again

    classRoster.~Roster();  //Destructing the roster
    return 0;
}