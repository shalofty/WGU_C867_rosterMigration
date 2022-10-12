#ifndef SCHOOLROSTER_STUDENT_H
#define SCHOOLROSTER_STUDENT_H

// imports
#include <iostream>
#include <array>

#include "degree.h"

using namespace std;


// student class
class student {
public: // public functions to access/mutate private variables
    // Constructors
    student();
    student(string studentID, string fname, string lname, string email, int age, int days_in_course[], DegreeProgram focus);

    // Mutator Functions
    void setID(string studentID);
    void setFname(string fname);
    void setLname(string lname);
    void setEmail(string email);
    void setAge(int age);
    void setDaysInCourse(int days[]);
    void setFocus(DegreeProgram focus);

    // Accessor Functions
    string getID();
    string getFname();
    string getLname();
    string getEmail();
    int getAge();
    int* getDaysInCourse();
    DegreeProgram getFocus();

    // Print
    void print();

    // student class Destructor
    ~student();

    const static int array_size = 3;

private: // all external access/mutation must occur from public functions

    string studentID, fname, lname, email;
    int age;
    int days_in_course[array_size]; // UPDATED TO ARRAY TYPE

    // var focus, type DegreeProgram. Ref degree.h to see values
    // named focus instead of degreeprogram to avoid confusion during coding
    DegreeProgram focus;

    // i var iterator
    int i = 0;
};

#endif //SCHOOLROSTER_STUDENT_H
