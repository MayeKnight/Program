class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, left = 0;
        multiset<int> res;
        for (int i = 0; i < n; i++) {
            if (n == 0) {
                return 0;
            }
            while (res.count(nums[i]) > k - 1) {  //这里因为随后还要插入一个nums[i], 如若当前res中已经有大于k - 1个nums[i] (即已经有k个), 那么再加上后来的nums[i]一定会超过k个, 所以要执行删除操作.
                res.erase(res.find(nums[left]));
                left++;
            }
            ans = max(ans, i - left + 1);
            res.insert(nums[i]);
        }
        return ans;
    }
};