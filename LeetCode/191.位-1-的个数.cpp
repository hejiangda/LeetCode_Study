/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        while(n!=0) {
            if(n&1)cnt++;
            n>>=1;
        }
        return cnt;
    }
};
// @lc code=end

