#include <bits/stdc++.h>

using namespace std;

int main()
{
    // 初始化栈
    stack<int> stack1;

    // 元素入栈
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);

    // 访问栈顶元素
    int top = stack1.top();
    cout << "top is" << " " << top << endl; // 输出栈顶元素验证

    // 元素出栈
    stack1.pop();

    // 再次访问栈顶元素, 查看此时栈顶元素
    top = stack1.top();
    cout << "after that, top is" << " " << top << endl; // 输出栈顶元素验证

    // 获取栈的长度
    int size = stack1.size();
    cout << "the size of stack is" << " " << size << endl; // 输出栈长度

    // 判断栈是否为空
    bool empty = stack1.empty();
    cout << empty << endl; // 若empty为1, 则栈空, 若empty为0, 则栈不空
}