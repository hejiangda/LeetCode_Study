//## 链表
//+ 实现两个有序的链表合并为一个有序链表

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};


int main(){
    Node * l1,*l2;
    l1=new Node;
    l1->data=1;
    Node* tmp;
    tmp=l1;
    for(int i=3;i<10;i+=2){
        tmp->next=new Node;
        tmp=tmp->next;
        tmp->data=i;
        tmp->next=nullptr;
    }
    
    l2=new Node;
    l2->data=0;
    tmp=l2;
    for(int i=2;i<10;i+=2){
        tmp->next=new Node;
        tmp=tmp->next;
        tmp->data=i;
        tmp->next=nullptr;
    }
    tmp=l1;
    cout<<"l1:";
    while(tmp){
        cout<<" "<<tmp->data;
        tmp=tmp->next;
    }
    cout<<endl;
    tmp=l2;
    cout<<"l2:";
    while(tmp){
        cout<<" "<<tmp->data;
        tmp=tmp->next;
    }
    cout<<endl;

    Node* p1,*p2;
    p1=l1;
    p2=l2;

    Node* list;
    list=new Node;
    list->next=nullptr;
    tmp=list;
    while(p1!=nullptr&&p2!=nullptr){
        if(p1->data<p2->data){
            tmp->next=p1;
            p1=p1->next;
        }else{
            tmp->next=p2;
            p2=p2->next;
        }
        tmp=tmp->next;
    }
    if(p1){
        tmp->next=p1;
    }else tmp->next=p2;
    
    tmp=list->next;
    cout<<"list:";
    while(tmp){
        cout<<" "<<tmp->data;
        tmp=tmp->next;
    }



    return 0;
}