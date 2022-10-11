// imports
#include <iostream>
#include <string>

#include "roster.h"
#include "degree.h"
#include "student.h"

using namespace std;

// Constructor Function
roster::roster() {}

// Mutator Functions
// Roster Add function
void roster::add(string studentID, string fname, string lname, string email,
                 int age, int dic1, int dic2, int dic3,
                 DegreeProgram focus)
{
    // integer vector totDIC for days in course
    vector<int> totDIC{dic1, dic2, dic3};
    student* addStudent = new student(studentID, fname, lname, email, age, totDIC, focus);
    classRosterArray.push_back(addStudent);

}

// Roster remove function
void roster::remove(string studentID) {
    // assigning locatedID variable of type bool
    bool locatedID = false;
    // iterating through classRosterArray using for loop
    for (size_t i = 0; i < classRosterArray.size(); i++) {
        // comparing iterated values with function parameter
        if (studentID == classRosterArray.at(i)->getID())
        {
            delete classRosterArray.at(i);
            classRosterArray.erase(classRosterArray.begin()+i);
            locatedID = true;
        }
    }
    if (!locatedID) {
        cout << "Cannot locate ID" << endl;
    }
}

// printALl student attributes using attributes enum in student.h
void roster::printAll() {
    for (size_t i = 0; i < classRosterArray.size(); i++)
    {
        classRosterArray.at(i)->print(attributes::STUDENTID);
        classRosterArray.at(i)->print(attributes::FNAME);
        classRosterArray.at(i)->print(attributes::LNAME);
        classRosterArray.at(i)->print(attributes::EMAIL);
        classRosterArray.at(i)->print(attributes::AGE);
        classRosterArray.at(i)->print(attributes::DEGREEPROGRAM);
        classRosterArray.at(i)->print(attributes::DAYSTOCOMPLETE);
    }
}

// printFocus function
void roster::printByDegreeProgram(DegreeProgram focus) {
    // assigning locatedFocus variable of type bool
    bool locatedFocus = false;
    // iterating through classRosterArray
    for (size_t i = 0; i < classRosterArray.size(); i++) {
        // comparing focus parameter with classRosterArray iteration values
        if (focus == classRosterArray.at(i)->getFocus())
        {
            classRosterArray.at(i)->print(attributes::DEGREEPROGRAM);
            classRosterArray.at(i)->print(attributes::STUDENTID);
            classRosterArray.at(i)->print(attributes::FNAME);
            classRosterArray.at(i)->print(attributes::LNAME);
            classRosterArray.at(i)->print(attributes::EMAIL);
            classRosterArray.at(i)->print(attributes::AGE);
            classRosterArray.at(i)->print(attributes::DAYSTOCOMPLETE);
        }
    }
}

// incEmail function
