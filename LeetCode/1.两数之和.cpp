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
        for(int x:nums) {
            mp[x]++;
        }
        vector<int> ret;
        for(int i=0;i<nums.size();i++) {
            if(mp.find(target-nums[i])!=mp.end() ) {
                if(target-nums[i] == nums[i] and mp[nums[i]]>1) {
                    ret.push_back(i);
                    for(int j=i+1;j<nums.size();j++) {
                        if(nums[j] == target-nums[i]) {
                            ret.push_back(j);
                            return ret;
                        }
                    }
                }else if(target-nums[i] != nums[i]){
                    
                    ret.push_back(i);
                    for(int j=0;j<nums.size();j++) {
                        if(nums[j] == target-nums[i]) {
                            ret.push_back(j);
                            return ret;
                        }
                    }
                }
            }
        }
        return ret;
    }
    // 1. 暴力法，两重循环
    // 2. 排序后双指针
    // 3. 哈希表法
    // a+b=target a=target-b
};
// @lc code=end

