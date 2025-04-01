#include <bits/stdc++.h>

using namespace std;

int main()
{
    // 初始化双向队列
    deque<int> deque1;

    // 元素入队
    deque1.push_back(2); // 添加至队尾
    deque1.push_back(5);
    deque1.push_back(4);
    deque1.push_front(3); // 添加至队首
    deque1.push_front(1);

    // 访问元素
    int front = deque1.front(); // 访问队首元素
    int back = deque1.back();   // 访问队尾元素
    cout << "the front of the deque is" << " " << front << endl;
    cout << "the back of the deque is" << " " << back << endl;

    // 元素出队
    deque1.pop_front(); // 队首元素出队
    deque1.pop_back();  // 队尾元素出队
    front = deque1.front();
    back = deque1.back();
    cout << "after that, the front of the deque is" << " " << front << endl;
    cout << "after that, the back of the deque is" << " " << back << endl;

    // 获取双向队列长度
    int size = deque1.size();
    cout << "the size of the deque1 is" << " " << size << endl;

    // 判断双向队列是否为空
    bool empty = deque1.empty();
    cout << empty << endl;
}