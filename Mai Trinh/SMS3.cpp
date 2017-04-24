#include "SMS.h"

int Student_management_service::Assign_one_student(string course_code,string year,int semester,string student_id) {
    filebuf fb, fbnew;
    fb.open ("course_student.txt",ios::in);
    fbnew.open ("course_student_new.txt",ios::out);
    istream fin(&fb);
    ostream fnew(&fbnew);
    string S, s;
    int c;
    while (getline(fin,S)) {
        c = Next_token(S,s);
        fnew << s << ",";
        if (s != course_code) {
            fnew << S << endl;
            continue;
        }
        c = Next_token(S,s);
        fnew << s << ",";
        if (s != year) {
            fnew << S << endl;
            continue;
        }
        c = Next_token(S,s);
        fnew << s;
        int tmp = 0;
        for (string::iterator i=s.begin();i!=s.end();++i)
            tmp = tmp*10 + *i - '0';
        if (tmp != semester) {
            fnew << "," << S << endl;
            continue;
        }
        while (Next_token(S,s)) {
            fnew << "," << s;
            if (s == student_id) return 0;
        }
        fnew << "," << S << "," << student_id << endl;
    }
    fb.close();
    fbnew.close();
    system("mv course_student_new.txt course_student.txt");
    return 1;
}
