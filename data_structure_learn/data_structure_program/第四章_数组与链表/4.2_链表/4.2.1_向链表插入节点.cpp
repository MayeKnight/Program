#include <bits/stdc++.h>

using namespace std;

// 定义链表节点结构体
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 在链表节点n0后插入节点p
void insert(ListNode *n0, ListNode *p)
{
    ListNode *n1 = n0->next; // 意为告诉函数存在一节点n1 且该节点是由节点n0所指向的
    p->next = n1;
    n0->next = p;
}

int main()
{
    // 初始化各个节点
    ListNode *n0 = new ListNode(1);
    ListNode *n1 = new ListNode(3);
    ListNode *p = new ListNode(9);
    // 构建节点之间的引用
    n0->next = n1;
    // 在节点n0与n1之间插入p节点
    insert(n0, p);
}