#include "CSVhelper.h"
#include "MD5.h"
void CSV_helper::Change_password(string username,string password) {
    filebuf fb, fbnew;
    fb.open ("user.txt",ios::in);
    fbnew.open ("user_new.txt",ios::out);
    istream fin(&fb);
    ostream fnew(&fbnew);
    string S, s;
    while (getline(fin,S)) {
        Next_token(S,s);
        fnew << s << ",";
        if (s != username) {
            fnew << S << endl;
            continue;
        }
        Md5 hsh;
        hsh.pass = password;
        Next_token(S,s);
        fnew << s << ",";
        Next_token(S,s);
        fnew << s << ",";
        Next_token(S,s);
        fnew << s << ",";
        Next_token(S,s);
        fnew << s << ",";
        fnew << hsh.Process() << ",";
        Next_token(S,s);
        fnew << S << endl;
    }
    fb.close();
    fbnew.close();
    system("mv course_student_new.txt course_student.txt");
}
