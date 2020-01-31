//- [Linked List Cycle I（环形链表）](https://leetcode-cn.com/problems/linked-list-cycle/)
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
    bool hasCycle(ListNode *head) {
        if(head==NULL or head->next==NULL)
            return false;
        ListNode* p1=head,*p2=head;
        do{
            p1=p1->next;
            p2=p2->next->next;
        }
        while(p1 and p2 and p2->next and p1!=p2);
        if(p1==p2){
            return true;
        }
        return false;
    }
};
int main(){

    return 0;
}