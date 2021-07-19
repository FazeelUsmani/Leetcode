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

ListNode* reverseLL(ListNode* head){
    if (head == NULL)
        return head;
    ListNode *prev = NULL, *next1, *curr = head;
    while (curr != NULL){
        next1 = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next1;        
    }
    return prev;
}

class Solution {
public:
    void reorderList(ListNode* head) {
        
        if (!head || !head->next)
            return;
        
        ListNode *slow=head, *fast=head, *prev;
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev = slow->next;
        slow->next = NULL;
        ListNode *l2 = reverseLL(prev);
        ListNode *l1 = head;
        
        ListNode *temp = l1;
                
        while (l2 && l1){
            
            l1 = l1->next;
            temp->next = l2;
            temp = temp->next;
            
            l2 = l2->next;
            temp->next = l1;                 
            temp = temp->next;
        }
        
       
    }
};
