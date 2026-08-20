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
    ListNode* removeNodes(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode* nextNode = removeNodes(head->next);

        if (nextNode && head->val < nextNode->val) {
            return nextNode;
        }
        else {
            head->next = nextNode;
            return head;
        }
    }
};




























// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* removeNodes(ListNode* head) {
//         ListNode* cur = head;
//         vector<int> res;
//         vector<int> srt;
//         while (cur != nullptr) {
//             res.push_back(cur->val);
//             srt.push_back(cur->val);
//             cur = cur->next;
//         }
//         ranges::sort(srt.begin(), srt.end(), greater<int>());
//         int cnt = 0;
//         vector<int> ans;
//         for (int i = 0; i < res.size(); i++) {
//             if (res[i] == srt[cnt]) {
//                 ans.push_back(res[i]);
//                 cnt++;
//             }
//         }
//         ListNode* ret = new ListNode(ans[0]);
//         ListNode* cur1 = ret;
//         for (int i = 1; i < ans.size(); i++) {
//             cur1->next = new ListNode(ans[i]);
//             cur1 = cur1->next;
//         }
//         return ret;
//     }
// };