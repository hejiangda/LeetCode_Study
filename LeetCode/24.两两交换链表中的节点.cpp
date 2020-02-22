/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr or head->next==nullptr)return head;
        ListNode* firstNode=head;
        ListNode* secondNode=head->next;

        firstNode->next=swapPairs(secondNode->next);
        secondNode->next=firstNode;

        return secondNode;
    }
    // 1. 递归法，swapPairs返回的是交换后结点的头
    // 第一个结点的下一个结点是第三个结点交换后的结点
    // 第二个结点的下一个结点是第一个结点
    // 第二个结点为头返回
    // 2. 
};
// @lc code=end

