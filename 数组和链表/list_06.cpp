//## 链表
//- 实现求链表的中间结点

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

int main(){
    Node* list=new Node;
    Node * p=list;
    for(int i=1;i<10;i++){
        p->next=new Node;
        p=p->next;
        p->data=i;
    }
    p->next=nullptr;

    p=list->next;
    cout<<"list:";
    while(p){
        cout<<" "<<p->data;
        p=p->next;
    }
    cout<<endl;
    int cnt=0;
    p=list->next;
    while(p){
        cnt++;
        p=p->next;
    }
    cout<<"length:"<<cnt<<endl;
    p=list->next;
    for(int i=0;i<cnt/2;i++){
        p=p->next;
    }
    cout<<"mid:"<<p->data<<endl;

    return 0;
}