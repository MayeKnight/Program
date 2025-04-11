#include<bits/stdc++.h>

using namespace std;

//二分查找插入点(无重复元素)
int binarySearchInsertionSimple(vector<int>& nums, int target)
{
    int i = 0, j = nums.size() - 1;  //初始化双闭区间[0, n-1]
    while (i <= j)
    {
        int m = (i + (j - i) / 2);  //计算中点索引m
        if (nums[m] < target)
            i = m + 1;  //target在区间[m+1,j]中
        else if (nums[m] > target)
            j = m - 1; //target在区间[i,m-1]中
        else
            return m; //找到target, 返回插入点m
    }
    //未找到target, 返回插入点i
    return i;
}