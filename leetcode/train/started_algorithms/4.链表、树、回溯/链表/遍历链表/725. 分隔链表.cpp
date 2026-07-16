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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int cnt = 0;
        vector<ListNode*> ans;
        ListNode* cur = head;
        ListNode* pre = head;
        while (cur != nullptr) {
            cnt++;
            cur = cur->next;
        }
        int div = cnt / k, mod = cnt % k;
        cur = head;
        ans.push_back(head);
        while (cur != nullptr) {
            if (mod > 0) {
                for (int i = 0; i < div; i++) {
                    cur = cur->next;
                }
                pre = cur->next;
                cur->next = nullptr;
                cur = pre;
                ans.push_back(cur);
                mod--;
            }
            else {
                for (int i = 0; i < (div - 1); i++) {
                    cur = cur->next;
                }
                pre = cur->next;
                cur->next = nullptr;
                cur = pre;
                ans.push_back(cur);
            }
        }
        ans.resize(k);
        return ans;
    }
};