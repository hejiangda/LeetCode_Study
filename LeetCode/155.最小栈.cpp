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
    deque<long long> st;
    long long minNum;
    MinStack() {

    }
    
    void push(int x) {
        if(st.empty()) {
            minNum=x;
        }
        st.push_back(x-minNum);
        if(x-minNum<0)minNum=x;
    }
    
    void pop() {
        if(st.back()<0) {
            minNum=minNum-st.back();
        }
        st.pop_back();
    }
    
    int top() {
        if(st.back()>0)
            return st.back()+minNum;
        else return minNum;
    }
    
    int getMin() {
        return minNum;
    }
    // 1. 双栈，一个保存最小元素，一个保存数据
    // 2. 用一个变量保存最小结点，若获得了比当前最小元素还小的值，把当前最小的压栈然后再把最小值压栈
    // 出栈时，若出的是最小元素，则最小元素的下一个元素也出栈给最小值
    // 3. 入栈时保存该元素与最小值之差，如果更小则负数入栈，出栈时两者相加，若为负数则更新最小值
    // 4. 修改栈结构，每次入栈时同时包含最小值
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

