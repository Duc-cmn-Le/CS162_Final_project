#ifndef _COURSE_H_
#define _COURSE_H_

#include <iostream>
#include <cstring>
using namespace std;

void _Next__token(string &,string &);
void _Date_token(string &s,string &target);
void _Time_token(string &s,string &target);


struct Date
{
    int d, m, y;
};

struct Time
{
    int s, m, h;
};

void Date_process(string &S, Date &d);

void Time_process(string &S, Time &t);

class Course
{
    public:
    string course_code, year, course_name, lecturer_name, date_of_week;
    Date start_at, end_at;
    Time from, to;
    int semester;
    void Input();
    void Print(ostream &);
    void Print_one_line(ostream &);
} ;

class Node_course
{
    public:
    Course data;
    Node_course* next;
    Node_course(Course x);
};

class Course_list
{
    Node_course* head;
public:
    Course_list() {head = NULL;};
    ~Course_list();
    void Add_tail(Course x);
    void Add_a_course();
    void Delete_node(string s);
    void Delete_a_course();
    void Input_line_by_line(istream &);
    void Print_list(ostream &);
    void Print_list_one_line(ostream &);
    void Make_empty();
};

#endif
