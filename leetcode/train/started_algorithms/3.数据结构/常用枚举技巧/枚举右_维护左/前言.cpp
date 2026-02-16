常用枚举技巧
算法策略中的"枚举法"(enumeration), 是一种解决问题的思路, 意思是:
枚举 = 遍历、穷举、诸葛尝试

1.枚举右, 维护左
在这个算法技巧中, "枚举右"是指循环遍历右边的元素
对于双变量问题, 例如两数之和, ai + aj = t, 可以枚举右边的aj, 转换成单变量问题, 也就是在aj左边查找是否有ai = t - aj, 这可以用哈希表维护
这个技巧叫做枚举右, 维护左.
例:下述为一用哈希表维护的例子
//问题: 找出数组中的两个数, 使他们的和等于目标值t
vector<int> nums = { 2, 7, 11, 15 };
int t = 9;

//使用"枚举右, 维护左"策略
unordered_map<int, int> hashMap;  //值 - 索引(数组下标)

for (int j = 0; j < nums.size(); j++) {  //这里就是"枚举右", 遍历右边的元素
    int complement = t - nums[j];  //需要查找的数

    //在左边(已经遍历过的部分)查找
    if (hashMap.find(complement) != hashMap.end()) {  //如果在hashMap能找到compldment, 则return
        //找到了解
        return { hashMap[complement], j }; //找到, 则返回两个索引(数组下标)
    }

    //"维护左", 将当前数和索引存入哈希表
    hashMap[nums[j]] = j;
}

Note:不一定要用哈希表维护, 主体是"枚举右, 维护左"的思想



