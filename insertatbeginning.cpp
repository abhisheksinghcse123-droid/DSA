#include<iostream>
using namespace std;
    struct Node{
        int val;
        Node* next;
    };
    void display(Node* head){
        int sum=0;
        Node* temp=head;
        while(temp!=NULL){
            sum+=temp->val;
            cout<<temp->val<<" ";
            temp=temp->next;
        }cout<<endl;
        cout<<sum<<endl;
    }
    bool search(Node* head,int data){
        Node* temp=head;
        while (temp!=NULL){
            if(temp->val==data){
                return true;
            }
            temp=temp->next;
        }
        return false;
        
    }
    void atend(Node*& head,int val){
        Node* newnode=new Node();
        newnode->val=val;
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            return;
        }
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    void insertatbeginning(Node*& head,int val){
        Node* newnode=new Node();
        newnode->val=val;
        newnode->next=head;
        head=newnode;

    }
    int main(){
        Node* head=NULL;
        atend(head,10);
        atend(head,20);
        atend(head,30);
        display(head);
        insertatbeginning(head,5);
        display(head);
        if(search(head,5)) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
  return 0;
}