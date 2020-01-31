// - [Design Circular Deque（设计一个双端队列）](https://leetcode-cn.com/problems/design-circular-deque/)
#include <bits/stdc++.h>

using namespace std;
class MyCircularDeque {
#define DEBUG 1
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        data=new int[k];
        cnt=0;
        front=-1;
        last=0;
        sz=k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(cnt<sz){
            cnt++;
            front=(sz+front+1)%sz;
            data[front]=value;
            if(DEBUG)cout<<"front:"<<front<<endl;
            return true;
        }
        return false;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(cnt<sz){
            cnt++;
            last=(sz+last-1)%sz;
            data[last]=value;
            if(DEBUG)cout<<"last:"<<last<<endl;
            return true;
        }
        return false;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(cnt>0){
            front=(front-1+sz)%sz;
            cnt--;
            if(DEBUG)cout<<"front:"<<front<<endl;
            return true;
        }
        return false;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(cnt>0){
            last=(last+sz+1)%sz;
            cnt--;
            if(DEBUG)cout<<"last:"<<last<<endl;
            return true;
        }
        return false;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        // if(cnt<=0){
            // return 0;
        // }
        if(DEBUG)cout<<"front:"<<front<<endl;
        return data[front];
        
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        // if(cnt<=0){
            // return 0;
        // }
        if(DEBUG)cout<<"last:"<<last<<endl;
        return data[last];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return cnt==0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return cnt==sz;
    }
private:
    int* data;
    int front;
    int last;
    int cnt;
    int sz;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
int main(){
    MyCircularDeque obj(5);
    obj.insertFront(7);
    obj.insertLast(1);
    cout<<obj.getFront()<<endl;
    obj.insertLast(3);
    cout<<obj.getFront()<<endl;
    obj.insertFront(9);
    cout<<obj.getRear()<<endl;
    cout<<obj.getFront()<<endl;
    cout<<obj.getFront()<<endl;
    obj.deleteLast();
    cout<<obj.getRear()<<endl;
    return 0;
}