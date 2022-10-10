// Imports
#include <iostream>
#include <string>

#include "student.h"
#include "degree.h"
#include "roster.h"

using namespace std;

// Declaring sd function
roster sd(const string studentData[], size_t numstu);

int main() {
    // Outputting my information
    cout << "C867 Scripting and Programming in C++" << endl;
    cout << "Stephan Haloftis, Computer Science" << endl;
    cout << "shaloftis@wgu.edu, 010727171" << endl;

    // studentData Table from Class Roster Scenario
    const string studentData[] =
            {"A1, John, Smith, John1989@gmail.com, 20, 30, 35, 40, SECURITY",
             "A2, Suzan, Erickson, Erickson_1990@gmail.com, 19, 50, 30, 40, NETWORK",
             "A3, Jack, Napoli, The_lawyer99yahoo.com, 19, 20, 40, 33, SOFTWARE",
             "A4, Erin, Black, Erin.black@comcast.net, 22, 50, 58, 40, SECURITY",
             "A5, Stephan, Haloftis, shaloft@wgu.edu, 29, 4, 2, 5, SOFTWARE"};

    // Calculating numbers of students
    const size_t numstu = sizeof(studentData)/sizeof(studentData[0]);

    // Populate roster
    roster classRoster = sd(studentData, numstu);

    return 0;
}

// Parsing Roster Function
roster sd(const string studentData[], size_t numstu) {
    roster roster;

    // find() function finds the position of delimiter within string
    // substr() returns a substring of the object
    // reference https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
    for (size_t i = 0; i < numstu; i++) {

        // find() function searches the string for the first occurrence of the sequence specified in args
        // When pos is specified, the search only includes characters at or after pos

        // parsing for studentID
        string com = ","; // declaring comma variable
        size_t acomma = studentData[i].find(com); // finding first comma in string
        string putsID = studentData[i].substr(0, acomma); // assigning string before first comma
        cout << putsID << endl; // testing line

        // parsing for fname
        size_t nexcomma = acomma + 1; // creating next position args for find function
        acomma = studentData[i].find(',', nexcomma); // finding next comma
        string putsfname = studentData[i].substr(nexcomma, acomma - nexcomma); // assigning string in between commas
        cout << putsfname << endl; // testing line

        // parsing for lname
        nexcomma = acomma + 1; // creating next position args for find function
        acomma = studentData[i].find(',', nexcomma); // finding next comma
        string putslname = studentData[i].substr(nexcomma, acomma - nexcomma); // assigning string in between commas
        cout << putslname << endl; // testing line

        // parsing for email
        nexcomma = acomma + 1; // creating next position args for find function
        acomma = studentData[i].find(',', nexcomma); // finding next comma
        string putsemail = studentData[i].substr(nexcomma, acomma - nexcomma); // assigning string in between commas
        cout << putsemail << endl; // testing line

        // parsing for age
        nexcomma = acomma + 1; // creating next position args for find function
        acomma = studentData[i].find(',', nexcomma); // finding next comma
        string putsage = studentData[i].substr(nexcomma, acomma - nexcomma); // assigning string in between commas
        int ageit = stoi(putsage); // string to int conversion
        cout << putsage << endl; // testing line

        // parsing for dic1
        nexcomma = acomma + 1; // creating next position args for find function
        acomma = studentData[i].find(',', nexcomma); // finding next comma
        string putsdic1 = studentData[i].substr(nexcomma, acomma - nexcomma); // assigning string in between commas
        int dic1it = stoi(putsdic1); // string to int conversion
        cout << putsdic1 << endl; // testing line

        // parsing for dic2
        nexcomma = acomma + 1; // creating next position args for find function
        acomma = studentData[i].find(',', nexcomma); // finding next comma
        string putsdic2 = studentData[i].substr(nexcomma, acomma - nexcomma); // assigning string in between commas
        int dic2it = stoi(putsdic2); // string to int conversion
        cout << putsdic2 << endl; // testing line

        // parsing for dic3
        nexcomma = acomma + 1; // creating next position args for find function
        acomma = studentData[i].find(',', nexcomma); // finding next comma
        string putsdic3 = studentData[i].substr(nexcomma, acomma - nexcomma); // assigning string in between commas
        int dic3it = stoi(putsdic3); // string to int conversion
        cout << putsdic3 << endl; // testing line

        // parsing for degree focus
        nexcomma = acomma + 1; // creating next position args for find function
        DegreeProgram focus = DegreeProgram::NONE;
        string focusString = studentData[i].substr(nexcomma, studentData[i].length() - nexcomma);
        cout << focusString << endl; // testing line

        // logic to assign proper DegreeProgram values
        if (focusString == " SECURITY")
        {
            focus = DegreeProgram::SECURITY;
//            cout << focusString + " if statement print checkpoint" << endl; // testing line
        }
        else if (focusString == " NETWORK")
        {
            focus = DegreeProgram::NETWORK;
//            cout << focusString + " if statement print checkpoint" << endl; // testing line
        }
        else if (focusString == " SOFTWARE")
        {
            focus = DegreeProgram::SOFTWARE;
//            cout << focusString + " if statement print checkpoint" << endl; // testing line
        }
        else
        {
            cout << "Error with focusString assignment to enum" << endl;
        }

        // adding parsed data to roster
        roster.add(putsID, putsfname, putslname, putsemail, ageit, dic1it, dic2it, dic3it, focus);
    }
    return roster;
}