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
        int cnt=0;
        ListNode* node=head;
        while(cnt<k) {
            if(node){
                node=node->next;
                cnt++;
            }else {
                return head;
            }
        }
        ListNode* pre=reverseKGroup(node,k);
        while(cnt>0) {
            ListNode* secondNode=head->next;
            head->next=pre;
            pre=head;
            head=secondNode;
            cnt--;
        }
        return pre;
        
    }
    // 1. 用数组保存结点后进行逆转
    // 2. 递归法 和两两逆转的那个差不多
    // 3. 迭代法 和两两逆转的那个差不多
};
// @lc code=end

