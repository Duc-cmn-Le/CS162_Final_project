#include "UI.h"
void User_interface::Login() {
    
}

void User_interface::Logout() {

}

void User_interface::Menu_display(string role) {
    // Role: "student", "staff", "lecturer"    
    string s[] = {"Show menu",                                  // 0 
        "Logout",                                               // 1
        // Academic Staff
        "Import courses",                                       // 2
        "Import student lists",                                 // 3
        "Import schedules",                                     // 4
        "Export scores of student",                             // 5
        "Export scores of course",                              // 6
        "Export lists of student who was present in class",     // 7
        "Export lists of student who was absent in class",      // 8
        // Lecturer
        "Import scores",                                        // 9 
        // Student
        "Check-in class"                                        // 10
    };
    int _width = 70;
    cout << setw(10) << "Number" << setw(_width) << "Function\n";
    for (int i=0;i<=1;++i)
        cout << setw(10) << i << setw(_width) << s[i] << '\n';
    if (role == "student") {
        for (int i=10;i<=10;++i)
            cout << setw(10) << i << setw(_width) << s[i] << '\n';
    }
    else if (role == "staff") {
        for (int i=2;i<=8;++i)
            cout << setw(10) << i << setw(_width) << s[i] << '\n';
    }
    else {
        for (int i=9;i<=9;++i)
            cout << setw(10) << i << setw(_width) << s[i] << '\n';
    }
}
