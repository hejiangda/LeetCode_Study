/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minD=INT_MAX;
    int minDepth(TreeNode* root) {
        if(root==nullptr)return 0;
        dfs(root,1);
        return minD;
    }
    void dfs(TreeNode* root,int level) {
        if(root==nullptr)return;
        if(root->left==nullptr and root->right==nullptr) {
            if(minD>level)minD=level;
        }
        if(root->left)dfs(root->left,level+1);
        if(root->right)dfs(root->right,level+1);
    }
};
// @lc code=end

