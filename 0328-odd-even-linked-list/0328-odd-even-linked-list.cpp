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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL or head->next==NULL) return head; 
        ListNode* oddhead=head;
        ListNode* evenhead=head->next;
        ListNode* temp1=oddhead;
        ListNode* temp2=evenhead;
        while(temp2 and temp2->next ){
            temp1->next=temp2->next;
            temp2->next=temp2->next->next;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        temp1->next=evenhead;
        return oddhead;

        
    }
};