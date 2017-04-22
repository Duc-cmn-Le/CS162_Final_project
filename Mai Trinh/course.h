#ifndef _COURSE_H_
#define _COURSE_H_

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct Date
{
    int d, m, y;
};

struct Time
{
    int s, m, h;
};

void _Next_token(string &,string &);
void _Date_token(string &s,string &target);
void Date_process(string &S, Date &d);
void _Time_token(string &s,string &target);
void Time_process(string &S, Time &t);

class Course
{
    public:
    string course_code, year, course_name, lecturer_name, date_of_week;
    Date start_at, end_at;
    Time from, to;
    int semester;
    void Input();
    void Print(ofstream &fout);
    void Print_one_line(ofstream &fout);
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
    void Input_line_by_line(ifstream &fin);
    void Print_list(ofstream &fout);
    void Print_list_one_line(ofstream &fout);
    void Make_empty();
};

#endif

