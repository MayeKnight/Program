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
    int numComponents(ListNode* head, vector<int>& nums) {
        ListNode* cur = head;
        set<int> st;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }
        while (cur != nullptr) {
            if (st.count(cur->val)) {
                ans++;
                while (cur != nullptr && st.count(cur->val)) {
                    cur = cur->next;
                }
            }
            else {
                cur = cur->next;
            }
        }
        return ans;
    }
};