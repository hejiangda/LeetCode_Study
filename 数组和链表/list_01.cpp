//## 链表
//+ 实现单链表、循环链表、双向链表，支持增删操作
// 单链表

#include <iostream>

using namespace std;

class singleList{
    public:
        int size()
        {
            return head.data;
        }
        void insert(int x,int pos){
            if(pos<0||pos>head.data)
            {
                cout<<"error! pos out of range"<<endl;
            }
            else{
                Node* tmp=&head;
                for(int i=0;i<pos;i++){
                    tmp=tmp->next;
                }    
                tmp->next=new Node(x,tmp->next);
                head.data++;
            }
        }
        void insert(int x){
            Node* tmp=&head;
            while(tmp->next!=nullptr){
                tmp=tmp->next;
            }
            tmp->next=new Node(x);
            head.data++;
        }
        void del(int pos){
             if(pos<0||pos>=head.data)
            {
                cout<<"error! pos out of range"<<endl;
            }
            else{
                Node* tmp=&head;
                for(int i=0;i<pos;i++)
                    tmp=tmp->next;
                Node* t=tmp->next;
                tmp->next=tmp->next->next;
                delete t;
            }
        }
        void del(){
            Node* tmp=&head;
            for(int i=0;i<head.data;i++){
                tmp=tmp->next;
            }
            Node* t=tmp->next;
            tmp->next=tmp->next->next;
            delete t;
        }
        void print(){
            Node* tmp=head.next;
            int count=0;
            while(tmp){
                cout<<"["<<count++<<"]="<<tmp->data<<endl;
                tmp=tmp->next;
            }
            cout<<"print finished"<<endl;
        }
    private:
        struct Node{
            int data;
            Node* next;
            Node()
            {
                data=0;
                next=nullptr;
            }
            Node(int x)
            {
                data=x;
                next=nullptr;
            }
            Node(int x,Node* n){
                data=x;
                next=n;
            }
        };
        Node head;    
};

int main()
{
    singleList a;
    a.insert(4);
    a.insert(5);
    a.insert(3);
    a.insert(2,0);
    a.del(2);
    a.print();
    return 0;
}