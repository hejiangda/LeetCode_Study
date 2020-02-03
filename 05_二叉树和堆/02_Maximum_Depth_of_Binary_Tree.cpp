// - [Maximum Depth of Binary Tree（二叉树的最大深度）](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)
#include <bits/stdc++.h>

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int left=0;
        if(root->left)
            left=maxDepth(root->left);
        int right=0;
        if(root->right)
            right=maxDepth(root->right);
        return left>right?left+1:right+1;        
    }
};

int main(){

    return 0;
}