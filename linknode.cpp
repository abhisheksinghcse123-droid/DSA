#include<iostream>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};
int main(){
    int n;
    cout<<"enter the no of node= ";
    cin>>n;
    Node* head=NULL;
    Node* tail=NULL;
    for(int i=1;i<=n;i++){
        int value;
        cout<<"enter the value for node ="<<i<<" ";
        cin>>value;
        Node* newNode= new Node(value);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    Node* temp=head;// traverse
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
  return 0;
}