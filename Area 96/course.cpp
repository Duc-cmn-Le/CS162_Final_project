#include "course.h"

void _Next__token(string &s,string &target) {
    target = "";
    int cnt = 0;
    for (string::iterator i=s.begin();i!=s.end();++i,cnt++)
        if (*i == ',') {
            target.insert(target.begin(),s.begin(),i);
            s.erase(0,cnt+1);
            return;
        }
    target = s;
}

// Check Leap year - Mai Trinh

bool LeapYear(int y)
{
    if (y% 400 == 0 || (y%100 != 0 && y%4 == 0))
        return true;
    return false;
}

// nth date

int nth(int d, int m, int y)
{
    switch(m)
    {
        case 1: return d; break;
        case 2: return 31+d; break;
        case 3: return 59+LeapYear(y)+d; break;
        case 4: return 90+LeapYear(y)+d; break;
        case 5: return 120+LeapYear(y)+d; break;
        case 6: return 151+LeapYear(y)+d; break;
        case 7: return 181+LeapYear(y)+d; break;
        case 8: return 212+LeapYear(y)+d; break;
        case 9: return 243+LeapYear(y)+d; break;
        case 10: return 273+LeapYear(y)+d; break;
        case 11: return 304+LeapYear(y)+d; break;
        case 12: return 334+LeapYear(y)+d; break;
    }
    return 0;
}

// Date token - Mai Trinh

void _Date_token(string &s,string &target) {
    target = "";
    int cnt = 0;
    for (string::iterator i=s.begin();i!=s.end();++i,cnt++)
        if (*i == '/') {
            target.insert(target.begin(),s.begin(),i);
            s.erase(0,cnt+1);
            return;
        }
    target = s;
}

// Date process - Mai Trinh

void Date_process(string &S, Date &d)
{
    string s;
    int date;
    _Date_token(S,s);
    date = 0;
    for (string::iterator i=s.begin();i!=s.end();++i)
        date = date*10 + int(char(*i)) - 48;
    d.d = date;
    _Date_token(S,s);
    date = 0;
    for (string::iterator i=s.begin();i!=s.end();++i)
        date = date*10 + int(char(*i)) - 48;
    d.m = date;
    date = 0;
    for (string::iterator i=S.begin();i!=S.end();++i)
        date = date*10 + int(char(*i)) - 48;
    d.y = date;
}

// Time token - Mai Trinh

void _Time_token(string &s,string &target) {
    target = "";
    int cnt = 0;
    string n = "'";
    for (string::iterator i=s.begin();i!=s.end();++i,cnt++)
        if (*i == 'h' || *i == *(n.begin())) {
            target.insert(target.begin(),s.begin(),i);
            s.erase(0,cnt+1);
            return;
        }
    target = s;
}

// Time process - Mai Trinh

void Time_process(string &S, Time &t)
{
    string s;
    int time;
    _Time_token(S,s);
    time = 0;
    for (string::iterator i=s.begin();i!=s.end();++i)
        time = time*10 + int(char(*i)) - 48;
    t.h = time;
    _Time_token(S,s);
    time = 0;
    for (string::iterator i=s.begin();i!=s.end();++i)
        time = time*10 + int(char(*i)) - 48;
    t.m = time;
    time = 0;
    S.erase(S.length()-2,S.length()-1);
    for (string::iterator i=S.begin();i!=S.end();++i)
        time = time*10 + int(char(*i)) - 48;
    t.s = time;
}

// Mai Trinh

void Course::Input()
{
    cout << "Course Code?\n";
    cin >> course_code;
    cout << "Year?\n";
    cin >> year;
    cout << "Semester?\n";
    cin >> semester;
    cin.ignore();
    cout << "Course Name?\n";
    getline(cin,course_name);
    cout << "Leturer Username?\n";
    getline(cin,lecturer_name);
    cout << "Start at? Should be entered as dd/mm/yyyy\n";
    char c;
    cin >> start_at.d >> c >> start_at.m >> c >> start_at.y;
    cout << "End at? Should be entered as dd/mm/yyyy\n";
    cin >> end_at.d >> c >> end_at.m >> c >> end_at.y;
    cout << "From? Should be entered as hh:mm:ss\n";
    cin >> from.h >> c >> from.m >> c >> from.s;
    cout << "To? Should be entered as hh:mm:ss\n";
    cin >> to.h >> c >> to.m >> c >> to.s;
    cout << "Date of week? Eg: monday, tuesday, ...\n";
    cin >> date_of_week;
}

