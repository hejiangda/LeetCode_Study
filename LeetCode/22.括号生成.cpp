/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> ret;
    vector<string> generateParenthesis(int n) {
        gen("",n,n);
        return ret;
    }
    void gen(string s,int left, int right) {
        if(left==right and left==0) {
            ret.push_back(s);
            return;
        }
        if(left>0) {
            gen(s+'(',left-1,right);
        }
        if(right>0 and left<right) {
            gen(s+')',left,right-1);
        }
    }
    // n=1 ()
    // n=2 (()) ()()
};
// @lc code=end

