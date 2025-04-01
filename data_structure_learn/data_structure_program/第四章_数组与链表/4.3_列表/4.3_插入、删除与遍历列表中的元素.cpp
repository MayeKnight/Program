#include <bits/stdc++.h>

using namespace std;

int main()
{ // 初始化列表(动态数组vector)
    // 无初始值初始化
    vector<int> nums1;
    // 有初始值初始化
    vector<int> nums2 = {1, 2, 3, 4, 5};

    // 访问元素
    int num = nums2[1];
    // 更新元素
    nums2[1] = 6;

    // 插入与删除元素
    // 清空列表
    nums2.clear();
    // 在尾部添加元素
    nums2.push_back(1); // 尾部添加元素, 值为1
    nums2.push_back(3);
    nums2.push_back(2);
    nums2.push_back(5);
    nums2.push_back(4);

    // 中间插入元素
    nums2.insert(nums2.begin() + 3, 6); // 在索引3处插入数字6
    // 删除元素
    nums2.erase(nums2.begin() + 3); // 删除索引3处的元素, erase有抹去, 擦掉, 删除的意思

    // 通过索引遍历列表
    int count = 0;
    for (int i = 0; i < nums2.size(); i++) // nums2.size()为列表(动态数组)nums2的大小, 常规for循环
    {
        count += nums2[i];
    }

    // 直接遍历列表元素
    count = 0;
    for (int num : nums2) // 增强型for循环(也称为'for-each'循环), 用于 遍历一个名为nums2的集合(通常是一个数组或列表), 其中'int num'是一个循环变量, 它在每次迭代时会被赋值为'nums2'中的下一个元素, 这个循环会遍历'nums2'中的每一个元素, 直到所有元素都被访问过
    {
        count += num; // 这行代码的作用是将当前的num值加到count变量中
    }

    cout << count << endl;
}