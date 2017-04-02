//Bao
#ifndef _USER_H_
#define _USER_H_
#include<iostream>
#include<cstring>
#include<string>
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
class Linkedlist
{
private:
    Node *head;
public:
    Linkedlist();
    void Add_to_last(const User u);
    void Add_student_to_last();
    void Print_list();
    ~Linkedlist();
};
#endif
