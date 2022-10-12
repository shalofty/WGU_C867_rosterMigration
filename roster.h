#ifndef SCHOOLROSTER_ROSTER_H
#define SCHOOLROSTER_ROSTER_H

// imports
#include <iostream>
#include <vector>
#include <array>
#include "degree.h"
#include "student.h"

class roster {
private:
    int i = 0;
    int z = -1;

public:
    // array of pointers classRosterArray and number of student variable
    const static int numstu = 5;
    student* classRosterArray[numstu];

    // Constructor
    roster();

    // Mutator Functions
    // remove function
    void remove(std::string studentID);

    // add function
    void add(std::string studentID, std::string fname, std::string lname, std::string email, int age, int dtc1, int dtc2, int dtc3, DegreeProgram focus);

    // printAll function
    void printAll();

    // printByDegreeProgram function
    void printByDegreeProgram(DegreeProgram focus);

    // printAverageDaysInCourse function (average days in course)
    void printAverageDaysInCourse(string studentID);

    // printInvalidEmails function
    void printInvalidEmails();

    // Destructor
    ~roster();
};

#endif //SCHOOLROSTER_ROSTER_H
