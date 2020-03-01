/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    int s=0;
    bool flg=false;
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==nullptr)return flg;
        if(flg==true)return flg;
        s+=root->val;
        if(s==sum and root->left==nullptr and root->right==nullptr)flg=true;
        hasPathSum(root->left,sum);
        hasPathSum(root->right,sum);
        s-=root->val;
        return flg;
    }
};
// @lc code=end

