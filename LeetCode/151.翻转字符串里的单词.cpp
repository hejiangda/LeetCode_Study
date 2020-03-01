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
        istringstream iss(s);
        string tmp;
        string ret;
        while (getline(iss,tmp,' ')) {
            if (!tmp.empty()) {
                ret=tmp+" "+ret;
            }
        }
        ret.pop_back();
        return ret;
    }
};
// @lc code=end

