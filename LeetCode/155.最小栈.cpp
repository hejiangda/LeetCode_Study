/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class MinStack {
public:
    /** initialize your data structure here. */
    deque<int> st;
    deque<int> stMin;
    MinStack() {

    }
    
    void push(int x) {
        st.push_back(x);
        if(stMin.size()>0) {
            stMin.push_back(stMin.back()<x?stMin.back():x);
        }else stMin.push_back(x);

    }
    
    void pop() {
        st.pop_back();
        stMin.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return stMin.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

