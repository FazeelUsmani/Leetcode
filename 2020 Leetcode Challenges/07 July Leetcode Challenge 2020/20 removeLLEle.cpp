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
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode *curr = head;
        
        if (head == NULL)
            return head;        
        
        while (curr->next != NULL){
            if (curr->next->val == val){
                curr->next = curr->next->next;
            }             
            else{
                curr = curr->next;
            }
        }
        
        if (head->val == val)
            head = head->next;
        
        return head;
    }
};
