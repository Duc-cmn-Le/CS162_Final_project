#include "SMS.h"

// Import courses

//Import student list
void Student_management_service::Import_student_list() {
    cout << "Enter 0 if you want to import from keyboard\n";
    int flag;
    Student_list a;
    while (cin >> flag) {
        cout << "Enter number of student\n";
        int number;
        cin >> number;
        for (;number;number--) 
            a.Add_student_to_last();
        break;
    }

}

//Import schedules

//Import scores

//Get score of student

//Get score of course

//Get list of student who was present

//Get list of student who was absent

//Check-in class
