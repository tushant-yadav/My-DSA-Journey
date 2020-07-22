#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int d){
        data=d;
        next=NULL;
    }
};

void delete_athead(node *&head){
    node* temp=head;
    head=temp->next;
    delete temp;
    return;
}

void delete_attail(node *& head){
    node* temp=head;
    node *temp2=NULL;
    while(temp->next!=NULL){
        temp2=temp;
        temp=temp->next;
    }
    temp2->next=NULL;
    delete temp;
    return;
}

void insert_athead(node*& head ,int d){
    node *n= new node(d);
    n->next=head;
    head=n;
    return;
}

void insert_attail(node *&head,int data){
    node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next= new node(data);
    //head=temp;
    return ;
}

void print(node * head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    return;
}

//void operator>>(head)
void reverse_ll(node *&head){
    node* c=head;
    node* n=NULL;
    node* p=NULL;
    while(c!=NULL){
        n=c->next;
        c->next=p;
        p=c;
        c=n;
        n=NULL;
    }
    head=p;
    return;
}


node* find_mid(node* head){
    if(head==NULL || head->next== NULL) return head;
    node* x=head;
    node* xx=head;
    while(xx!=NULL || xx->next!= NULL){
        x=x->next;
        xx=xx->next;
        xx=xx->next;
        if(head==NULL || head->next== NULL) break;
    }
    return x;
}


int main() {
    node *head=NULL;
    insert_athead(head,1);
    insert_athead(head,2);
    insert_athead(head,11);
    insert_athead(head,22);
    insert_attail(head,3);
    insert_attail(head,33);
    insert_attail(head,4);
    node *x;
    //x=find_mid(head);
    //cout<<endl<<x->data;
    //reverse_ll(head);
    //delete_athead(head);
    //delete_attail(head);
    print(head);
    return 0;
}
