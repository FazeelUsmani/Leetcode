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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL)        
            return head;
                
        ListNode* temp = head->next;
        if (temp == NULL)
            return head;
        
        ListNode* nextNode = temp->next;
        
        temp->next = head;
        head->next = swapPairs(nextNode);        
        
        return temp;
    }
};
