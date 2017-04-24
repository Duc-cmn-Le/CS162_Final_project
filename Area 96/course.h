#ifndef _COURSE_H_
#define _COURSE_H_

#include "user.h"
#include <iostream>
#include <cstring>
using namespace std;

int Get_details(string file_name,string user_name,User &res);               // Cong Duc

bool LeapYear(int);                                                         // Mai Trinh
int nth(int,int,int);                                                       // Mai Trinh

void _Next__token(string &,string &);                                       // Mai Trinh
void _Date_token(string &s,string &target);                                 // Mai Trinh
void _Time_token(string &s,string &target);                                 // Mai Trinh


struct Date
{
    int d, m, y;
};

struct Time
{
    int s, m, h;
};

void Date_process(string &S, Date &d);                                      // Mai Trinh

void Time_process(string &S, Time &t);                                      // Mai Trinh

class Course
{
    public:
    string course_code, year, course_name, lecturer_name, date_of_week;
    Date start_at, end_at;
    Time from, to;
    int semester;
    void Input();                                                           // Mai Trinh
    void Print(ostream &);                                                  // Mai Trinh
    void Print_one_line(ostream &);                                         // Mai Trinh
    int Count_week();                                                      // Mai Trinh
} ;

class Node_course
{
    public:
    Course data;
    Node_course* next;
    Node_course(Course x);                                                  // Mai Trinh
};

class Course_list
{
    Node_course* head;
public:
    Course_list() {head = NULL;};
    ~Course_list();                                                         // Mai Trinh 
    void Create_lecturer(string s);                                         // Cong Duc
    void Add_tail(Course x);                                                // Mai Trinh
    void Add_a_course();                                                    // Mai Trinh
    void Delete_node(string s);                                             // Mai Trinh
    void Delete_a_course();                                                 // Mai Trinh
    void Input_line_by_line(istream &);                                     // Mai Trinh
    void Print_list(ostream &);                                             // Mai Trinh
    void Print_list_one_line(ostream &);                                    // Mai Trinh
    void Make_empty();                                                      // Mai Trinh
};

#endif
