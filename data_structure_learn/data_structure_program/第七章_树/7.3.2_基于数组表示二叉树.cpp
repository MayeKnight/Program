#include <bits/stdc++.h>

using namespace std;

// 数组表示下的二叉树类
class ArrayBinaryTree // 通常public在前, private在后, 是因为public成员通常是类的接口部分, 可以使类的使用者更容易找打可以直接调用的公共方法, 但在实际写的时候, 通常先写private, 再写public, 或者一一对照写
{
public: //'public'修饰符表示类的成员可以被任何其它代码访问。即无论是类的外部代码还是类的内部代码都可以访问'public'成员, 通常用于定义类的接口部分, 即用户可以直接调用的函数和访问的变量
    // 构造方法(构造函数), 其名称与类名相同, 没有返回值, 是用于初始化对象的特殊成员函数, 当创建对象时, 构造函数会被自动调用, 可以定义多个构造函数(函数重载), 以支持不同的初始化方式
    ArrayBinaryTree(vector<int> arr)
    {
        tree = arr; // 构造函数接受一个整数数组'arr', 并将其存储在成员变量'tree'中. 这个数组表示二叉树的节点值
    }

    // 列表容量
    int size()
    {
        return tree.size();
    }

    // 获取索引为i节点的值
    int val(int i)
    {
        if (i < 0 || i >= tree.size())
            return INT_MAX;
        return tree[i];
    }

    // 获取索引为i节点的左子节点的索引
    int left(int i)
    {
        return 2 * i + 1;
    }

    // 获取索引为i节点的右子节点的索引
    int right(int i)
    {
        return 2 * i + 2;
    }

    // 获取索引为i节点的父节点的索引
    int parent(int i)
    {
        return (i - 1) / 2;
    }

    // 层序遍历
    vector<int> levelOrder() // 函数levelOrder的类型为vector<int>, 则其最后应返回一个int类型的vector(列表)
    {
        vector<int> res; // 用于返回
        // 直接遍历数组
        for (int i; i < size(); i++)
        {
            if (val(i) != INT_MAX)
            {
                res.push_back(val(i));
            }
        }
        return res;
    }

    // 前序遍历
    vector<int> preOrder()
    {
        vector<int> res;
        dfs(0, "pre", res);
        return res;
    }

    // 中序遍历
    vector<int> inOrder()
    {
        vector<int> res;
        dfs(0, "in", res);
        return res;
    }

    // 后序遍历
    vector<int> postOrder()
    {
        vector<int> res;
        dfs(0, "post", res);
        return res;
    }

private:              //'private'修饰符表示类的成员只能在类的内部访问, 外部代码无法直接访问这些成员. 这是为了保护类的内部状态, 防止外部代码直接修改. 通常用于定义类的实现细节, 即不希望外部代码直接访问或修改的变量和函数, 通过合理使用'public'和'private', 可以有效地控制类的接口和实现, 增强代码的安全性和可维护性
    vector<int> tree; // 声明成员变量tree, 用于在创建对象时, 在构造函数中自动调用, 用于存储表示二叉树的节点值

    // 深度优先遍历, 我们可以发现, 这里在定义dfs函数是仍遵循前序遍历:根-左子节点递归-右子节点递归, 中序遍历:左子节点递归-根-右子节点递归, 后序遍历: 左子节点递归-右子节点递归-根 的原则
    void dfs(int i, string order, vector<int> &res) // vector<int> &res是一个对'vector<int>'类型的引用, 将'vector<int> &res'作为函数参数是, 传递的是对原始对象的引用. 即在函数内部对res的任何修改都会直接影响到原始的'vector'对象, 而没有创建副本. 相较于'vecotr<int> res', 当将其作为函数参数时, 传递的是该对象的副本, 即在函数内部对 res 的任何修改不会影响到原始的 vector 对象。需要复制整个 vector 的内容. vector<int> &res 是一个对 vector<int> 类型的引用，允许在函数中直接操作传入的 vector 对象，而不需要复制整个对象。这种方式提高了性能，并且使得函数能够修改传入的 vector。
    {
        // 若为空位则返回
        if (val(i) == INT_MAX)
            return;
        // 前序遍历
        if (order == "pre")
        {
            res.push_back(val(i));
        }
        dfs(left(i), order, res);
        // 中序遍历
        if (order == "in")
        {
            res.push_back(val(i));
        }
        dfs(right(i), order, res);
        // 后序遍历
        if (order == "post")
        {
            res.push_back(val(i));
        }
    }
};