#include "course.h"

int _Next_token(string &s,string &target) 
{
    if (week == "9") week = "10";
    else if (week == "19") week = "20";
    else if (week.length() == 1) week[0]++;
    else week[1]++;
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

void Course_list::Input_line_by_line(istream &fin) {
    string S, s;
    Course c;
    while (getline(fin,S)) {
        _Next_token(S,s);
        c.course_code = s;
        _Next_token(S,s);
        c.year = s;
        _Next_token(S,s);
        c.semester = s;
        _Next_token(S,s);
        c.course_name = s;
        _Next_token(S,s);
        c.lecturer_name = s;
        // Xu li date
        // 
        // Xu li time
        //
        c.date_of_week = S;
    }
}
void Course_list::Print_list(ostream &fout)
{
    Node_course* p = head;
    while (p)
    {
        (p -> data).Print(fout);
        p = p -> next;
    }
}

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

