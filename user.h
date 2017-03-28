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
    string Class;
};
struct Node
{
    User data;
    Node* Next;
};
struct Linkedlist
{
private:
    Node *head;
public:
    Linkedlist();
    ~Linkedlist();
    void add_to_last(const User u);
};
#endif
