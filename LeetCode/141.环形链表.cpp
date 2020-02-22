/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head) {
        if(head==nullptr or head->next==nullptr)return false;
        ListNode* fastPtr=head->next;
        ListNode* slowPtr=head;
        while(fastPtr and slowPtr) {
            if(fastPtr!=slowPtr) {
                slowPtr=slowPtr->next;
                if(fastPtr->next) {
                    fastPtr=fastPtr->next->next;
                }else {
                    return false;
                }
            }else return true;
        }
        return false;
    }
    // 1.暴力法，用一个哈希表记录下链表的结点，遍历时先查看哈希表中有没有当前的结点，
    // 如果有则说明有环，遍历完链表后发现没有说明没有环
    // 2.快慢指针，一个指针一次走两步，一个指针一次走一步，遍历整个链表，若快指针和慢指针重合说明有环
    
};
// @lc code=end

