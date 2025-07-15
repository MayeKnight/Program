using ll = long long;
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        ll n = nums.size(), cur = 0, sum = 0;
        for (ll i = 0; i < n; i++) {
            //进入窗口
            cur += nums[i];
            map[nums[i]]++;
            if (i < k - 1) {
                continue;
            }
            //更新答案
            if (map.size() == k) {
                sum = max(sum, cur);
            }
            //离开窗口
            cur -= nums[i - k + 1];
            map[nums[i - k + 1]]--;
            if (map[nums[i - k + 1]] == 0) {
                map.erase(nums[i - k + 1]);
            }
        }
        return sum;
    }
};