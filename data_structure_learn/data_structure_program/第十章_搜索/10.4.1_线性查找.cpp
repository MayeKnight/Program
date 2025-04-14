#include<bits/stdc++.h>

using namespace std;

//方法一: 暴力枚举
vector<int> twoSumBruteForce(vector<int>& nums, int target)  //BruteForce是"暴力破解"的意思
{
    int size = nums.size();
    //两层循环, 时间复杂度为O(n^2)
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                return { i, j }; //twoSumBruteForce()函数类型为vector<int>，故也应返回一个列表
            }
        }
    }
    return {};  //若不存咱, 返回一个空列表
}
