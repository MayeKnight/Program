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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cur = head;
        ListNode* nxt = head;
        while (cur->next != nullptr) {
            nxt = cur->next;
            cur->next = new ListNode(gcd(cur->val, nxt->val));
            cur->next->next = nxt;
            cur = nxt;
        }
        return head;
    }
};