/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p==q)return p;
        if(root==nullptr)return nullptr;
        bool left=hasNode(root->left,p,q);
        bool right=hasNode(root->right,p,q);
        // cout<<left<<" "<<right<<" "<<root->val<<endl;
        if(left and right) return root;
        if(left and (p==root or q==root)) {
            return root;
        }
        if(right and (p==root or q==root)) {
            return root;
        }
        if(left) {
            return lowestCommonAncestor(root->left,p,q);
        }
        
        return lowestCommonAncestor(root->right,p,q);
        
    }
    bool hasNode(TreeNode *root,TreeNode* p,TreeNode* q) {
        if(root==nullptr)return false;
        bool left=false,right=false;
        if(root==p or root==q)return true;
        if(root->left) {
            left=hasNode(root->left,p,q);
        }
        if(root->right) {
            right=hasNode(root->right,p,q);
        }
        return left or right;
    }
    // 1.后序遍历，用栈保存结点，之后两个结点的栈分别对比
    // 2.分治法：如果pqroot相等说明他们最近的祖先就是自己，之后判断左右子树，
    // 若左子树有pq则遍历左子树，如果右子树有pq则遍历右子树，如果左右各有一个则说明lca为root

};
// @lc code=end

