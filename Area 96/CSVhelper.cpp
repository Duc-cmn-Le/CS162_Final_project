#include "CSVhelper.h"

void CSV_helper::Write_file(Student_list &L,string file_name) {
    freopen((file_name).c_str(),"a+",stdout);
    L.Print_list_one_line();
}

/*

User CSVhelper::Get_details(string file_type,string username) {

}

Course CSVhelper::Get_details(string file_type,string course_code) {

}

Presence CSVhelper::Get_details(string file_type,pair<string,string> primary_key) {

}

Score CSVhelper::Get_details(string file_type,pair<string,string> primary_key) {

}
*/
