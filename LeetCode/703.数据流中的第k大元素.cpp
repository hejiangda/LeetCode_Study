/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第K大元素
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int sz;
    KthLargest(int k, vector<int>& nums) {
        sz=k;
        for(int i=0;i<nums.size();i++) {
            if(i<k)pq.push(nums[i]);
            else {
                if(nums[i]>pq.top()) {
                    pq.pop();pq.push(nums[i]);
                }
            }
        }
            
    }
    int add(int val) {
        if(!pq.empty()){
            if(pq.size()<sz) {
                pq.push(val);
            }else
            if(val>pq.top()) {
                pq.pop();pq.push(val);
            }
            return pq.top();
        } else {
            pq.push(val);
            return pq.top();
        }
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

