#include<bits/stdc++.h>

using namespace std;

//上一节内容调用 (二分插入点(有重复元素情况))
int binarySearchInsertion(vector<int>& nums, int target)
{
    int i = 0, j = nums.size() - 1;
    while (i <= j)
    {
        int m = i + (j - i) / 2;
        if (nums[m] < target)
            i = m + 1;
        else if (nums[m] > target)
            j = m - 1;
        else
            j = m - 1;
    }
    return i;
}

//本节内容
//二分查找最左一个target
int binarySearchLeftEdge(vector<int>& nums, int target)
{
    //等价于查找target的插入点
    int i = binarySearchInsertion(nums, target);
    //未找到target, 返回-1
    if (i == nums.size() || nums[i] != target)
    {
        return -1;
    }
    //找到target, 返回i
    return i;
}

