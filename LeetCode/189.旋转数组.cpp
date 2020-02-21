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
        k = k % nums.size();
        int cnt=0;
        for (int start = 0; start < k and cnt<nums.size(); start++) {
            int current = start;
            int prev = nums[start];
            do {
                cnt++;
                int next = (current+k)%nums.size();
                int tmp = nums[next];
                nums[next] = prev;
                prev = tmp;
                current = next;
            }while(current != start);
        }
    }
};
// @lc code=end
// 1. 暴力法依次移动数据
// 2. 计算好每个数字移动后的位置，然后把数据填入临时数组，最后把数据复制到原数组
// 3. 环替换法，这个我昨天想到了，但是一直卡在了循环回到起点上。