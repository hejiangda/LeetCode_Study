// - [Validate Binary Search Tree（验证二叉查找树）](https://leetcode-cn.com/problems/validate-binary-search-tree/)
#include<bits/stdc++.h>

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
    void travel(TreeNode* t,deque<int>& dq,bool& flg){
        if(t==nullptr)return;
        if(flg==false)return;
        travel(t->left,dq,flg);
        if(dq.size()>0){
            if(dq.back()>=t->val){
                flg=false;
                return ;
            }
            if(dq.size()>1)
                dq.pop_front();
        }
        dq.push_back(t->val);
        travel(t->right,dq,flg);
    }
    bool isValidBST(TreeNode* root) {
        deque<int> dq;
        bool flg=true;
        travel(root,dq,flg);
        return flg;
    }
};
int main(){

    return 0;
}