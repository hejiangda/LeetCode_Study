/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> st1,st2;

    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        st1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(!empty()){

            if(!st2.empty()) {
                int tmp=st2.top();
                st2.pop();
                return tmp;
            }else {
                while(!st1.empty()) {
                    st2.push(st1.top());
                    st1.pop();
                }
                int tmp=st2.top();
                st2.pop();
                return tmp;
            }
        }
        return -1;
    }
    
    /** Get the front element. */
    int peek() {
        if(!empty()){

            if(!st2.empty()) {
                int tmp=st2.top();
                return tmp;
            }else {
                while(!st1.empty()) {
                    st2.push(st1.top());
                    st1.pop();
                }
                int tmp=st2.top();
                return tmp;
            }
        }
        return -1;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (st1.empty() and st2.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

