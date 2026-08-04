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
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    ListNode* reverseList(ListNode* head) {
        //1.终止条件: 空链表只有一个节点, 直接返回.
        if (head == nullptr || head->next == nullptr) return head;

        //2.递归反转子链表 (head->next 及其之后的所有节点)
        //假设它返回了反转后的新头节点
        ListNode* newNode = reverseList(head->next);

        //3.归的过程:调整指针, 把当前节点接到子链表末尾
        head->next->next = head;  //让下一个节点指向自己
        head->next = nullptr;     //断开当前节点的原 next, 防止成环 
        return newNode;           //返回新头节点(原链表的尾节点)
    }
};