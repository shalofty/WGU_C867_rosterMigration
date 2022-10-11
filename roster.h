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

    // Destructor, program will not compile without body
    ~roster(){

    };
};


#endif //SCHOOLROSTER_ROSTER_H
