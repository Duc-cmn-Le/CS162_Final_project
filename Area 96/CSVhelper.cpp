#include "CSVhelper.h"
#include <cstdio>

// Plus one week - Van Nam
void Plus_one_week (string &week)
{
    if (week == "9") week = "10";
    else if (week == "19") week = "20";
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
// Change password - Van Nam
/*
void Change_password(string username, string password)
{
    ifstream filein;
    ofstream fileout;
    filein.open ("user.txt");
    fileout.open ("user_out.txt");
    //	string line;
    string usn, tmp;
    char* line_c= new char [100];
    int swi= 0, i= 0;
    bool check= false;
    
    while (!filein.eof ())
    {
        if (i!=0) fileout << endl;
        i++;
        filein.getline (line_c, 200);
        //		cout << line_c << endl;
        string line(line_c);
        //		cout << line << endl;
        swi= __Next_token (line, usn);
        if (usn!= username)
            fileout << usn << ',' << line;
        else
        {
            fileout << usn << ',';
            for (int i= 0; i< 4; i++)
            {
                swi= __Next_token (line, tmp);
                fileout << tmp << ',';
            }
            fileout << password << ',';
            swi= __Next_token (line, tmp);
            swi= __Next_token (line, tmp);
            fileout << tmp;
            check= true;
        }
    }
    filein.close ();
    fileout.close ();
    
    // File control
    system("mv user_out.txt user.txt")
    return check;
    delete []line_c;
}
*/
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
