/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    int last=INT_MIN;
    bool flg=false;
    bool isValidBST(TreeNode* root) {
        if(root==nullptr)return true;
        bool left=isValidBST(root->left);
        if(flg){
            if(last<root->val)last=root->val;
            else return false;
        }else {
            flg=true;
            last=root->val;
        }
        bool right=isValidBST(root->right);    
        return (left==true and right==true);
    }
    
    // 1.中序遍历为递增的数列为二叉搜索树
    // 2.找到左边最大的，右边最小的值，当前结点小于右边大于左边
};
// @lc code=end

