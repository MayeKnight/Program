#include <iostream>
using namespace std;

typedef char ElementType;

struct Node
{
    ElementType data;
    Node *next;
};

struct Queue
{
    Node *front;
    Node *rear;
};

// 初始化链队列
void InitQueue(Queue &q)
{
    q.front = q.rear = new Node; // 创建头结点
    q.front->next = nullptr;     // 头结点的指针域置为空
    cout << "成功建立链队列！" << endl;
}

// 入队操作
void EnQueue(Queue &q, ElementType e)
{
    Node *newNode = new Node; // 创建新节点
    newNode->data = e;        // 设置数据域
    newNode->next = nullptr;  // 新节点的指针域置为空
    q.rear->next = newNode;   // 将新节点加入到队尾
    q.rear = newNode;         // 更新队尾指针
}

// 出队操作
int DeQueue(Queue &q, ElementType &e)
{
    if (q.front->next == nullptr)
    {
        return -1; // 队列为空
    }
    Node *temp = q.front->next; // 获取队头节点
    e = temp->data;             // 获取队头元素
    q.front->next = temp->next; // 更新队头指针
    if (q.front->next == nullptr)
    {
        q.rear = q.front; // 如果队列为空，更新队尾指针
    }
    delete temp; // 释放节点空间
    return 0;    // 成功
}

int main()
{
    Queue q;
    InitQueue(q);

    // 入队操作
    for (char c = 'A'; c <= 'E'; c++)
    {
        EnQueue(q, c);
    }

    // 显示队列内容
    cout << "当前队列内容：";
    Node *current = q.front->next;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    // 出队操作
    char dequeuedElement;
    while (DeQueue(q, dequeuedElement) != -1)
    {
        cout << "出队元素：" << dequeuedElement << endl;
    }

    return 0;
}