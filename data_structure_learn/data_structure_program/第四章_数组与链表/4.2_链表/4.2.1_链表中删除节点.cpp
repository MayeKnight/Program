#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void remove(ListNode *n0)
{
    if (n0->next == nullptr)
        return;
    ListNode *p = n0->next; // 告知函数节点n0会指向一节点p, p又指向n1, 即n0->p->n1.
    ListNode *n1 = p->next;
    n0->next = n1; // 执行删除操作, 尽管删除完成后p仍指向n1, 但实际上遍历此链表已经无法访问到p, 这意味着p已经不再属于该链表了
    // 释放内存 (释放p所占内存)
    delete p;
}

int main()
{
    // 初始化节点
    ListNode *n0 = new ListNode(1);
    ListNode *n1 = new ListNode(2);
    ListNode *n2 = new ListNode(3);
    // 构建节点之间的引用
    n0->next = n1;
    n1->next = n2;
    // 执行删除操作
    remove(n1);
}
