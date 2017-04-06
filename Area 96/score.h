#ifndef _SCORE_H_
#define _SCORE_H_
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;

class Score
{
protected:
    string course_code;
    string student_id;
    int year;
    int semester;
    double midterm;
    double lab;
    double _final;
public:
    void Input();
    void Print(ostream &);
    void Print_one_line(ostream &);
};

class Node_score
{
public:
    Score data;
    Node_score *next;
};

class Score_list
{
protected:
    Node_score *head;
public:
    Score_list();
    void Add_to_last(const Score s);
    void Add_score_to_last();
    void Print_list(ostream &);
    void Print_list_one_line(ostream &);
    ~Score_list();
};
#endif
