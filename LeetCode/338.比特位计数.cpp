/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret;
        for(int i=0;i<=num;i++) {
            int x=i;
            int cnt=0;
            while(x) {
                x=x&(x-1);
                cnt++;
            }
            ret.push_back(cnt);
        }
        return ret;
    }
};
// @lc code=end

