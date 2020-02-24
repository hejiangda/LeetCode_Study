/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<=0)return 0;
        int left[height.size()];
        int right[height.size()];
        int maxn=0;
        for(int i=0;i<height.size();i++) {
            if(height[i]>maxn)maxn=height[i];
            left[i]=maxn;
        }
        maxn=0;
        for(int i=height.size()-1;i>=0;i--) {
            if(height[i]>maxn)maxn=height[i];
            right[i]=maxn;
        }
        int area=0;
        for(int i=0;i<height.size();i++) {
            area+=min(left[i],right[i])-height[i];
        }
        return area;
    }
};
// 1. 暴力法：对于每个条分别遍历其左右找到比它大的边界，如果没有说明它无法积水，找到后用左右边界最小值减去条的高度就是它积水量
// 2. 用额外数组记录每个条从左或右方向上的最大值，用这两个数组相应的最小值作为坑边缘的高度，用这个高度减去条的值得到积水的值
// 3. 栈：依次填入递减顺序的条高度，若遇到一个更高的说明有水坑，则弹出栈顶，计算当前位置与新栈顶的差值，用边界的最小的那个减坑的高度得到积水的大小，如果有多个相同高度的坑则使用一遍又一遍的循环即可
// 4. 双指针：分别从做和右向中间指，如果左边遇到更大的就填充再向右边指。
// @lc code=end

