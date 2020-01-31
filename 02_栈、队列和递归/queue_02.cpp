// - 用链表实现一个链式队列
#include <bits/stdc++.h>

using namespace std;
class LinkQueue{
    public:
        LinkQueue(){
            head=tail=nullptr;
        }
        ~LinkQueue(){
            while(head){
                Node* tmp=head;
                head=head->next;
                delete tmp;
            }
        }
        LinkQueue& EnQueue(int x){
            if(tail==nullptr){
                tail=new Node(x);
                head=tail;
            }else{
                tail->next=new Node(x);
                tail=tail->next;
            }
            cout<<"#EnQueue ";
            print();
            return *this;
        }
        LinkQueue& DeQueue(){
            if(head!=nullptr){
                Node* tmp=head;
                head=head->next;
                delete tmp;
                cout<<"#DeQueue ";
                print();
            }
            else{
                cout<<"error! Queue Empty!"<<endl;;
            }
            return *this;
        }
        LinkQueue& print(){
            Node* tmp=head;
            cout<<"Queue ";
            while(tmp){
                cout<<tmp->data<<" ";
                tmp=tmp->next;
            }
            cout<<endl;
            return *this;
        }
        int front(){
            if(head){
                return head->data;
            }else{
                cout<<"error! Queue empty"<<endl;
                return -1;
            }
        }
    private:
        struct Node{
            int data;
            Node *next;
            Node(int x){
                data=x;
                next=nullptr;
            }
        };
        Node* head;
        Node* tail;

};
int main(){
    LinkQueue lq;
    lq.EnQueue(1).EnQueue(2).EnQueue(3).EnQueue(4).EnQueue(5).EnQueue(6);
    lq.DeQueue().DeQueue().DeQueue().DeQueue().DeQueue().DeQueue().DeQueue();
    return 0;
}