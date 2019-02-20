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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL and l2 == NULL) return NULL;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int c = 0;
        ListNode* sentinel = new ListNode(0);
        ListNode* p = sentinel;
        while(p1 != NULL || p2 != NULL) {
            int p1v = (p1) ? p1->val : 0;
            int p2v = (p2) ? p2->val : 0;
            int val = (p1v + p2v + c) % 10;
            c = (p1v + p2v + c) / 10;
            ListNode* p_next = new ListNode(val);
            p->next = p_next;
            p = p_next;
            if (p1) p1 = p1->next;
            if (p2) p2 = p2->next;
        }
        if (c != 0) {
            ListNode* p_next = new ListNode(c);
            p->next = p_next;
        }
        return sentinel->next;
    }
};