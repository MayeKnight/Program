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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* pre = head;
        ListNode* cur = head->next;
        ListNode* rec = new ListNode(0);
        ListNode* cur2 = rec;
        ListNode* lst = head;

        while (pre != nullptr && cur != nullptr) {
            cur2->next = cur;
            cur2 = cur2->next;
            pre->next = cur->next;
            cur->next = nullptr;

            lst = pre;
            pre = pre->next;
            if (pre != nullptr) {
                cur = pre->next;
            }
            else {
                break;
            }
        }

        if (pre == nullptr && lst != nullptr) {
            lst->next = rec->next;
        }
        else if (pre != nullptr)
        {
            pre->next = rec->next;
        }

        return head;
    }
};