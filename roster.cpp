// imports
#include <iostream>
#include <string>
#include <vector>
#include <regex>

#include "roster.h"
#include "degree.h"
#include "student.h"

using namespace std;

// Constructor Function
roster::roster() = default;

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

// printAverageDaysInCourse function
void roster::printAverageDaysInCourse(std::string studentID)
{
    // assigning ad variable (average days) of type float
    float average_days = 0.00;
    // iterating through classRosterArray
    for (size_t n = 0; n < classRosterArray.size(); n++)
    {
        // comparing studentID with results during iteration
        if (studentID == classRosterArray.at(n)->getID())
        {
            // assigning adv variable of type vector using results from iteration
            vector<int> adv = classRosterArray.at(n)->getNdtc();
            for (size_t i = 0; i < adv.size(); i++)
            {
                average_days = average_days + adv.at(i);
            }
            cout
            << classRosterArray.at(n)->getID()
            << ", "
            << classRosterArray.at(n)->getFname()
            << " "
            << classRosterArray.at(n)->getLname()
            << " takes an average of "
            << average_days/adv.size()
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
    for (size_t n = 0; n < classRosterArray.size(); n++)
    {
        const regex pattern("^\\w+([-+.']\\w+)*@\\w+([-.]\\w+)*\\.\\w+([-.]\\w+)*$");
        if (!regex_match(classRosterArray.at(n)->getEmail(), pattern))
        {
            cout << "Email field for " << classRosterArray.at(n)->getID() << " is invalid." << endl;
            cout << classRosterArray.at(n)->getEmail() << endl;
        }
    }
}