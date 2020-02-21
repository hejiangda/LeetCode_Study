/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.size()<3)return ret;
        set<vector<int>> s;
        set<int> ok;
        sort(nums.begin(), nums.end());
        for (int i=0;i<nums.size()-2;i++) {
            int fix=nums[i];
            if(ok.find(fix)!=ok.end())continue;
            int left = i+1, right = nums.size()-1;
            while (left<right) {
                if(nums[left] + nums[right] == -fix){
                    s.insert(vector<int>{fix,nums[left],nums[right]});
                    left++;right--;
                    ok.insert(fix);
                }
                else if(nums[left] + nums[right] < -fix){
                    left++;
                }
                else if(nums[left] + nums[right] > -fix){
                    right--;
                }
            }
        }
       
        for(auto x:s){
            ret.push_back(x);
        }            
        return ret;
    }
};
// @lc code=end

// 1. 暴力法三重循环遍历
// 2. 排序，固定一个数，首尾双指针找出相加等于该数相反数的结果，把结果放在set中；我少了一步跳过重复解
