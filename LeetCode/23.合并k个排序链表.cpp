/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        return merge(lists,0,lists.size()-1);
    }
    ListNode* merge(vector<ListNode*>& lists,int left,int right) {
        if(left>right)return nullptr;
        else if(left==right)return lists[left];
        int mid=(right+left)/2;
        ListNode* l1 = merge(lists,left,mid);
        ListNode* l2 = merge(lists,mid+1,right);
        ListNode L(-1);
        ListNode* p=&L;
        while(l1 and l2) {
            if(l1->val<l2->val) {
                p->next=l1;l1=l1->next;
                if(p->next)
                    p=p->next;
            }else {
                p->next=l2;l2=l2->next;
                if(p->next)
                    p=p->next;
            }
        }
        if(l1)p->next=l1;
        if(l2)p->next=l2;
        return L.next;
        
    }
    // 1.暴力法，每次找到所有链表头结点最小的那个摘到list尾上
    // 2.分治法，把lists分成两半，分别合并，最后再合并成大链表
    // 
};
// @lc code=end

