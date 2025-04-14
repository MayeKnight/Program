#include<bits/stdc++.h>

using namespace std;

//上上一节内容调用 (二分插入点(有重复元素情况))
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
//二分查找最右一个target
int binarySearchRightEdge(vector<int>& nums, int target)
{
    //转化为查找最左一个target+1
    int i = binarySearchInsertion(nums, target + 1);
    //j指向最右一个target, i指向首个大于target的元素
    int j = i - 1;
    //未找到target, 返回-1
    if (j == -1 || nums[j] != target)
    {
        return -1;
    }
    //找到target, 返回索引j
    return j;
}