#include "CSVhelper.h"
//#include "UI.h"
#include "SMS.h"
#include "user.h"
#include "course.h"

using namespace std;

int main() {
    Student_management_service Service;
    Service.Print_present("MTH251",cout);
    Service.Print_absent("MTH251",cout);
//    Service.Import_student_list();
//    Service.Import_score();
//    Service.Import_course();
}
/*
 TEST IMPORT STUDENT
int main() {
    Course_list a;
    cout << "Enter number of course\n";
    int n;
    cin >> n;
    for (;n;n--) a.Add_a_course();
    CSV_helper Helper;
    Helper.Write_file(a,"course.txt");
    return 0;
}
*/
/* 
 * TEST IMPORT STUDENT
int main() {
    Student_list a;
    cout << "Enter number of student\n";
    int n;
    cin >> n;
    for (;n;n--) a.Add_student_to_last();
//    a.Print_list();
    CSV_helper Helper;
    Helper.Write_file(a,"user.txt");
    return 0;
}
*/
