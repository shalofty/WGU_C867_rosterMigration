#ifndef SCHOOLROSTER_STUDENT_H
#define SCHOOLROSTER_STUDENT_H

// imports
#include <iostream>
#include <array>
#include <vector>

#include "degree.h"

using namespace std;

// enumerated student attributes
enum class attributes{STUDENTID, FNAME, LNAME, EMAIL, AGE, DEGREEPROGRAM, DAYSTOCOMPLETE};

class student {
private: // all external access/mutation must occur from public functions
    // student vars, type string
    std::string studentID, fname, lname, email;

    // var age, type int
    int age;

    // var days_to_complete, type array size 3
    vector<int> days_to_complete;

    // var focus, type DegreeProgram. Ref degree.h to see values
    DegreeProgram focus;

public: // public functions to access/mutate private variables
    // Constructor
    explicit student(string studentID = "", string fname = "", string lname = "", string email = "",
            int age = 0, vector<int> days_to_complete = {0, 0, 0}, DegreeProgram focus = DegreeProgram::NONE);

    // Mutator Functions
    // setID function
    void setID(string studentID);

    // setFname function
    void setFname(string fname);

    // setLname function
    void setLname(string lname);

    // setEmail function
    void setEmail(string email);

    // setAge function
    void setAge(int age);

    // setNdtc function
    void setNdtc(vector<int> days_to_complete);

    // setFocus function
    void setFocus(DegreeProgram focus);

    // Accessor Functions
    // getID function
    string getID();

    // getFname function
    string getFname();

    // getLname function
    string getLname();

    // getEmail function
    string getEmail();

    // getAge function
    int getAge();

    // getNdtc function
    vector<int> getNdtc();

    // getFocus function
    DegreeProgram getFocus();

    // Print student attributes function
    void print(attributes) {

    };

};

#endif //SCHOOLROSTER_STUDENT_H
