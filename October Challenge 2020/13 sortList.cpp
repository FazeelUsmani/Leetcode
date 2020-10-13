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
    ListNode* sortList(ListNode* head) {
         vector<int> curr;
        while (head != NULL) {
            curr.push_back(head->val);
            head = head->next;
        }
        
        sort(curr.begin(), curr.end());
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        
        for (int x: curr){
            temp->next = new ListNode(x);            
            temp = temp->next;
        }
        
        return dummy->next;    
        
    }
};
