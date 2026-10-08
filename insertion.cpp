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
class Linkedlist{
    public:
    Node* head;
    Node* tail;
    int size=0;
    Linkedlist(){
        head=tail=NULL;
        size=0;
    }
    void insertAtend(int val){
        Node* temp=new Node(val);
        if(size==0) head=tail=temp;
        else{
            tail->next=temp;
            tail=temp;
        }
        size++;
    }
    void insertAtbeginning(int val){
        Node* temp=new Node(val);
        if(size==0)
         head=tail=temp;
        else{
            temp->next=head;
            head=temp;
        }
        size++;
    }
    bool search(int val){
        Node* temp=head;
        while(temp!=NULL){
            if(temp->val==val){
                return true;
            }
            temp=temp->next;
        }
        return false;
        
    }
    void insertatidx(int idx,int val){
        if(idx<0||idx>size) cout<<"invalid index"<<endl;
        else if(idx==0) insertAtbeginning(val);
        else if(idx==size) insertAtend(val);
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
    int getelementatidx(int idx){
        if(idx<0||idx>=size){
            cout<<"invaled"<<endl;
            return -1;
        }
        else if(idx==0) return head->val;
        else if(idx=size-1) return tail->val;
        else{
            Node* temp=head;
            for(int i=1;i<=size;i++){
                temp=temp->next;
            }
            return temp->val;
        }
    }
    void deleteAthead(){
        if(size==0) return;
        head=head->next;
        size--;
    }
    void deleteAttail(){
        if(size==0) return;
        Node* temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=NULL;
        tail=temp;
        size--;
    }
    void deleteAtidx(int idx){
        if(idx<0||idx>=size) return;
        else if(idx==0) return deleteAthead();
        else if(idx==size-1) return deleteAttail();
        else{
            Node* temp=head;
            for(int i=1;i<=idx-1;i++){
                temp=temp->next;
            }
            temp->next=temp->next->next;
            size--;
        }
    }
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }cout<<endl;

    }

};
int main(){
    Linkedlist ll;
    ll.insertAtend(10);
    ll.insertAtend(20);
    ll.display();
    ll.insertAtbeginning(30);
    ll.display();
    ll.insertAtbeginning(40);
    ll.display();
    ll.insertatidx(2,80);
    ll.display();
    cout<<ll.getelementatidx(0)<<endl;
    //ll.display();
    ll.deleteAthead();
    ll.display();
    ll.deleteAttail();
    ll.display();
    ll.deleteAtidx(2);
    ll.display();
   cout<<ll.size<<endl;
   if(ll.search(40))cout<<"Yes"<<endl;
   else cout<<"No"<<endl;
    return 0;
}