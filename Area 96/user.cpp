#include "user.h"

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

// CLASS USER

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
        if (ss == s) {password = s; break;}
        cout << "Password is not matched\n";
    }   
    cout << "Class? ";
    cin >> _class;
    type = 0;
}


void User::Print() {
    int _width = 20;
    cout << "Username: " << setw(_width+4) << username << '\n';
    cout << "Full name: " << setw(_width+3) << full_name << '\n';
    cout << "Email: " << setw(_width+7) << email << '\n';
    cout << "Mobile phone: " << setw(_width) << mobile_phone << '\n';
    cout << "Class: " << setw(_width+7) << _class << '\n';
}

void User::Print_one_line() {
    cout << username << ',';
    cout << full_name << ',';
    cout << email << ',';
    cout << mobile_phone << ',';
    cout << type << ',';
    cout << password << ',';
    cout << _class;
}



// Linked list of users

Student_list::Student_list()
{
    head=NULL;
}

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


void Student_list::Add_student_to_last() {
    User a;
    a.Input();
    Add_to_last(a);
}

void Student_list::List_all_student() {
    freopen("user.txt","r",stdin);
    string S, s;
    User t;
    while (getline(cin,S)) {
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

void Student_list::Delete_node(string student_id) {
    if (head->data.username == student_id) head = head->next;
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

void Student_list::Print_list() {
    Node *cur = head;
    while (cur != NULL) {
        cur->data.Print();
        cur = cur->next;
    }
}

void Student_list::Print_list_one_line() {
    Node *cur  = head;
    while (cur != NULL) {
        cur->data.Print_one_line();
        cout << '\n';
        cur = cur->next;
    }
}

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
