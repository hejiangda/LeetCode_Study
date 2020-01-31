//## 链表
//+ 实现单链表、循环链表、双向链表，支持增删操作
// 双向链表

#include <iostream>

using namespace std;

class doubleList{
    public:
        void insert(int x){
            if(head.data==0){
                head.next=new Node(x);
                head.prev=head.next;
            }else{
                Node* tmp=&head;
                while(tmp->next!=nullptr){
                    tmp=tmp->next;
                }
                tmp->next=new Node(x);
                tmp->next->prev=tmp;
                head.prev=tmp->next;
            }
            head.data++;
        }
        void del(int pos){
            if(pos<0||pos>head.data-1)
            {
                cout<<"error! pos out of range"<<endl;
            }
            else{
                Node* tmp=&head;
                for(int i=0;i<pos;i++){
                    tmp=tmp->next;
                }
                Node* t=tmp->next;
                if(pos!=0){
                    tmp->next=tmp->next->next;
                    tmp->prev=tmp->next->prev;
                    delete t;
                }
                else{
                    tmp->next=tmp->next->next;
                    if(head.prev==t)
                        head.prev=nullptr;
                    delete t;
                }
                head.data--;
            }
        }
        void print(){
            Node* tmp1=head.next;
            Node* tmp2=head.prev;
            for(int i=0;i<head.data;i++){
                cout<<"["<<i<<"]="<<tmp1->data<<" ["<<head.data-i-1<<"]="<<tmp2->data<<endl;
                tmp1=tmp1->next;
                tmp2=tmp2->prev;
            }
        }
    private:
        struct Node{
            int data;
            Node* next;
            Node* prev;
            Node(){
                data=0;
                next=nullptr;
                prev=nullptr;
            }
            Node(int x){
                data=x;
                next=nullptr;
                prev=nullptr;
            }
        };
        Node head;
};

int main()
{
    doubleList a;
    a.insert(1);
    a.insert(3);
    a.insert(5);
    a.insert(8);
    a.del(0);
    
    a.print();
    return 0;
}