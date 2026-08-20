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
    ListNode* partition(ListNode* head, int x) {
        ListNode* res = new ListNode(0);
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        ListNode* pre = dummy;
        ListNode* rec = dummy;
        ListNode* cur1 = res;

        if (head == nullptr) return head;

        while (cur->next != nullptr) {
            if (cur->next->val >= x) {
                rec = cur->next;
                cur->next = cur->next->next;
                cur1->next = rec;
                rec->next = nullptr;
                cur1 = cur1->next;
            }
            else {
                cur = cur->next;
            }
        }

        cur->next = res->next;
        return dummy->next;
    }
};