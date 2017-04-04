//#include "CSVhelper.h"
//#include "UI.h"
//#include "SMS.h"
#include "user.h"

using namespace std;

int main() {
    Student_list a;
    a.List_all_student();
    a.Print_list();
    cout << "Xoa me thang Hieu\n";
    a.Delete_node("1651044");
    a.Print_list();
    return 0;
}
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
