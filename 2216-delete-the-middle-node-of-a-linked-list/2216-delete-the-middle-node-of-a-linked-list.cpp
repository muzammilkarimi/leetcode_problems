/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head or  !head->next) return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* slow_pre=NULL;
        while(fast and fast->next){
            slow_pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        slow_pre->next=slow->next;
        return head;
    }
};