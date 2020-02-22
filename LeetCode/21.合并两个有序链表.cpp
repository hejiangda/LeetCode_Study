/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode* p=&dummy;
        while(l1 and l2) {
            if(l1->val<l2->val) {
                p->next=l1;p=l1;
                l1=l1->next;
            }else {
                p->next=l2;p=l2;
                l2=l2->next;
            }
        }
        if(l1)p->next=l1;
        if(l2)p->next=l2;
        return dummy.next;
    }
    // 用一个空结点做头结点，依次把两个链表中较小的接在p的末尾
};
// @lc code=end

