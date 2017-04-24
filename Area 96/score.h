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
public:
    string course_code;
    string student_id;
    string year;
    int semester;
    int type;
    double mark;
public:
    void Input();
    void Print(ostream &);
    void Print_one_line(ostream &);
    void Print_one_line_(ostream &);
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
    void Print_list_one_line_(ostream &);
    ~Score_list();
};
#endif
