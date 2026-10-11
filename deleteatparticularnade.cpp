#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};
void deleteanynode(Node*& head){}
int main(){
    int n;
    cout<<"enter the no of node= ";
    cin>>n;
    Node* head=NULL;
    Node* tail=NULL;
    for(int i=1;i<=n;i++){
        int value;
        cout<<"value for node ="<<i<<" ";
        cin>>value;
        Node* newnode=new Node(value);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    Node* temp=head;
    while(temp!=NULL){
     cout<<temp->val<<" ";
     temp=temp->next;
    }
  return 0;
}