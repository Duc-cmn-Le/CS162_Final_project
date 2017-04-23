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
int to_int(const string);
double to_double(const string );

class Student_management_service{
public:
    void Import_course(); // Finished
    void Import_course_from_file();
    void Import_student_list(); // Finished
    void Import_schedules();
    void Import_score();

    void Export_scores_of_student(const string,ostream &);
    void Export_scores_of_course(const string,ostream &);
    void Print_present(string,ostream &); 
    void Print_absent(string,ostream &);
};
#endif
