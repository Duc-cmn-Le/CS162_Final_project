#ifndef _SMS_H_
#define _SMS_H_
#include "CSVhelper.h"
#include "user.h"
#include "course.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>

using namespace std;
int to_int(const string); // Gia Bao
double to_double(const string ); // Gia Bao

class Student_management_service{
public:
    void Import_course(); // Finished - Cong Duc
    void Import_course_from_file(); // Finished - Cong Duc
    void Import_student_list(); // Finished - Cong Duc
    void Import_schedules();
    void Import_score(); // Finished - Cong Duc
    void View_list_of_course(); // Finished - Mai Trinh
    void Export_scores_of_student(const string,ostream &); // Finished - Gia Bao
    void Export_scores_of_course(const string,ostream &); // Finished - Gia Bao
    void Print_present(string,ostream &); // Finished - Van Nam 
    void Print_absent(string,ostream &); // Finished - Van Nam
    int Check_in(string,string,string,int);
};
#endif
