//#include "CSVhelper.h"
//#include "UI.h"
//#include "SMS.h"
#include "user.h"

using namespace std;

int main() {
    Linkedlist a;
    int n;
    cin >> n;
    for (;n;n--) a.Add_student_to_last();
    a.Print_list();
    return 0;
}
