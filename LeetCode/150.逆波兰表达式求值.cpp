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
        int index=tokens.size()-1;
        return eval(tokens,index);
    }
    int eval(vector<string>& tokens,int& index) {
        string tmp=tokens[index--];
        if(tmp=="+") {
            return eval(tokens,index)+eval(tokens,index);
        }else if(tmp=="-") {
            int t=eval(tokens,index);
            return eval(tokens,index)-t;
        }else if(tmp=="*") {
            return eval(tokens,index)*eval(tokens,index);
        }else if(tmp=="/") {
            int t=eval(tokens,index);
            return eval(tokens,index)/t;
        }else return stoi(tmp);
    }
    // 1. 后缀表达式求值：遇到数字存到栈中，遇到一个运算符就弹出两个数字，
    // 做相应运算，之后把结果再压栈，
    // 2. 递归法：从后向前，先得到运算符，之后两个操作数分别是前一个和前前一个求到的值
    // 也就是说该函数返回后缀表示法得到的值，将两个操作数分别当成已知的
};
// @lc code=end

