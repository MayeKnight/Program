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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* dummy1 = new ListNode(0);
        ListNode* cur = dummy;
        ListNode* reca = list1;
        ListNode* recb = list1;
        dummy->next = list1;
        int cnt = 0;

        while (cur->next != nullptr) {
            if (cnt == a) {
                reca = cur;
                cur = cur->next;
                cnt++;
            }
            else {
                cur = cur->next;
                cnt++;
            }
            if (cnt == b) {
                recb = cur->next->next;
            }
        }

        reca->next = list2;

        dummy1->next = list2;
        cur = dummy1;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = recb;

        return dummy->next;
    }
};