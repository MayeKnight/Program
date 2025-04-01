#include <bits/stdc++.h>

using namespace std;

// 二叉树结构体
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 查找节点
TreeNode *search(int num) // 函数search()类型为TreeNode * ,则应返回一个TreeNode * 类型(类型为一个节点)的变量
{
    TreeNode *cur; // 给出想要的返回对象
    // 循环查找, 超过叶节点后跳出
    while (cur != nullptr)
    {
        // 目标节点在cur的左子树中
        if (cur->val > num)
            cur = cur->left;
        // 目标节点在cur的右子树中
        else if (cur->val < num)
            cur = cur->right;
        // 找到目标节点, 跳出循环
        else
            break;
    }
    // 返回目标节点
    return cur;
}

// 插入节点
void insert(int num, TreeNode *root)
{
    // 若树为空, 则初始化根节点
    if (root == nullptr)
    {
        root = new TreeNode(num);
        return;
    }
    TreeNode *cur = root, *pre = nullptr;
    // 循环查找, 超过叶节点后跳出
    while (cur != nullptr)
    {
        // 找到重复节点, 直接返回
        if (cur->val == num)
            return;
        pre = cur;
        // 插入位置在cur的左子树中
        if (cur->val > num)
            cur = cur->left;
        // 插入位置在cur的右子树中
        else if (cur->val < num)
            cur = cur->right;
    }
    // 插入节点
    TreeNode *node = new TreeNode(num);
    if (pre->val > num)
        pre->left = node;
    else if (pre->val < num)
        pre->right = node;
}

// 删除节点
void remove(int num, TreeNode *root)
{
    // 若树为空, 直接提前返回
    if (root == nullptr)
        return;
    TreeNode *cur = root, *pre = nullptr;
    // 循环查找, 越过叶节点后跳出
    while (cur != nullptr)
    {
        // 找到待删除节点, 跳出循环
        if (cur->val == num)
            break;
        pre = cur;
        // 待删除节点在左子树中
        if (cur->val > num)
            cur = cur->left;
        // 待删除节点在右子树中
        else
            cur = cur->right;
    }
    // 若无待删除节点则直接返回
    if (cur == nullptr)
        return;
    // 子节点数量 = 0 or 1
    if (cur->left == nullptr || cur->right == nullptr)
    {
        // 当子节点数量 = 0 or 1 时, child = nullptr or 该子节点
        TreeNode *child = cur->left != nullptr ? cur->left : cur->right; // 这一行代码的意思是如果cur->left不是nullptrm 则令声明的节点child = cur->left, 否则则为cur->right, 当然, 若cur->right也为nullptr，则此时child也为nullptr, 否则不是nullptr
        // 删除节点cur
        if (cur != root)
        {
            if (pre->left == cur)
                pre->left = child;
            else
                pre->right = child;
        }
        // 若删除节点为根节点, 则重新指定根节点
        else
            root = child;
        // 释放内存
        delete cur;
    }
    // 子节点数量 = 2
    else
    {
        // 获取中序遍历中cur的下一个节点
        TreeNode *tmp = cur->right;
        while (tmp->left != nullptr)
        {
            tmp = tmp->left;
        }
        int tmpVal = tmp->val;
        // 递归删除节点tmp
        remove(tmp->val, root);
        // 用tmp覆盖cur
        cur->val = tmpVal;
    }
}