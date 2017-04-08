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

void Plus_one_week(string &);
int Next_token(string &,string &);

class CSV_helper{
public:
    void Write_file(Student_list &,string);
    void Write_file(Course_list &,string);
    void Write_file(Score_list &,string);
    int Get_details(string,string,User &);
//    int Get_details(string,pair<string,string>,Presence &);
    /*
    Course Get_details(string,string);
    Presence Get_details(string,pair<string,string>);
    Score Get_details(string,pair<string,string> );
    */
};

#endif
