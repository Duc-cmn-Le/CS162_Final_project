#include "SMS.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <unistd.h>
#include <stdio.h>
using namespace std;

class User_interface{
protected:
    string role[3] = {"student","staff","lecturer"};
    int type; // -1, 0, 1, 2
    string account_name;
public:
    User_interface(); 
    void Program(); // Cong Duc
    int Login(string,string); // Gia Bao
    void Logout(); // Cong Duc
    void Menu(string); // Cong Duc
    void Change_password(); // Van Nam
    void Check_in(); // Cong Duc
};
