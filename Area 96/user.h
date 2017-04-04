//Bao
#ifndef _USER_H_
#define _USER_H_
#include<iostream>
#include<cstring>
#include<string>
#include<iomanip>
//
using namespace std;
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
    void Print();
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
    void Print_list();
    ~Student_list();
};
#endif
