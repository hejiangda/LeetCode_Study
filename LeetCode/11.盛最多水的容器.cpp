#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0, l = 0, r = height.size() - 1;
        while (l < r) {
            maxarea = max(maxarea, min(height[r], height[l] ) * ( r - l ) );
            if ( height[l] < height[r] )
                l++;
            else 
                r--;
        }
        return maxarea;
    }
};
// @lc code=end

// 1. 将每个竖线分别匹配得到最大的容积
// 2. 题解的双指针法，固定最长边移动最短边。

