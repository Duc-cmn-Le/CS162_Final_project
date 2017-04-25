#include "score.h"

// CLASS

void Score::Input() {
    cout << "Course code:\n ";
    cin >> course_code;
    cout << "Year:\n ";
    cin >> year;
    cout << "Semester:\n ";
    cin >>  semester;
    cin.ignore();
    cout << "Student ID:\n ";
    cin >> student_id;
    cout << "Type (midterm - 0, lab - 1, final 2)\n ";
    cin >> type;
    cout << "Mark:\n ";
    cin >> mark;
}

void Score::Print(ostream &fout) {
    int _width = 20;
    fout << "Course code: " << setw(_width+2) << course_code << '\n';
    fout << "Year: " << setw(_width+9) << year<< '\n';
    fout << "Semester: " << setw(_width+5) << semester << '\n';
    fout << "Student ID: " << setw(_width+3) << student_id << '\n';
    if (type == 0) cout << "Midterm\n";
    if (type == 1) cout << "Lab\n";
    if (type == 2) cout << "Final\n";
    fout << "Mark: " << setw(_width+9) << mark << '\n';
}

void Score::Print_one_line(ostream &fout) {
    fout << course_code << ',';
    fout << year << ',';
    fout << semester << ',';
    fout << student_id << ',';
    fout << type << ',';
    fout << mark;
}

void Score::Print_one_line_(ostream &fout) {
    fout << course_code << ',';
    fout << year << ',';
    fout << semester << ',';
    fout << student_id << ',';
    if (type == 0) fout << "Midterm,";
    else if (type == 1) fout << "Lab,";
    else fout << "Final,";
    fout << mark;
}

// Linked list of score

Score_list::Score_list()
{
    head = NULL;
}

void Score_list::Add_to_last(const Score s)
{
    if (head == NULL) head = new Node_score({s,NULL});
    else
    {
        Node_score *cur = head;
        while (cur->next != NULL)
            cur = cur->next;
        cur->next = new Node_score({s,NULL});
    }
}

void Score_list::Add_score_to_last()
{
    Score s;
    s.Input();
    Add_to_last(s);
}

int Score_list::Find_student(string student_id) 
{
    Node_score *cur = head;
    while (cur != NULL) {
        if (cur->data.student_id == student_id) return true;
        cur = cur->next;
    }
    return false;
}

void Score_list::Print_list(ostream &fout)
{
    Node_score *cur = head;
        while (cur != NULL) {
            cur->data.Print(fout);
            fout << " - - \n";
            cur = cur->next;
        }
}

void Score_list::Print_list_one_line(ostream &fout)
{
    Node_score *cur = head;
    while (cur != NULL) {
        cur->data.Print_one_line(fout);
        fout << '\n';
        cur = cur->next;
    }
}

void Score_list::Print_list_one_line_(ostream &fout)
{
    fout << "Course code,Year,Semester,Student ID,Exam,Mark\n";
    Node_score *cur = head;
    while (cur != NULL) {
        cur->data.Print_one_line_(fout);
        fout << '\n';
        cur = cur->next;
    }
}
Score_list::~Score_list()
{
    Node_score *tmp;
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        delete tmp;
    }
}
