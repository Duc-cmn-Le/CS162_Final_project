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
    if (s.y < d.y && d.y < e.y) return 1;
    if (s.y == d.y && d.y != e.y) {
        if (s.m < d.m) return 1;
        if (s.m != d.m) return 0;
        if (s.d < d.d) return 1;
        if (s.d != d.d) return 0;
        return 1;
    }
    if (e.y == d.y && d.y != s.y) {
        if (d.m < e.m) return 1;
        if (d.m != e.m) return 0;
        if (d.d < e.d) return 1;
        if (d.d != e.d) return 0;
        return 1;
    }
    if (s.y == e.y && s.y == d.y) {
        if (s.m < d.m && d.m < e.m) return 1;
        if (s.m == d.m && d.m != e.m) {
            if (s.d < d.d) return 1;
            if (s.d != d.d) return 0;
            return 1;
        }
        if (e.m == d.m && d.m != s.m) {
            if (d.d < e.d) return 1;
            if (d.d != e.d) return 0;
            return 1;
        }
        if (s.m == e.m && d.m == e.m) {
            if (s.d <= d.d && d.d <= e.d) return 1;
            return 0;
        }
    }
    return 0;
}

int Check_in_time(Time d, Course c) {
    Time s = c.from, e = c.to;
    if (s.h < d.h && d.h < e.h) return 1;
    if (s.h == d.h && d.h != e.h) {
        if (s.m < d.m) return 1;
        if (s.m != d.m) return 0;
        if (s.s < d.s) return 1;
        if (s.s != d.s) return 0;
        return 1;
    }
    if (e.h == d.h && d.h != s.h) {
        if (d.m < e.m) return 1;
        if (d.m != e.m) return 0;
        if (d.s < e.s) return 1;
        if (d.s != e.s) return 0;
        return 1;
    }
    if (s.h == e.h && s.h == d.h) {
        if (s.m < d.m && d.m < e.m) return 1;
        if (s.m == d.m && d.m != e.m) {
            if (s.s < d.s) return 1;
            if (s.s != d.s) return 0;
            return 1;
        }
        if (e.m == d.m && d.m != s.m) {
            if (d.s < e.s) return 1;
            if (d.s != e.s) return 0;
            return 1;
        }
        if (s.m == e.m && d.m == e.m) {
            if (s.s <= d.s && d.s <= e.s) return 1;
            return 0;
        }
    }
    return 0;
}

int Student_management_service::Check_in(string username,string course_code,string year,int semester) {
    CSV_helper csv;
    Course c;
    string file_name = "course.txt";
    if (csv.Get_details(file_name,course_code,year,semester,c)) {
        Date d;
        Time t;
        string wday;
        Take_time(d,t,wday);
        return (wday == c.date_of_week)*(Check_in_date(d,c))*(Check_in_time(t,c));
    }
    return 0;
}
