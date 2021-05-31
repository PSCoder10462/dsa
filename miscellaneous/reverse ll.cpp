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
    ListNode* reverseList(ListNode* head) {
        // nullptr or single node
        if (!head || !head->next) return head;
        
        // two node
        if (!head->next->next) {
            ListNode* ptr = head->next;
            ptr->next = head;
            head->next = nullptr;
            return ptr;
        }
        
        
        ListNode *p1 = head, *p2 = head->next, *p3 = p2->next;
        
        while (p3) {
            
            p2->next = p1;
            
            p1 = p2;
            p2 = p3;
            
            p3 = p3->next;
            
        }
        
        p2 -> next = p1;
        
        head->next = nullptr;
        
        return p2;
        
    }
};
