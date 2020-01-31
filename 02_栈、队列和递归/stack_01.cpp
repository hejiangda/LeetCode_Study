//- 用数组实现一个顺序栈
#include <bits/stdc++.h>

using namespace std;
class Stack{
    public:
        Stack(int sz){
            this->sz=sz;
            data=new int[sz];
            stackTop=-1;
        }
        ~Stack(){
            delete[] data;
        }
        Stack& push(int x){
            if(stackTop+1<sz)
                data[++stackTop]=x;
            return *this;
        }
        int pop(){
            if(stackTop>=0 and stackTop<sz){
                return data[stackTop--];
            }
            return -1;
        }
        int top(){
            if(stackTop>=0 and stackTop<sz){
                return data[sz];
            }
            else return INT_MAX;
        }
        void print(){
            cout <<"Stack: ";
            for(int i=0;i<sz;i++){
                cout<<data[i]<<" ";
            }
            cout<<endl;
        }
        int size(){
            return sz;
        }
    private:
        int* data;
        int sz;
        int stackTop;
};
int main(){
    Stack s(5);
    s.push(1).push(2).push(3).push(4).push(5).push(6).print();
    cout<<"Pop sequence:";
    for(int i=0;i<s.size();i++){
        cout<<s.pop()<<" ";
    }
    cout<<endl;
    return 0;
}