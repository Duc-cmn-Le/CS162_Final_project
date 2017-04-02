//Bao
#ifndef _USER_H_
#define _USER_H_
#include<iostream>
#include<string>
using namespace std;
class User
{
private:
    string username;
    string full_name;
    string email;
    string mobile_phone;
    short type;
    string password;
    string _class;
public:
    void Input();
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
    ~Linkedlist();
    void Add_to_last(const User u);
};
#endif
