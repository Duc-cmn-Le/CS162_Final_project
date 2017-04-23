#include "SMS.h"

void Student_management_service::View_list_of_course() {
    string S, s;
    Course c;
    Course_list a;
    filebuf fb;
    fb.open ("course.txt",ios::in);
    istream fin(&fb);
    while (getline(fin,S)) {
        _Next__token(S,s);
        c.course_code = s;
        _Next__token(S,s);
        c.year = s;
        _Next__token(S,s);
        c.semester = int(s[0])-48;
        _Next__token(S,s);
        c.course_name = s;
        _Next__token(S,s);
        c.lecturer_name = s;
        _Next__token(S,s);
        Date_process(s,c.start_at);
        _Next__token(S,s);
        Date_process(s,c.end_at);
        _Next__token(S,s);
        Time_process(s,c.from);
        _Next__token(S,s);
        Time_process(s,c.to);
        c.date_of_week = S;
        a.Add_tail(c);
    }
    a.Print_list(cout);
    fb.close();
}
