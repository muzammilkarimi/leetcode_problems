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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newhead = NULL;
        ListNode* list_1 = list1;
        ListNode* list_2 = list2;
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        if (list_1->val < list_2->val) {
            newhead = list_1;
            list_1 = list_1->next;
        } else {
            newhead = list_2;
            list_2 = list_2->next;
        }
        ListNode * newcurr=newhead;
        while (list_1 and list_2) {
            if (list_1->val < list_2->val) {
                newcurr->next = list_1;
                list_1 = list_1->next;
                newcurr = newcurr->next;
            } else {
                newcurr->next = list_2;
                list_2 = list_2->next;
                newcurr = newcurr->next;
            }
        }
        if(list_1){
            newcurr->next = list_1;
            list_1 = list_1->next;
            newcurr = newcurr->next;
        }
        if(list_2){
            newcurr->next = list_2;
            list_2 = list_2->next;
            newcurr = newcurr->next;
        }
        return newhead;
    }
};