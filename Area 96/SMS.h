#ifndef _SMS_H_
#define _SMS_H_
#include "CSVhelper.h"
#include "user.h"
#include "course.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <ctime>

using namespace std;
int to_int(const string); // Gia Bao
double to_double(const string ); // Gia Bao
int Check_in_date(Date,Course); // Mai Trinh
int Check_in_time(Time,Course); // Mai Trinh
void Take_time(Date&,Time&,string&); // Mai Trinh

class Student_management_service{
public:
    void Import_course(); // Finished - Cong Duc
    void Import_course_from_file(); // Finished - Cong Duc
    void Import_student_list(); // Finished - Cong Duc
    void Import_class_from_file(); // Finished - Cong Duc
    void Import_score(); // Finished - Cong Duc
    void Import_score_from_file(); // - Cong Duc
    void Assign_one_student(); // Finished - Mai Trinh
    void Assign_one_class(); // Finished - Cong Duc
    void Show_list_of_student_in_class(); // Finished - Cong Duc
    void Show_list_of_student_in_course(); // Finished - Cong Duc
    void View_list_of_course(); // Finished - Mai Trinh
    void Edit_score();  // Finished - Gia Bao
    void View_score_of(string); // Finished - Gia Bao
    void Export_scores_of_student(const string,ostream &); 
    void Export_scores_of_course(const string,ostream &); 
    void Print_present(string,ostream &); // Finished - Van Nam 
    void Print_absent(string,ostream &); // Finished - Van Nam
    int Is_ok_check_in(string,string,string,int);
};
#endif
