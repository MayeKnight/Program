#include <bits/stdc++.h>

using namespace std;

// 二叉树结构体
struct TreeNode
{
    int val;                                                   // 节点值
    TreeNode* left;                                            // 左子节点指针
    TreeNode* right;                                           // 右子节点指针
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // 构造函数, 用于初始化对象, 给对象成员变量赋初值, 使其在一个合理的初始状态
};

int main()
{
    // 初始化二叉树
    // 初始化节点
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);

    // 构建节点之间的引用(指针)
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;

    // 插入与删除节点
    TreeNode* p = new TreeNode(0);

    // 在 n1->n2 中间插入节点p
    n1->left = p;
    p->left = n2;

    // 删除节点p
    n1->left = n2;

    // 释放内存
    delete p;
}