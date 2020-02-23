/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj=nums[0];
        int cnt=1;
        for(int i=1;i<nums.size();i++) {
            if(nums[i]==maj)cnt++;
            else cnt--;
            if(cnt<0){
                maj=nums[i];
                cnt=1;
            }
        }
        return maj;
    }
    // 1. 暴力法：用哈希表记录每个数字出现的次数，最后找出出现次数大于0.5n的元素
    // 2. 多数元素大于0.5n，所以所有多数元素加起来的次数要超过非多数元素，
    // 把他们想象成1和-1，全部相加后结果一定是正的，假设a为多数元素，计数器记录到目前位置a出现的次数
    // 如果下一个是a就加一否则减一，减到负的时候就更换多数元素，前面的相当于已经消掉了。
};
// @lc code=end

