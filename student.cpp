// imports
#include <iostream>

#include "student.h"
#include "degree.h"

using namespace std;

// Accessor Functions
// getID function
string student::getID() {
    return studentID;
}

// getFname function
string student::getFname() {
    return fname;
}

// getLname function
string student::getLname() {
    return lname;
}

// getEmail function
string student::getEmail() {
    return email;
}

// getAge function
int student::getAge() {
    return age;
}

// getNdtc function
vector<int> student::getNdtc() {
    return days_to_complete;
}

// getFocus function
DegreeProgram student::getFocus() {
    return focus;
}

// Mutator Functions
// setID function
void student::setID(string studentID) {
    this->studentID = studentID;
}

// setFname function
void student::setFname(string fname) {
    this->fname = fname;
}

// setLname function
void student::setLname(string lname) {
    this->lname = lname;
}

// setEmail function
void student::setEmail(string email) {
    this->email = email;
}

// setAge function
void student::setAge(int age) {
    this->age = age;
}

// setNdtc function
void student::setNdtc(vector<int> days_to_complete) {
    this->days_to_complete = days_to_complete;
}

// setFocus function
void student::setFocus(DegreeProgram focus) {
    this->focus = focus;
}

// student object constructor
student::student(string studentID, string fname, string lname, string email,
                 int age, vector<int> days_to_complete, DegreeProgram focus)
{
    this->studentID = studentID;
    this->fname = fname;
    this->lname = lname;
    this->email = email;
    this->age = age;
    this->focus = focus;
    this->days_to_complete = days_to_complete;
}