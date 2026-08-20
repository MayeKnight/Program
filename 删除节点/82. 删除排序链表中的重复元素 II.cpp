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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        ListNode* pre = dummy;
        dummy->next = head;
        set<int> st;

        while (cur->next != nullptr) {
            if (st.count(cur->next->val)) {
                while (cur->next != nullptr && st.count(cur->next->val)) {
                    cur->next = cur->next->next;
                }
                pre->next = cur->next;
                cur = pre;
            }
            else {
                st.insert(cur->next->val);
                pre = cur;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};