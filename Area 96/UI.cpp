#include "UI.h"
#include "CSVhelper.h"
#include "user.h"



void User_interface::Program() {
    string username, password;
    while (1) {
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;
        if (Login(username,password) == 0) continue;
        Menu(role);
    }
}

int User_interface::Login(string username,string password) {
    if (username == "httu" && password == "admin") {
        type = 1;
        account_name = "httu"; 
        return true;
    }
    User u;
    CSV_helper csv;
    if (csv.Get_details("user.txt",username,u) && u.password==password) {
        account_name = username;
        type = u.type; // gan gia tri cho type tuong ung voi user ma minh tim dc
        return true;
    }
    return false;
}

void User_interface::Logout() {
    type = -1;
}

void User_interface::Menu(string role) {
    // Role: "student", "staff", "lecturer"
    string s[] = {"Show menu",                                  // 0
        "Logout",                                               // 1
        "Change password",                                      // 2
        // Academic Staff
        "Add a course",                                         // 3
        "Import courses from csv file",                         // 4
        "View list of course in the console screen",            // 5
        "Assign an existing class to a course",                 // 6
        "Add an existing student to a course",                  // 7
        "Import a list of students in a class from a csv file", // 8
        "Show list of students in a class in the console screen",// 9
        "Show list of students in a course in the console screen",// 10
        // Lecturer
        "Export scores of an exam in a course to a csv file",   // 11
        "Show scores of an exam in a course in the console screen", // 12
        "Import scores of an exam in a course from a csv file", // 13
        "Edit a score of a student in an exam",                 // 14
        // Student
        "Check-in ",                                            // 15
        "View my check in history in a course",                 // 16
        "View my score in a course"                             // 17
    };
    int flag;
    int _width = 100;
    if (role == "student") {
        for (int i=0;i<=1;++i)
            cout << setw(10) << i << setw(_width) << s[i] << '\n';
        for (int i=15;i<=17;++i)
            cout << setw(10) << i-13 << setw(_width) << s[i] << '\n';
        while (cin >> flag) 
        switch(flag)
        {
            case 0:
                for (int i=0;i<=1;++i)
                    cout << setw(10) << i << setw(_width) << s[i] << '\n';
                for (int i=15;i<=17;++i)
                    cout << setw(10) << i-13 << setw(_width) << s[i] << '\n';
                break;
        }
    }
    else if (role == "staff") {
        for (int i=0;i<=1;++i)
            cout << setw(10) << i << setw(_width) << s[i] << '\n';
        for (int i=3;i<=10;++i)
            cout << setw(10) << i-1 << setw(_width) << s[i] << '\n';
        while (cin >> flag) 
        switch(flag)
        {
            case 0:
                for (int i=0;i<=1;++i)
                    cout << setw(10) << i << setw(_width) << s[i] << '\n';
                for (int i=3;i<=10;++i)
                    cout << setw(10) << i-1 << setw(_width) << s[i] << '\n';
                break;
        }
    }
    else {
        for (int i=0;i<=1;++i)
            cout << setw(10) << i << setw(_width) << s[i] << '\n';
        for (int i=11;i<=14;++i)
            cout << setw(10) << i-9 << setw(_width) << s[i] << '\n';
        while (cin >> flag) 
        switch(flag)
        {
            case 0:
                for (int i=0;i<=1;++i)
                    cout << setw(10) << i << setw(_width) << s[i] << '\n';
                for (int i=11;i<=14;++i)
                    cout << setw(10) << i-9 << setw(_width) << s[i] << '\n';
                break;
        }
    }
}

// Change:wq
//

void User_interface::Change_password(string username,string password) 
{


}
