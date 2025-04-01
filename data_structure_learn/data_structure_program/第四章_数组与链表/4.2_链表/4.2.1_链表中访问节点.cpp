#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *access(ListNode *head, int index) // 其中'ListNode *access' 返回值应是一节点(ListNode)的指针或nullptr, 具体是是什么功能由所提供参数和函数体决定, 这里则是用于访问链表中的特定节点. 'ListNode *head'则是指向链表头节点的指针, 'index'则是要访问的节点的索引(从0开始)
{
    for (int i = 0; i < index; i++)
    {
        if (head == nullptr)
            return nullptr;
        head = head->next;
    }
    return head; // 循环结束后'head'将指向目标索引的节点, 如果索引有效,则返回该节点的指针; 如若超出索引范围, 返回的将是nullptr
}

int main()
{
    ListNode *n0 = new ListNode(1);
    ListNode *n1 = new ListNode(2);
    ListNode *n2 = new ListNode(3);
    n1 = n0->next;
    n2 = n1->next;
    access(n0, 2);
}