// imports
#include <iostream>
#include <string>
#include <array>
#include <regex>

#include "roster.h"
#include "degree.h"
#include "student.h"

using namespace std;

// Constructor Function
roster::roster() = default;

// Mutator Functions
// Roster Add function
void roster::add(string studentID, string fname, string lname, string email, int age, int dic1, int dic2, int dic3, DegreeProgram focus)
{
    int days_in_course[student::array_size]{dic1, dic2, dic3};
    classRosterArray[++z] = new student(studentID, fname, lname, email, age, days_in_course, focus);
}

// Roster remove function
void roster::remove(string studentID) {
    bool locatedID = false;
    for (i = 0; i <= roster::z; i++)
    {
        if (studentID == classRosterArray[i]->getID())
        {
            locatedID = true;
            if (i < numstu - 1)
            {
                student* fill = classRosterArray[i];
                classRosterArray[i] = classRosterArray[numstu - 1];
                classRosterArray[numstu -1] = fill;
            }
            roster::z--;

            student* fill = classRosterArray[roster::z];
            classRosterArray[roster::z] = classRosterArray[roster::z - 1];
            classRosterArray[roster::z - 1] = fill;
        }
    }
    if (!locatedID)
    {
        cout << "Attempted to locate student " << studentID << endl;
        cout << "Cannot locate any student by that ID." << endl;
    }
}

// print functions

// printAll
void roster::printAll() {
    for (i=0;i<=roster::z;i++) {
        classRosterArray[i]->print();
    }
}

// printByDegreeProgram
void roster::printByDegreeProgram(DegreeProgram focus)
{
    for (i = 0; i <= roster::z; i++)
    {
        if (roster::classRosterArray[i]->getFocus() == focus)
        {
            classRosterArray[i]->print();
        }
    }
}

// printAverageDaysInCourse function
void roster::printAverageDaysInCourse(std::string studentID)
{
    for (i = 0; i <= roster::z; i++)
    {
        if (studentID == classRosterArray[i]->getID()) {
            float average_days = (classRosterArray[i]->getDaysInCourse()[0] + classRosterArray[i]->getDaysInCourse()[1] + classRosterArray[i]-> getDaysInCourse()[2])/3.00;
            cout
            << classRosterArray[i]->getID()
            << ", "
            << classRosterArray[i]->getFname()
            << " "
            << classRosterArray[i]->getLname()
            << " takes an average of "
            << average_days
            << " days to complete a course"
            << endl;
        }
    }
}

// printInvalidEmails function
// http://www.ex-parrot.com/~pdw/Mail-RFC822-Address.html
// https://stackoverflow.com/questions/22683358/email-validation-expression-w-w-w-w-w-w-allows
void roster::printInvalidEmails()
{
    cout << "ATTENTION: Invalid emails have been located in the roster." << endl;
    // iterate through classRosterArray
    for (size_t n = 0; n < sizeof(classRosterArray) / sizeof(student*); n++)
    {
        const regex pattern("^\\w+([-+.']\\w+)*@\\w+([-.]\\w+)*\\.\\w+([-.]\\w+)*$");
        if (!regex_match(classRosterArray[n]->getEmail(), pattern))
        {
            cout << "Email field for " << classRosterArray[n]->getID() << " is invalid." << endl;
            cout << classRosterArray[n]->getEmail() << endl;
        }
    }
}

// roster destructor

roster::~roster() {
    for (i = 0; i < numstu; i++) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}