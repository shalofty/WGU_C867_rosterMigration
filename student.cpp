// imports
#include <iostream>
#include <iomanip>

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

// print function
void student::print(attributes printat)
{
   switch (printat)
   {
       case attributes::STUDENTID:
           cout << " SID: " << studentID;
           break;
       case attributes::FNAME:
           cout << " First: " << fname;
           break;
       case attributes::LNAME:
           cout << " Last: " << lname;
           break;
       case attributes::EMAIL:
           cout << " Email: " << email;
           break;
       case attributes::AGE:
           cout << " Age: " << age;
           break;
       case attributes::DEGREEPROGRAM:
           // insert value of focus into focusStrings[] array from degree.h
           cout << " Degree: " << focusStrings[int(focus)];
           break;
       case attributes::DAYSTOCOMPLETE:
           // iterate through days_to_complete, print each value
           cout << " DiC: ";
           for (size_t i = 0; i < days_to_complete.size(); i++)
           {
               cout << days_to_complete.at(i) << " ";
           }
           cout << endl;
           break;
   }
}