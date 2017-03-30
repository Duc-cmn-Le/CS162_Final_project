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
        head=head->next;
        delete tmp;
    }
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
