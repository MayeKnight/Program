#include <bits/stdc++.h>

using namespace std;

int main()
{
    // 初始化队列
    queue<int> queue1;

    // 元素入队
    queue1.push(1);
    queue1.push(3);
    queue1.push(2);
    queue1.push(5);
    queue1.push(4);

    // 访问队首元素
    int front = queue1.front();
    cout << "the front of queue is" << " " << front << endl;

    // 元素出队
    queue1.pop();
    front = queue1.front();
    cout << "after that, the front of queue is" << " " << front << endl;

    // 获取队列长度
    int size = queue1.size();
    cout << "the size of queue1 is" << " " << size << endl;

    // 判断队列是否为空
    bool empty = queue1.empty();
    cout << empty << endl; // 输出0则队列不空, 输出1队列为空
}