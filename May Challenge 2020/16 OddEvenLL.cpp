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
        
        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return head;
        
        ListNode *prev = NULL, *h1 = head, *h2 = head->next, *ptrStart = h2;
        
        while (h1 != NULL && h2 != NULL){
            
            h1->next = h2->next;
            prev = h1;
            h1 = h1->next;
            
            if (h1 != NULL){
                h2->next = h1->next;
                h2 = h2->next;           
            }            
        }
        
        if (h1 != NULL)
            h1->next = ptrStart;
        else
            prev->next = ptrStart;
        
        return head;
    }
};
