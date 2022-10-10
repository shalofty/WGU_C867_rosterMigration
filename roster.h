#ifndef SCHOOLROSTER_ROSTER_H
#define SCHOOLROSTER_ROSTER_H
// imports
#include <iostream>
#include "degree.h"
#include "student.h"

class roster {

public:
    vector<student*> classRosterArray;
    // Constructor
    roster();

    // Mutator Functions
    // del function
    void del(std::string studentID);

    // add function
    void add(std::string studentID, std::string fname, std::string lname, std::string email,
             int age, int dtc1, int dtc2, int dtc3,
             DegreeProgram focus);

    // printing functions
    void printAttributes();

    // printFocus function
    void printFocus(DegreeProgram focus);

    // Destructor, program will not compile without body
    ~roster(){

    };
};


#endif //SCHOOLROSTER_ROSTER_H
