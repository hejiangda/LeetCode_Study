/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1,q2;
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if(empty()) {
            q1.push(x);
        }else {
            if(q1.empty()) q2.push(x);
            else if(q2.empty())q1.push(x);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(empty())return -1;
        int ret=0;
        if(q2.empty()) {
            while(q1.size()!=1) {
                q2.push(q1.front());q1.pop();
            }
            ret=q1.front();q1.pop();
        }else if(q1.empty()) {
            while(q2.size()!=1) {
                q1.push(q2.front());q2.pop();
            }
            ret=q2.front();q2.pop();
        }
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        if(empty())return -1;
        int ret=0;
        if(q2.empty()) {
            while(q1.size()!=1) {
                q2.push(q1.front());q1.pop();
            }
            ret=q1.front();q2.push(ret);q1.pop();
        }else if(q1.empty()) {
            while(q2.size()!=1) {
                q1.push(q2.front());q2.pop();
            }
            ret=q2.front();q1.push(ret);q2.pop();
        }
        return ret;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() and q2.empty();
    }
    // q1: 4
    // q2: 123
    
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

