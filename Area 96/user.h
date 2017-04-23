//Bao
#ifndef _USER_H_
#define _USER_H_
#include "MD5.h"
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<iomanip>
//
using namespace std;

int _Next_token(string &s,string &target);

class User
{
public:
    string username;
    string full_name;
    string email;
    string mobile_phone;
    short type;
    string password;
    string _class;
public:
    void Input();
    void Print(ostream &);
    void Print_one_line(ostream &);
};

class Node
{
public:
    User data;
    Node* next;
};
class Student_list
{
private:
    Node *head;
public:
    Student_list();
    void Add_to_last(const User u);
    void Add_student_to_last();
    void List_all_student();
    void Delete_node(string);
    void Print_list(ostream &);
    void Print_list_one_line(ostream &);
    void Make_empty();
    ~Student_list();
};
#endif
