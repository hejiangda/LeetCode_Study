/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层次遍历
 */
#include <bits/stdc++.h>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root,0);
        
        return ret;
    }
    void dfs(TreeNode* root, int level) {
        if(root==nullptr)return ;
        if(ret.size()<=level)ret.push_back({});
        ret[level].push_back(root->val);
        if(root->left)dfs(root->left,level+1);
        if(root->right)dfs(root->right,level+1);
    }
};
// @lc code=end

