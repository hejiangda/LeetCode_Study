/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//   struct ListNode {
//       int val;
//       ListNode *next;
//       ListNode(int x) : val(x), next(NULL) {}
//   };
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr or head->next==nullptr)return head;      
        ListNode* p=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;
        return p;
    }
    // 1. 暴力法，依次遍历找到每个结点把他们一个一个串起来，n^2
    // 2. 迭代法：三指针，一个指向当前结点，一个指向前一个结点，一个保存后一个结点的值，
    // 依次把当前结点的下一个结点指向前一个结点
    // 3. 记忆化递归
    // 4. 递归法，假设 n1 n2 ... nk nk+1 ... nk之后的结点已经逆转，现在要让nk+1指向nk
    // nk->next->next=nk;
    // 递归出口为 head为空或只有一个结点此时已经到达链表尾部
};
// @lc code=end

