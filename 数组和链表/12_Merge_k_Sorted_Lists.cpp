// - [Merge k Sorted Lists（合并 k 个排序链表）](https://leetcode-cn.com/problems/merge-k-sorted-lists/)
#include <bits/stdc++.h>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()<=0)
            return NULL;
        ListNode head(0);
        head.next=lists[0];
        int sz=lists.size();
        for(int i=1;i<sz;i++){
            ListNode* p=&head;
            ListNode* q=lists[i];
            if(p->next==NULL){
                p->next=q;
                continue;
            }
            while(p and p->next and q){
                if(p->next->val<=q->val ){
                    if(p->next->next==NULL){
                        p->next->next=q;
                        q=NULL;
                    }
                    else if(p->next->next->val>=q->val){
                        ListNode* tmp1=p->next->next;
                        p->next->next=q;
                        ListNode* tmp2=q->next;
                        q->next=tmp1;
                        q=tmp2;
                        p=p->next;
                    }else{
                        p=p->next;
                    }
                }
                else{
                    ListNode * tmp1=p->next;
                    p->next=q;
                    ListNode* tmp2=q->next;
                    q->next=tmp1;
                    q=tmp2;
                    p=p->next;
                }
            }


        }
        return head.next;
    }
};

int main(){

    return 0;
}