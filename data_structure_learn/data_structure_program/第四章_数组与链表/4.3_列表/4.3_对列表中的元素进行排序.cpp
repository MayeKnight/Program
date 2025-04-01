#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> nums1 = {2, 4, 1, 3, 5};
    // 排序列表
    sort(nums1.begin(), nums1.end());

    // 遍历输出验证
    for (int num : nums1)
    {
        cout << num;
    }

    return 0;
}