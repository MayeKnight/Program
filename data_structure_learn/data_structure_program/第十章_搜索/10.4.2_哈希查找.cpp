#include<bits/stdc++.h>

using namespace std;

vector<int> twoSumHashTable(vector<int> nums, int target)
{
    int size = nums.size();
    //辅助哈希表, 空间复杂度为O(n)
    unordered_map<int, int> dic;
    //单层循环, 时间复杂度为O(n)
    for (int i = 0; i < size; i++)
    {
        if (dic.find(target - nums[i]) != dic.end())  //即查找哈希表中是否存在target - nums[i], 若存在返回对应两个索引
        {
            return { dic[target - nums[i]], i };
        }
        dic.emplace(nums[i], i);  //.emplace是C++ STL中 unordered_map 和其他容器, 如 map, set等提供的一个成员函数, 它的主要作用是直接在容器中构造元素, 而不是创建一个对象再插入. 这种方式可以提高性能, 尤其是在需要存储复杂对象时.
    }
    return {};
}