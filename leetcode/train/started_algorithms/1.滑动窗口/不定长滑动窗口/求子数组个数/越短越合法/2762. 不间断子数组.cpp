class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        //可以通过map实现, 因为map存储默认按键从小到大排序
        //.rbegin()返回指向最后一个元素的反向迭代器 (即键最大的元素的迭代器)
        //.begin()返回指向第一个元素的的迭代器 (即返回最小元素的迭代器)
        //迭代器需要通过 ->first 访问值, res.rbegin() -> first; 等价于 (*res.rbegin).first;
        map<int, int> res;
        long long ans = 0, left = 0;
        for (int i = 0; i < nums.size(); i++) {
            //进入窗口
            res[nums[i]]++;
            //满足窗口条件
            while (res.rbegin()->first - res.begin()->first > 2) {
                //缩小左边界
                if (--res[nums[left]] == 0) {
                    res.erase(nums[left]);
                }
                left++;
            }
            ans += i - left + 1;
        }
        return ans;
    }
};