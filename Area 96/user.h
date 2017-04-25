//Bao
#ifndef _USER_H_
#define _USER_H_
#include "MD5.h"
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<iomanip>
#include<stdio.h>
#include<unistd.h>
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
    void Input();                                               // Cong Duc
    void Print(ostream &);                                      // Cong Duc
    void Print_one_line(ostream &);                             // Cong Duc
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
    int Get_details(string,string,User &); // Cong Duc
    void Add_to_last(const User u);                             // Cong Duc
    void Add_student_to_last();                                 // Cong Duc
    void List_all_student();                                    // Cong Duc
    void List_all_student_of_class(string,string &);            // Cong Duc
    void List_all_student_of_course(string,string,int,string &);// Cong Duc 
    void Delete_node(string);                                   // Cong Duc
    void Input_line_by_line(istream &);                         // Cong Duc
    void Print_list(ostream &);                                 // Cong Duc
    void Print_list_one_line(ostream &);                        // Cong Duc
    void Make_empty();                                          // Cong Duc
    int Is_empty();                                             // Cong Duc
    ~Student_list();                                            // Cong Duc
};
#endif
