/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int lenA = 0, lenB = 0;
        ListNode *head = headA;
        
        while (head != NULL) {
            lenA++;
            head = head->next;
        }
        
        head = headB;
        while (head != NULL) {
            lenB++;
            head = head->next;
        }
        
        int diff;
        if (lenA > lenB) {
            diff = lenA-lenB;
            while (diff--) {
                headA = headA->next;
            }            
        } 
        else {
            diff = lenB-lenA;
            while (diff--) {
                headB = headB->next;
            }            
        }
        
        while (headA!= NULL || headB != NULL) {
            if (headA == headB) {
                return headA;
            }    
            headA = headA->next;
            headB = headB->next;
        }       
               
        return NULL;        
    }
};
