// - 实现二叉树前、中、后序以及按层遍历
#include <bits/stdc++.h>
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
    void inOrderTravel(){
        inOrderTravel(T);
        cout<<endl;
    }
    void inOrderTravel(Node* p){
        if(p==nullptr)
            return;
        inOrderTravel(p->left);
        cout<<p->data<<" ";
        inOrderTravel(p->right);
    }
    void priorOrderTravel(){
        priorOrderTravel(T);
        cout<<endl;
    }
    void priorOrderTravel(Node* p){
        if(p==nullptr)
            return;
        cout<<p->data<<" ";
        priorOrderTravel(p->left);
        priorOrderTravel(p->right);
    }
    void postOrderTravel(){
        postOrderTravel(T);
        cout<<endl;
    }
    void postOrderTravel(Node* p){
        if(p==nullptr)
            return;
        postOrderTravel(p->left);
        postOrderTravel(p->right);
        cout<<p->data<<" ";
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
    Node* findPrior(int x){
        Node* p=nullptr;
        bool flg=false;
        findPrior(x,T,p,flg);
        if(p and p->data<=x)
            return p;
        return nullptr;
    }
    
    void findPrior(int x,Node* p,Node*& prior,bool& flg){
        if(flg or p==nullptr)
            return;
        
        findPrior(x,p->left,prior,flg);
        if(flg)return;
        if(p->data==x){
            flg=true;
            return ;
        }
        prior=p;
        findPrior(x,p->right,prior,flg);
    }
   Node* findPost(int x){
        Node* p=nullptr;
        bool flg=false;
        findPost(x,T,p,flg);
        if(p and p->data>=x)
            return p;
        return nullptr;
    }
    
    void findPost(int x,Node* p,Node*& prior,bool& flg){
        if(flg or p==nullptr)
            return;
        
        findPost(x,p->right,prior,flg);
        if(flg)return;
        if(p->data==x){
            flg=true;
            return ;
        }
        prior=p;
        findPost(x,p->left,prior,flg);
    }

private:
    Node* T;
};
int main(){
    Tree bst;
    bst.insert(4).insert(2).insert(1).insert(3).insert(5);
    bst.priorOrderTravel();
    bst.inOrderTravel();
    bst.postOrderTravel();
    return 0;
}