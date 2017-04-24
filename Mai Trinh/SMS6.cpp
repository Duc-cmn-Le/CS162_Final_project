#include "SMS.h"
#include "course.h"

//Check-in class
int Student_management_service::Is_ok_check_in(string username,string course_code,string year,int semester) {
    CSV_helper csv;
    Course c;
    string file_name = "course.txt";
    if (csv.Get_details(file_name,course_code,year,semester,c)) {
        Date d;
        Time t;
        string wday;
        Take_time(d,t,wday);
        if ((wday == c.date_of_week) && (Check_in_date(d,c)) && (Check_in_time(t,c))) {
        Course cou;
        cou.start_at = c.start_at;
        cou.end_at = d;
        return cou.Count_week();
        }
    }
    return 0;
}
