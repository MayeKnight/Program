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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* cur1 = headA;
        ListNode* cur2 = headB;
        set<ListNode*> st;

        while (cur1 != nullptr) {
            st.insert(cur1);
            cur1 = cur1->next;
        }
        while (cur2 != nullptr) {
            if (st.find(cur2) != st.end()) {
                return cur2;
            }
            cur2 = cur2->next;
        }

        return nullptr;
    }
};