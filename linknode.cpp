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
void deleteat(Node*& head,int idx){
    Node* temp=head;
    for(int i=1;i<=idx-1;i++){
        temp=temp->next;
    }
    temp->next=temp->next->next;
    
}
int fromend(Node*& head,int n){
    int size=0;
    Node* temp=head;
    while(temp!=NULL){
        size++;
        temp=temp->next;
    }
    if(n<1||n>size){
        return -1;
    }
    temp=head;
    for(int i=1;i<size-(n-1);i++){
        temp=temp->next;
    }
    return temp->val;
}
bool hascycle(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
          return true;
    }
}
    return false;
}
Node* reverselist(Node* head){
    Node* prev=NULL;
    Node* cur=head;
    while(cur!=NULL){
        Node* nextNode=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nextNode;
    }
    return prev;
}
Node* middlenode(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
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
    Node* middle=middlenode(head);
    cout<<middle->val<<endl;
    //head= reverselist(head);

    //deleteat(head,2);
    int size=0;
    Node* temp=head;// traverse
    while(temp!=NULL){
        size++;
        cout<<temp->val<<" ";
        temp=temp->next;
    }cout<<endl;
    cout<<size<<endl;
    cout<<fromend(head,3)<<endl;
    if(hascycle(head)) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
  return 0;
}