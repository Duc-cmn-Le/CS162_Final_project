#ifndef _CSVhelper_H_
#define _CSVhelper_H_
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>

#include "user.h"
#include "course.h"
#include "presence.h"
#include "score.h"

using namespace std;

void Plus_one_week(string &); // Van Nam
int Next_token(string &,string &); // Cong Duc
int Next_token(string &,string &,char); // Cong Duc

class CSV_helper{ // Cong Duc
public:
    void CSV_reform(string);                        // Cong Duc
    void Write_file(Student_list &,string); // Cong Duc
    void Write_file(Course_list &,string); // Cong Duc
    void Write_file(Score_list &,string); // Cong Duc
    int Get_details(string,string,User &); // Cong Duc
    int Get_details(string,string,string,int,Course &); // Cong Duc
    int Is_student_in_course(string,string,string,int); // Cong Duc
};

#endif
