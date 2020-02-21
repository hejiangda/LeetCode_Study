/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> tmp(nums.size());
        for(int i=0;i<nums.size();i++){
            tmp[(i+k)%nums.size()]=nums[i];
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=tmp[i];
        }
    }
};
// @lc code=end
// 1. 暴力法依次移动数据
// 2. 计算好每个数字移动后的位置，然后把数据填入临时数组，最后把数据复制到原数组
