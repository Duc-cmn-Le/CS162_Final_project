#include "CSVhelper.h"

int Next_token(string &s,string &target) {
    target = "";
    int cnt = 0;
    for (string::iterator i=s.begin();i!=s.end();++i,cnt++)
        if (*i == ',') {
            target.insert(target.begin(),s.begin(),i);
            s.erase(0,cnt+1);
            return true;
        }
    target = s;
    return false;
}

void CSV_helper::Write_file(Student_list &L,string file_name) {
    freopen((file_name).c_str(),"a+",stdout);
    L.Print_list_one_line();
}

void CSV_helper::Write_file(Course_list &L,string file_name) {
    freopen((file_name).c_str(),"a+",stdout);
    L.Print_list_one_line();
}

int CSV_helper::Get_details(string file_type,string username,User &res) {
    freopen(file_type.c_str(),"r",stdin);
    string S, s;
    while (getline(cin,S)) {
        Next_token(S,s);
        if (s != username) continue;
        res.username = s;
        Next_token(S,s);
        res.full_name = s;
        Next_token(S,s);
        res.email = s;
        Next_token(S,s);
        res.mobile_phone = s;
        Next_token(S,s);
        res.type  = s[0]-'0';
        Next_token(S,s);
        res._class = S; 
        return true;
    }
    return false;
}
/*
Presence CSV_helper::Get_details(string file_name,pair<string,string> primary_key,Presence &res) {
    freopen(file_name.c_str(),"r",stdin);
    string S, s, s_code;
    int year, semester, week;
    while (getline(cin,S)) {
        Next_token(S,s_code);
        if (s_code != primary_key.first) continue;

    }
}
*/

/*

Course CSVhelper::Get_details(string file_type,string course_code) {

}

Presence CSVhelper::Get_details(string file_type,pair<string,string> primary_key) {

}

Score CSVhelper::Get_details(string file_type,pair<string,string> primary_key) {

}
*/
