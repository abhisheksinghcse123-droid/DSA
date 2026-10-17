#include<iostream>
using namespace std;
struct Node{
    int val;
    Node* next;
};
void insertatbeg(Node*& head,int val){
    Node* newnode=new Node();
    newnode->val=val;
    if(head==NULL){
        newnode->next=newnode;
        head=newnode;
        return;
    }
    auto temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    newnode->next=head;
    temp->next=newnode;
    head=newnode;
}
void insertatend(Node*& head,int val){
    Node* t=new Node();
    t->val=val;
    if(head==NULL){
        t->next=t;
        head=t;
        return ;
    }
    auto temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=t;
    t->next=head;
}
void insertatmiddle(Node*& head,int val,int idx){
    Node* t=new Node();
    t->val=val;
    if(head==NULL){
        t->next=t;
        head=t;
        return ;
    }
    auto temp=head;
    for(int i=1;i<idx-1;i++){
        temp=temp->next;
    }
    t->next=temp->next;
    temp->next=t;
}
void display(Node* head) {
    if (head == NULL) return;

    Node* temp = head;

    do {
        cout << temp->val << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

int main(){
    Node*a=new Node();
    Node*b=new Node();
    Node*c=new Node();
    Node*d=new Node();

    a->val=10;
    b->val=20;
    c->val=30;
    d->val=40;
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=a;
    insertatbeg(a,50);
    insertatend(a,100);
    insertatmiddle(a,200,3);
    display(a);
  return 0;
}