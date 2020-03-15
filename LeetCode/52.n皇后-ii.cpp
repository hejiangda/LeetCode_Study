/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<bool> col;
    set<int> pie;
    set<int> na;
    int cnt=0;
    int totalNQueens(int n) {
        col.resize(n);
        helper(n,0);
        return cnt;
    }
    void helper(int n,int r) {
        if(r>=n){
            cnt++;return;
        }
        for(int c=0;c<n;c++) {
            if(col[c] or pie.find(c+r)!=pie.end() or na.find(c-r)!=na.end())
                continue;
            col[c]=true;
            pie.insert(c+r);
            na.insert(c-r);
            helper(n,r+1);
            na.erase(c-r);
            pie.erase(c+r);
            col[c]=false;
        }
    }
};
// @lc code=end

