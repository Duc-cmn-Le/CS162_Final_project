//Bao
#include "user.h"

Linkedlist::Linkedlist()
{
    head=NULL;
}
Linkedlist::~Linkedlist()
{
    Node* tmp;
    while (head!=NULL)
    {
        tmp=head;
        head=head->Next;
        delete tmp;
    }
}
void Linkedlist::add_to_last(const User u)
{
    if (head==NULL) head=new Node({u,NULL});
    else
    {
        Node* cur=head;
        while (cur->Next!=NULL) cur=cur->Next;
        cur->Next=new Node({u,NULL});
    }
}
