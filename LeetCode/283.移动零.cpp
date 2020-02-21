/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p = 0;
        for (int i = 0; i < nums.size(); i++ ) {
            if( nums[ i ] != 0 )
                nums[ p++ ] = nums [ i ];
        }
        for( int i = p; i < nums.size(); i++)
            nums[ i ] = 0;
    }
};
// @lc code=end
// 1. 删除每个遇到的0，在结尾补上
// 2. 双指针，一个指向当前待处理位置，另一个遍历数组，遇到非零结点就把它赋值给当前待处理位置。
