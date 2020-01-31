//## 链表
//+ 实现单链表、循环链表、双向链表，支持增删操作
// 循环链表

#include <iostream>

using namespace std;

class loopList{
    public:
        
        void insert(int x){
            if(head.data==0){
                head.next=new Node(x,nullptr);
                head.next->next=head.next;
            } 
            else{
                Node* tmp=head.next;
                while(tmp->next!=head.next){
                    tmp=tmp->next;
                }
                tmp->next=new Node(x,head.next);
            }   
            head.data++;
        }
        void del(){
            if(head.data>0){
                Node* tmp=&head;
                for(int i=1;i<head.data;i++)
                {
                    tmp=tmp->next;
                }
                Node* t=tmp->next;
                delete t;
                tmp->next=nullptr;
                tmp->next=head.next;
                head.data--;
            }
        }
        void print(){
            Node* tmp=head.next;
            for(int i=0;i<head.data;i++){
                cout<<"["<<i<<"]="<<tmp->data<<endl;
                tmp=tmp->next;
            }
        }
    private:
        struct Node{
            int data;
            Node* next;
            Node(){
                data=0;
                next=nullptr;
            }
            Node(int x,Node* t){
                data=x;
                next=t;
            }
        };
        Node head;
};

int main(){
    loopList a;
    a.insert(5);
    a.insert(2);
    a.insert(8);
    a.insert(3);
    // a.del();
    a.print();
    return 0;
}