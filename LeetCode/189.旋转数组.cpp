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
        k=k%nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
    
};
// @lc code=end
// 1. 暴力法依次移动数据
// 2. 计算好每个数字移动后的位置，然后把数据填入临时数组，最后把数据复制到原数组
// 3. 环替换法，这个我想到了，但是一直卡在了循环回到起点上。
// 4. 反转法，整体反转一次，在k位置前后分别反转