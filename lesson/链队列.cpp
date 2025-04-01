#include <iostream>
#include <string>

using namespace std;

// 数据结构定义
struct book
{
    int number;
    string name;
    float price;
};

// 单链表节点定义
struct LNode
{
    book data;
    LNode *next;
};

// 初始化函数
bool InitList_L(LNode *&L)
{
    L = new LNode;
    if (L == nullptr)
    {
        return false;
    }
    L->next = nullptr;
    return true;
}

// 插入结点函数
bool Insert_L(LNode *&L, int i, book e) // 在第i个结点之前插入结点e
{
    // 检查i的合法性
    if (i < 1)
    {
        return false;
    }

    // 找到第i-1个结点
    LNode *p = L;
    int j = 1;
    while (j < i - 1 && p->next != nullptr)
    {
        p = p->next;
        j++;
    }

    // 检查第i-1个结点是否存在
    if (p == nullptr || j < i - 1)
    {
        return false;
    }

    // 创建新结点
    LNode *s = new LNode;
    if (s == nullptr)
    {
        return false;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 获取第i个结点的函数
bool GetElem_L(LNode *L, int i, book &e)
{
    // 检查i的合法性
    if (i < 1)
    {
        return false;
    }

    // 找到第i个结点
    LNode *p = L->next;
    int j = 1;
    while (j < i && p != nullptr)
    {
        p = p->next;
        j++;
    }

    // 检查第i个结点是否存在
    if (p == nullptr || j < i)
    {
        return false;
    }

    // 获取第i个结点的数据
    e = p->data;
    return true;
}

// 查找书籍信息的函数
bool FindBook_L(LNode *L, int number, book &e)
{
    LNode *p = L->next; // 从第一个数据结点开始
    while (p != nullptr)
    {
        if (p->data.number == number) // 找到书号匹配的书籍
        {
            e = p->data;
            return true;
        }
        p = p->next;
    }
    return false; // 未找到
}

// 删除结点函数
bool Delete_L(LNode *&L, int i)
{
    // 检查i的合法性
    if (i < 1)
    {
        return false;
    }

    LNode *p = L; // 从头结点开始
    int j = 0;
    while (p != nullptr && j < i - 1) // 找到第i-1个结点
    {
        p = p->next;
        j++;
    }

    // 检查第i-1个结点是否存在
    if (p == nullptr || p->next == nullptr)
    {
        return false; // 第i个结点不存在
    }

    // 删除第i个结点
    LNode *q = p->next; // q指向要删除的结点
    p->next = q->next;  // 将第i-1个结点的next指向第i+1个结点
    delete q;           // 释放内存
    return true;
}

int main()
{
    LNode *L;
    if (InitList_L(L))
    {
        cout << "成功建立链表!!!" << endl;
        cout << "链表的头结点地址为: " << L << endl;
        cout << "链表头结点的下一个结点地址为: " << L->next << endl;

        // 插入三个结点
        book book1 = {101, "样本图书名字1", 100};
        book book2 = {202, "样本图书名字2", 200};
        book book3 = {303, "样本图书名字3", 300};

        Insert_L(L, 1, book1);
        Insert_L(L, 2, book2);
        Insert_L(L, 3, book3);

        // 删除第二个结点
        if (Delete_L(L, 2))
        {
            cout << "成功删除第2个结点!!!" << endl;
        }
        else
        {
            cout << "删除失败!!!" << endl;
        }

        // 输出链表内容
        LNode *current = L->next; // 从第一个数据结点开始
        while (current != nullptr)
        {
            cout << "书号: " << current->data.number << ", 书名: " << current->data.name << ", 价格: " << current->data.price << endl;
            current = current->next;
        }
    }
    else
    {
        cout << "建立失败!!!" << endl;
    }
    return 0;
}