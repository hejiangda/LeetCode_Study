/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<bool> col;
    set<int> pie,na;
    vector<vector<string>> res;
    vector<string> board;
    vector<vector<string>> solveNQueens(int n) {
        col.resize(n);
        helper(n,0);
        return res;
    }
    void helper(int n,int r) {
        if(r>=n) {
            res.push_back(board);
            return;
        }
        for(int c=0;c<n;c++) {
            if(col[c] or pie.find(c+r)!=pie.end() or na.find(c-r)!=na.end())
                continue;
            col[c]=true;
            pie.insert(c+r);
            na.insert(c-r);
            string tmp;
            for(int i=0;i<n;i++)
                tmp.push_back('.');
            tmp[c]='Q';
            board.push_back(tmp);
            helper(n,r+1);
            board.pop_back();
            na.erase(c-r);
            pie.erase(c+r);
            col[c]=false;
        }
    }
};
// @lc code=end

