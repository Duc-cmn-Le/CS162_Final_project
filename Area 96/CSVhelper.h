#ifndef _CSVhelper_H_
#define _CSVhelper_H_
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>

#include "user.h"
/*
#include "course.h"
#include "score.h"
#include "presence.h"
*/
using namespace std;

int Next_token(string &,string &);

class CSV_helper{
public:
    void Write_file(Student_list &,string);
    int Get_details(string,string,User &);
    /*
    Course Get_details(string,string);
    Presence Get_details(string,pair<string,string>);
    Score Get_details(string,pair<string,string> );
    */
};

#endif
