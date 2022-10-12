// imports
#include <iostream>
#include <iomanip>

#include "student.h"
#include "degree.h"

using namespace std;

// Constructors
student::student()
{
    this->studentID = "";
    this->fname = "";
    this->lname = "";
    this->email = "";
    this->age = 0;
    this->focus = DegreeProgram::NONE;

    for (i = 0; i < array_size; i++)
    {
        this->days_in_course[i] = 0;
    }
}

student::student(string studentID, string fname, string lname, string email,
                 int age, int days_in_course[], DegreeProgram focus)
{
    this->studentID = studentID;
    this->fname = fname;
    this->lname = lname;
    this->email = email;
    this->age = age;
    this->focus = focus;
    for (int q = 0; q < array_size; q++){this->days_in_course[q] = days_in_course[q];}
}

// student Destructor
student::~student() {}

// Accessor Functions
string student::getID() {return studentID;}
string student::getFname() {return fname;}
string student::getLname() {return lname;}
string student::getEmail() {return email;}
int student::getAge() {return age;}
int* student::getDaysInCourse() {return days_in_course;}
DegreeProgram student::getFocus() {return focus;}

// Mutator Functions
void student::setID(string studentID) {this->studentID = studentID;}
void student::setFname(string fname) {this->fname = fname;}
void student::setLname(string lname) {this->lname = lname;}
void student::setEmail(string email) {this->email = email;}
void student::setAge(int age) {this->age = age;}
void student::setFocus(DegreeProgram focus) {this->focus = focus;}
void student::setDaysInCourse(int days[]) {for (i = 0; i < array_size; i++) {this->days_in_course[i] = days[i];}}


// print function for printing specific student data
void student::print()
{
    cout
    << "SID: " << getID() << "\t"
    << "First: " << getFname() << "\t"
    << "Last: " << getLname() << "\t"
    << "Age: " << getAge() << "\t"
    << "DIC: {" << getDaysInCourse()[0] << " "
    << getDaysInCourse()[1] << " "
    << getDaysInCourse()[2] << "}" << "\t"
    << "Program: " << focusStrings[(int)getFocus()] << "\t"
    << endl;
}