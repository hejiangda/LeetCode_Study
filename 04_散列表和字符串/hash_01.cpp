//- 实现一个基于链表法解决冲突问题的散列表
#include <bits/stdc++.h>

using namespace std;
class HashTable{
public:
    HashTable(int sz){
        this->sz=sz;
        data=new Node[sz];
    }
    ~HashTable(){
        delete[] data;
    }
    HashTable& insert(int x){
        if(find(x))return *this;
        if(data[x%sz].data==-1){
            data[x%sz].data=x;
        }else{
            Node* p=&data[x%sz];
            while(p->next!=nullptr){
                p=p->next;
            }
            p->next=new Node(x);
        }
        return *this;
    }
    bool find(int x){
        if(data[x%sz].data==x)return true;
        Node* p=data[x%sz].next;
        while(p!=nullptr){
            if(p->data==x)return true;
            p=p->next;
        }
        return false;
    }
    bool del(int x){
        if(data[x%sz].data==x){
            Node*p=&data[x%sz];
            Node* tmp=nullptr;
            while(p and p->next){
                tmp=p;
                p=p->next;
            }
            if(p==&data[x%sz])
            {
                p->data=-1;
                return true;
            }
            else{
                data[x%sz]=p->data;
                delete tmp->next;
                return true;
            }
        }else{
            Node* p=data[x%sz].next;
            while(p!=nullptr){
                if(p->data==x){
                    p=p->next;
                    return true;
                }
                p=p->next;
            }
        }
        return false;
    }
private:
    struct Node{
        int data;
        Node* next;
        Node(int x){
            data=x;
            next=nullptr;
        }
        Node(){
            data=-1;
            next=nullptr;
        }
    };
    int sz;
    Node* data;
};

int main(){
    HashTable hs(5);
    hs.insert(1).insert(2).insert(3).insert(4).insert(5).insert(6).insert(7);
    for(int i=0;i<20;i++){
        if(hs.find(i))cout<<i<<" ";
        else cout<<"*"<<" ";
    }
    cout<<endl;
    hs.insert(19).insert(18).insert(17);
    hs.del(1);
    hs.del(2);
    hs.del(5);
    hs.del(4);
    for(int i=0;i<20;i++){
        if(hs.find(i))cout<<i<<" ";
        else cout<<"*"<<" ";
    }
    cout<<endl;
    return 0;
}