// Mai Trinh

void Course::Print(ostream &fout)
{
    fout << "Course Code: " << course_code << "\n";
    fout << "Year: " << year <<"\n";
    fout << "Semester: " << semester << "\n";
    fout << "Course Name: " << course_name << "\n";
    fout << "Lecturer Name: " << lecturer_name << "\n";
    fout << "Start at: " << start_at.d << "/" << start_at.m << "/" << start_at.y << "\n";
    fout << "End at: " << end_at.d << "/" << end_at.m << "/" << end_at.y << "\n";
    fout << "From: " << from.h << "h" << from.m << "'" << from.s << "''\n";
    fout << "To: " << to.h << "h" << to.m << "'" << to.s << "''\n";
    fout << "Dates of week: " << date_of_week << "\n";
}

// Mai Trinh

void Course::Print_one_line(ostream &fout)
{
    fout << course_code << ",";
    fout << year << ",";
    fout << semester << ",";
    fout << course_name << ",";
    fout << lecturer_name << ",";
    fout << start_at.d << "/" << start_at.m << "/" << start_at.y << ',';
    fout << end_at.d << "/" << end_at.m << "/" << end_at.y << ",";
    fout << from.h << "h" << from.m << "'" << from.s << "'',";
    fout << to.h << "h" << to.m << "'" << to.s << "'',";
    fout << date_of_week;
}

// Mai Trinh

int Course::Count_week()
{
    int cnt = 0;
    if (start_at.y == end_at.y)
        return (-nth(start_at.d,start_at.m,start_at.y) + nth(end_at.d,end_at.m,end_at.y)+7)/7;
    else {
        for (int i = start_at.y+1; i <= end_at.y-1; ++i)
            cnt += nth(31,12,i);
    }
    cnt = cnt + nth(31,12,start_at.y) - nth(start_at.d,start_at.m,start_at.y) + 7 + nth(end_at.d,end_at.m,end_at.y);
    return cnt/7;
}


// = = = = = = = = = = = = =
// Course list
// = = = = = = = = = = = = =

Node_course::Node_course(Course x)
{
    data = x;
    next = NULL;
}

// Mai Trinh

Course_list::~Course_list()
{
    while (head)
    {
        Node_course* p = head;
        head = head -> next;
        delete p;
    }
}

// Add a node to list - Mai Trinh

void Course_list::Add_tail(Course x)
{
    if (!head)
    {
        head = new Node_course(x);
        return;
    }
    Node_course* p = head;
    while (p && p -> next)
        p = p -> next;
    p -> next = new Node_course(x);
}

// Add a course - Mai Trinh

void Course_list::Add_a_course()
{
    Course x;
    x.Input();
    Add_tail(x);
}

// Input course line by line - Mai Trinh

void Course_list::Input_line_by_line(istream &fin) {
    string S, s;
    Course c;
    getline(fin,S);
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
        Add_tail(c);
    }
}

// Print list - Mai Trinh

void Course_list::Print_list(ostream &fout)
{
    Node_course* p = head;
    while (p)
    {
        (p -> data).Print(fout);
        fout << " - - \n";
        p = p -> next;
    }
}

// Print list line by line - Mai Trinh

void Course_list::Print_list_one_line(ostream &fout)
{
    Node_course* p = head;
    while (p)
    {
        (p -> data).Print_one_line(fout);
        fout << '\n';
        p = p -> next;
    }
}

// Make list empty - Mai Trinh

void Course_list::Make_empty()
{
    while (head)
    {
        Node_course* p = head;
        head = head -> next;
        delete p;

    }
}

// Delete a course - Mai Trinh

void Course_list::Delete_a_course()
{
    string s;
    cin >> s;
    Delete_node(s);
}

// Delete a node in list - Mai Trinh

void Course_list::Delete_node(string s)
{
    if ((head -> data).course_code == s)
        head = head -> next;
    else
    {
        Node_course* p = head;
        while (p && p -> next)
        {
            if ((p -> next -> data).course_code == s)
            {
                Node_course* tmp = p -> next;
                p -> next = tmp -> next;
                delete tmp;
                return;
            }
        }
    }
}

