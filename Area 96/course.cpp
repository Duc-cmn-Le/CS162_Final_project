#include "course.h"

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

void Course::Print()
{
    cout << "Course Code: " << course_code << "\n";
    cout << "Year: " << year <<"\n";
    cout << "Semester: " << semester << "\n";
    cout << "Course Name: " << course_name << "\n";
    cout << "Lecturer Name: " << lecturer_name << "\n";
    cout << "Start at: " << start_at.d << "/" << start_at.m << "/" << start_at.y << "\n";
    cout << "End at: " << end_at.d << "/" << end_at.m << "/" << end_at.y << "\n";
    cout << "From: " << from.h << "h" << from.m << "'" << from.s << "''\n";
    cout << "To: " << to.h << "h" << to.m << "'" << to.s << "''\n";
    cout << "Dates of week: " << date_of_week << "\n";
}

void Course::Print_one_line()
{
    cout << course_code << ",";
    cout << year << ",";
    cout << semester << ",";
    cout << course_name << ",";
    cout << lecturer_name << ",";
    cout << start_at.d << "/" << start_at.m << "/" << start_at.y << ',';
    cout << end_at.d << "/" << end_at.m << "/" << end_at.y << ",";
    cout << from.h << "h" << from.m << "'" << from.s << "'',";
    cout << to.h << "h" << to.m << "'" << to.s << "'',";
    cout << date_of_week << "\n";
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

void Course_list::Print_list()
{
    Node_course* p = head;
    while (p)
    {
        (p -> data).Print();
        p = p -> next;
    }
}

void Course_list::Print_list_one_line()
{
    Node_course* p = head;
    while (p)
    {
        (p -> data).Print_one_line();
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

