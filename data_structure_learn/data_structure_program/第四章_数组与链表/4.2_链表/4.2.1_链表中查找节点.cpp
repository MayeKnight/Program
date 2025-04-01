#include <bits/stdc++.h>

using namespace std;

// 链表节点结构体
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int find(ListNode *head, int target) // find函数返回值应为一int值, 这里目的是为了找到相应节点的索引, 'ListNode *head'表明应输入一头结点, 'target'是输入目标target值
{
    int index = 0;
    while (head != nullptr)
    {
        if (head->val == target) // 由链表节点结构体可知, 访问节点的值, 用head->val即可
            return index;
        head = head->next;
        index++;
    }
    return -1;
}

int main()
{
    ListNode *n0 = new ListNode(1);
    ListNode *n1 = new ListNode(2);
    ListNode *n2 = new ListNode(3);
    n1 = n0->next;
    n2 = n1->next;
    find(n0, 2);
}