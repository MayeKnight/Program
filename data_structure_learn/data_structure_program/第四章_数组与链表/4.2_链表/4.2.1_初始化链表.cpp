#include <bits/stdc++.h>

using namespace std;

// 链表节点结构体
struct ListNode
{
    int val;                                   // 节点值
    ListNode *next;                            // 指向下一节点的指针
    ListNode(int x) : val(x), next(nullptr) {} // 构造函数, 用于初始化对象, 给对象成员变量赋初值, 使其在一个合理的初始状态
};

int main()
{
    // 初始化链表 1 -> 3 -> 2 -> 5 -> 4, 其中 1, 3, 2, 5, 4为节点对象的值, -> 为节点对象的指向下一个节点的引用(C++中为指针)
    // 初始化各个节点
    ListNode *n0 = new ListNode(1); // 初始化头结点n0, 并将该节点对象的值设为1, 且我们通常将头结点当做链表的代称, 则该代码中的链表可记作链表n0
    ListNode *n1 = new ListNode(3);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(5);
    ListNode *n4 = new ListNode(4);
    // 构建节点之间的引用
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
}