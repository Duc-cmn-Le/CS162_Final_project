#include "SMS.h"

void Next_token_(string &s,string &target) {
    target = "";
    int cnt = 0;
    for (string::iterator i=s.begin();i!=s.end();++i,cnt++)
        if (*i == ' ') {
            target.insert(target.begin(),s.begin(),i);
            s.erase(0,cnt+1);
            return;
        }
    target = s;
}

void Take_time(Date &d, Time &t, string &wday) {
    time_t tme;
    time(&tme);
    tm *cur;
    cur = localtime(&tme);
    string S = asctime(cur);
    string s;
    Next_token_(S,s);
    switch (s[2]) {
    case 'n':
        if (s[1] == 'u') wday = "Sunday";
        else wday = "Monday";
        break;
    case 'e':
        wday = "Tuesday";
        break;
    case 'd':
        wday = "Wednesday";
        break;
    case 'u':
        wday = "Thursday";
        break;
    case 'i':
        wday = "Friday";
        break;
    case 't':
        wday = "Saturday";
    }
    Next_token_(S,s);
    switch (s[2]) {
    case 'r':
        if (s[1] == 'a') d.m = 3;
        else d.m = 4;
        break;
    case 'n':
        if (s[1] == 'a') d.m = 1;
        else d.m = 6;
        break;
    case 'b':
        d.m = 2;
        break;
    case 'y':
        d.m = 5;
        break;
    case 'l':
        d.m = 7;
        break;
    case 'g':
        d.m = 8;
        break;
    case 'p':
        d.m = 9;
        break;
    case 't':
        d.m = 10;
        break;
    case 'v':
        d.m = 11;
        break;
    case 'c':
        d.m = 12;
        break;
    }
    Next_token_(S,s);
    d.d = (int(s[0])-48)*10 + s[1] - 48;
    Next_token_(S,s);
    t.h = (int(s[0])-48)*10 + s[1] - 48;
    t.m = (int(s[3])-48)*10 + s[4] - 48;
    t.s = (int(s[6])-48)*10 + s[7] - 48;
    Next_token_(S,s);
    d.y = 0;
    S.erase(S.length()-1,S.length()-1);
    for (string::iterator i=S.begin();i!=S.end();++i)
        d.y = d.y*10 + int(char(*i)) - 48;
}

int Check_in_date(Date d, Course c) {
    Date s = c.start_at, e = c.end_at;
    if (s.y < d.y && d.y < e.y) {
        return 1;
    }
    else if (s.y == d.y) {
        if (s.m < d.m) return 1;
        else if (s.m == d.m) {
            if (s.d <= d.d) return 1;
            else return 0;
        }
        else return 0;
    }
    else if (e.y == d.y) {
        if (e.m > d.m) return 1;
        else if (e.m == d.m) {
            if (e.d >= d.d) return 1;
            else return 0;
        }
        else return 0;
    }
    return 0;
}

int Check_in_time(Time t, Course c) {
    Time s = c.from, e = c.to;
    if (s.h < t.h && t.h < e.h) {
        return 1;
    }
    else if (s.h == t.h) {
        if (s.m < t.m) return 1;
        else if (s.m == t.m) {
            if (s.s <= t.s) return 1;
            else return 0;
        }
        else return 0;
    }
    else if (e.h == t.h) {
        if (e.m > t.m) return 1;
        else if (e.m == t.m) {
            if (e.s >= t.s) return 1;
            else return 0;
        }
        else return 0;
    }
    return 0;
}
int Student_management_service::Check_in(string username,string course_code,string year,int semester)
{
    CSV_helper csv;
    Course c;
    string file_name = "course.txt";
    if (csv.Get_details(file_name,course_code,year,semester,c)) {
        Date d;
        Time t;
        string wday;
        Take_time(d,t,wday);
        if (wday != c.date_of_week) return 0;
        if (!(Check_in_time(t,c))) return 0;
        if (!(Check_in_date(d,c))) return 0;
        return 1;
    }
    return 0;
}
