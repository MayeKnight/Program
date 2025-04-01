#include <bits/stdc++.h>

using namespace std;

// 基于堆查找数组中最大的k个元素
priority_queue<int, vector<int>, greater<int>> topKHeap(vector<int> &nums, int k) // 函数topKHeap()的类型为priority_queue<int, vector<int>, greater<int>>类型(优先队列(堆)), 所以该函数最后也应返回该类型, 且这里的vector<int> &nums的 & 目的是为了引用, 当对数组nums进行改动时是直接改变数组nums本身
{
    // 初始化小顶堆, 用于返回
    priority_queue<int, vector<int>, greater<int>> heap;
    // 将数组的前k个元素入堆
    for (int i = 0; i < k; i++)
    {
        heap.push(nums[i]);
    }
    // 从第k+1个元素开始, 保持堆的长度为k
    for (int i = k; i < nums.size(); i++)
    {
        // 若当前元素大于堆顶元素, 则将堆顶元素出堆, 当前元素入堆
        if (nums[i] > heap.top())
        {
            heap.pop();
            heap.push(nums[i]);
        }
    }
    return heap;
}