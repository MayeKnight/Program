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

// 层序遍历(广度优先搜索, BFS)
vector<int> levelOrder(TreeNode* root) // 函数levelOrder的类型为vector<int>, 则其最后应返回一个int类型的vector(列表)
{
    // 初始化队列, 加入根节点 (广度优先遍历通常借助"队列"来实现. 队列遵循"先进先出"的规则, 而广度优先遍历则遵循"逐层推进"的规则, 两者背后的思想是一致的)
    queue<TreeNode*> queue1; // 初始化一个类型为TreeNode * 的队列queue1, 用于保存节点
    queue1.push(root);

    // 初始化一个列表, 用于保存遍历序列, 因为该函数目的是要返回一个int类型的vector(列表)
    vector<int> vec;
    while (!queue1.empty()) // 若队列queue1非空则执行循环体
    {
        TreeNode* node = queue1.front(); // 取以节点node等于queue1的队首元素(节点)
        queue1.pop();                    // 队列出队
        vec.push_back(node->val);        // 保存节点值
        if (root->left != nullptr)
            queue1.push(root->left); // 左子节点入队
        if (root->right != nullptr)
            queue1.push(root->right); // 右子节点入队
    }
    return vec;
}

int main()
{
    // 初始化二叉树
    // 初始化节点
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n7 = new TreeNode(7);

    // 构建节点之间的引用(指针)
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    n3->right = n7;

    // // 调用层序遍历并输出结果
    // for (int num : levelOrder(n1)) // 范围'for'循环
    // {
    //     cout << num;
    // }
}