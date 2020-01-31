// - 实现一个循环队列
#include <bits/stdc++.h>

using namespace std;
class LoopQueue{
    public:
        LoopQueue(int sz){
            this->sz=sz;
            data=new int[sz];
            head=0;
            tail=0;
            cnt=0;
        }
        ~LoopQueue(){
            delete[] data;
         }
        LoopQueue& EnQueue(int x){
            if(cnt!=sz){
                data[tail]=x;
                tail=(tail+1)%sz;
                cnt++;
                cout<<"#EnQueue ";
                print();
            }
            
            return *this;
        }
        LoopQueue& DeQueue(){
            if(cnt!=0){
                head=(head+1)%sz;
                cnt--;
                cout<<"#DeQueue ";
                print();
            }
            return *this;
        }
        LoopQueue& print(){
            int i=head;
            if(cnt>0){
                int k=0;
                cout<<"LoopQueue: ";
                while(k!=cnt){
                    cout<<data[i]<<" ";
                    i=(i+1)%sz;
                    k++;
                }
                cout<<endl;
            }else 
                cout<<"error! LoopQueue empty!"<<endl;
            return *this;
        }
        int front(){
            if(cnt!=0){
                return data[head];
            }
            else{
                cout<<"error! LoopQueue empty"<<endl;
                return -1;
            }
        }
    private:
        int* data;
        int sz;
        int head;
        int tail;
        int cnt;
};
int main(){
    LoopQueue lpq(5);
    lpq.EnQueue(1).EnQueue(2).EnQueue(3).EnQueue(4).EnQueue(5).EnQueue(6);
    lpq.DeQueue().DeQueue().DeQueue().DeQueue().DeQueue().DeQueue().DeQueue();
    lpq.EnQueue(1).EnQueue(2);
    return 0;
}