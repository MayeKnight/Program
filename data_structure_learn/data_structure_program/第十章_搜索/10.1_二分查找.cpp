#include<bits/stdc++.h>

using namespace std;

//二分查找(双闭区间)
int binarySearch(vector<int>& nums, int target)
{
    //初始化双闭区间[0, n-1], 即i, j分别指向数组首元素、尾元素
    int i = 0, j = nums.size() - 1;
    //循环, 当搜索区间为空时跳出(当i > j时为空)
    while (i <= j)
    {
        int m = (i + (j - i) / 2); //计算重点索引m
        if (nums[m] < target)  //此情况说明target在区间[m+1, j]中
            i = m + 1;
        else if (nums[m] > target)  //此情况说明target在区间[i, m-1]中
            j = m - 1;
        else //找到目标元素, 返回其索引
            return m;
    }
    //未找到目标元素, 返回-1.
    return -1;
}