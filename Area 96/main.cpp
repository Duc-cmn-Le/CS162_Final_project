//#include "CSVhelper.h"
//#include "UI.h"
//#include "SMS.h"
#include "user.h"
#include "CSVhelper.h"

using namespace std;

int main() {
    User a;
    CSV_helper helper;
    if (helper.Get_details("user.txt","1651049",a))
        a.Print();
    else cout << "Cant find";
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
