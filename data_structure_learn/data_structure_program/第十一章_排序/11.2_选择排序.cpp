#include<bits/stdc++.h>

using namespace std;

void selectionSort(vector<int>& nums)
{
    int n = nums.size();
    //外循环, 未排序区间为[i, n-1]
    for (int i = 0; i < n - 1; i++)
    {
        //内循环, 找到未排序区间内的最小元素
        int k = i;
        for (int j = i; i < n; j++)
        {
            if (nums[j] < nums[k])
            {
                k = j;  //记录最小元素的索引
            }
        }
        //将该最小元素与未排序区间的首个元素交换, 关于swap函数, 在Data_Structure文档中已阐述
        swap(nums[k], nums[i]);
    }
}