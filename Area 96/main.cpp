#include "UI.h"
#include "SMS.h"
#include "user.h"
#include "course.h"

using namespace std;

int main() {
    User_interface UI;
    UI.Program();
    return 0;
}

/*
int main() {
    ios_base::sync_with_stdio(false);
    Student_management_service Service;
//    Service.View_checkin_of_course("1651044");
//    Service.View_score_of("1651044");
//    Service.Edit_score();
//    Service.Import_score_from_file();
//    Service.Import_class_from_file();
//    Service.Show_list_of_student_in_course();
//    Service.Assign_one_class();
//    Service.Assign_one_student();
//    Service.Show_list_of_student_in_course();
//    Service.Show_list_of_student_in_class();
//    cout << Service.Check_in("ldcduc","AA123","2017",3);
//    Service.View_list_of_course(); 
//    Service.Import_course_from_file();
//    Service.Export_scores_of_student("1651044",cout);
//    Service.Export_scores_of_course("CS161",cout);
//    Service.Print_present("MTH251",cout);
//    Service.Print_absent("MTH251",cout);
//    Service.Import_student_list();
//    Service.Import_score();
//    Service.Import_course();
}
*/
