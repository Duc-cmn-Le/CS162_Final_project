//#include "CSVhelper.h"
//#include "UI.h"
//#include "SMS.h"
#include "user.h"

using namespace std;

int main() {
    Linkedlist a;
    cout << "Enter number of student\n";
    int n;
    cin >> n;
    for (;n;n--) a.Add_student_to_last();
    a.Print_list();
    return 0;
}
