/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        deque<int> st;
        for(auto x:tokens) {
            if(x=="+"){
                int b=st.back();st.pop_back();
                int a=st.back();st.pop_back();
                st.push_back(a+b);
            }else if(x=="-"){
                int b=st.back();st.pop_back();
                int a=st.back();st.pop_back();
                st.push_back(a-b);
            }else if(x=="*"){
                int b=st.back();st.pop_back();
                int a=st.back();st.pop_back();
                st.push_back(a*b);
            }else if(x=="/"){
                int b=st.back();st.pop_back();
                int a=st.back();st.pop_back();
                st.push_back(a/b);
            }else {
                st.push_back(stoi(x));
            }
        }
        return st.back();
    }
    // 1. 后缀表达式求值：遇到数字存到栈中，遇到一个运算符就弹出两个数字，
    // 做相应运算，之后把结果再压栈，
};
// @lc code=end

