#include "course.h"

void _Next_token(string &s,string &target) {
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

void Course::Print(ofstream &fout)
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

void Course::Print_one_line(ofstream &fout)
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

Node_course::Node_course(Course x)
{
    data = x;
    next = NULL;
}

Course_list::~Course_list()
{
    while (head)
    {
        Node_course* p = head;
        head = head -> next;
        delete p;
    }
}

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

void Course_list::Add_a_course()
{
    Course x;
    x.Input();
    Add_tail(x);
}

void Course_list::Input_line_by_line(ifstream &fin) {
    string S, s;
    Course c;
    while (getline(fin,S)) {
        _Next_token(S,s);
        c.course_code = s;
        _Next_token(S,s);
        c.year = s;
        _Next_token(S,s);
        c.semester = int(s[0])-48;
        _Next_token(S,s);
        c.course_name = s;
        _Next_token(S,s);
        c.lecturer_name = s;
        _Next_token(S,s);
        Date_process(s,c.start_at);
        _Next_token(S,s);
        Date_process(s,c.end_at);
        _Next_token(S,s);
        Time_process(s,c.from);
        _Next_token(S,s);
        Time_process(s,c.to);
        c.date_of_week = S;
        Add_tail(c);
    }
}
void Course_list::Print_list(ofstream &fout)
{
    Node_course* p = head;
    while (p)
    {
        (p -> data).Print(fout);
        p = p -> next;
    }
}

void Course_list::Print_list_one_line(ofstream &fout)
{
    Node_course* p = head;
    while (p)
    {
        (p -> data).Print_one_line(fout);
        fout << '\n';
        p = p -> next;
    }
}

void Course_list::Make_empty()
{
    while (head)
    {
        Node_course* p = head;
        head = head -> next;
        delete p;

    }
}

void Course_list::Delete_a_course()
{
    string s;
    cin >> s;
    Delete_node(s);
}

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
