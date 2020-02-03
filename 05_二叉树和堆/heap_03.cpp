// - 实现一个小顶堆、大顶堆、优先级队列
// 优先级队列
#include <bits/stdc++.h>

using namespace std;
class Heap{
public:
    Heap(int sz){
        this->sz=sz+1;
        data=new int[sz+1];
        data[0]=0;
    }
    void adjustUp(int pos){
        if(pos<1)return;
        while(pos>1){
            if(data[pos/2]<data[pos]){
                swap(data[pos/2],data[pos]);
            }
            pos/=2;
        }
    }
    void adjustDown(int pos){
        while(pos<=data[0]/2){
            if(pos*2+1<=data[0] ){
                if(data[pos*2]>data[pos*2+1]){
                   if(data[pos]<data[pos*2])
                        swap(data[pos],data[pos*2]);
                }else{
                    if(data[pos]<data[pos*2+1])
                        swap(data[pos],data[pos*2+1]);
                }
            }else{
                if(data[pos]<data[pos*2])
                    swap(data[pos],data[pos*2]);
            }
            pos*=2;
        }
    }
    Heap& insert(int x){
        if(data[0]<sz-1){
            data[0]++;
            data[data[0]]=x;
            adjustUp(data[0]);
        }
        return *this;
    }
    int top(){
        if(data[0]>0)
            return data[1];
        else return -1;
    }
    void del(){
        data[1]=data[data[0]];
        data[0]--;
        adjustDown(1);
    }
    void print(){
        cout<<"heap:";
        int j=2;
        for(int i=1;i<=data[0];i++){
            if(i<j){
                cout<<data[i]<<" ";
            }
            else{
                j*=2;
                cout<<endl;
                cout<<data[i]<<" ";
            }
        }
        cout<<endl;
    }
private:
    int* data;
    int sz;
};
class Priority_Queue{
public:
    Priority_Queue(int sz){
        h=new Heap(sz);
    }
    Priority_Queue& push(int x){
        h->insert(x);
        return *this;
    }
    int top(){
        return h->top();
    }
    Priority_Queue& pop(){
        h->del();
        return *this;
    }
private:
    Heap* h;

};
int main(){
    Priority_Queue q(5);
    q.push(1).push(3).push(5).push(4).push(2);
    cout<<"priority queue:";
    for(int i=0;i<5;i++){
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;


    return 0;
}