#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> nums1 = {6, 7, 8, 9};

    // 将列表nums1拼接到nums后
    nums.insert(nums.end(), nums1.begin(), nums1.end());

    // 遍历列表验证下, 遍历操作详见 4.3_插入、删除与遍历列表中的元素.cpp
    for (int num : nums)
    {
        cout << num;
    }
    return 0;
}