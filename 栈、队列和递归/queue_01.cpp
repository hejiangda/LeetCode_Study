//- 用数组实现一个顺序队列
#include <bits/stdc++.h>

using namespace std;
class Queue{
    public:
        Queue(int sz){
            this->sz=sz;
            front=0;
            end=0;
            data=new int[sz];
        }
        ~Queue(){
            delete[] data;
        }
        Queue& enQ(int x){
            if(end<sz){
                data[end++]=x;
            }else if(end-front<sz){
                for(int i=0;i<end-front;i++){
                    data[i]=data[i+front];
                }
                end=end-front;;
                front=0;
                data[end++]=x;
            }
            cout<<"#EnQueue ";
            print();
            return *this;
        }
        Queue& deQ(){
            if(front<end){
                front++;
                cout<<"#DeQueue ";
                print();
                
            }else{
                cout<<"Queue empty"<<endl;
            }
            return *this;
        }
        int qfront(){
            return data[front];
        }
        Queue& print(){
            cout<<"Queue:";
            for(int i=front;i<end;i++){
                cout<<data[i]<<" ";
            }
            cout<<endl;
            return *this;
        }
    private:
        int* data;
        int front;
        int end;
        int sz;

};
int main(){
    Queue q(5);
    q.enQ(1).enQ(2).enQ(3).enQ(4).enQ(5).enQ(6);
    q.deQ().deQ().deQ().deQ().deQ().deQ();
    q.enQ(1).enQ(2).enQ(3).enQ(4).enQ(5).enQ(6);
    return 0;
}