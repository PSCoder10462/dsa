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
        ListNode *p1 = headA, *p2 = headB;
        bool ra, rb;
        ra = rb = false;
        while (!(ra && rb)) {
            if (! p1 -> next) {
                p1 = headB;
                ra = true;
            } else p1 = p1->next;
            if (!p2->next){
                p2 = headA;
                rb = true;
            } else p2 = p2->next;
        }
        
        while (p1 && p2) {
            if (p1 == p2) return p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        return NULL;
    }
};
