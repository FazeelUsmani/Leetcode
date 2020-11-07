class Solution {
public:
    void helper(ListNode* l1, ListNode* l2, int& carry){
        if (l1 == NULL || l2 == NULL) return;
        helper(l1->next, l2->next, carry);
        int val = (l1->val + l2->val + carry) % 10;
        carry = (l1->val + l2->val + carry) / 10;
        l2->val = val;
        return;
    }
    int len(ListNode* head){
        int len = 0;
        ListNode* cur = head;
        while (cur != NULL){
            cur = cur->next;
            len++;
        }
        return len;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = len(l1);
        int len2 = len(l2);
        
        ListNode* dummyhead = new ListNode(0);
        ListNode* cur = dummyhead;
        int len = max(len1, len2), diff = abs(len1 - len2);
        
        ListNode* head = len1 > len2 ? l2 : l1;
        for (int i = 0; i < diff; i++){
            cur->next = new ListNode(0);
            cur = cur->next;
        }
        for (int i = diff; i < len; i++){
            cur->next = new ListNode(head->val);
            cur = cur->next;
            head = head->next;
        }
        
        int carry = 0;
        head = len1 > len2 ? l1 : l2;
        helper(head, dummyhead->next, carry);
        if (carry != 0){
            dummyhead->val = carry;
            return dummyhead;
        }
        
        return dummyhead->next;
    }
};
