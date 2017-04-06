#include "SMS.h"

// Import courses

//Import student list
void Student_management_service::Import_student_list() {
    Student_list a;
    cout << "Enter number of student\n";
    int number;
    cin >> number;
    for (;number;number--) 
        a.Add_student_to_last();
    CSV_helper Helper;
    Helper.Write_file(a,"user.txt");
}

void Student_management_service::Import_course() {
    Course_list a;
    cout << "Enter number of course\n";
    int number;
    cin >> number;
    for (;number;number--) 
        a.Add_a_course();
    CSV_helper Helper;
    Helper.Write_file(a,"course.txt");
}



//Import schedules

//Import scores
void Student_management_service::Import_score() {
    Score_list a;
    int number;
    cout << "Enter number of score\n";
    cin >> number;
    for (;number;number--)
        a.Add_score_to_last();
    CSV_helper Helper;
    Helper.Write_file(a,"score.txt");
}

//Get score of student

//Get score of course

//Get list of student who was present

//Get list of student who was absent

//Check-in class
