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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head or !k)
            return head;
        int len = 0;
        ListNode* curr = head;
        while (curr) {
            len++;
            curr = curr->next;
        }
        k %= len;
        if (k == 0)
            return head;
        curr = head;
        for (int i = 1; i < len - k; i++)
            curr = curr->next;
        ListNode * newhead = curr->next;
        curr->next = NULL;
        ListNode* temp = newhead;
        while(temp->next) temp = temp->next;
        temp->next = head;
        return newhead;
    }
};