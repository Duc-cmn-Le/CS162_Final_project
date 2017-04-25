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
    void Input();                           // Gia Bao
    void Print(ostream &);                  // Gia Bao
    void Print_one_line(ostream &);         // Gia Bao
    void Print_one_line_(ostream &);        // Gia Bao
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
    Score_list();                           // Gia Bao
    void Add_to_last(const Score s);        // Gia Bao
    void Add_score_to_last();               // Gia Bao
    int Find_student(string);               // Gia Bao
    void Print_list(ostream &);             // Gia Bao
    void Print_list_one_line(ostream &);    // Gia Bao
    void Print_list_one_line_(ostream &);   // Gia Bao
    ~Score_list();
};
#endif
