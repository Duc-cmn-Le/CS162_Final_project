#include "CSVhelper.h"
#include "MD5.h"
void CSV_helper::Change_password(string username,string password) {
    filebuf fb, fbnew;
    fb.open ("user.txt",ios::in);
    fbnew.open ("user_new.txt",ios::out);
    istream fin(&fb);
    ostream fnew(&fbnew);
    string S, s;
    int c;
    while (getline(fin,S)) {
        c = Next_token(S,s);
        fnew << s << ",";
        if (s != username) {
            fnew << S << endl;
            continue;
        }
        Md5 hsh;
        hsh.pass = password;
        c = Next_token(S,s);
        fnew << s << ",";
        c = Next_token(S,s);
        fnew << s << ",";
        c = Next_token(S,s);
        fnew << s << ",";
        c = Next_token(S,s);
        fnew << s << ",";
        fnew << hsh.Process() << ",";
        c = Next_token(S,s);
        fnew << S << endl;
    }
    fb.close();
    fbnew.close();
    system("mv course_student_new.txt course_student.txt");
}
