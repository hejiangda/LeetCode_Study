/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n=0;
        for(ListNode* i=head;i!=nullptr;n++,i=i->next);

        ListNode dummy(-1);
        dummy.next=head;
        for(ListNode* prev=&dummy,*tail=head;n>=k;n-=k) {
            for(int i=1;i<k;i++) {
                ListNode* next=tail->next->next;// 保存第三个
                tail->next->next=prev->next;// 第二个指向第一个
                prev->next=tail->next;// prev 保存第二个
                tail->next=next;// 第一个指向第三个
            }
            prev=tail;
            tail=tail->next;
        }
        return dummy.next;
    }
    // 1. 用数组保存结点后进行逆转
    // 2. 递归法 先判断当前链表有没有k个结点，若没有直接返回头，若有则进行处理
    // pre=reverseKGroup(tail,k);
    // loop:
    // secondNode=head->next;
    // head->next=pre;
    // pre=head;
    // head=secondNode;
    // 
    // 3. 迭代法 先数出链表结点数，设置dummy结点用于保存新的头，循环
    // 每次逆转k个结点，首先记录第三个结点，第二个结点连第一个结点
    // 
};
// @lc code=end

