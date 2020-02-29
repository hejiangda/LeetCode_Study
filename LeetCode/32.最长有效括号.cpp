/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        deque<int> st;
        st.push_back(-1);
        int num=0;
        for(int i=0;i<s.size();i++) {
            if(s[i]==')') {
                if(!st.empty()) {
                    st.pop_back();
                    if(!st.empty()){
                        int topNum=st.back();
                        num=max(num,i-topNum);
                    }else {
                        st.push_back(i);   
                    }
                }
            }
            else st.push_back(i);
        }
        return num;
    }
};
// @lc code=end

