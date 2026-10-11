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
class Linkedlist{
    public:
    Node* head;
    Node* tail;
    int size;
    Linkedlist(){
        head=tail=NULL;
        size=0;
    }
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void inseratend(int val){
        Node* temp=new Node(val);
        if(size==0) head=tail=temp;
        else{
            tail->next=temp;
            tail=temp;
        }
        size++;
    }
    void insertatbegin(int val){
        Node* temp=new Node(val);
        if(size==0) head=tail=temp;
        else{
            temp->next=head;
            head=temp;
            size++;
        }
    }
    Node* reverselink(Node* head){
        Node* pre=NULL;
        Node* cur=head;
        while(cur!=NULL){
            Node* newnext=cur->next;
            cur->next=pre;
            pre=cur;
            cur=newnext;
        }
        return pre;
    }
    int minelement(Node* head){
        auto temp=head;
        int ans= head->val;
        if(head==NULL) return -1;
        while(temp!=NULL){
            ans=min(ans,temp->val);
            temp=temp->next;
        }
        return ans;
    }

};
int main(){
    Linkedlist ll;
    ll.inseratend(10);
    ll.inseratend(20);
    ll.inseratend(30);
    ll.inseratend(40);
    ll.display();
    ll.insertatbegin(50);
    ll.display();
    ll.head = ll.reverselink(ll.head);
    ll.display();
    cout<<ll.minelement(ll.head)<<endl;
    cout<<ll.size<<endl;
  return 0;
}