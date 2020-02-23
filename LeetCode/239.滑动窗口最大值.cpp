/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ret;
        for(int i=0;i<nums.size();i++) {
            if(i<k){
                while(!q.empty() and nums[q.front()]<nums[i])
                    q.pop_front();
                q.push_front(i);
            } else {
                if(!q.empty())
                    ret.push_back(nums[q.back()]);
                if(q.back()==i-k)q.pop_back();
                while(!q.empty() and nums[q.front()]<nums[i])
                    q.pop_front();
                q.push_front(i);
            }
        }
        if(!q.empty())
            ret.push_back(nums[q.back()]);
        return ret;
    }
    // 1. 暴力法：依次滑动窗口，每次遍历一遍窗口得到最大值，n**2的复杂度
    // 2. 单调队列，左边放当前的最大值，每次有新的值进来如果比前面的大就把前面小的都删除，
    // 注意队列中不要放元素的值，而要放元素的索引，这样删除队首的元素就好办了
    
};
// @lc code=end

