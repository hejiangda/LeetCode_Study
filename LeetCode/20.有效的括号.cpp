/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        deque<char> st;
        for(char x:s) {
            switch(x) {
                case '(':
                case '[':
                case '{':st.push_back(x);break;
                case ')':if(st.size()>0 and st.back()=='(')st.pop_back();else return false;break;
                case ']':if(st.size()>0 and st.back()=='[')st.pop_back();else return false;break;
                case '}':if(st.size()>0 and st.back()=='{')st.pop_back();else return false;break;
            }
            
        }
        if(st.size()==0)return true;
        return false;
    }
};
// @lc code=end

