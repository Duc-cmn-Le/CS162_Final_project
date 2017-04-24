#include "user.h"

// Cong Duc

int _Next_token(string &s,string &target) {
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

// =============
// CLASS USER
// =============

// Cong Duc
void User::Input() {
    cout << "Student ID? ";
    cin >> username;
    cout << "Full name? ";
    cin.ignore();
    getline(cin,full_name);
    cout << "Email? ";
    cin >> email;
    cout << "Mobile phone? ";
    cin >> mobile_phone;
    cout << "Password ";
    string s, ss;
    cin >> s;
    cout << "Confirm your password ";
    while (cin >> ss) {
        if (ss == s) {
            Md5 md5;
            md5.pass = s;
            password = md5.Process(); 
            break;
        }
        cout << "Password is not matched\n";
    }   
    cout << "Class? ";
    cin >> _class;
    type = 0;
}

// Cong Duc

void User::Print(ostream &fout) {
    int _width = 20;
    fout << "Username: " << setw(_width+4) << username << '\n';
    fout << "Full name: " << setw(_width+3) << full_name << '\n';
    fout << "Email: " << setw(_width+7) << email << '\n';
    fout << "Mobile phone: " << setw(_width) << mobile_phone << '\n';
    fout << "Class: " << setw(_width+7) << _class << '\n';
}

// Cong Duc

void User::Print_one_line(ostream &fout) {
    fout << username << ',';
    fout << full_name << ',';
    fout << email << ',';
    fout << mobile_phone << ',';
    fout << type << ',';
    fout << password << ',';
    fout << _class;
}


//=========================
/// Linked list of users
//=========================

Student_list::Student_list()
{
    head=NULL;
}

// Get detail of a student in database - Cong Duc

int Student_list::Get_details(string file_type,string username,User &res) {
    ifstream fin(file_type.c_str());
    string S, s;
    while (getline(fin,S)) {
        _Next_token(S,s);
        if (s != username) continue;
        res.username = s;
        _Next_token(S,s);
        res.full_name = s;
        _Next_token(S,s);
        res.email = s;
        _Next_token(S,s);
        res.mobile_phone = s;
        _Next_token(S,s);
        res.type  = s[0]-'0';
        _Next_token(S,s);
        res._class = S; 
        return true;
    }
    return false;
}

// Add a node to last - Cong Duc

void Student_list::Add_to_last(const User u)
{
    if (head==NULL) head=new Node({u,NULL});
    else
    {
        Node* cur=head;
        while (cur->next!=NULL) cur=cur->next;
        cur->next=new Node({u,NULL});
    }
}

// Add student to last of list - Cong Duc

void Student_list::Add_student_to_last() {
    User a;
    a.Input();
    Add_to_last(a);
}

// Create a list of all students in system - Cong Duc

void Student_list::List_all_student() {
    ifstream fin("user.txt");
    string S, s;
    User t;
    while (getline(fin,S)) {
        _Next_token(S,s);
        t.username = s;
        _Next_token(S,s);
        t.full_name = s;
        _Next_token(S,s);
        t.email = s;
        _Next_token(S,s);
        t.mobile_phone = s;
        _Next_token(S,s);
        t.type  = s[0]-'0';
        _Next_token(S,s);
        t._class = S;
        Add_to_last(t);
    }
}

// Create a list of all students in a class - Cong Duc

void Student_list::List_all_student_of_class(string class_name,string &all_student_id) 
{
    all_student_id = "";
    ifstream fin("user.txt");
    string S, s;
    User t;
    int cnt = 0;
    while (getline(fin,S)) {
        _Next_token(S,s);
        t.username = s;
        _Next_token(S,s);
        t.full_name = s;
        _Next_token(S,s);
        t.email = s;
        _Next_token(S,s);
        t.mobile_phone = s;
        _Next_token(S,s);
        t.type  = s[0]-'0';
        _Next_token(S,s);
        t._class = S;
        if (t._class != class_name) continue;
        if (cnt) all_student_id += ',';
        all_student_id += t.username;
        Add_to_last(t);
        cnt++;
    }
}

// Create list of all students of a course - Cong Duc

void Student_list::List_all_student_of_course(string course_name,string year,int semester)
{
    ifstream fin("course_student.txt");
    string S, s;
    User t;
    while (getline(fin,S)) {
        _Next_token(S,s);
        if (s != course_name) continue;
        _Next_token(S,s);
        if (s != year) continue;
        _Next_token(S,s);
        if (s[0]-'0' != semester) continue;
        while (_Next_token(S,s)) {
            Get_details("user.txt",s,t);
            Add_to_last(t);
        }
        Get_details("user.txt",S,t);
        Add_to_last(t);
    }
}

// Delete a node in list - Cong Duc

void Student_list::Delete_node(string student_id) {
    if (head == NULL) return;
    if (head->data.username == student_id) 
    {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }
    else {
        Node *cur = head;
        while (cur->next != NULL && cur->next->data.username != student_id)
            cur = cur->next;
        if (cur->next != NULL && cur->next->data.username ==student_id) {
            Node *next = cur->next->next;
            delete cur->next;
            cur->next = next;
        }
    }
}

// Input line by line - Cong Duc
void Student_list::Input_line_by_line(istream &fin) 
{
    string S, s;
    User u;
    while (getline(fin,S)) {
        _Next_token(S,s); 
        u.username = s;
        if (u.username[0] < '0' || u.username[0] > '9') continue;
        _Next_token(S,s);
        u.full_name = s;
        _Next_token(S,s);
        u.email = s;
        _Next_token(S,s);
        u.mobile_phone = s;
        u.type = 0;
        Md5 md5;
        md5.pass = u.username;
        u.password = md5.Process();
        u._class = S; 
        Add_to_last(u);
    }
}

// Print list - Cong Duc

void Student_list::Print_list(ostream &fout) {
    Node *cur = head;
    while (cur != NULL) {
        cur->data.Print(fout);
        cout << " - -\n";
        cur = cur->next;
    }
}

// Print list line by line - Cong Duc

void Student_list::Print_list_one_line(ostream &fout) {
    Node *cur  = head;
    while (cur != NULL) {
        cur->data.Print_one_line(fout);
        fout << '\n';
        cur = cur->next;
    }
}

// Make list empty - Cong Duc

void Student_list::Make_empty() {
    Node *cur, *next;
    cur = head;
    while (cur != NULL) {
        next = cur->next;
        delete cur;
        cur = next;
    }
    head = NULL;
}

// Check empty list - Cong Duc

int Student_list::Is_empty() {
    return head == NULL;
}

// Destructor - Cong Duc

Student_list::~Student_list()
{
    Node* tmp;
    while (head!=NULL)
    {
        tmp=head;
        head=head->next;
        delete tmp;
    }
}
