#include <bits/stdc++.h>

using namespace std;

// 二叉树结构体
struct TreeNode
{
    int val;                                                   // 节点值
    TreeNode *left;                                            // 左子节点指针
    TreeNode *right;                                           // 右子节点指针
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // 构造函数, 用于初始化对象, 给对象成员变量赋初值, 使其在一个合理的初始状态
};

vector<int> vec;

// 由下述代码可以看出, 对于前序、中序、后序遍历, 可以通过访问优先级根节点位置确定最后三行代码的顺序, 且只需保证子树顺序不变, 为先左子树后右子树.
// 前序遍历
void preOrder(TreeNode *root)
{
    if (root == nullptr)
        return;
    // 访问优先级: 根节点 -> 左子树 -> 右子树
    vec.push_back(root->val);
    preOrder(root->left);
    preOrder(root->right);
}

// 中序遍历
void inOrder(TreeNode *root)
{
    if (root == nullptr)
        return;
    // 访问优先级: 左子树 -> 根节点 -> 右子树
    inOrder(root->left);
    vec.push_back(root->val);
    inOrder(root->right);
}

// 后序遍历
void postOrder(TreeNode *root)
{
    if (root == nullptr)
        return;
    // 访问优先级: 左子树 -> 右子树 -> 根节点
    postOrder(root->left);
    postOrder(root->right);
    vec.push_back(root->val);
}

int main()
{
    // 初始化二叉树
    // 初始化节点
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(5);
    TreeNode *n6 = new TreeNode(6);
    TreeNode *n7 = new TreeNode(7);

    // 构建节点之间的引用(指针)
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;

    // 调用前序、中序、后序遍历
    preOrder(n1);
    inOrder(n1);
    postOrder(n1);
}