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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head, *ptr;
        head = ptr = NULL;
        
        ListNode *p1 = l1, *p2 = l2;
        
        while ( p1 && p2 ) {
            
            if (p1->val <= p2->val) {
                
                if (!head) {
                
                    head = new ListNode(p1->val);
                    ptr = head;
            
                } else {
                    
                    ptr -> next = new ListNode (p1 -> val);
                    ptr = ptr->next;
                
                }
            
                p1 = p1->next;
            
            } else {
                
                if (!head) {
                    head = new ListNode(p2->val);
                    ptr = head;
                } else {
                    ptr -> next = new ListNode (p2 -> val);
                    ptr = ptr->next;
                }
                
                p2 = p2->next;
            
            }
        }
        
        while (p1) {
             if (!head) {
                    head = new ListNode(p1->val);
                    ptr = head;
                    
                } else {
                    ptr -> next = new ListNode (p1 -> val);
                    ptr = ptr->next;
                }
            p1 = p1->next;
        }
        
        while (p2) {
             if (!head) {
                    head = new ListNode(p2->val);
                    ptr = head;
                    
                } else {
                    ptr -> next = new ListNode (p2 -> val);
                    ptr = ptr->next;
                }
            p2 = p2->next;
        }
        return head;
    }
};
