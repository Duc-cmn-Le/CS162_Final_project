#include "SMS.h"

// Import courses

//Import student list
void Student_management_service::Import_student_list() {
    cout << "Enter 0 if you want to import from keyboard\n";
    cout << "Enter 1 if you want to import from file\n";
    int flag;
    while (cin >> flag) {
        if (flag == 0) {
                
            break;
        } 
        else if (flag == 1) {

            break;
        }
        else cout << "Invalid number - Please enter a key again\n";
    }

}

//Import schedules

//Import scores

//Get score of student

//Get score of course

//Get list of student who was present

//Get list of student who was absent

//Check-in class
