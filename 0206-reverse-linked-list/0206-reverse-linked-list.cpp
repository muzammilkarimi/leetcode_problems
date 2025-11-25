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
    ListNode* reverseList(ListNode* head) {
        if (!head or !head->next)
            return head;
        ListNode* newhead = reverseList(head->next);
        ListNode* first = head->next;
        first->next = head;
        head->next = NULL;
        return newhead;
        // if(head==NULL) return head;
        // ListNode *curr=head;
        // ListNode *prev=NULL;
        // while(curr){
        //     ListNode * temp = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = temp;
        // }
        // return prev;
    }
};