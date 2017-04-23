#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class User_interface{
protected:
    string role[3] = {"student","staff","lecturer"};
    int type; // -1, 0, 1, 2
    string account_name;
public:
    User_interface();
    void Program();
    int Login(string,string);
    void Logout();
    void Menu_display(string);
};
