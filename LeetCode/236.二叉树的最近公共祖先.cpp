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
    deque<TreeNode *> st1;
    deque<TreeNode *> st2;
    bool flg1=false;
    bool flg2=false;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs1(root,p);
        dfs2(root,q);
        // for(auto &x:st1) {
        //     cout<<x->val<<" ";
        // }
        // cout<<endl;
        // for(auto &x:st2) {
        //     cout<<x->val<<" ";
        // }
        // cout<<endl;
        TreeNode* ret=root;
        while(!st1.empty() and !st2.empty() and st1.front()==st2.front()) {
            ret=st1.front();
            st1.pop_front();
            st2.pop_front();
        }
        return ret;
    }
    void dfs1(TreeNode* root,TreeNode* p) {
        if(flg1==true)return;
        if(root==nullptr)return;
        if(root==p){
            flg1=true;
            st1.push_back(root);
            return;
        }
        st1.push_back(root);
        if(root->left)dfs1(root->left,p);
        if(root->right)dfs1(root->right,p);
        if(flg1==false)
        st1.pop_back();
    }
    void dfs2(TreeNode* root,TreeNode* p) {
        if(flg2==true)return;
        if(root==nullptr)return;
        if(root==p){
            flg2=true;
            st2.push_back(root);
            return;
        }
        st2.push_back(root);
        if(root->left)dfs2(root->left,p);
        if(root->right)dfs2(root->right,p);
        if(flg2==false)
        st2.pop_back();
    }
    // 1.后序遍历，用栈保存结点，之后两个结点的栈分别对比
    // 2.分治法：如果pqroot相等说明他们最近的祖先就是自己，之后判断左右子树，
    // 若左子树有pq则遍历左子树，如果右子树有pq则遍历右子树，如果左右各有一个则说明lca为root

};
// @lc code=end

