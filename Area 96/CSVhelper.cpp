#include "CSVhelper.h"
#include <cstdio>

// Plus one week - Van Nam
void Plus_one_week (string &week)
{
    if (week == "9") week = "10";
    else if (week == "19") week = "20";
    else if (week == "29") week = "30";
    else if (week == "39") week = "40";
    else if (week == "49") week = "50";
    else if (week.length() == 1) week[0]++;
    else week[1]++;
}

// Next token - Cong Duc
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

int Next_token(string &s,string &target,char c) {
    target = "";
    int cnt = 0;
    for (string::iterator i=s.begin();i!=s.end();++i,cnt++)
        if (*i == c) {
            target.insert(target.begin(),s.begin(),i);
            s.erase(0,cnt+1);
            return true;
        }
    target = s;
    return false;
}

// Cong Duc
void CSV_helper::CSV_reform(string file_name) 
{
    system(("tr '\r' '\n' < "+file_name+" > "+file_name+"2").c_str());
    system(("mv "+file_name+"2 "+file_name).c_str());
}
// Cong Duc
void CSV_helper::Write_file(Student_list &L,string file_name) {
    ofstream fout(file_name.c_str(),fstream::app);
    L.Print_list_one_line(fout);
    fout.close();
}

// Cong Duc
void CSV_helper::Write_file(Course_list &L,string file_name) {
    ofstream fout(file_name.c_str(),fstream::app);
    L.Print_list_one_line(fout);
    fout.close();
}

// Cong Duc
void CSV_helper::Write_file(Score_list &L,string file_name) {
    ofstream fout(file_name.c_str(),fstream::app);
    L.Print_list_one_line(fout);
    fout.close();
}

// Cong Duc
int CSV_helper::Get_details(string file_type,string username,User &res) {
    ifstream fin(file_type.c_str());
    string S, s;
    while (getline(fin,S)) {
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

// Cong Duc
int CSV_helper::Get_details(string file_name,string course_code,string year,int semester,Course &res) 
{
    ifstream fin(file_name.c_str());
    string S, s;
    while (getline(fin,S)) { 
        Next_token(S,s);
        if (s != course_code) continue;
        res.course_code = s;
        Next_token(S,s);
        if (s != year) continue;
        res.year = s;
        Next_token(S,s);
        if (s[0]-'0' != semester) continue;
        res.semester = s[0]-'0';
        Next_token(S,s);
        res.course_name = s;
        Next_token(S,s);
        res.lecturer_name = s;
        Next_token(S,s);
        Date_process(s,res.start_at);
        Next_token(S,s);
        Date_process(s,res.end_at);
        Next_token(S,s);
        Time_process(s,res.from);
        Next_token(S,s);
        Time_process(s,res.to);
        res.date_of_week = S;
        return true;
        
    }
    return false;
}

// Cong Duc

int CSV_helper::Is_student_in_course(string student_id,string course_code,string year,int semester) 
{
    ifstream fin("course_student.txt");
    string S, s;
    while (getline(fin,S)) {
        Next_token(S,s);
        if (s != course_code) continue;
        Next_token(S,s);
        if (s != year) continue;
        Next_token(S,s);
        if (s[0]-'0' != semester) continue;
        while (Next_token(S,s)) 
            if (s == student_id) {
                fin.close();
                return true;
            }
        fin.close();
        return (S == student_id);
    }
    fin.close();
    return false;
}

