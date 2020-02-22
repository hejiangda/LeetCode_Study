/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++) {
            if(mp.find(target-nums[i])!=mp.end()){
                return {mp[target-nums[i]],i};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
    // 1. 暴力法，两重循环
    // 2. 排序后双指针
    // 3. 哈希表法
    // a+b=target a=target-b
    // 4. 一遍哈希法，在遍历的同时查看该节点之前的结点有没有在哈希表中
};
// @lc code=end

