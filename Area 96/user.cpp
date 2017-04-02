#include "user.h"

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
        if (ss == s) break;
        cout << "Password is not matched\n";
    }   
    cout << "Class? ";
    cin >> _class;
    type = 0;
}


void User::Print() {
    cout << "Username " << username << '\n';
    cout << "Full name " << full_name << '\n';
    cout << "Email " << email << '\n';
    cout << "Mobile phone " << mobile_phone << '\n';
    cout << "Class " << _class << '\n';
}




// Linked list of users

Linkedlist::Linkedlist()
{
    head=NULL;
}

void Linkedlist::Add_to_last(const User u)
{
    if (head==NULL) head=new Node({u,NULL});
    else
    {
        Node* cur=head;
        while (cur->next!=NULL) cur=cur->next;
        cur->next=new Node({u,NULL});
    }
}


void Linkedlist::Add_student_to_last() {
    User a;
    a.Input();
    Add_to_last(a);
}

void Linkedlist::Print_list() {
    Node *cur = head;
    while (cur != NULL) {
        cur->data.Print();
        cur = cur->next;
    }
}

Linkedlist::~Linkedlist()
{
    Node* tmp;
    while (head!=NULL)
    {
        tmp=head;
        head=head->next;
        delete tmp;
    }
}
