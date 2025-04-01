#include <bits/stdc++.h>

using namespace std;

int main()
{
    // 初始化堆
    // 初始化小顶堆
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // 初始化大顶堆
    priority_queue<int, vector<int>, less<int>> maxHeap;

    // 元素入堆
    maxHeap.push(1);
    maxHeap.push(3);
    maxHeap.push(2);
    maxHeap.push(5);
    maxHeap.push(4);

    // 获取堆顶元素
    int top = maxHeap.top();
    cout << "the top of the maxHeap is" << " " << top << endl;

    // 堆顶元素出堆
    // 出队元素会形成一个从大到小的序列
    maxHeap.pop(); // 5
    maxHeap.pop(); // 4
    maxHeap.pop(); // 3
    maxHeap.pop(); // 2
    maxHeap.pop(); // 1

    // 获取堆大小
    int size = maxHeap.size();
    cout << "the size of the maxHeap is" << " " << size << endl;

    // 判断堆是否为空
    bool isEmpty = maxHeap.empty();
    cout << isEmpty << endl;

    // 输入列表并建堆
    vector<int> input{1, 3, 2, 5, 4};
    priority_queue<int, vector<int>, greater<int>> minHeap1(input.begin(), input.end()); // minHeap被声明过了, 所以这里声明minHeap1
}