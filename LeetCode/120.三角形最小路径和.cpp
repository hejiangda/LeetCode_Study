/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> mini = triangle[triangle.size()-1];
        for(int i=triangle.size()-2;i>=0;--i)
            for(int j=0;j<triangle[i].size();++j)
                mini[j]=triangle[i][j]+min(mini[j],mini[j+1]);
        return mini[0];
    }
};
// @lc code=end

