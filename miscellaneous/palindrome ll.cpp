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
    bool isPalindrome(ListNode* head) {
        if (!head->next) return true;        
        ListNode *slow, *fast, *pslow;
        slow = fast = pslow = head;
     
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            pslow = slow;
            slow = slow->next;
        }
        
        if (fast && !fast->next) slow = slow->next;
        
        ListNode *p, *q, *r;
        
        if (!slow->next) {
            r = slow;
        }
        else if (!slow->next->next) {
            p = slow;
            q = p->next;
            q->next = p;
            r = q;
        } else {
            p = slow;
            q = p->next;
            r = q->next;
            while (r) {
                q->next = p;
                p = q;
                q = r;
                r = r->next;
            }
            q->next = p;
            r = q;
        }
        
        slow->next = nullptr;
        
        while (head && r) {
            if (r->val != head->val) return false;
            head = head->next;
            r = r->next;
        }
        
        return true;
    }
};
