//## 链表
//+ 实现两个有序的链表合并为一个有序链表

#include <iostream>

using namespace std;

class singleList{
    public:
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
        int operator [](int index){
            if(index<0 or index>=head.data){
                cout<<"error! index out of range"<<endl;
                return -1;
            }  
            else{
                Node* p=head.next;
                for(int i=0;i<=index;i++){
                    p=p->next;
                }
                return p->data;
            }

        }
        void merge(singleList b){
            for(int i=0;i<b.size();i++){
                
            }
        }
        Node * next(){

        }
        
};
int main(){

    return 0;
}