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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(-5001);
        dummy->next = head;
        ListNode* cur = head;
        ListNode* temp = new ListNode(-5001);
        ListNode* aft = head;
        ListNode* aft2 = head;
        ListNode* rec = temp;

        while (cur->next != nullptr) {
            if (cur->val <= cur->next->val) {
                cur = cur->next;
            }
            else {
                aft = cur->next;
                cur->next = cur->next->next;
                aft->next = nullptr;  //将从原链表摘除的节点"挂到"新链表(或暂存区域)前, 必须要将其 'next'指针置为 'nullptr', 切断与旧链表的所有联系, 否则会因交叉引用(同一个节点同时存在于两个链表中), 内存错误(在释放链表时, 同一块内存被可能被释放两次('double free'), 或访问已释放内存('heap-use-after-free'))等原因而出现报错. 
                rec->next = aft;
                rec = rec->next;
            }
        }

        cur = dummy;
        rec = temp;
        while (cur->next != nullptr && rec->next != nullptr) {
            if (cur->next->val < rec->next->val) {
                cur = cur->next;
            }
            else {
                aft = cur->next;
                aft2 = rec->next->next;
                rec->next->next = nullptr;
                cur->next = rec->next;
                cur->next->next = aft;
                rec->next = aft2;
                cur = dummy;
            }
        }

        if (rec->next != nullptr) {
            cur->next = rec->next;
        }
        return dummy->next;
    }
};

//本题使用了 "在解决较为复杂的链表类问题时, 若感到指针绕不清、边界难把控, "可考虑在纸上画图模拟链表的处理过程". 通过将抽象的指针转化为可视化的箭头移动, 能直观地看到节点如何断开与连接, 从而有效避免断链和边界错误."的解题策略.
//实质上本题可以用链表插入排序模板作答.





























// class Solution {
// public:
//     ListNode* insertionSortList(ListNode* head) {
//         ListNode* dummy = new ListNode(0);
//         ListNode* cur = head;
//         dummy->next = head;

//         ListNode* temp = new ListNode(0);
//         ListNode* cur2 = temp;

//         while (cur->next != nullptr) {
//             if (cur->val <= cur->next->val) {
//                 cur = cur->next;
//             }
//             else {
//                 cur2->next = cur->next;
//                 cur->next = cur->next->next;
//                 cur = cur->next;
//                 cur2 = cur2->next;
//             }
//         }

//         cur = dummy->next;
//         int cnt = 0;
//         while (temp->next != nullptr) {
//             while (cur != nullptr) {
//                 if (temp->next->val >= cur->val) {
//                     cur->next = temp->next;
//                     temp->next = temp->next->next;
//                     cnt = 1;
//                     break;
//                 }
//                 else {
//                     cur = cur->next;
//                 }
//             }
//             cur = dummy->next;
//         }
//         return dummy->next;
//     }
// };