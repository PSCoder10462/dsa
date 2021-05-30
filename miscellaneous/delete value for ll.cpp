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
    ListNode* removeElements(ListNode* head, int val) {
        
        while (head && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        
        if (!head) return NULL;

        
        for (ListNode* ptr = head; ptr && ptr->next!=NULL; ptr=ptr->next) {
            while (ptr && ptr->next && val == ptr->next->val) {
                ListNode* temp = ptr->next;
                ptr->next = ptr->next->next;
                delete temp;
            }
        } 
        
        return head;
    }
};
