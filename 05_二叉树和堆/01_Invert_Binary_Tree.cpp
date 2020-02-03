// - [Invert Binary Tree（翻转二叉树）](https://leetcode-cn.com/problems/invert-binary-tree/)
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
    void invert(TreeNode* p){
        if(p==nullptr)return;
        TreeNode* tmp=p->left;
        p->left=p->right;
        p->right=tmp;
        invert(p->left);
        invert(p->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};
int main(){
    
    return 0;
}