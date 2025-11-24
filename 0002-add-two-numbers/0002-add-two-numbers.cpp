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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newhead = new ListNode();
        ListNode* c1 = l1->next;
        ListNode* c2 = l2->next;
        int carry = 0;
        if ((l1->val + l2->val) > 9) {
            newhead->val = (l1->val + l2->val) - 10;
            carry = 1;
        } else
            newhead->val = l1->val + l2->val;
        ListNode* curr = newhead;
        while (c1 and c2) {
            ListNode* temp = new ListNode();
            int sum = c1->val + c2->val + carry;
            if (sum > 9) {
                temp->val = sum - 10;
                carry = 1;
            } else {
                temp->val = sum;
                carry = 0;
            }
            curr->next = temp;
            c1 = c1->next;
            c2 = c2->next;
            curr = curr->next;
        }
        while (c1) {
            ListNode* temp = new ListNode();
            int sum = c1->val + carry;
            if (sum > 9) {
                temp->val = sum - 10;
                carry = 1;
            } else {
                temp->val = sum;
                carry = 0;
            }
            curr->next = temp;
            c1 = c1->next;
            curr = curr->next;
        }
        while (c2) {
            ListNode* temp = new ListNode();
            int sum = c2->val + carry;
            if (sum > 9) {
                temp->val = sum - 10;
                carry = 1;
            } else {
                temp->val = sum;
                carry = 0;
            }
            curr->next = temp;
            c2 = c2->next;
            curr = curr->next;

        }
        if (carry) {
            ListNode* temp = new ListNode();
            temp->val = 1;
            curr->next = temp;
        }
        return newhead;
    }
};