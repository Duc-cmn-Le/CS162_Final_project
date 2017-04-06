#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class User_interface{
protected:
    string role[] = {"student","staff","lecturer"};
    int type; // -1, 0, 1, 2
public:
    void Program();
    int Login(string,string);
    void Logout();
    void Menu_display(string);
};
