// - [Path Sum（路径总和）](https://leetcode-cn.com/problems/path-sum/)
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
    void travel(TreeNode* root,int sum,int num,bool& flg){
        if(root==nullptr)return;
        if(root->left==nullptr and root->right==nullptr){
            if(sum==num+root->val){
                flg=true;
            }
            return;
        }
        if(flg==true)return;
        travel(root->left,sum,num+root->val,flg);
        travel(root->right,sum,num+root->val,flg);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==nullptr)return false;
        bool flg=false;
        travel(root,sum,0,flg);
        return flg;
    }
};
int main(){

    return 0;
}