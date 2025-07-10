using ll = long long;
class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        ll n = nums.size(), sum = 0, cur = 0;  //cur存储当前窗口元素的和, sum存储可以更新的最大和
        unordered_map<int, int> map;  //哈希表, 记录当前窗口中每个数字出现的次数
        for (ll i = 0; i < n; i++) {
            //进入窗口
            cur += nums[i];
            map[nums[i]]++;
            if (i < k - 1) {
                continue;
            }
            if (map.size() >= m) {  //map.size()即键的数量, 表示当前滑动窗口(子数组)中不同元素的数量, map.size()>=m 的含义是当前子数组中至少有m个不同的元素, 此时可以更新sum
                sum = max(sum, cur);
            }
            //离开窗口
            cur -= nums[i - k + 1];  //移除左边界元素
            map[nums[i - k + 1]]--;  // 同时将该元素计数减一
            if (map[nums[i - k + 1]] == 0) {  //当map[nums[i - k + 1]] == 0 时, 意味着当前数组中不存在nums[i - k + 1]对应的数, 故需要erase删除map中对应该键
                map.erase(nums[i - k + 1]);
            }
        }
        return sum;
    }
};
