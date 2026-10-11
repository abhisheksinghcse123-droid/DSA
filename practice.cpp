#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node*next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};
class linkedlist{
    public:
    Node* head;
    Node* tail;
    int size;
    linkedlist(){
        head=tail=NULL;
        size=0;
    }
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }cout<<endl;
    }
    void insertatend(int val){
        Node* temp=new Node(val);
        if(size==0){
            head=tail=temp;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
        size++;
    }
    void insertatbeg(int val){
        Node* temp=new Node(val);
        if(size==0) head=tail=temp;
        else {
            temp->next=head;
            head=temp;
        }
        size++;
    }
    void insertidx(int val,int idx){
        Node* newnode=new Node(val);
        if(idx<0 ||idx>size){
            cout<<"invalid"<<endl;
            return;
        }
        else if(idx==0) insertatbeg(val);
        else if(idx==size) insertatend(val);
        else{
            Node* t=new Node(val);
            Node* temp=head;
            for(int i=1;i<=idx-1;i++){
                temp=temp->next;
            }
                t->next=temp->next;
                temp->next=t;
                size++;
        }
    }
    void deleteathead(){
        if(size==0) cout<<"list is empty";
        if(size==1) head=tail=NULL;
        if(size>1) head=head->next;
        size--;
    }
    void deleteattail(){
        if(size==0) cout<<"list is empty";
        if(size==1) head=tail=NULL;
        if(size>1){
            Node* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=NULL;
            tail=temp;
        }
        size--;
    }
    void deleteatidx(int idx){
        if(size==0) cout<<"list is empty";
        if(size==1) head=tail=NULL;
        if(size>1){
            Node* temp=head;
            for(int i=1;i<=idx-1;i++){
                temp=temp->next;
            }
            temp->next=temp->next->next;    }
        size--;
    }
};
int main(){
    linkedlist ll;
    ll.insertatend(10);
    ll.insertatend(20);
    ll.insertatend(30);
    ll.insertatend(40);
    ll.display();
    ll.insertatbeg(50);
    ll.display();
    ll.insertidx(60,2);
    ll.display();
    ll.deleteathead();
    ll.display();
    ll.deleteattail();
    ll.display();
  return 0;
}