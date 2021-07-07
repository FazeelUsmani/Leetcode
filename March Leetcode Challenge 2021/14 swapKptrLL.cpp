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
    ListNode* swapNodes(ListNode* head, int k) {        
        
        vector<int> arr;
        while (head!= NULL) {
            arr.push_back(head->val);
            head = head->next;
        }
        swap(arr[k-1], arr[arr.size()-k]);
        
        ListNode *dummy, *newHead = new ListNode(0);
        ListNode *temp = newHead;
        
        for (int x: arr) {            
            dummy = new ListNode(x);
            temp->next = dummy;
            temp = temp->next;            
        }        
        
        return newHead->next;
    }
};
