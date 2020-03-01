/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int left=0;
        int right=0;
        deque<string> st;
        while(left<s.size() and right<s.size()) {
            while(left<s.size() and s[left]==' ')left++;
            right=left;
            while(right<s.size() and s[right]!=' ')right++;
            if(right-left>0)
                st.push_back(s.substr(left,right-left));
            left=right;
        }
        string ret;
        while(!st.empty()) {
            // cout<<st.back()<<endl;
            ret = ret + st.back()+" ";
            // cout<<ret<<endl;
            st.pop_back();
        }
        ret.pop_back();
        return ret;
    }
};
// @lc code=end

