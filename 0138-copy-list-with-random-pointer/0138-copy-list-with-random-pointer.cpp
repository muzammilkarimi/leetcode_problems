/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node* curr = head;
        Node* newhead=NULL;
        Node* prev=NULL;
        unordered_map<Node*,Node*> mapping;
        while(curr){
            Node* temp=new Node(curr->val);
            mapping[curr]=temp;
            if(!newhead) {
                newhead=temp;
                prev=newhead;
            }
            else {
                prev->next=temp;
                prev=temp;
            }
            curr=curr->next;
        }
        // fill random pointer
        curr=head;
        Node* newcurr=newhead;
        while(curr){
            if(!curr->random) newcurr->random=NULL;
            else newcurr->random=mapping[curr->random];
            curr=curr->next;
            newcurr=newcurr->next;
        }
        return newhead;

        
    }
};