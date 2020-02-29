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
        int left=0,right=0;
        int num=0;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='(')left++;
            else if(s[i]==')')right++;
            if(left<right){
                left=right=0;
            }else if(left==right) {
                num=max(num,left+left);
            }
        }
        left=right=0;
        for(int i=s.size()-1;i>=0;i--) {
            if(s[i]=='(')left++;
            else if(s[i]==')')right++;
            if(left>right){
                left=right=0;
            }else if(left==right) {
                num=max(num,left+left);
            }
        }
        return num;
    }
};
// @lc code=end

