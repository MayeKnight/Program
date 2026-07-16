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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* cur = head;
        vector<int> res;
        int cnt = 1, min = INT_MAX, max = INT_MIN;
        while (cur->next->next != nullptr) {
            if ((cur->next->val > cur->val && cur->next->val > cur->next->next->val) || (cur->next->val < cur->val && cur->next->val < cur->next->next->val)) {
                res.push_back(cnt);
            }
            cnt++;
            cur = cur->next;
        }
        if (res.size() < 2) {
            return { -1, -1 };
        }
        for (int i = 0; i < res.size() - 1; i++) {
            min = ranges::min(res[i + 1] - res[i], min);
        }
        max = res[res.size() - 1] - res[0];
        return { min, max };
    }
};

