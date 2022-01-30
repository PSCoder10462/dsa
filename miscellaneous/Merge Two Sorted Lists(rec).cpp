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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 and !list2) return nullptr;
        if (list1 and !list2) return list1;
        if (!list1 and list2) return list2;
        ListNode* head = nullptr;
        if (list1->val >=list2->val) {
            head = new ListNode(list2->val);
            head -> next = mergeTwoLists(list1, list2->next);
        } else {
            head = new ListNode(list1->val);
            head -> next = mergeTwoLists(list1->next, list2);
        }
        return head;
    }
};
