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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root==nullptr)return ret;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int sz=q.size();
            vector<int> tmp;
            for(int i=0;i<sz;i++) {
                TreeNode* p=q.front();
                q.pop();
                tmp.push_back(p->val);
                if(p->left)q.push(p->left);
                if(p->right)q.push(p->right);
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};
// @lc code=end

