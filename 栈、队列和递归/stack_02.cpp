//- 用链表实现一个链式栈
#include <bits/stdc++.h>

using namespace std;
class LinkStack{
    public:
    LinkStack(){
        StackTop=nullptr;
    }
    ~LinkStack(){
        while(StackTop){
            Node* tmp=StackTop->next;
            delete StackTop;
            StackTop=tmp;
        }
    }
    LinkStack& push(int x){
        Node* tmp=new Node(x);
        tmp->next=StackTop;
        StackTop=tmp;
        return *this;
    }
    int pop(){
        if(StackTop){
            int data=StackTop->data;
            StackTop=StackTop->next;
            return data;
        }
        cout<<"error! stack empty!"<<endl;
        return -1;
    }
    int top(){
        if(StackTop){
            return StackTop->data;
        }
        cout<<"error! stack empty!"<<endl;
        return -1;
    }
    void print(){
        cout<<"LinkStack:";
        Node * p=StackTop;
        reversePrint(p);
        cout<<endl;
    }
    bool isEmpty(){
        if(StackTop)
            return false;
        else return true;
    }
    private:
        struct Node{
            int data;
            Node* next;
            Node(int x){
                data=x;
                next=nullptr;
            }
        };
        Node* StackTop;
        void reversePrint(Node * p){
            if(p){
                reversePrint(p->next);
                cout<<p->data<<" ";
            }
        }
};

int main(){
    LinkStack ls;
    ls.push(1).push(2).push(3).push(4).push(5).push(6).print();
    cout<<"Pop sequence:";
    while(!ls.isEmpty()){
        cout<<ls.pop()<<" ";
    }
    cout<<endl;
    return 0;
}