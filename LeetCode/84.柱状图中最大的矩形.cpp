/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        deque<int> st;
        st.push_back(-1);
        int maxArea=0;
        for(int i=0;i<heights.size();i++) {
            while(st.back()!=-1 and heights[st.back()]>=heights[i]){
                int h=heights[st.back()];
                st.pop_back();
                maxArea=max(maxArea,h*(i-st.back()-1));
            }
            st.push_back(i);
        }
        while(st.back()!=-1) {
            int h=heights[st.back()];
            st.pop_back();
            maxArea=max(maxArea,(int)(h*(heights.size()-st.back()-1)));
        }
        return maxArea;
    }
    // 1. 暴力法：二重循环遍历每个条，两两匹配，用宽乘以区间内最短的部分
    // 2. 用堆栈：首先把哨兵-1入栈，用于表示最开始的位置，然后依次按递增顺序入栈
    // 当遇到一个小于栈顶元素的值时，开始计算此元素前的元素所组成的矩形的大小，依次按pop出的
    // 元素从左至右组成矩形，因为栈里的元素都是递增的所以越pop越小，也就符合了题目要求，以当前元素的下标作为被减数求长度
    // 减数为作为高元素的前一个元素的下标（这样可以通过最开始的-1简化运算）
    // 
};
// @lc code=end

