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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if (!head) return NULL;
        
        ListNode *p, *p1, *p2;
        
        p = new ListNode(head->val);
        
        p1 = p;
        
        p2 = head;
        
        for (p2; p2 != NULL; p2 = p2->next) {
            if (p2->val != p1->val) {
                p1 -> next = new ListNode (p2->val);
                p1 = p1 -> next;
            }
        }
        
        return p;
    }
};
