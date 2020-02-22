/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
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
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr or head->next==nullptr)return nullptr;
        ListNode*slow=head;
        ListNode*fast=head;
        do{
            slow=slow->next;
            fast=fast->next->next;
        }while(slow and fast and fast->next and slow!=fast);
        if(fast==nullptr or fast->next==nullptr or slow==nullptr)return nullptr;
        ListNode* ret=head;
        while(ret!=slow) {
            ret=ret->next;
            slow=slow->next;
        }
        return ret;
    }
    // 1.哈希表法，遍历时先看有没有再加入表中，若有则返回该结点的指针
    // 2.快慢指针法，快慢指针重合后，让一个新的指针从head开始走当它和慢指针重合时就是入口
    // f=2s
    // f=s+nb
    // s=nb
    // nb+a就是环入口
    // 慢指针已经走了nb了 再走a就到了入口
    // 此时另一个指针从head开始走，和慢指针相遇时候就到了入口
};
// @lc code=end

