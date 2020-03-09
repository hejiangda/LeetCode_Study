/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层次遍历
 */

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
    map<int,vector<int>> ret;
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        dfs(root,0);
        for(auto x:ret) {
            result.push_back(x.second);
        }
        return result;
    }
    void dfs(TreeNode* root, int level) {
        if(root==nullptr)return ;
        ret[level].push_back(root->val);
        if(root->left)dfs(root->left,level+1);
        if(root->right)dfs(root->right,level+1);
    }
};
// @lc code=end

