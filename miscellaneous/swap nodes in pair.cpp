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
        if (!head or !head->next) return head;
        
        
        // swapping first two
        ListNode *a, *b, *c = NULL;
        a = head; b = a->next;
        a->next = b->next;
        b->next = a;
        head = b;
        
        c = a;
        a = a->next;
        
        if (a) {
            b = a->next;
        } else b = nullptr;
        
        while (b) {
            
            c->next = b;
            a->next = b->next;
            b->next = a;
            
            c = a;
            a = a->next;
            
            if (a) {
                b = a->next;
            } else b = nullptr;
            
        }
        
        return head;
    }
};
