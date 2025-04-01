#include <bits/stdc++.h>

using namespace std;

int main()
{
    // 初始化哈希表
    unordered_map<int, string> map; // 这里是初始化了一个空的哈希表map, 键类型为int, 值类型为string.

    // 添加操作, 在哈希表中添加键值对(key, value)
    map[12836] = "小哈";
    map[15937] = "小啰";
    map[16750] = "小算";
    map[13276] = "小法";
    map[10583] = "小鸭";

    // 查询操作, 向哈希表中输入键key, 得到值value.
    string name = map[15937];
    cout << "name is" << " " << name << endl;

    // 删除操作, 在哈希表中删除键值对(key, value)
    map.erase(10583);

    // 遍历哈希表
    // 遍历键值对 key->value
    for (auto kv : map) //'auto'时C++11引入的一种类型推导关键字, 用于自动推导变量的类型, 从而简化代码并提高可读性, 并且这里'kv'时一个常用的命名约定, 通常代表"key-value"(键值对). 在遍历哈希表或映射(如std::unordered_map或std::map)时, 每个元素都是一个键值对, 'kv'这个变量名便于开发者理解其含义
    {
        cout << kv.first << "->" << kv.second << endl; // kv.first即当前元素(键值对)的键key, kv.second即当前元素(键值对)的值value. 两者是'std::pair'类型的成员, 'std::pair'时一个标准库模板类, 用于存储两个相关的值
    }

    // 使用迭代器遍历 key->value
    for (auto iter = map.begin(); iter != map.end(); iter++) //'iter'是一个迭代器(iterator), 用于遍历C++中的容器(如std::unordered_map或std::map), 迭代器是一种对象, 他提供了一种统一的方式访问容器中的元素, 而不需要关心容器的具体实现细节, 其中'map.begin()'返回一个指向容器第一个元素的迭代器. auto自动推导'iter'的类型
    {
        cout << iter->first << "->" << iter->second << endl; // iter->first即访问当前元素(键值对)的键key, iter->second即访问当前元素(键值对)的值value
    }
}