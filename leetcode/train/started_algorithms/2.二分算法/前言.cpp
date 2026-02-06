#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

//返回数组中第一个>=target的数的位置
//闭区间，左闭右开区间，开区间
//闭区间[left, right] 如区间为0到5，left初始化为0, right初始化为5 (len(nums) == 6, 故6-1 = 5)
ll lower_bound(vector<int>& nums, ll target) {
    ll left = 0;
    ll right = nums.size() - 1; //闭区间[left, right]
    while (left <= right) {//区间不为空
        //mid = left + (right - left) / 2;  这样写可以避免溢出
        mid = (left + right) / 2;
        if (nums[mid] < target)
            left = mid + 1;  //[mid + 1, right]
        else
            right = mid - 1; //[left, mid - 1]
    }
    return left;
}

//左闭右开区间[left, right) 如区间为0到5，left初始化为0, right初始化为6 
ll lower_bound2(vector<int>& nums, ll target) {
    ll left = 0;
    ll right = nums.size(); //这里right指向n, 即指向len(nums), 表示左闭右开区间[left, right)
    while (left < right) {//区间不为空, 即left == right时左闭右开区间就是空的了，退出循环
        //mid = left + (right - left) / 2;  这样写可以避免溢出
        mid = (left + right) / 2;
        if (nums[mid] < target)
            left = mid + 1;  //[mid + 1, right)
        else
            right = mid; //[left, mid)
    }
    return left;  //这里return left 或 return right 均可
}

//开区间(left, right) 如区间为0到5，left初始化为-1, right初始化为6 
ll lower_bound3(vector<int>& nums, ll target) {
    ll left = -1;
    ll right = nums.size(); //这里right指向n, 即指向len(nums), 表示左闭右开区间[left, right)
    while (left + 1 < right) {//区间不为空, 即left + 1 == right时区间就是空的了，退出循环
        //mid = left + (right - left) / 2;  这样写可以避免溢出
        mid = (left + right) / 2;
        if (nums[mid] < target)
            left = mid;  //(mid + 1, right)
        else
            right = mid; //(left, mid - 1)
    }
    return left;  //答案为return right
}

//由此可见lower_bound3这种写法是不需要做加一减一的，比较方便
//三种写法喜欢哪种写法就用哪种

//上面的lower_bound()所求为 >= taregt的下标
//若问 > ,则可以视为 >= target + 1  (在数组中都是整数是可以用的),  lower_bound(nums, target + 1)
//若问 < ,则可以视为 (>= target) - 1   (即大于等于taregt的数的左边的那个数),  lower_bound(nums, target) - 1
//若问 <=, 则可以视为 (> target) - 1   (即大于target的数的左边的那个数), 即 (>= target + 1) - 1,  lower_bound(nums, target + 1) - 1
//因此这四种类型均可以用 lower_bound() 解决


//对于lower_bound(), 若问 >=target, 而数组中所有数均小于taregt, 此时left == len(nums);

//个人常用lower_bound()






