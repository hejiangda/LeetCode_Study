// - 实现一个二叉查找树，并且支持插入、删除、查找操作
#include<bits/stdc++.h>

using namespace std;
struct Node{
        int data;
        Node* left;
        Node* right;
        Node(int x){
            data=x;
            left=nullptr;
            right=nullptr;
        }
    };
class Tree{
public:
    Tree(){
        T=nullptr;
    }
    Tree& insert(int x){
        insert(x,T);
        return *this;
    }
    void insert(int x,Node*& p){
        if(p==nullptr){
            p=new Node(x);
            return ;
        }
        if(p->data>x){
            return insert(x,p->left);
        }
        else return insert(x,p->right);
    }
    void inorderTravel(){
        inorderTravel(T);
        cout<<endl;
    }
    void inorderTravel(Node* p){
        if(p==nullptr)
            return;
        inorderTravel(p->left);
        cout<<p->data<<" ";
        inorderTravel(p->right);
    }
    Tree& del(int x){
        del(x,T);
        return *this;
    }
    void del(int x,Node*& p){
        if(p==nullptr)
            return;
        if(p->data==x){
            if(p->right){
                Node * tmp=p->right;
                while(tmp->left)
                    tmp=tmp->left;
                tmp->left=p->left;
                tmp=p->right;
                delete p;
                p=tmp;
            }
            else {
                Node * tmp=p->left;
                delete p;
                p=tmp;
            }
            return;
        }
        else if(p->data>x)
            del(x,p->left);
        else 
            del(x,p->right);
    }
    Node* find(int x){
        return find(x,T);
    }
    Node* find(int x,Node* p){
        if(p==nullptr)
            return nullptr;
        if(p->data==x)
            return p;
        if(p->data>x)
            return find(x,p->left);
        else return find(x,p->right);
    }
private:
    Node* T;
};
int main(){
    Tree bst;
    bst.insert(4).insert(2).insert(1).insert(3).insert(5);
    bst.inorderTravel();
    bst.del(5).del(1);
    bst.inorderTravel();
    cout<<bst.find(2)<<endl;
    cout<<bst.find(10)<<endl;
    return 0;
}