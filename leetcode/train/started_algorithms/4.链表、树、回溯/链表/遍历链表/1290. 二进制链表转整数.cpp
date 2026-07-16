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
    int getDecimalValue(ListNode* head) {
        ListNode* cur;
        string res;
        cur = head;
        while (cur != nullptr) {
            res += (cur->val % 2 == 0) ? '0' : '1';
            cur = cur->next;
        }
        return stoi(res, nullptr, 2);
    }
};