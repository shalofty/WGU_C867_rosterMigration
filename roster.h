#ifndef SCHOOLROSTER_ROSTER_H
#define SCHOOLROSTER_ROSTER_H

// imports
#include <iostream>
#include "degree.h"
#include "student.h"

class roster {

public:
    // array of pointers classRosterArray
    vector<student*> classRosterArray;
    // Constructor
    roster();

    // Mutator Functions
    // remove function
    void remove(std::string studentID);

    // add function
    void add(std::string studentID, std::string fname, std::string lname, std::string email,
             int age, int dtc1, int dtc2, int dtc3,
             DegreeProgram focus);

    // printAll function
    void printAll();

    // printByDegreeProgram function
    void printByDegreeProgram(DegreeProgram focus);

    // printAverageDaysInCourse function (average days in course)
    void printAverageDaysInCourse(string studentID);

    // printInvalidEmails function
    void printInvalidEmails();

    // Destructor is explicitly defaulted
    // https://stackoverflow.com/questions/13576055/how-is-default-different-from-for-default-constructor-and-destructor
    // https://stackoverflow.com/questions/20828907/the-new-syntax-default-in-c11
    ~roster()= default;
};

#endif //SCHOOLROSTER_ROSTER_H
